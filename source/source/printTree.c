#include <stdio.h>
#include "../headers/parseTree.h"
#include "../headers/printTree.h"


void PrintTree(TERNARY_TREE t, int tabbingAmount)
{
	if (t == NULL) return;

	/* Do tabbing */
	for (int i = 0; i < tabbingAmount; i++) {
		printf("    ");
	}

	if (t->item != NOTHING || t->nodeIdentifier == REAL_NODE) {
		
		if (t->nodeIdentifier == INTEGER_NODE) { /* Integer Number */
			printf("Integer Item: %d", t->item);
		}
		else if (t->nodeIdentifier == REAL_NODE) { /* Real Number */
			printf("Real Number Item: %d.%d", t->first->item, t->second->item);
		}
		else if (t->nodeIdentifier == CONSTANT && t->first == NULL) { /* Character Constant */
			printf("Character Constant: %c", t->item);
		}
		else if (t->nodeIdentifier == NUMBER_CONSTANT && t->item == MINUS) {
			printf("Number Constant Item: Minus");
		}
		else if (t->nodeIdentifier == IDENNODE) { /* Identifier */
			if (t->item < 0 || t->item >= SYMTABSIZE) {
				printf("Unknown identifier item: %d", t->item);
			}
			else {
				printf("Identifier Item: %s", symTab[t->item]->identifier);
			}
			
		}
		else if (t->nodeIdentifier == STATEMENT) {
			switch (t->item) {
				case ASSIGNMENT_STATEMENT:
					printf("Statement Item: assignment_statement");
				break;
				
				case IF_STATEMENT:
					printf("Statement Item: if_statement");
				break;

				case DO_STATEMENT:
					printf("Statement Item: do_statement");
				break;

				case WHILE_STATEMENT:
					printf("Statement Item: while_statement");
				break;

				case FOR_STATEMENT:
					printf("Statement Item: for_statement");
				break;

				case WRITE_STATEMENT:
					printf("Statement Item: write_statement");
				break;

				case READ_STATEMENT:
					printf("Statement Item: read_statement");
				break;

				default:
					printf("Statement Item: default");
				break;
			}

		}
		else if (t->nodeIdentifier == TYPENODE) {
			switch (t->item) {
				case CHAR:
					printf("TypeNode Item: char");
				break;

				case INT:
					printf("TypeNode Item: int");
				break;

				case REAL:
					printf("TypeNode Item: real");
				break;
			}
		}
		else if (t->nodeIdentifier == COMPARATOR) {
			switch (t->item) {
				case EQUAL:
					printf("Comparator Item: equal");
				break;
				case NOTEQ:
					printf("Comparator Item: noteq");
				break;
				case LESSTHAN:
					printf("Comparator Item: lessthan");
				break;
				case MORETHAN:
					printf("Comparator Item: morethan");
				break;
				case LESSEQUAL:
					printf("Comparator Item: lessequal");
				break;
				case MOREEQUAL:
					printf("Comparator Item: moreequal");
				break;

			}
		}
		else {
			printf("Unknown Item: %d", t->item);
		}


	}


	int namesLength = sizeof(NodeNames) / sizeof(NodeNames[0]);
	if (t->nodeIdentifier < 0 || t->nodeIdentifier >= namesLength) {
		printf(" unknown nodeIdentifier: %d\n", t->nodeIdentifier);
	}
	else {
		printf(" nodeIdentifier: %s\n", NodeNames[t->nodeIdentifier]);
	}


	PrintTree(t->first, tabbingAmount + 1);
	PrintTree(t->second, tabbingAmount + 1);
	PrintTree(t->third, tabbingAmount + 1);
}
