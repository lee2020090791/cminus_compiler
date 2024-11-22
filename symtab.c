/****************************************************/
/* File: symtab.c                                   */
/* Symbol table implementation for the TINY compiler*/
/* (allows only one symbol table)                   */
/* Symbol table is implemented as a chained         */
/* hash table                                       */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "globals.h"
#include "symtab.h"

/* SIZE is the size of the hash table */
#define SIZE 211
#define MaxParam 255
/* SHIFT is the power of two used as multiplier
   in hash function  */
#define SHIFT 4

static int globalIndex;

/* the hash function */
static int hash ( char * key )
{ int temp = 0;
  int i = 0;
  while (key[i] != '\0')
  { temp = ((temp << SHIFT) + key[i]) % SIZE;
    ++i;
  }
  return temp;
}

/* the list of line numbers of the source 
 * code in which a variable is referenced
 */
typedef struct LineListRec
   { int lineno;
     struct LineListRec * next;
   } * LineList;

/* The record in the bucket lists for
 * each variable, including name, 
 * assigned memory location, and
 * the list of line numbers in which
 * it appears in the source code
 */
typedef struct BucketListRec
   { char * name;
     LineList lines;
     int memloc ; /* memory location for variable */
     ExpType type;
     struct BucketListRec * next;
     int isFunc;
   } * BucketList;

/* the hash table */
// static BucketList hashTable[SIZE];

/* define Scope Type for scope analysis
 *
 */
typedef struct ScopeListRec
  { char * name;
    int nestedLevel;
    BucketList hashTable[SIZE];
    struct ScopeListRec *parent;
    struct ScopeListRec *next;
    int location;
    ExpType ParamArr[MaxParam];
    int ParamSize;
    int isFunc;
    ExpType retType;
    int index;
  } * Scope;

Scope currentScope = NULL;
Scope globalScope = NULL;

int CurrentScopeLocation(){ 
  return currentScope->location;
}

void AddLocation(){
  currentScope->location++;
}
void InsertScope(char *scopeName){
  Scope newScope = (Scope)malloc(sizeof(struct ScopeListRec));
  newScope->name = scopeName;
  newScope->nestedLevel = (currentScope==NULL)? 0 : currentScope->nestedLevel+1;
  memset(newScope->hashTable, 0, sizeof(newScope->hashTable));
  newScope->parent=currentScope;
  newScope->next = NULL;
  newScope->location = 0;
  newScope->index = globalIndex++;
  if(globalScope == NULL){
    globalScope = newScope;
  } else {
    Scope temp = globalScope;
    while(temp->next != NULL){
      temp=temp->next;
    }
    temp->next = newScope;
  }
  currentScope=newScope;
}

void ExitScope(){
  if(currentScope->parent!=NULL){
    currentScope = currentScope->parent;
  }
}

Scope FindIndex2Scope(int index){
  if(globalScope ==NULL) return NULL;
  Scope sc = globalScope;
  while(sc!=NULL){
    if(sc->index == index) return sc;
    sc = sc->next;
  }
  return NULL;
}

void changeCurrentScope(int index){
  currentScope = FindIndex2Scope(index);
  if(currentScope==NULL) fprintf(listing,"currentScope NULL\n");
  else fprintf(listing,"change current scope to %d\n",currentScope->index);
}
/* Procedure st_insert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */

ExpType GlobalFuncReturnType(char * name){
  Scope sc = globalScope;
  int h = hash(name);
  BucketList l =  sc->hashTable[h];
  while ((l != NULL) && (strcmp(name,l->name) != 0))
    l = l->next;
  if(l!=NULL){
    if(l->isFunc) return l->type;
    else {
      fprintf(listing,"in globalFuncReturnType, not a function");
      return undetermined;
    }
  }
  return undetermined;
}
void makeCurrentFuncScope(TreeNode* t){
  currentScope->isFunc=1;
  currentScope->retType = t->type;
}
ExpType ReturnType(){
  Scope sc = currentScope;
  while(sc != NULL && !sc->isFunc ){
    // fprintf(listing,"%s\n",sc->name);
    sc = sc->parent;
  }
  // if(sc!=NULL){
  //   if(sc->retType == Integer)
  //     fprintf(listing,"func %s return type : integer",sc->name);
  //   else 
  //     fprintf(listing,"func %s return type : integerx",sc->name);
  // }
  if(sc==NULL) {
    fprintf(listing,"cannotfindscope");
    return undetermined;
  }
  return sc->retType;
}
// i : param size 

