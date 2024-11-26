/****************************************************/
/* File: analyze.c                                  */
/* Semantic analyzer implementation                 */
/* for the TINY compiler                            */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "globals.h"
#include "symtab.h"
#include "analyze.h"
/* counter for variable memory locations */
// static int location = 0;
// change to Scope->location

/* Procedure traverse is a generic recursive 
 * syntax tree traversal routine:
 * it applies preProc in preorder and postProc 
 * in postorder to tree pointed to by t
 */
int globalIndex=1;

typedef enum {
    Error_UndeclaredFunction,
    Error_UndeclaredVariable,
    Error_VoidVariable,
    Error_InvalidArrayIndexNonInteger,
    Error_InvalidArrayIndexOnNonArray,
    Error_InvalidFunctionCall,
    Error_InvalidReturn,
    Error_InvalidAssignment,
    Error_InvalidOperation,
    Error_InvalidCondition,
    Error_Redefined
} ErrorType;
static void endScope(TreeNode *t);
static void typeError(ErrorType errorType, TreeNode *t);
static void traverse( TreeNode * t,
               void (* preProc) (TreeNode *),
               void (* postProc) (TreeNode *) )
{ if (t != NULL)
  { preProc(t);
    { int i;
      for (i=0; i < MAXCHILDREN; i++)
        traverse(t->child[i],preProc,postProc);
    }
    postProc(t);
    traverse(t->sibling,preProc,postProc);
  }
}
static void typeTraverse( TreeNode * t,
               void (* preProc) (TreeNode *),
               void (* postProc) (TreeNode *) )
{ if (t != NULL)
  { 
    preProc(t);
    // fprintf(listing,"pre %d %d\n",t->lineno,t->nodekind);
    { int i;
      for (i=0; i < MAXCHILDREN; i++)
        typeTraverse(t->child[i],preProc,postProc);
    }
    postProc(t);
    // fprintf(listing,"post %d %d\n",t->lineno,t->nodekind);
    endScope(t);
    typeTraverse(t->sibling,preProc,postProc);
  }
}

/* nullProc is a do-nothing procedure to 
 * generate preorder-only or postorder-only
 * traversals from traverse
 */
// static void nullProc(TreeNode * t)
// { if (t==NULL) return;
//   else return;
// }

static void endScope(TreeNode *t){
  if(t->nodekind==StmtK&&t->kind.stmt==CompoundK){
    ExitScope();
  }
  else if(t->nodekind==DeclK&&t->kind.decl==FunDeclK){
    ExitScope();
  }
}

/* Procedure insertNode inserts 
 * identifiers stored in t into 
 * the symbol table 
 */
static void insertNode( TreeNode * t) // StmtK modify + ExpK modify + Add DeclK 
{ switch (t->nodekind)
  { case StmtK:
      switch (t->kind.stmt)
      { case CompoundK:
          InsertScope("compound");
          break;
        default:
          break;
      }
      break;
    case ExpK:
      switch (t->kind.exp)
      { case IdK:
          if (st_lookup(t->attr.name)==-1){
            t->type = undetermined;
            int temp = CurrentScopeLocation();
            st_insert(t->attr.name,t->lineno,temp,t->type);
            AddLocation();
            // typeError(Error_UndeclaredVariable,t);
          } else {
            // if(st_giveType(t->attr.name)== undetermined) t->type = undetermined;
            t->type = st_giveType(t->attr.name);
            st_insert(t->attr.name,t->lineno,0,st_giveType(t->attr.name));
          }
          break;
        case CallK:
          if(st_lookup(t->attr.name)==-1){
            // fprintf(listing, "in callk");
            t->type = undetermined;
            t->child[0]->type = undetermined;
            TreeNode * tempParam = t->child[0];
            while(tempParam->sibling != NULL) {
              tempParam->type = undetermined;
              tempParam = tempParam->sibling;
            }

            int temp = CurrentScopeLocation();
            st_insert(t->attr.name,t->lineno,temp,t->type);
            st_isFunc(t->attr.name);
            AddLocation();
            InsertScope(t->attr.name);
            makeCurrentFuncScope(t);
            TreeNode *param = t->child[0];
            int i=0;
            while(param!=NULL){
              if(param->type == Void){
                // typeError(Error_VoidVariable,t);
              } else {
                int temp = CurrentScopeLocation();
                st_insert_func("undetermined",param->lineno,temp,param->type,i++,t->type);
                AddLocation();
              }
              param = param->sibling;
            }
            // typeError(Error_UndeclaredFunction,t);
          } else {
            t->type = GlobalFuncReturnType(t->attr.name);
            // fprintf(listing,"******%d******",t->type);
            st_insert(t->attr.name,t->lineno,0,t->type);
          }
          break;
        case OpK:
          t->type = Integer;
          break;
        case ConstK:
          t->type = Integer;
          break;
        case AssignK:
        case TypeK:
        case ParamK:
        default:
          break;
      }
      break;
    case DeclK:
      switch (t->kind.decl)
      {
      case VarDeclK:
        if(st_check(t->attr.name)){
          increaseDefineCount(t->attr.name);
        }
        else {
          int temp = CurrentScopeLocation();
          st_insert(t->attr.name,t->lineno,temp,t->type);
          AddLocation();
        }
        break;
      case FunDeclK:
        if(st_check(t->attr.name)){
          increaseDefineCount(t->attr.name);
        }
        else {
          int temp = CurrentScopeLocation();
          st_insert(t->attr.name,t->lineno,temp,t->type);
          st_isFunc(t->attr.name);
          AddLocation();
          InsertScope(t->attr.name);
          makeCurrentFuncScope(t);
          TreeNode *param = t->child[0];
          int i = 0;
          while(param!=NULL){
            if(param->type == Void){
              typeError(Error_VoidVariable,t);
            } else {
              int temp = CurrentScopeLocation();
              st_insert_func(param->attr.name,param->lineno,temp,param->type,i++,t->type);
              AddLocation();
            }
            param = param->sibling;
          }

        }
        break;
      default:
        break;
      }
      break;
    default:
      break;
    
  }
}

