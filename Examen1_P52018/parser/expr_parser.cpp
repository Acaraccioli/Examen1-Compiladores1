#include "expr_parser.h"

int Parser::parse() {

    input();
    return 0;
}
int Parser::input()
	{
		stmt_list();
	}

int Parser::stmt_list()
	{
		stmt();
		stmt_list_prime();

	}

int Parser::stmt_list_prime()
	{
		
		if(token==Token::Semicolon)
		{
			token=lexer.getNextToken();
			stmt();
			stmt_list_prime();
		}
	}

int Parser::stmt()
	{
		if(token==Token::Ident)
		{
			token = lexer.getNextToken();
			if(token==Token::OpAssign)
			{
				token = lexer.getNextToken();
				expr();
			}
		}

		else if(token==Token::KwPrint)
		{
			token =lexer.getNextToken();
			expr();

		}
		
	}

	int Parser::expr()
	{
		term();
		expr_prime();

	}

	int Parser::expr_prime()
	{

		if(token==Token::OpAdd)
		{
			token = lexer.getNextToken();
			term();
			expr_prime();
		}

	}

	int Parser::term()
	{
		factor();
		term_prime();

	}

	int Parser::term_prime()
	{
		
		if(token==Token::OpMul)
		{
			token = lexer.getNextToken();
			factor();
			term_prime();
		}
	}
	int Parser::factor()
	{
		if(token==Token::Ident)
		{
        	token=lexer.getNextToken();
		}
		else if(token==Token::Number)
		{
		    token=lexer.getNextToken();

		}
		else if(token==Token::OpenPar)
		{
			token=lexer.getNextToken();
			expr();
			if(token!=Token::ClosePar)
			{
				throw std::invalid_argument("Sintaxis Inavlida");

			}
			token=lexer.getNextToken();
		    
		}
		else
		{
		    throw std::invalid_argument("Sintaxis Inavlida");

		}
	}
