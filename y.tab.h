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
    LOWER_THAN_ELSE = 258,
    ELSE = 259,
    IF = 260,
    WHILE = 261,
    RETURN = 262,
    INT = 263,
    VOID = 264,
    ID = 265,
    NUM = 266,
    ASSIGN = 267,
    EQ = 268,
    NE = 269,
    LT = 270,
    LE = 271,
    GT = 272,
    GE = 273,
    LPAREN = 274,
    RPAREN = 275,
    LBRACE = 276,
    RBRACE = 277,
    LCURLY = 278,
    RCURLY = 279,
    SEMI = 280,
    COMMA = 281,
    MINUS = 282,
    PLUS = 283,
    TIMES = 284,
    OVER = 285,
    ERROR = 286
  };
#endif
/* Tokens.  */
#define LOWER_THAN_ELSE 258
#define ELSE 259
#define IF 260
#define WHILE 261
#define RETURN 262
#define INT 263
#define VOID 264
#define ID 265
#define NUM 266
#define ASSIGN 267
#define EQ 268
#define NE 269
#define LT 270
#define LE 271
#define GT 272
#define GE 273
#define LPAREN 274
#define RPAREN 275
#define LBRACE 276
#define RBRACE 277
#define LCURLY 278
#define RCURLY 279
#define SEMI 280
#define COMMA 281
#define MINUS 282
#define PLUS 283
#define TIMES 284
#define OVER 285
#define ERROR 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
