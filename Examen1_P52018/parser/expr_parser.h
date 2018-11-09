#ifndef _PARSER_H
#define _PARSER_H

#include "expr_lexer.h"

class Parser {
public:
    Parser(Lexer& lexer): lexer(lexer) {}
    int parse();
    int input();
    int stmt_list();
	int stmt_list_prime();
	int stmt();
	int expr();
	int expr_prime();
	int term();
	int term_prime();
	int factor();


private:
    Lexer& lexer;
    Token token;
    int veces;
};

#endif
