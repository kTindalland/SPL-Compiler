#include "parseTree.h"
#ifndef __SYMTABH
#define __SYMTABH

#define SYMTABSIZE     50
#define TYPELENGTH     10
#define IDLENGTH       15

struct symTabNode {
    char identifier[IDLENGTH];
    char typeSymbol[TYPELENGTH];
};

typedef  struct symTabNode SYMTABNODE;
typedef  SYMTABNODE        *SYMTABNODEPTR;

int installId(char*);
SYMTABNODEPTR newSymTabNode();
int lookup(char* s);

char* GetIdentifier(int number);
char* GetType(int number);
void SymbolTablePopulateTypes(TERNARY_TREE iden_list, int type);
void SymbolTablePopulateSingleType(TERNARY_TREE iden_list, int type);

#endif
