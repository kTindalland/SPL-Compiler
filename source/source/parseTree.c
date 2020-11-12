#include <stdio.h>
#include <stdlib.h>
#include "parseTree.h"


TERNARY_TREE create_node(int ival, int case_identifier, TERNARY_TREE p1,
			 TERNARY_TREE  p2, TERNARY_TREE  p3)
{
    TERNARY_TREE t;
    t = (TERNARY_TREE)malloc(sizeof(TREE_NODE));
    t->item = ival;
    t->nodeIdentifier = case_identifier;
    t->first = p1;
    t->second = p2;
    t->third = p3;

    if(case_identifier == IDENNODE) {
    	fprintf(stderr, "DEBUGIDENNODE %s\n", symTab[t->item]->identifier);
	}	
	
    if (case_identifier == DECLARATION) {
    	
    	fprintf(stderr, "DEBUGIDENNODE 2 \n");
    	SymbolTablePopulateTypes(t->first, t->second->item);

    }
    return (t);
}
