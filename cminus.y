/****************************************************/
/* File: cimnus.y                                   */
/* The TINY Yacc/Bison specification file           */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/
%{
#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreeNode *
static char * savedName; /* for use in assignments */
static int savedNumber; /* for use in assignments */
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */
static int yylex(void); // added 11/2/11 to ensure no conflict with lex

%}


%token ELSE IF INT RETURN VOID WHILE
%token ID NUM
%token PLUS MINUS TIMES OVER LT LE GT GE EQ NE ASSIGN SEMI COMMA
%token LPAREN RPAREN LBRACE RBRACE LCURLY RCURLY
%token ERROR

%% /* Grammar for CMINUS */

program     : declaration_list
                 { 
                    savedTree = $1;
                    
                 } 
            ;
declaration_list : declaration_list declaration 
                  {
                    YYSTYPE t = $1;
                    if(t != NULL){
                      while(t->sibling != NULL)
                        t = t->sibling;
                      t->sibling = $2;
                      $$ = $1;
                    } else {
                      $$ = $2;
                    }
                  }
                | declaration {$$ = $1;}
                ;
declaration : var_declaration{$$=$1;}
            | fun_declaration{$$=$1;}
            ;
identifier  : ID 
             {
                savedName = copyString(tokenString);
                savedLineNo = lineno;
             }
            ;
number      : NUM
            {
                savedNumber = atoi(tokenString);
                savedLineNo = lineno;
            }
            ;
var_declaration : type_specifier identifier SEMI 
                  {
                    $$ = newDeclNode(VarDeclK);
                    $$->attr.name = savedName;
                    $$->lineno = lineno;
                    $$->child[0] = $1;
                  }
                | type_specifier identifier LBRACE number RBRACE SEMI
                  {
                    $$=newDeclNode(VarDeclK);
                    $$->child[1] = $4;
                    $$->lineno = lineno;
                    $$->attr.name = savedName;
                    $$->child[0] = $1;
                    $$->attr.val = savedNumber;
                  }
                ;
type_specifier  : INT 
                  {
                    $$ = newTypeNode(TypeNameK);  
                    $$->type=Int;
                  }
                | VOID
                  {
                    $$ = newTypeNode(TypeNameK);  
                    $$->type=Void;
                  }
                ;
fun_declaration : type_specifier identifier {
                        $$=newDeclNode(FunDeclK);
                        $$->attr.name = savedName;
                        $$->lineno = lineno;
                    }
                  LPAREN params RPAREN compound_stmt
                    {
                        $$=$3;
                        $$->child[0] =$1;
                        $$->child[1]=$5;
                        $$->child[2]=$7;
                    }
                ;
params      : param_list 
                {$$=$1;}
            | VOID
              {
                $$=newTypeNode(TypeNameK);
                $$->type = Void;
              }
            ;
param_list  : param_list COMMA param
                {
                  YYSTYPE t = $1;
                  if(t!=NULL){
                    while(t->sibling !=NULL)t=t->sibling;
                    t->sibling=$3;
                    $$=$1;
                  } else {
                    $$=$3;
                  }
                }
              | param {
                $$=$1;
              }
            ;
param
    : type_specifier identifier
        {
            $$ = newParamNode(NonArrParamK);
            $$->attr.name = savedName;
            $$->child[0]=$1;
        }
    | type_specifier identifier LBRACE RBRACE
        {
            $$ = newParamNode(ArrParamK);
            $$->attr.name = savedName;
            $$->child[0]=$1;
        }
    ;

compound_stmt
    : LCURLY local_declarations statement_list RCURLY
        {
            $$ = newStmtNode(CompoundK);
            $$->lineno = lineno;
            $$->child[0] = $2;  
            $$->child[1] = $3;  
        }
    ;

local_declarations
    : local_declarations var_declaration
        {
            YYSTYPE t = $1;
            if (t != NULL) {
                while (t->sibling != NULL) t = t->sibling;
                t->sibling = $2;
                $$ = $1;
            } else {
                $$ = $2;
            }
        }
    | /* empty */
        { $$ = NULL; }
    ;

statement_list
    : statement_list statement
        {
            YYSTYPE t = $1;
            if (t != NULL) {
                while (t->sibling != NULL) t = t->sibling;
                t->sibling = $2;
                $$ = $1;
            } else {
                $$ = $2;
            }
        }
    | /* empty */
        { $$ = NULL; }
    ;

statement
    : expression_stmt
        { $$ = $1; }
    | compound_stmt
        { $$ = $1; }
    | selection_stmt
        { $$ = $1; }
    | iteration_stmt
        { $$ = $1; }
    | return_stmt
        { $$ = $1; }
    ;

expression_stmt
    : expression SEMI
        { $$ = $1; }
    | SEMI
        { $$ = NULL; }  
    ;