/* Function buildSymtab constructs the symbol 
 * table by preorder traversal of the syntax tree
 */
void buildSymtab(TreeNode * syntaxTree)
{ 
  InsertScope("global");
  int temp = CurrentScopeLocation();
  st_insert_func("input",0,temp,Integer,0,Integer);
  AddLocation();
  temp = CurrentScopeLocation();
  st_insert_func("output",0,temp,Void,1,Void);
  AddLocation();

  traverse(syntaxTree,insertNode,endScope);
  ExitScope();

  if(TraceAnalyze){
    fprintf(listing,"\nSymbol Table:\n\n");
    printSymTab(listing);
  }
}

static void typeError(ErrorType errorType, TreeNode *t) {
    Error = TRUE;

    switch (errorType) {
        case Error_UndeclaredFunction:
            fprintf(listing, "Error: undeclared function \"%s\" is called at line %d\n", t->attr.name, t->lineno);
            break;
        case Error_UndeclaredVariable:
            fprintf(listing, "Error: undeclared variable \"%s\" is used at line %d\n", t->attr.name, t->lineno);
            break;
        case Error_VoidVariable:
            fprintf(listing, "Error: The void-type variable is declared at line %d (name : \"%s\")\n", t->lineno, t->attr.name);
            break;
        case Error_InvalidArrayIndexNonInteger:
            fprintf(listing, "Error: Invalid array indexing at line %d (name : \"%s\"). indicies should be integer\n", t->lineno, t->attr.name);
            break;
        case Error_InvalidArrayIndexOnNonArray:
            fprintf(listing, "Error: Invalid array indexing at line %d (name : \"%s\"). indexing can only allowed for int[] variables\n", t->lineno, t->attr.name);
            break;
        case Error_InvalidFunctionCall:
            fprintf(listing, "Error: Invalid function call at line %d (name : \"%s\")\n", t->lineno, t->attr.name);
            break;
        case Error_InvalidReturn:
            fprintf(listing, "Error: Invalid return at line %d\n", t->lineno);
            break;
        case Error_InvalidAssignment:
            fprintf(listing, "Error: Invalid assignment at line %d\n", t->lineno);
            break;
        case Error_InvalidOperation:
            fprintf(listing, "Error: Invalid operation at line %d\n", t->lineno);
            break;
        case Error_InvalidCondition:
            fprintf(listing, "Error: Invalid condition at line %d\n", t->lineno);
            break;
        case Error_Redefined:
            fprintf(listing,"Error: Symbol \"%s\" is redefined at line %d\n",t->attr.name,t->lineno);
            break;
        default:
            fprintf(listing, "Unknown error at line %d\n", t->lineno);
            break;
    }
}

/* Procedure checkNode performs
 * type checking at a single tree node
 */
