#include <string.h>
#include "symbolTable.h"

SYMTABNODEPTR  symTab[SYMTABSIZE]; 

int currentSymTabSize = 0;

SYMTABNODEPTR newSymTabNode()
{
    return ((SYMTABNODEPTR)malloc(sizeof(SYMTABNODE)));
}

int lookup(char *s)
{
    extern SYMTABNODEPTR symTab[SYMTABSIZE];
    extern int currentSymTabSize;
    int i;

    for(i=0; i<currentSymTabSize; i++)
    {
        if(strncmp(s,symTab[i]->identifier,IDLENGTH) == 0)
        {
            return (i);
        }
    }
    return (-1);    
}

/* Look up an identifier in the symbol table, if its there return
   its index.  If its not there, put it in the end position,
   as long as the table isn't full, and return its index.
*/

int installId(char *id) 
{
    extern SYMTABNODEPTR symTab[SYMTABSIZE]; 
    extern int currentSymTabSize;
    int index;

    index = lookup(id);
    if (index >= 0)
    {
        return (index);
    }
    else 
       if (currentSymTabSize >= SYMTABSIZE) 
          /* SYMTAB is full */
          return (NOTHING) ;
    else
    {
       symTab[currentSymTabSize] = newSymTabNode();
       /* Recommended code for preventing buffer overrun on bounded strings */
       strncpy(symTab[currentSymTabSize]->identifier,id,IDLENGTH);
       symTab[currentSymTabSize]->identifier[IDLENGTH-1] = '\0';
       return(currentSymTabSize++);
    }
}

char* GetIdentifier(int number) {
	if (number < SYMTABSIZE) {
		return symTab[number]->identifier;
	}
	else {
		return "Identifier not found!";
	}

}

char* GetType(int number) {
	if (number < SYMTABSIZE) {
		return symTab[number]->typeSymbol;
	}
	else {
		return "notfound";
	}
}


void SymbolTablePopulateTypes(TERNARY_TREE iden_list, int type) {

	if (iden_list->second == NULL) { // Single Iden
		SymbolTablePopulateSingleType(iden_list->first, type);
	}
	else { // Still a list
		SymbolTablePopulateTypes(iden_list->first, type);
		SymbolTablePopulateSingleType(iden_list->second, type);
	}

}

void SymbolTablePopulateSingleType(TERNARY_TREE iden_list, int type) {

		char typeSym[4];
		
		switch(type) {
			case INT:
				strncpy(symTab[iden_list->item]->typeSymbol, "%d", TYPELENGTH);
				fprintf(stderr, "Hit INT");
				break;
			case REAL:
				//*typeSym = "%lf";
				strncpy(symTab[iden_list->item]->typeSymbol, "%lf", TYPELENGTH);
				fprintf(stderr, "Hit REAL");
				break;
			case CHAR:
				//*typeSym = "%c";
				strncpy(symTab[iden_list->item]->typeSymbol, "%c", TYPELENGTH);
				fprintf(stderr, "Hit CHAR");
				break;
			default:
				fprintf(stderr, "Hit default");
				break;
		}


		//symTab[iden_list->item]->typeSymbol = *typeSym;
}
