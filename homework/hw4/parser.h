#ifndef YY_CalcParser_h_included
#define YY_CalcParser_h_included

#line 1 "/usr/lib/bison.h"
/* before anything */
#ifdef c_plusplus
#ifndef __cplusplus
#define __cplusplus
#endif
#endif
#ifdef __cplusplus
#ifndef YY_USE_CLASS
#define YY_USE_CLASS
#endif
#else
#endif
#include <stdio.h>

/* #line 14 "/usr/lib/bison.h" */
#line 21 "parser.h"
#define YY_CalcParser_DEBUG  1
#define YY_CalcParser_LSP_NEEDED 
#define YY_CalcParser_ERROR_BODY  = 0
#define YY_CalcParser_LEX_BODY  = 0
#line 7 "parser.y"

#include <iostream>
#include "math_tree.h"
extern Tree *math_tree;

Tree *new_op(const char *op, Tree *left, Tree *right);
Tree *new_val(double val);

#line 16 "parser.y"
typedef union {
    Tree *t;
    char *op;
    double val;
} yy_CalcParser_stype;
#define YY_CalcParser_STYPE yy_CalcParser_stype

#line 14 "/usr/lib/bison.h"
 /* %{ and %header{ and %union, during decl */
#ifndef YY_CalcParser_COMPATIBILITY
#ifndef YY_USE_CLASS
#define  YY_CalcParser_COMPATIBILITY 1
#else
#define  YY_CalcParser_COMPATIBILITY 0
#endif
#endif

#if YY_CalcParser_COMPATIBILITY != 0
/* backward compatibility */
#ifdef YYLTYPE
#ifndef YY_CalcParser_LTYPE
#define YY_CalcParser_LTYPE YYLTYPE
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
/* use %define LTYPE */
#endif
#endif
#ifdef YYSTYPE
#ifndef YY_CalcParser_STYPE 
#define YY_CalcParser_STYPE YYSTYPE
/* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
/* use %define STYPE */
#endif
#endif
#ifdef YYDEBUG
#ifndef YY_CalcParser_DEBUG
#define  YY_CalcParser_DEBUG YYDEBUG
/* WARNING obsolete !!! user defined YYDEBUG not reported into generated header */
/* use %define DEBUG */
#endif
#endif
#ifdef YY_CalcParser_STYPE
#ifndef yystype
#define yystype YY_CalcParser_STYPE
#endif
#endif
/* use goto to be compatible */
#ifndef YY_CalcParser_USE_GOTO
#define YY_CalcParser_USE_GOTO 1
#endif
#endif

/* use no goto to be clean in C++ */
#ifndef YY_CalcParser_USE_GOTO
#define YY_CalcParser_USE_GOTO 0
#endif

#ifndef YY_CalcParser_PURE

/* #line 63 "/usr/lib/bison.h" */
#line 95 "parser.h"

#line 63 "/usr/lib/bison.h"
/* YY_CalcParser_PURE */
#endif

/* #line 65 "/usr/lib/bison.h" */
#line 102 "parser.h"

#line 65 "/usr/lib/bison.h"
/* prefix */
#ifndef YY_CalcParser_DEBUG

/* #line 67 "/usr/lib/bison.h" */
#line 109 "parser.h"

#line 67 "/usr/lib/bison.h"
/* YY_CalcParser_DEBUG */
#endif
#ifndef YY_CalcParser_LSP_NEEDED

/* #line 70 "/usr/lib/bison.h" */
#line 117 "parser.h"

#line 70 "/usr/lib/bison.h"
 /* YY_CalcParser_LSP_NEEDED*/
#endif
/* DEFAULT LTYPE*/
#ifdef YY_CalcParser_LSP_NEEDED
#ifndef YY_CalcParser_LTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YY_CalcParser_LTYPE yyltype
#endif
#endif
/* DEFAULT STYPE*/
#ifndef YY_CalcParser_STYPE
#define YY_CalcParser_STYPE int
#endif
/* DEFAULT MISCELANEOUS */
#ifndef YY_CalcParser_PARSE
#define YY_CalcParser_PARSE yyparse
#endif
#ifndef YY_CalcParser_LEX
#define YY_CalcParser_LEX yylex
#endif
#ifndef YY_CalcParser_LVAL
#define YY_CalcParser_LVAL yylval
#endif
#ifndef YY_CalcParser_LLOC
#define YY_CalcParser_LLOC yylloc
#endif
#ifndef YY_CalcParser_CHAR
#define YY_CalcParser_CHAR yychar
#endif
#ifndef YY_CalcParser_NERRS
#define YY_CalcParser_NERRS yynerrs
#endif
#ifndef YY_CalcParser_DEBUG_FLAG
#define YY_CalcParser_DEBUG_FLAG yydebug
#endif
#ifndef YY_CalcParser_ERROR
#define YY_CalcParser_ERROR yyerror
#endif

#ifndef YY_CalcParser_PARSE_PARAM
#ifndef __STDC__
#ifndef __cplusplus
#ifndef YY_USE_CLASS
#define YY_CalcParser_PARSE_PARAM
#ifndef YY_CalcParser_PARSE_PARAM_DEF
#define YY_CalcParser_PARSE_PARAM_DEF
#endif
#endif
#endif
#endif
#ifndef YY_CalcParser_PARSE_PARAM
#define YY_CalcParser_PARSE_PARAM void
#endif
#endif