static void enterScope(TreeNode * t){
   switch (t->nodekind)
  { case StmtK:
      switch (t->kind.stmt)
      { case CompoundK:
          changeCurrentScope(globalIndex++);
          // fprintf(listing,"%d",globalIndex);
          break;
        default:
          break;
      }
      break;
    case ExpK:
      switch (t->kind.exp)
      { case IdK:
          if (t->type == undetermined){
            if(!undeclError(t->attr.name))
              typeError(Error_UndeclaredVariable,t);
          } 
          break;
        case CallK:
          
          break;
        case OpK:
        case ConstK:
        case AssignK:
        case TypeK:
        case ParamK:
        default:
          break;
      }
      break;
    case DeclK:
      switch (t->kind.decl)
      {
      case VarDeclK:
        if(isRedefined(t->attr.name)){
          typeError(Error_Redefined,t);
        }
        break;
      case FunDeclK:
        if(isRedefined(t->attr.name)){
          typeError(Error_Redefined,t);
        }
        changeCurrentScope(globalIndex++);
        // fprintf(listing,"%d lineno: %d",globalIndex,t->lineno);
        TreeNode *param = t->child[0];
        while(param!=NULL){
          if(param->type == Void){
            typeError(Error_VoidVariable,t);
          } 
          param = param->sibling;
        }
        break;
      default:
        break;
      }
      break;
    default:
      break;
    
  }
}
static void checkNode(TreeNode * t) // StmtK modify + ExpK modify + Add DeclK 
{ switch (t->nodekind)
  { case DeclK:
      switch (t->kind.decl)
      {
      case VarDeclK:
        if(t->type == Void || t->type == VoidArr){
          typeError(Error_VoidVariable,t);
        }
        break;
      case FunDeclK:
      default:
        break;
      }
      break;
    case ExpK:
      switch (t->kind.exp)
      { case OpK:
          if(t->child[0] == NULL || t->child[1] == NULL) break;
          // fprintf(listing,"lineno : %d location : type: %d %d\n",t->lineno,t->child[0]->type,t->child[1]->type);
          if (t->child[0]->type %2 != t->child[1]->type %2) {
            typeError(Error_InvalidOperation,t);
          }
          if(t->child[0]->type == IntArr && t->child[1]->type == Integer){
            if(t->child[0]->child[0]==NULL) typeError(Error_InvalidOperation,t);
          }
          if(t->child[0]->type == Integer && t->child[1]->type == IntArr){
            if(t->child[1]->child[0]==NULL) typeError(Error_InvalidOperation,t);
          }
          if(t->child[0]->type == IntArr && t->child[1]->type == IntArr){
            if(t->child[0]->child[0]==NULL || t->child[1]->child[0]==NULL) typeError(Error_InvalidOperation,t);
          }


          break;
        case ConstK:
          t->type = Integer;
          break;
        case IdK:
          if(t->type==IntArr||t->type==VoidArr){
            if(t->child[0] != NULL && t->child[0]->type != Integer){
              typeError(Error_InvalidArrayIndexNonInteger, t);
            } else {
              if(t->child[0] != NULL && !isArr(t->attr.name)){
                typeError(Error_InvalidArrayIndexOnNonArray,t);
              }
            }
          }
          break;
        case AssignK:
          if ((t->child[0]->type)%2 != (t->child[1]->type)%2) {
            if((t->child[0]->type !=4)||(t->child[1]->type!=4)){ // not allow for undetermined
              // fprintf(listing,"%d %d",t->child[0]->type,t->child[1]->type);
              typeError(Error_InvalidAssignment, t);
            }
          }
          break;
        case CallK:
        {
           
          // fprintf(listing,"  %s Call Type: %d\n",t->attr.name,t->type);
          TreeNode *arg = t->child[0];
          ExpType argArr[255]; // MaxParam 255
          int i = 0;
          while(arg!=NULL){
            argArr[i]=arg->type;
            i++;
            arg = arg->sibling;
          }
          i = i-1;
          // fprintf(listing,"arg %d",i);
          
          if(!strcmp(t->attr.name,"input")){
            if(i!=-1) typeError(Error_InvalidFunctionCall,t);
          }
          else if(!strcmp(t->attr.name,"output")){
            if(i!=0) typeError(Error_InvalidFunctionCall,t);
          }
          else {
            int temp = compareParamArg(t->attr.name,argArr,i);
            if(t->type == undetermined){
              if(!undeclError(t->attr.name))
                typeError(Error_UndeclaredFunction,t);
              else{
                if(temp)
                  typeError(Error_InvalidFunctionCall,t);
              }
            } else {
              if(temp){
                typeError(Error_InvalidFunctionCall,t);
              }
            }
            
          }
        }
          break;
        case TypeK:
        case ParamK:
        default:
          break;
      }
      break;
    case StmtK:
      switch (t->kind.stmt)
      { case IfK:
        case WhileK:
          if (t->child[0]->type != Integer)
            typeError(Error_InvalidCondition,t);
          break;
        case ReturnK:
          if(t->child[0]==NULL){ // void return 
            ExpType temp = ReturnType();
            if(temp != Void) typeError(Error_InvalidReturn,t);
          }
          else if(t->child[0]->type != ReturnType()){
            // ExpType temp = ReturnType();
            // fprintf(listing,"   %s\n",t->child[0]->attr.name);
            // fprintf(listing,"retType %d %d\n",t->child[0]->type, temp);
            typeError(Error_InvalidReturn,t);
          }
          break;
        case CompoundK:
        default:
          break;
      }
      break;
    default:
      break;

  }
}

/* Procedure typeCheck performs type checking 
 * by a postorder syntax tree traversal
 */
void typeCheck(TreeNode * syntaxTree)
{ typeTraverse(syntaxTree,enterScope,checkNode);
}

