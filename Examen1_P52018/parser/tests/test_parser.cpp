#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#define YYSTYPE double

#include <sstream>
#include <memory>
#include <vector>
#include <cstring>
#include "doctest.h"
#include "expr_parser.h"

std::vector<TokenInfo> genError = { 
    {Token::Ident, "x"}
};

std::vector<TokenInfo> test1 = {
    {Token::Number, "45.0"},
    {Token::OpAdd, "+"},
    {Token::Number, "10.0"},
};

std::vector<TokenInfo> test2 = {
    {Token::OpenPar, "("},
    {Token::Number, "0.535"},
    {Token::OpSub, "-"},
    {Token::Number, "0.035"},
    {Token::ClosePar, ")"},
    {Token::OpMul, "*"},
    {Token::Number, "10.0"},
};

std::vector<TokenInfo> test3 = {
    {Token::OpenPar, "("},
    {Token::Number, "0.535"},
    {Token::OpSub, "-"},
    {Token::Number, "0.035"},
    {Token::ClosePar, ")"},
    {Token::OpMul, "*"},
    {Token::Number, "100.0"},
    {Token::Semicolon, ";"},
    {Token::OpenPar, "("},
    {Token::Number, "0.4"},
    {Token::OpAdd, "+"},
    {Token::Number, "0.6"},
    {Token::ClosePar, ")"},
    {Token::OpDiv, "/"},
    {Token::Number, "4"},
};

bool genExceptionOnError() {
    Lexer el(genError);
    Parser ep(el);
    
    bool res;
    try {
        ep.parse();
        res = false;
    } catch (...) {
        res = true;
    }
    return res;
}

TEST_CASE("Add expression") {
    REQUIRE(genExceptionOnError());
    
    Lexer l(test1);
    Parser p(l);
    
    bool parseSuccess = false;
    int exprCount = 0;
    try {
        exprCount = p.parse();
        parseSuccess = true;
    } catch (...) {
        parseSuccess = false;
    }
    REQUIRE(!l.hasTokens());
    CHECK(parseSuccess);
    CHECK(exprCount == 1);
}

TEST_CASE("Sub/Mult expression") {
    REQUIRE(genExceptionOnError());
    
    Lexer l(test2);
    Parser p(l);
    
    bool parseSuccess = false;
    int exprCount = 0;
    try {
        exprCount = p.parse();
        parseSuccess = true;
    } catch (...) {
        parseSuccess = false;
    }
    REQUIRE(!l.hasTokens());
    CHECK(parseSuccess);
    CHECK(exprCount == 1);
}

TEST_CASE("Multiple expressions") {
    REQUIRE(genExceptionOnError());
    
    Lexer l(test3);
    Parser p(l);
    
    bool parseSuccess = false;
    int exprCount = 0;
    try {
        exprCount = p.parse();
        parseSuccess = true;
    } catch (...) {
        parseSuccess = false;
    }
    REQUIRE(!l.hasTokens());
    CHECK(parseSuccess);
    CHECK(exprCount == 2);
}