/* TOKEN C */
#ifndef YY_USE_CLASS

#ifndef YY_CalcParser_PURE
extern YY_CalcParser_STYPE YY_CalcParser_LVAL;
#endif


/* #line 143 "/usr/lib/bison.h" */
#line 195 "parser.h"
#define	LEFT_PAREN	258
#define	RIGHT_PAREN	259
#define	PLUS	260
#define	MINUS	261
#define	TIMES	262
#define	DIVIDE	263
#define	CARET	264
#define	FUNC	265
#define	NUMBER	266


#line 143 "/usr/lib/bison.h"
 /* #defines token */
/* after #define tokens, before const tokens S5*/
#else
#ifndef YY_CalcParser_CLASS
#define YY_CalcParser_CLASS CalcParser
#endif

#ifndef YY_CalcParser_INHERIT
#define YY_CalcParser_INHERIT
#endif
#ifndef YY_CalcParser_MEMBERS
#define YY_CalcParser_MEMBERS 
#endif
#ifndef YY_CalcParser_LEX_BODY
#define YY_CalcParser_LEX_BODY  
#endif
#ifndef YY_CalcParser_ERROR_BODY
#define YY_CalcParser_ERROR_BODY  
#endif
#ifndef YY_CalcParser_CONSTRUCTOR_PARAM
#define YY_CalcParser_CONSTRUCTOR_PARAM
#endif
/* choose between enum and const */
#ifndef YY_CalcParser_USE_CONST_TOKEN
#define YY_CalcParser_USE_CONST_TOKEN 0
/* yes enum is more compatible with flex,  */
/* so by default we use it */ 
#endif
#if YY_CalcParser_USE_CONST_TOKEN != 0
#ifndef YY_CalcParser_ENUM_TOKEN
#define YY_CalcParser_ENUM_TOKEN yy_CalcParser_enum_token
#endif
#endif

class YY_CalcParser_CLASS YY_CalcParser_INHERIT
{
public: 
#if YY_CalcParser_USE_CONST_TOKEN != 0
/* static const int token ... */

/* #line 182 "/usr/lib/bison.h" */
#line 249 "parser.h"
static const int LEFT_PAREN;
static const int RIGHT_PAREN;
static const int PLUS;
static const int MINUS;
static const int TIMES;
static const int DIVIDE;
static const int CARET;
static const int FUNC;
static const int NUMBER;


#line 182 "/usr/lib/bison.h"
 /* decl const */
#else
enum YY_CalcParser_ENUM_TOKEN { YY_CalcParser_NULL_TOKEN=0

/* #line 185 "/usr/lib/bison.h" */
#line 267 "parser.h"
	,LEFT_PAREN=258
	,RIGHT_PAREN=259
	,PLUS=260
	,MINUS=261
	,TIMES=262
	,DIVIDE=263
	,CARET=264
	,FUNC=265
	,NUMBER=266


#line 185 "/usr/lib/bison.h"
 /* enum token */
     }; /* end of enum declaration */
#endif
public:
 int YY_CalcParser_PARSE(YY_CalcParser_PARSE_PARAM);
 virtual void YY_CalcParser_ERROR(const char *msg) YY_CalcParser_ERROR_BODY;
#ifdef YY_CalcParser_PURE
#ifdef YY_CalcParser_LSP_NEEDED
 virtual int  YY_CalcParser_LEX(YY_CalcParser_STYPE *YY_CalcParser_LVAL,YY_CalcParser_LTYPE *YY_CalcParser_LLOC) YY_CalcParser_LEX_BODY;
#else
 virtual int  YY_CalcParser_LEX(YY_CalcParser_STYPE *YY_CalcParser_LVAL) YY_CalcParser_LEX_BODY;
#endif
#else
 virtual int YY_CalcParser_LEX() YY_CalcParser_LEX_BODY;
 YY_CalcParser_STYPE YY_CalcParser_LVAL;
#ifdef YY_CalcParser_LSP_NEEDED
 YY_CalcParser_LTYPE YY_CalcParser_LLOC;
#endif
 int YY_CalcParser_NERRS;
 int YY_CalcParser_CHAR;
#endif
#if YY_CalcParser_DEBUG != 0
public:
 int YY_CalcParser_DEBUG_FLAG;	/*  nonzero means print parse trace	*/
#endif
public:
 YY_CalcParser_CLASS(YY_CalcParser_CONSTRUCTOR_PARAM);
public:
 YY_CalcParser_MEMBERS 
};
/* other declare folow */
#endif


#if YY_CalcParser_COMPATIBILITY != 0
/* backward compatibility */
#ifndef YYSTYPE
#define YYSTYPE YY_CalcParser_STYPE
#endif

#ifndef YYLTYPE
#define YYLTYPE YY_CalcParser_LTYPE
#endif
#ifndef YYDEBUG
#ifdef YY_CalcParser_DEBUG 
#define YYDEBUG YY_CalcParser_DEBUG
#endif
#endif

#endif
/* END */

/* #line 236 "/usr/lib/bison.h" */
#line 333 "parser.h"
#endif
