/****************************************************/
/* File: symtab.h                                   */
/* Symbol table interface for the TINY compiler     */
/* (allows only one symbol table)                   */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#ifndef _SYMTAB_H_
#define _SYMTAB_H_

/* Procedure st_insert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */
// typedef enum {Void,Integer,VoidArr,IntArr,undetermined} ExpType;

void st_insert( char * name, int lineno, int loc, ExpType type );

void st_insert_func(char * name, int lineno, int loc, ExpType type, int i, ExpType retType);

/* Function st_lookup returns the memory 
 * location of a variable or -1 if not found
 */
int st_lookup ( char * name );

void InsertScope( char * name);

void ExitScope();

int st_check(char * name);

void printAllScopes(FILE * listing);

int CurrentScopeLocation();

ExpType GlobalFuncReturnType(char * name);

void makeCurrentFuncScope(TreeNode *t);

ExpType st_giveType(char *name);

int undeclError(char *name);

void increaseDefineCount(char *name);

int isRedefined(char *name);

void st_isFunc(char * name);

void AddLocation();

int compareParamArg(char *name,ExpType* argArr, int size);

int isArr(char*name);

void changeCurrentScope(int index);

ExpType ReturnType();


/* Procedure printSymTab prints a formatted 
 * listing of the symbol table contents 
 * to the listing file
 */
void printSymTab(FILE * listing);

void printAllScopes(FILE *listing);
#endif