void st_isFunc(char * name){
  int h = hash(name);
  BucketList l =  currentScope->hashTable[h];
  while ((l != NULL) && (strcmp(name,l->name) != 0))
    l = l->next;
  l->isFunc=1;
}
void st_insert_func(char *name, int lineno, int loc, ExpType type, int i, ExpType retType){
  int h = hash(name);
  BucketList l =  currentScope->hashTable[h];
  while ((l != NULL) && (strcmp(name,l->name) != 0))
    l = l->next;
  if (l == NULL) /* variable not yet in table */
  { l = (BucketList) malloc(sizeof(struct BucketListRec));
    l->name = name;
    l->lines = (LineList) malloc(sizeof(struct LineListRec));
    l->lines->lineno = lineno;
    l->memloc = loc;
    l->lines->next = NULL;
    l->next = currentScope->hashTable[h]; //
    currentScope->hashTable[h] = l; 
    l->type = type;
    // additional part
    l->isFunc=1;
    currentScope->isFunc=1;
    currentScope->ParamArr[i] = type;
    currentScope->ParamSize = i;
    currentScope->retType=retType;
    }
  else /* found in table, so just add line number */
  { LineList t = l->lines;
    while (t->next != NULL) t = t->next;
    t->next = (LineList) malloc(sizeof(struct LineListRec));
    t->next->lineno = lineno;
    t->next->next = NULL;
    currentScope->isFunc=1;
  }
}
void st_insert( char * name, int lineno, int loc, ExpType type )
{ int h = hash(name);
  BucketList l =  currentScope->hashTable[h];
  while ((l != NULL) && (strcmp(name,l->name) != 0))
    l = l->next;
  if (l == NULL) /* variable not yet in table */
  { l = (BucketList) malloc(sizeof(struct BucketListRec));
    l->name = name;
    l->lines = (LineList) malloc(sizeof(struct LineListRec));
    l->lines->lineno = lineno;
    l->memloc = loc;
    l->lines->next = NULL;
    l->next = currentScope->hashTable[h]; //
    currentScope->hashTable[h] = l; 
    l->type = type;
    l->isFunc=0;
    currentScope->isFunc=0;
    }
  else /* found in table, so just add line number */
  { LineList t = l->lines;
    while (t->next != NULL) t = t->next;
    t->next = (LineList) malloc(sizeof(struct LineListRec));
    t->next->lineno = lineno;
    t->next->next = NULL;
    currentScope->isFunc=0;
  }
} /* st_insert */

/* Function st_lookup returns the memory 
 * location of a variable or -1 if not found
 */
int st_lookup ( char * name )
{ int h = hash(name);
  Scope sc = currentScope;
  while(sc!=NULL){
    BucketList l =  sc->hashTable[h];
    while ((l != NULL) && (strcmp(name,l->name) != 0))
      l = l->next;
    if (l != NULL) return l->memloc;
    sc = sc->parent ;
  }
  return -1;
}
// st_check returns 1 if x is defined in the current scope 
// returns 0 if x is not defined in the current scope 
int st_check( char * name ){
  int h = hash(name);
  BucketList l = currentScope->hashTable[h];
  while((l!=NULL) && (strcmp(name,l->name)!=0))
    l = l->next;
  if(l!=NULL) return 1;
  return 0;
}

Scope st_findScope(char * name){
  Scope sc = globalScope;
  while(sc!=NULL){
    if(strcmp(sc->name,name)==0)
      return sc;
    sc = sc->next ;
  }
  return NULL;
}

// Scope st_findScope(char *name){
//   Scope sc = currentScope;
//   while(sc!=NULL){
//     if(strcmp(sc->name,name)==0)
//       return sc;
//     sc = sc->parent ;
//   }
//   return NULL;
// }

int isArr(char *name){
  int h = hash(name);
  Scope sc = currentScope;
  while(sc!=NULL){
    BucketList l =  sc->hashTable[h];
    while ((l != NULL) && (strcmp(name,l->name) != 0))
      l = l->next;
    if (l != NULL){
      if(l->type == IntArr) return 1;
      else return 0;
    }
    sc = sc->parent ;
  }
  return 0;
}

int compareParamArg(char *name, ExpType* argArr, int size){ // return 0 if arg right / return 1 if arg wrong
  Scope sc = st_findScope(name);
  fprintf(listing,"Param %d\n",sc->ParamSize);
  if(sc==NULL) {
    fprintf(listing,"isNULL");
    return 1;
  }
  if(sc != NULL && sc->ParamSize != size){
    fprintf(listing,"size problem %d %d\n",size,sc->ParamSize);
    return 1;
  }
  for(int i=0;i<=size;i++){
    if(sc->ParamArr[i]!=argArr[i]) {
      fprintf(listing,"paramType %d\n",i);
      return 1;
    }
  }
  return 0;
}

void printAllScopes(FILE *listing) {
    fprintf(listing, "< Scopes >\n");
    fprintf(listing, " %-12s %-13s %-15s %-12s %-6s\n", "Scope Name", "Nested Level", "Symbol Name", "Symbol Type","Index");
    fprintf(listing, " ------------ ------------- --------------- ------------\n");

    Scope sc = globalScope;
    while (sc != NULL) {
        for (int i = 0; i < SIZE; i++) {
            BucketList l = sc->hashTable[i];
            while (l != NULL) {
                fprintf(listing, " %-12s %-13d %-15s %-12d %-6d\n", 
                        sc->name, 
                        sc->nestedLevel, 
                        l->name, 
                        l->type,
                        sc->index);
                l = l->next;
            }
        }
        sc = sc->next; 
    }
}
/* Procedure printSymTab prints a formatted 
 * listing of the symbol table contents 
 * to the listing file
 */
void printSymTab(FILE * listing)
{ int i;
  fprintf(listing,"Variable Name  Location   Line Numbers\n");
  fprintf(listing,"-------------  --------   ------------\n");
  Scope sc = globalScope;
  while(sc!=NULL){
    for (i=0;i<SIZE;++i)
    { if (sc->hashTable[i] != NULL)
      { BucketList l = sc->hashTable[i];
        while (l != NULL)
        { LineList t = l->lines;
          fprintf(listing,"%-14s ",l->name);
          fprintf(listing,"%-8d  ",l->memloc);
          while (t != NULL)
          { fprintf(listing,"%4d ",t->lineno);
            t = t->next;
          }
          fprintf(listing,"\n");
          l = l->next;
        }
      }
    }
    sc = sc->next;
  }
  
} /* printSymTab */