/* selection_stmt
    : uif
        {$$ = $1;}
    | mif
        {$$=$1;}
mif     : IF LPAREN expression RPAREN mif ELSE mif
        {
            $$ = newStmtNode(IfK);
            $$->child[0] = $3;  
            $$->child[1] = $5; 
            $$->child[2] = $7;
        }
        | statement
            {$$ = $1;}
uif     : IF LPAREN expression RPAREN statement
        {
            $$ = newStmtNode(IfK);
            $$->child[0] = $3;
            $$->child[1] = $5;
        }
        | IF LPAREN expression RPAREN mif ELSE uif
        {
            $$ = newStmtNode(IfK);
            $$->child[0] = $3;  
            $$->child[1] = $5; 
            $$->child[2] = $7;
        }
    ; */
selection_stmt
    : IF LPAREN expression RPAREN statement
        {
            $$ = newStmtNode(IfK);
            $$->child[0] = $3;
            $$->child[1] = $5;
            $$->child[2] = NULL;
        }
    | IF LPAREN expression RPAREN statement ELSE statement
        {
            $$ = newStmtNode(IfK);
            $$->child[0] = $3;  
            $$->child[1] = $5; 
            $$->child[2] = $7;
        }
    ;

iteration_stmt
    : WHILE LPAREN expression RPAREN statement
        {
            $$ = newStmtNode(WhileK);
            $$->child[0] = $3;  
            $$->child[1] = $5;  
        }
    ;

return_stmt
    : RETURN SEMI
        { 
            $$ = newStmtNode(ReturnK); 
            $$->child[0] = NULL;
        }
    | RETURN expression SEMI
        {
            $$ = newStmtNode(ReturnK);
            $$->child[0] = $2;  
        }
    ;

expression
    : var ASSIGN expression
        {
            $$ = newExpNode(AssignK);
            $$->child[0] = $1;  
            $$->child[1] = $3;  
        }
    | simple_expression
        { $$ = $1; }
    ;

var
    : identifier
        {
            $$ = newExpNode(IdK);
            $$->attr.name = savedName;
        }
    | identifier LBRACE expression RBRACE
        {
            $$ = newExpNode(IdK);
            $$->attr.name = savedName;
            $$->child[0] = $3;  
        }
    ;

simple_expression
    : additive_expression relop additive_expression
        {
            $$ = newExpNode(OpK);
            $$->child[0] = $1;
            $$->attr.op = $2->attr.op;
            $$->child[1] = $3;
        }
    | additive_expression
        { $$ = $1; }
    ;

relop
    : LE
        { 
          $$ = newExpNode(OpK);
          $$->attr.op=LE; 
        }
    | LT
        { 
          $$ = newExpNode(OpK);
          $$->attr.op=LT; 
        }
    | GE
        { 
          $$ = newExpNode(OpK);
          $$->attr.op=GE; 
        }
    | GT
        { 
          $$ = newExpNode(OpK);
          $$->attr.op=GT; 
        }
    | EQ
        { 
          $$ = newExpNode(OpK);
          $$->attr.op=EQ; 
        }
    | NE
        { 
          $$ = newExpNode(OpK);
          $$->attr.op=NE; 
        }
    ;

additive_expression
    : additive_expression addop term
        {
            $$ = newExpNode(OpK);
            $$->child[0] = $1;
            $$->attr.op = $2->attr.op;
            $$->child[1] = $3;
        }
    | term
        { $$ = $1; }
    ;

addop
    : PLUS
        { 
          $$ = newExpNode(OpK); 
          $$->attr.op = PLUS;
        }
    | MINUS
        { 
          $$ = newExpNode(OpK); 
          $$->attr.op = MINUS;
        }
    ;

term
    : term mulop factor
        {
            $$ = newExpNode(OpK);
            $$->child[0] = $1;
            $$->attr.op = $2->attr.op;
            $$->child[1] = $3;
        }
    | factor
        { $$ = $1; }
    ;

mulop
    : TIMES
        { 
          $$ = newExpNode(OpK); 
          $$->attr.op = TIMES;
        }
    | OVER
        { 
          $$ = newExpNode(OpK); 
          $$->attr.op = OVER;
        }
    ;

factor
    : LPAREN expression RPAREN
        { $$ = $2; }
    | var
        { $$ = $1; }
    | call
        { $$ = $1; }
    | number
        {
            $$ = newExpNode(ConstK);
            $$->attr.val = savedNumber;
        }
    ;

call
    : identifier LPAREN args RPAREN
        {
            $$ = newExpNode(CallK);
            $$->attr.name = savedName;
            $$->child[0] = $3;  
        }
    ;

args
    : arg_list
        { $$ = $1; }
    | /* empty */
        { $$ = NULL; }
    ;

arg_list
    : arg_list COMMA expression
        {
            YYSTYPE t = $1;
            if (t != NULL) {
                while (t->sibling != NULL) t = t->sibling;
                t->sibling = $3;
                $$ = $1;
            } else {
                $$ = $3;
            }
        }
    | expression
        { $$ = $1; }
    ;


%%

int yyerror(char * message)
{ fprintf(listing,"Syntax error at line %d: %s\n",lineno,message);
  fprintf(listing,"Current token: ");
  printToken(yychar,tokenString);
  Error = TRUE;
  return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 */
static int yylex(void)
{ 
    return getToken(); 
}

TreeNode * parse(void)
{ 
    yyparse();
  return savedTree;
}

