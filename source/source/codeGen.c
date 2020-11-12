#include <stdio.h>
#include "parseTree.h"
#include "codeGen.h"
#include "symbolTable.h"


void CodeGen(TERNARY_TREE t) {

	if (t == NULL) return; // Null node

	switch (t->nodeIdentifier) {

		case PROGRAM:
			printf("#include <stdio.h>\n");
			printf("void main() {");
			
			CodeGen(t->second);

			printf("}");
			break;

		case BLOCK:
			CodeGen(t->first);
			CodeGen(t->second);
			break;

		case IDENTIFIERS_LIST:
			// If there's not a second node, first is iden, if not, first is list
			if (t->second == NULL) { // Iden
				CodeGen(t->first);
			}
			else { // Iden list, iden
				CodeGen(t->second);
				printf(",");
				CodeGen(t->first);
			}
			break;

		case DECLARATION:
			CodeGen(t->second); // Type
			printf(" ");

			CodeGen(t->first); // Iden list
			printf(";"); // End the line
			break;

		case DECLARATION_BLOCK:
			CodeGen(t->first);
			CodeGen(t->second);
			break;

		case TYPENODE:
			switch(t->item) {
				case CHAR:
					printf("char");
					break;
				case INT:
					printf("int");
					break;
				case REAL:
					printf("double");

			}
			break;

		case STATEMENT_LIST:
			CodeGen(t->first);
			CodeGen(t->second);
			break;

		case STATEMENT:
			CodeGen(t->first);
			break;

		case ASSIGNMENT_STATEMENT:
			CodeGen(t->second);
			printf(" = ");
			CodeGen(t->first);
			printf(";");
			break;

		case IF_STATEMENT:
			printf("if (");
			CodeGen(t->first);
			printf(") {");
			CodeGen(t->second);
			printf("}");

			if( t->third != NULL) {
				printf("else {");
				CodeGen(t->third);
				printf("}");
			}
			
			break;

		case DO_STATEMENT:
			printf("do {");
			CodeGen(t->first);
			printf("} while(");
			CodeGen(t->second);
			printf(");");

			break;

		case WHILE_STATEMENT:
			printf("while (");
			CodeGen(t->first);
			printf(") {");
			CodeGen(t->second);
			printf("}");
			break;

		case FOR_STATEMENT:
			GenerateForLoop(t, t->second);
			break;

		case WRITE_STATEMENT:
			if (t->first == NULL) {
				// NEWL
				printf("printf(\"\\n\");");
			}
			else {
				// Normal Write
				CodeGen(t->first);

			}
			break;

		case OUTPUT_LIST:
			if (t->second == NULL) { // Single Value
				if (t->first->item == CONSTANT) { // If a constant
					printf("printf(\"");
					CodeGen(t->first->first);
					printf("\");");
				}
				else { // if a iden
					// Get Iden
					SYMTABNODEPTR iden = symTab[t->first->first->item];
					printf("printf(\"");
					printf(iden->typeSymbol);
					printf("\", ");
					printf(iden->identifier);
					printf(");");
				}
			}
			else { // Still a list
				
				CodeGen(t->first);
				if (t->second->item == CONSTANT) { // If a constant
					printf("printf(\"");
					CodeGen(t->second->first);
					printf("\");");
				}
				else { // if a iden
					// Get Iden
					SYMTABNODEPTR iden = symTab[t->second->first->item];
					printf("printf(\"");
					printf(iden->typeSymbol);
					printf("\", ");
					printf(iden->identifier);
					printf(");");
				}

			}
			break;

		case READ_STATEMENT:
			printf("scanf(\"");
			char* typesymbol = GetType(t->first->item);
			printf("%s\",", typesymbol);    /* Type */

			char* idensymbol = GetIdentifier(t->first->item);
			printf("&%s);",idensymbol);    /* Variable */
			break;
		
		case CONDITIONAL:
			if (t->item == NOT) {
				printf("!(");
				CodeGen(t->first);
				printf(")");
			}
			else if (t->item == AND || t->item == OR) {
				printf("(");
				CodeGen(t->first);
				printf(")");

				if (t->item == AND) { printf("&&"); }
				else { printf("||"); }

				printf("(");
				CodeGen(t->second);
				printf(")");

			}
			else { // Normal
				printf("(");
				CodeGen(t->first);
				printf(")");
				
				CodeGen(t->second);

				printf("(");
				CodeGen(t->third);
				printf(")");
			}

			break;

		case COMPARATOR:
			switch (t->item) {

				case EQUAL:
					printf("=");
					break;
				case NOTEQ:
					printf("!=");
					break;
				case LESSTHAN:
					printf("<");
					break;
				case MORETHAN:
					printf(">");
					break;
				case LESSEQUAL:
					printf("<=");
					break;
				case MOREEQUAL:
					printf(">=");
					break;
				

			}
			break;

		case EXPRESSION:
			if (t->second == NULL) { // Term
				CodeGen(t->first);
			}
			else {
				printf("(");
				CodeGen(t->first);

				if (t->item == PLUS) {
					printf(") + (");
				} else {
					printf(") - (");
				}

				CodeGen(t->second);
				printf(")");
					
			}
			break;

		case TERM:
			if (t->second == NULL) { // Value
				CodeGen(t->first);
			}
			else {
				printf("(");
				CodeGen(t->first);

				if (t->item == TIMES) {
					printf(") * (");
				} else {
					printf(") / (");
				}

				CodeGen(t->second);
				printf(")");
					
			}
			break;
			

		case VALUE:
			printf("(");
			CodeGen(t->first);
			printf(")");
			break;


		case INTEGER_NODE:
			printf("%d", t->item);
			break;

		case REAL_NODE:
			printf("%d.%d", t->first->item, t->second->item);
			break;

		case NUMBER_CONSTANT:
			if (t->item == MINUS) printf("-");
			CodeGen(t->first);
			break;

		case CONSTANT:
			if (t->first != NULL) { // Number
				CodeGen(t->first);
			} else { // Char
				printf("%c", t->item);
			}
			break;

		case IDENNODE: ;
			char* iden = GetIdentifier(t->item);
			printf("%s", iden);
			break;


	}

}


void GenerateForLoop(TERNARY_TREE for_node, TERNARY_TREE for_statements) {

	TERNARY_TREE ident = for_node->first;
	TERNARY_TREE statements = for_node->third;

	TERNARY_TREE is = for_statements->first;
	TERNARY_TREE by = for_statements->second;
	TERNARY_TREE to = for_statements->third;

	printf("register int _by;");
	printf("for (");
	CodeGen(ident);
	printf(" = (");
	CodeGen(is);
	printf("); _by = (");
	CodeGen(by);
	printf("), (");
	CodeGen(ident);
	printf("-(");
	CodeGen(to);
	printf("))*((_by > 0) - (_by < 0)) <= 0;");
	CodeGen(ident);
	printf("+= _by) {");

	CodeGen(statements);

	printf("}");

}
