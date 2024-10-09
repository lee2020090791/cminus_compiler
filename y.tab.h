/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ELSE = 258,
    IF = 259,
    WHILE = 260,
    RETURN = 261,
    INT = 262,
    VOID = 263,
    ID = 264,
    NUM = 265,
    EQ = 266,
    NE = 267,
    LT = 268,
    LE = 269,
    GT = 270,
    GE = 271,
    LPAREN = 272,
    RPAREN = 273,
    LBRACE = 274,
    RBRACE = 275,
    LCURLY = 276,
    RCURLY = 277,
    SEMI = 278,
    MINUS = 279,
    PLUS = 280,
    TIMES = 281,
    OVER = 282,
    COMMA = 283,
    EXPONENT = 284,
    ASSIGN = 285,
    ENDFILE = 286,
    ERROR = 287
  };
#endif
/* Tokens.  */
#define ELSE 258
#define IF 259
#define WHILE 260
#define RETURN 261
#define INT 262
#define VOID 263
#define ID 264
#define NUM 265
#define EQ 266
#define NE 267
#define LT 268
#define LE 269
#define GT 270
#define GE 271
#define LPAREN 272
#define RPAREN 273
#define LBRACE 274
#define RBRACE 275
#define LCURLY 276
#define RCURLY 277
#define SEMI 278
#define MINUS 279
#define PLUS 280
#define TIMES 281
#define OVER 282
#define COMMA 283
#define EXPONENT 284
#define ASSIGN 285
#define ENDFILE 286
#define ERROR 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
