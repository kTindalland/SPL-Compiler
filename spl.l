%{
/* Macro functions copied from Brian Tompsett's Lecture  */
#ifdef PRINT
#define RETURN(typearg, token) printf( #typearg " " #token "\n")
#else
#define RETURN(typearg, token) return(token)
#endif
%}
delim [ \t\r\n]
ws {delim}+
digit [0-9]
integer {digit}+
real {integer}.{integer}
character [a-zA-Z]
identifier {character}({character}|{digit})*
characterConst \'{character}\'
%%
":" RETURN(symbol, COLON);
";" RETURN(symbol, SEMICOLON);
"." RETURN(symbol, DOT);
"," RETURN(symbol, COMMA);
"'" RETURN(symbol, APOST);
"->" RETURN(symbol, ASSIGN);
"(" RETURN(symbol, BRA);
")" RETURN(symbol, KET);
"+" RETURN(symbol, PLUS);
"-" RETURN(symbol, MINUS);
"*" RETURN(symbol, TIMES);
"/" RETURN(symbol, DIV);
"=" RETURN(comparator, EQUAL);
"<>" RETURN(comparator, NOTEQ);
"<" RETURN(comparator, LESSTHAN);
">" RETURN(comparator, MORETHAN);
"<=" RETURN(comparator, LESSEQUAL);
">=" RETURN(comparator, MOREEQUAL);
ENDP RETURN(keyword, ENDP);
CODE RETURN(keyword, CODE);
OF RETURN(keyword, OF);
TYPE RETURN(keyword, TYPE);
DECLARATIONS RETURN(keyword, DECL);
IF RETURN(keyword, IF);
THEN RETURN(keyword, THEN);
ELSE RETURN(keyword, ELSE);
ENDIF RETURN(keyword, ENDIF);
DO RETURN(keyword, DO);
WHILE RETURN(keyword, WHILE);
ENDDO RETURN(keyword, ENDDO);
ENDWHILE RETURN(keyword, ENDWHILE);
FOR RETURN(keyword, FOR);
IS RETURN(keyword, IS);
BY RETURN(keyword, BY);
TO RETURN(keyword, TO);
ENDFOR RETURN(keyword, ENDFOR);
WRITE RETURN(keyword, WRITE);
NEWLINE RETURN(keyword, NEWL);
READ RETURN(keyword, READ);
NOT RETURN(keyword, NOT);
AND RETURN(keyword, AND);
OR RETURN(keyword, OR);
CHARACTER RETURN(vartype, CHAR);
INTEGER RETURN(vartype, INT);
REAL RETURN(vartype, REAL);
{ws} ; /* Do nothing */
{integer} {
	RETURN(number, NUMBER);
	}
{real} {
	RETURN(number, REALNUM);
	}
{characterConst} {
	RETURN(character, CHARCONST);
	}
{identifier} {
	RETURN(identifier, IDEN);
	}
