#ifndef CALC_PARSER_H
#define CALC_PARSER_H

#include "parser.h"
#include "scanner.h"

class Parser : public CalcParser
{
private:
    CalcScanner scanner;
public:
    Parser();
    virtual void yyerror(const char *msg);
    virtual int yylex();
};

Parser::Parser()
{
}

void Parser::yyerror(const char *msg)
{
    if(yylloc.text[0] != '\0')
    {
        std::cerr << yylloc.first_line << ":" << yylloc.first_column <<  ": "
                  << msg << " : <" << yylloc.text << ">" <<  std::endl;
    }
}

int Parser::yylex()
{
    yylloc.first_line = scanner.line;
    yylloc.first_column = scanner.column;
    int token = scanner.yylex(&yylval, &yylloc);
    yylloc.last_line = scanner.line;
    yylloc.last_column = scanner.column;
    yylloc.text = (char *)scanner.yytext;
    return token;
}

#endif
