#ifndef _EXPR_LEXER_H
#define _EXPR_LEXER_H
#include <iostream>
#include <fstream>
#include <string>

enum class Token {
    Num         = 100,
    Id          = 101,
    OpAdd       = 102,
    OpSub       = 103,
    OpMul       = 104,
    OpenPar     = 105,
    ClosePar    = 106,
    OpDiv       = 107,
    Semicolon   = 108,
    Error       = 998,
    Eof         = 999,
};


class ExprLexer {
public:
    ExprLexer(std::istream &in) : in(in) {}
    ~ExprLexer() {}

    Token getNextToken();
    std::string getText() { return text; }
    char ch;
    char getNextChar(){ch=in.get();};

private:
    std::istream &in;
    std::string text;
    
};
#endif
