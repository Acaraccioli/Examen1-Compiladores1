#include "expr_lexer.h"

Token ExprLexer::getNextToken() {
    getNextChar();
    text="";

    while(true){

//blank

     if(ch== ' ' || ch == '\n' ||  ch == '\t')
        {
            getNextChar();
        }

        //digito
     if(isdigit(ch))
        {
            text+=ch;
            getNextChar();
            while(isdigit(ch) || ch=='.')
         {
            text+=ch;
            getNextChar();
         }
         return Token::Num;

    }
        //suma
    if(ch=='+')
    {
        text+=ch;
        return Token::OpAdd;
    }
//div
  if(ch=='/')
    {
        text+=ch;
        return Token::OpDiv;
    }


//semicolon

  if(ch==';')
    {
        text+=ch;
        return Token::Semicolon;
    }
    //resta

      if(ch=='-')
    {
        text+=ch;
        return Token::OpSub;
    }
        //id
     if(ch=='_' || (ch>='a'&& ch<='z') || (ch>='A'&& ch<='Z'))
     {

            text+=ch;
            getNextChar();
            while(ch=='_' || (ch>='a'&& ch<='z') || (ch>='A'&& ch<='Z'))
         {
            text+=ch;
            getNextChar();
         }
         return Token::Id;

     }   

     //open par
       if(ch=='(')
    {
        text+=ch;
        return Token::OpenPar;
    }

     //close par
       if(ch==')')
    {
        text+=ch;
        return Token::ClosePar;
    }

    // comments


    if(ch=='#')
    {
        getNextChar();
        if(ch=='!')
        {
            getNextChar();
            while(ch!='!')
            {
              getNextChar();

            }
            getNextChar();
            if(ch!='#')
            {
            return Token::Error;
            }
            getNextChar();
            text+="";

        }
        else
        {
            getNextChar();
            while(ch!='t')
            {
                getNextChar();
            }
            getNextChar();
            getNextChar();
            getNextChar();
            
        }

    }
    else{
        return Token::Eof;
    }
}
    //return Token::Error;
}




