/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 7 "cminus.y"

#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreeNode *
static char * savedName; /* for use in assignments */
static int savedNumber; /* for use in assignments */
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */
static int yylex(void); // added 11/2/11 to ensure no conflict with lex


#line 88 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ELSE = 258,                    /* ELSE  */
    IF = 259,                      /* IF  */
    INT = 260,                     /* INT  */
    RETURN = 261,                  /* RETURN  */
    VOID = 262,                    /* VOID  */
    WHILE = 263,                   /* WHILE  */
    ID = 264,                      /* ID  */
    NUM = 265,                     /* NUM  */
    PLUS = 266,                    /* PLUS  */
    MINUS = 267,                   /* MINUS  */
    TIMES = 268,                   /* TIMES  */
    OVER = 269,                    /* OVER  */
    LT = 270,                      /* LT  */
    LE = 271,                      /* LE  */
    GT = 272,                      /* GT  */
    GE = 273,                      /* GE  */
    EQ = 274,                      /* EQ  */
    NE = 275,                      /* NE  */
    ASSIGN = 276,                  /* ASSIGN  */
    SEMI = 277,                    /* SEMI  */
    COMMA = 278,                   /* COMMA  */
    LPAREN = 279,                  /* LPAREN  */
    RPAREN = 280,                  /* RPAREN  */
    LBRACE = 281,                  /* LBRACE  */
    RBRACE = 282,                  /* RBRACE  */
    LCURLY = 283,                  /* LCURLY  */
    RCURLY = 284,                  /* RCURLY  */
    ERROR = 285                    /* ERROR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ELSE 258
#define IF 259
#define INT 260
#define RETURN 261
#define VOID 262
#define WHILE 263
#define ID 264
#define NUM 265
#define PLUS 266
#define MINUS 267
#define TIMES 268
#define OVER 269
#define LT 270
#define LE 271
#define GT 272
#define GE 273
#define EQ 274
#define NE 275
#define ASSIGN 276
#define SEMI 277
#define COMMA 278
#define LPAREN 279
#define RPAREN 280
#define LBRACE 281
#define RBRACE 282
#define LCURLY 283
#define RCURLY 284
#define ERROR 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ELSE = 3,                       /* ELSE  */
  YYSYMBOL_IF = 4,                         /* IF  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_RETURN = 6,                     /* RETURN  */
  YYSYMBOL_VOID = 7,                       /* VOID  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_ID = 9,                         /* ID  */
  YYSYMBOL_NUM = 10,                       /* NUM  */
  YYSYMBOL_PLUS = 11,                      /* PLUS  */
  YYSYMBOL_MINUS = 12,                     /* MINUS  */
  YYSYMBOL_TIMES = 13,                     /* TIMES  */
  YYSYMBOL_OVER = 14,                      /* OVER  */
  YYSYMBOL_LT = 15,                        /* LT  */
  YYSYMBOL_LE = 16,                        /* LE  */
  YYSYMBOL_GT = 17,                        /* GT  */
  YYSYMBOL_GE = 18,                        /* GE  */
  YYSYMBOL_EQ = 19,                        /* EQ  */
  YYSYMBOL_NE = 20,                        /* NE  */
  YYSYMBOL_ASSIGN = 21,                    /* ASSIGN  */
  YYSYMBOL_SEMI = 22,                      /* SEMI  */
  YYSYMBOL_COMMA = 23,                     /* COMMA  */
  YYSYMBOL_LPAREN = 24,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 25,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 26,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 27,                    /* RBRACE  */
  YYSYMBOL_LCURLY = 28,                    /* LCURLY  */
  YYSYMBOL_RCURLY = 29,                    /* RCURLY  */
  YYSYMBOL_ERROR = 30,                     /* ERROR  */
  YYSYMBOL_YYACCEPT = 31,                  /* $accept  */
  YYSYMBOL_program = 32,                   /* program  */
  YYSYMBOL_declaration_list = 33,          /* declaration_list  */
  YYSYMBOL_declaration = 34,               /* declaration  */
  YYSYMBOL_identifier = 35,                /* identifier  */
  YYSYMBOL_number = 36,                    /* number  */
  YYSYMBOL_var_declaration = 37,           /* var_declaration  */
  YYSYMBOL_type_specifier = 38,            /* type_specifier  */
  YYSYMBOL_fun_declaration = 39,           /* fun_declaration  */
  YYSYMBOL_40_1 = 40,                      /* @1  */
  YYSYMBOL_params = 41,                    /* params  */
  YYSYMBOL_param_list = 42,                /* param_list  */
  YYSYMBOL_param = 43,                     /* param  */
  YYSYMBOL_compound_stmt = 44,             /* compound_stmt  */
  YYSYMBOL_local_declarations = 45,        /* local_declarations  */
  YYSYMBOL_statement_list = 46,            /* statement_list  */
  YYSYMBOL_statement = 47,                 /* statement  */
  YYSYMBOL_expression_stmt = 48,           /* expression_stmt  */
  YYSYMBOL_selection_stmt = 49,            /* selection_stmt  */
  YYSYMBOL_iteration_stmt = 50,            /* iteration_stmt  */
  YYSYMBOL_return_stmt = 51,               /* return_stmt  */
  YYSYMBOL_expression = 52,                /* expression  */
  YYSYMBOL_var = 53,                       /* var  */
  YYSYMBOL_simple_expression = 54,         /* simple_expression  */
  YYSYMBOL_relop = 55,                     /* relop  */
  YYSYMBOL_additive_expression = 56,       /* additive_expression  */
  YYSYMBOL_addop = 57,                     /* addop  */
  YYSYMBOL_term = 58,                      /* term  */
  YYSYMBOL_mulop = 59,                     /* mulop  */
  YYSYMBOL_factor = 60,                    /* factor  */
  YYSYMBOL_call = 61,                      /* call  */
  YYSYMBOL_args = 62,                      /* args  */
  YYSYMBOL_arg_list = 63                   /* arg_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   97

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  105

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    33,    33,    39,    51,    53,    54,    56,    62,    68,
      75,    85,    90,    96,    96,   109,   111,   117,   128,   133,
     139,   148,   158,   170,   174,   186,   190,   192,   194,   196,
     198,   203,   205,   238,   245,   255,   264,   269,   277,   283,
     288,   293,   302,   309,   314,   319,   324,   329,   334,   339,
     347,   354,   359,   364,   372,   379,   384,   389,   397,   399,
     401,   403,   411,   420,   423,   427,   438
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ELSE", "IF", "INT",
  "RETURN", "VOID", "WHILE", "ID", "NUM", "PLUS", "MINUS", "TIMES", "OVER",
  "LT", "LE", "GT", "GE", "EQ", "NE", "ASSIGN", "SEMI", "COMMA", "LPAREN",
  "RPAREN", "LBRACE", "RBRACE", "LCURLY", "RCURLY", "ERROR", "$accept",
  "program", "declaration_list", "declaration", "identifier", "number",
  "var_declaration", "type_specifier", "fun_declaration", "@1", "params",
  "param_list", "param", "compound_stmt", "local_declarations",
  "statement_list", "statement", "expression_stmt", "selection_stmt",
  "iteration_stmt", "return_stmt", "expression", "var",
  "simple_expression", "relop", "additive_expression", "addop", "term",
  "mulop", "factor", "call", "args", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-88)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-17)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      17,   -88,   -88,    13,    17,   -88,   -88,    27,   -88,   -88,
     -88,   -88,    12,   -88,    33,    30,   -88,    41,    37,    47,
      46,    27,    48,    49,   -88,   -88,    44,    50,    17,    52,
     -88,   -88,   -88,   -88,    17,   -88,    27,    23,    12,    51,
      -5,    53,   -88,    -3,   -88,    22,   -88,   -88,   -88,   -88,
     -88,   -88,   -88,    54,    59,   -88,    45,    36,   -88,   -88,
      -3,   -88,    60,    -3,    56,    -3,    -3,   -88,    -3,   -88,
     -88,   -88,   -88,   -88,   -88,   -88,   -88,    -3,    -3,   -88,
     -88,    -3,    58,   -88,    61,   -88,   -88,    62,    65,    57,
     -88,   -88,    55,    36,   -88,    31,    31,   -88,    -3,   -88,
      71,   -88,   -88,    31,   -88
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    11,    12,     0,     2,     4,     5,     0,     6,     1,
       3,     7,    13,     9,     0,     0,     8,     0,     0,     0,
      12,     0,     0,    15,    18,    10,    19,     0,     0,     0,
      23,    14,    17,    20,    25,    22,     0,     0,     0,     0,
       0,     0,    32,     0,    21,    40,    61,    27,    24,    26,
      28,    29,    30,     0,    59,    39,    43,    51,    55,    60,
       0,    36,     0,     0,     0,    64,     0,    31,     0,    52,
      53,    45,    44,    47,    46,    48,    49,     0,     0,    56,
      57,     0,     0,    37,     0,    58,    66,     0,    63,     0,
      38,    59,    42,    50,    54,     0,     0,    62,     0,    41,
      33,    35,    65,     0,    34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -88,   -88,   -88,    81,    -6,    75,    63,   -16,   -88,   -88,
     -88,   -88,    64,    66,   -88,   -88,   -87,   -88,   -88,   -88,
     -88,   -40,   -67,   -88,   -88,    14,   -88,    16,   -88,     9,
     -88,   -88,   -88
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,    45,    46,     6,     7,     8,    15,
      22,    23,    24,    47,    34,    37,    48,    49,    50,    51,
      52,    53,    54,    55,    77,    56,    78,    57,    81,    58,
      59,    87,    88
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      62,    12,    21,    64,    11,    16,    11,    16,   100,   101,
      91,    91,    21,     9,    91,    26,   104,    61,    36,    43,
      82,    43,     1,    84,     2,    86,    89,    39,    90,    40,
      38,    41,    11,    16,    13,    39,    11,    40,    14,    41,
      11,    16,     1,    16,    20,    42,    65,    43,    66,    79,
      80,    30,    44,    42,    18,    43,    69,    70,   102,    30,
      71,    72,    73,    74,    75,    76,    69,    70,    19,    25,
      29,   -16,    28,    27,   103,    60,    67,    63,    30,    33,
      68,    85,    83,    95,    99,    10,    96,    97,    98,    17,
      94,    92,    32,    31,    93,     0,     0,    35
};

static const yytype_int8 yycheck[] =
{
      40,     7,    18,    43,     9,    10,     9,    10,    95,    96,
      77,    78,    28,     0,    81,    21,   103,    22,    34,    24,
      60,    24,     5,    63,     7,    65,    66,     4,    68,     6,
      36,     8,     9,    10,    22,     4,     9,     6,    26,     8,
       9,    10,     5,    10,     7,    22,    24,    24,    26,    13,
      14,    28,    29,    22,    24,    24,    11,    12,    98,    28,
      15,    16,    17,    18,    19,    20,    11,    12,    27,    22,
      26,    25,    23,    25,     3,    24,    22,    24,    28,    27,
      21,    25,    22,    25,    27,     4,    25,    25,    23,    14,
      81,    77,    28,    27,    78,    -1,    -1,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     7,    32,    33,    34,    37,    38,    39,     0,
      34,     9,    35,    22,    26,    40,    10,    36,    24,    27,
       7,    38,    41,    42,    43,    22,    35,    25,    23,    26,
      28,    44,    43,    27,    45,    37,    38,    46,    35,     4,
       6,     8,    22,    24,    29,    35,    36,    44,    47,    48,
      49,    50,    51,    52,    53,    54,    56,    58,    60,    61,
      24,    22,    52,    24,    52,    24,    26,    22,    21,    11,
      12,    15,    16,    17,    18,    19,    20,    55,    57,    13,
      14,    59,    52,    22,    52,    25,    52,    62,    63,    52,
      52,    53,    56,    58,    60,    25,    25,    25,    23,    27,
      47,    47,    52,     3,    47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    33,    33,    34,    34,    35,    36,    37,
      37,    38,    38,    40,    39,    41,    41,    42,    42,    43,
      43,    44,    45,    45,    46,    46,    47,    47,    47,    47,
      47,    48,    48,    49,    49,    50,    51,    51,    52,    52,
      53,    53,    54,    54,    55,    55,    55,    55,    55,    55,
      56,    56,    57,    57,    58,    58,    59,    59,    60,    60,
      60,    60,    61,    62,    62,    63,    63
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     3,
       6,     1,     1,     0,     7,     1,     1,     3,     1,     2,
       4,     4,     2,     0,     2,     0,     1,     1,     1,     1,
       1,     2,     1,     5,     7,     5,     2,     3,     3,     1,
       1,     4,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     4,     1,     0,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: declaration_list  */
#line 34 "cminus.y"
                 { 
                    savedTree = yyvsp[0];
                    
                 }
#line 1311 "y.tab.c"
    break;

  case 3: /* declaration_list: declaration_list declaration  */
#line 40 "cminus.y"
                  {
                    YYSTYPE t = yyvsp[-1];
                    if(t != NULL){
                      while(t->sibling != NULL)
                        t = t->sibling;
                      t->sibling = yyvsp[0];
                      yyval = yyvsp[-1];
                    } else {
                      yyval = yyvsp[0];
                    }
                  }
#line 1327 "y.tab.c"
    break;

  case 4: /* declaration_list: declaration  */
#line 51 "cminus.y"
                              {yyval = yyvsp[0];}
#line 1333 "y.tab.c"
    break;

  case 5: /* declaration: var_declaration  */
#line 53 "cminus.y"
                             {yyval=yyvsp[0];}
#line 1339 "y.tab.c"
    break;

  case 6: /* declaration: fun_declaration  */
#line 54 "cminus.y"
                             {yyval=yyvsp[0];}
#line 1345 "y.tab.c"
    break;

  case 7: /* identifier: ID  */
#line 57 "cminus.y"
             {
                savedName = copyString(tokenString);
                savedLineNo = lineno;
             }
#line 1354 "y.tab.c"
    break;

  case 8: /* number: NUM  */
#line 63 "cminus.y"
            {
                savedNumber = atoi(tokenString);
                savedLineNo = lineno;
            }
#line 1363 "y.tab.c"
    break;

  case 9: /* var_declaration: type_specifier identifier SEMI  */
#line 69 "cminus.y"
                  {
                    yyval = newDeclNode(VarDeclK);
                    yyval->attr.name = savedName;
                    yyval->lineno = lineno;
                    yyval->child[0] = yyvsp[-2];
                  }
#line 1374 "y.tab.c"
    break;

  case 10: /* var_declaration: type_specifier identifier LBRACE number RBRACE SEMI  */
#line 76 "cminus.y"
                  {
                    yyval=newDeclNode(VarDeclK);
                    yyval->child[1] = yyvsp[-2];
                    yyval->lineno = lineno;
                    yyval->attr.name = savedName;
                    yyval->child[0] = yyvsp[-5];
                    yyval->attr.val = savedNumber;
                  }
#line 1387 "y.tab.c"
    break;

  case 11: /* type_specifier: INT  */
#line 86 "cminus.y"
                  {
                    yyval = newTypeNode(TypeNameK);  
                    yyval->type=Int;
                  }
#line 1396 "y.tab.c"
    break;

  case 12: /* type_specifier: VOID  */
#line 91 "cminus.y"
                  {
                    yyval = newTypeNode(TypeNameK);  
                    yyval->type=Void;
                  }
#line 1405 "y.tab.c"
    break;

  case 13: /* @1: %empty  */
#line 96 "cminus.y"
                                            {
                        yyval=newDeclNode(FunDeclK);
                        yyval->attr.name = savedName;
                        yyval->lineno = lineno;
                    }
#line 1415 "y.tab.c"
    break;

  case 14: /* fun_declaration: type_specifier identifier @1 LPAREN params RPAREN compound_stmt  */
#line 102 "cminus.y"
                    {
                        yyval=yyvsp[-4];
                        yyval->child[0] =yyvsp[-6];
                        yyval->child[1]=yyvsp[-2];
                        yyval->child[2]=yyvsp[0];
                    }
#line 1426 "y.tab.c"
    break;

  case 15: /* params: param_list  */
#line 110 "cminus.y"
                {yyval=yyvsp[0];}
#line 1432 "y.tab.c"
    break;

  case 16: /* params: VOID  */
#line 112 "cminus.y"
              {
                yyval=newTypeNode(TypeNameK);
                yyval->type = Void;
              }
#line 1441 "y.tab.c"
    break;

  case 17: /* param_list: param_list COMMA param  */
#line 118 "cminus.y"
                {
                  YYSTYPE t = yyvsp[-2];
                  if(t!=NULL){
                    while(t->sibling !=NULL)t=t->sibling;
                    t->sibling=yyvsp[0];
                    yyval=yyvsp[-2];
                  } else {
                    yyval=yyvsp[0];
                  }
                }
#line 1456 "y.tab.c"
    break;

  case 18: /* param_list: param  */
#line 128 "cminus.y"
                      {
                yyval=yyvsp[0];
              }
#line 1464 "y.tab.c"
    break;

  case 19: /* param: type_specifier identifier  */
#line 134 "cminus.y"
        {
            yyval = newParamNode(NonArrParamK);
            yyval->attr.name = savedName;
            yyval->child[0]=yyvsp[-1];
        }
#line 1474 "y.tab.c"
    break;

  case 20: /* param: type_specifier identifier LBRACE RBRACE  */
#line 140 "cminus.y"
        {
            yyval = newParamNode(ArrParamK);
            yyval->attr.name = savedName;
            yyval->child[0]=yyvsp[-3];
        }
#line 1484 "y.tab.c"
    break;

  case 21: /* compound_stmt: LCURLY local_declarations statement_list RCURLY  */
#line 149 "cminus.y"
        {
            yyval = newStmtNode(CompoundK);
            yyval->lineno = lineno;
            yyval->child[0] = yyvsp[-2];  
            yyval->child[1] = yyvsp[-1];  
        }
#line 1495 "y.tab.c"
    break;

  case 22: /* local_declarations: local_declarations var_declaration  */
#line 159 "cminus.y"
        {
            YYSTYPE t = yyvsp[-1];
            if (t != NULL) {
                while (t->sibling != NULL) t = t->sibling;
                t->sibling = yyvsp[0];
                yyval = yyvsp[-1];
            } else {
                yyval = yyvsp[0];
            }
        }
#line 1510 "y.tab.c"
    break;

  case 23: /* local_declarations: %empty  */
#line 170 "cminus.y"
        { yyval = NULL; }
#line 1516 "y.tab.c"
    break;

  case 24: /* statement_list: statement_list statement  */
#line 175 "cminus.y"
        {
            YYSTYPE t = yyvsp[-1];
            if (t != NULL) {
                while (t->sibling != NULL) t = t->sibling;
                t->sibling = yyvsp[0];
                yyval = yyvsp[-1];
            } else {
                yyval = yyvsp[0];
            }
        }
#line 1531 "y.tab.c"
    break;

  case 25: /* statement_list: %empty  */
#line 186 "cminus.y"
        { yyval = NULL; }
#line 1537 "y.tab.c"
    break;

  case 26: /* statement: expression_stmt  */
#line 191 "cminus.y"
        { yyval = yyvsp[0]; }
#line 1543 "y.tab.c"
    break;

  case 27: /* statement: compound_stmt  */
#line 193 "cminus.y"
        { yyval = yyvsp[0]; }
#line 1549 "y.tab.c"
    break;

  case 28: /* statement: selection_stmt  */
#line 195 "cminus.y"
        { yyval = yyvsp[0]; }
#line 1555 "y.tab.c"
    break;

  case 29: /* statement: iteration_stmt  */
#line 197 "cminus.y"
        { yyval = yyvsp[0]; }
#line 1561 "y.tab.c"
    break;

  case 30: /* statement: return_stmt  */
#line 199 "cminus.y"
        { yyval = yyvsp[0]; }
#line 1567 "y.tab.c"
    break;

  case 31: /* expression_stmt: expression SEMI  */
#line 204 "cminus.y"
        { yyval = yyvsp[-1]; }
#line 1573 "y.tab.c"
    break;

  case 32: /* expression_stmt: SEMI  */
#line 206 "cminus.y"
        { yyval = NULL; }
#line 1579 "y.tab.c"
    break;

  case 33: /* selection_stmt: IF LPAREN expression RPAREN statement  */
#line 239 "cminus.y"
        {
            yyval = newStmtNode(IfK);
            yyval->child[0] = yyvsp[-2];
            yyval->child[1] = yyvsp[0];
            yyval->child[2] = NULL;
        }
#line 1590 "y.tab.c"
    break;

  case 34: /* selection_stmt: IF LPAREN expression RPAREN statement ELSE statement  */
#line 246 "cminus.y"
        {
            yyval = newStmtNode(IfK);
            yyval->child[0] = yyvsp[-4];  
            yyval->child[1] = yyvsp[-2]; 
            yyval->child[2] = yyvsp[0];
        }
#line 1601 "y.tab.c"
    break;

  case 35: /* iteration_stmt: WHILE LPAREN expression RPAREN statement  */
#line 256 "cminus.y"
        {
            yyval = newStmtNode(WhileK);
            yyval->child[0] = yyvsp[-2];  
            yyval->child[1] = yyvsp[0];  
        }
#line 1611 "y.tab.c"
    break;

  case 36: /* return_stmt: RETURN SEMI  */
#line 265 "cminus.y"
        { 
            yyval = newStmtNode(ReturnK); 
            yyval->child[0] = NULL;
        }
#line 1620 "y.tab.c"
    break;

  case 37: /* return_stmt: RETURN expression SEMI  */
#line 270 "cminus.y"
        {
            yyval = newStmtNode(ReturnK);
            yyval->child[0] = yyvsp[-1];  
        }
#line 1629 "y.tab.c"
    break;

  case 38: /* expression: var ASSIGN expression  */
#line 278 "cminus.y"
        {
            yyval = newExpNode(AssignK);
            yyval->child[0] = yyvsp[-2];  
            yyval->child[1] = yyvsp[0];  
        }
#line 1639 "y.tab.c"
    break;

  case 39: /* expression: simple_expression  */
#line 284 "cminus.y"
        { yyval = yyvsp[0]; }
#line 1645 "y.tab.c"
    break;

  case 40: /* var: identifier  */
#line 289 "cminus.y"
        {
            yyval = newExpNode(IdK);
            yyval->attr.name = savedName;
        }
#line 1654 "y.tab.c"
    break;

  case 41: /* var: identifier LBRACE expression RBRACE  */
#line 294 "cminus.y"
        {
            yyval = newExpNode(IdK);
            yyval->attr.name = savedName;
            yyval->child[0] = yyvsp[-1];  
        }
#line 1664 "y.tab.c"
    break;

  case 42: /* simple_expression: additive_expression relop additive_expression  */
#line 303 "cminus.y"
        {
            yyval = newExpNode(OpK);
            yyval->child[0] = yyvsp[-2];
            yyval->attr.op = yyvsp[-1]->attr.op;
            yyval->child[1] = yyvsp[0];
        }
#line 1675 "y.tab.c"
    break;

  case 43: /* simple_expression: additive_expression  */
#line 310 "cminus.y"
        { yyval = yyvsp[0]; }
#line 1681 "y.tab.c"
    break;

  case 44: /* relop: LE  */
#line 315 "cminus.y"
        { 
          yyval = newExpNode(OpK);
          yyval->attr.op=LE; 
        }
#line 1690 "y.tab.c"
    break;

  case 45: /* relop: LT  */
#line 320 "cminus.y"
        { 
          yyval = newExpNode(OpK);
          yyval->attr.op=LT; 
        }
#line 1699 "y.tab.c"
    break;

  case 46: /* relop: GE  */
#line 325 "cminus.y"
        { 
          yyval = newExpNode(OpK);
          yyval->attr.op=GE; 
        }
#line 1708 "y.tab.c"
    break;

  case 47: /* relop: GT  */
#line 330 "cminus.y"
        { 
          yyval = newExpNode(OpK);
          yyval->attr.op=GT; 
        }
#line 1717 "y.tab.c"
    break;

  case 48: /* relop: EQ  */
#line 335 "cminus.y"
        { 
          yyval = newExpNode(OpK);
          yyval->attr.op=EQ; 
        }
#line 1726 "y.tab.c"
    break;

  case 49: /* relop: NE  */
#line 340 "cminus.y"
        { 
          yyval = newExpNode(OpK);
          yyval->attr.op=NE; 
        }
#line 1735 "y.tab.c"
    break;

  case 50: /* additive_expression: additive_expression addop term  */
#line 348 "cminus.y"
        {
            yyval = newExpNode(OpK);
            yyval->child[0] = yyvsp[-2];
            yyval->attr.op = yyvsp[-1]->attr.op;
            yyval->child[1] = yyvsp[0];
        }
#line 1746 "y.tab.c"
    break;

  case 51: /* additive_expression: term  */
#line 355 "cminus.y"
        { yyval = yyvsp[0]; }
#line 1752 "y.tab.c"
    break;

  case 52: /* addop: PLUS  */
#line 360 "cminus.y"
        { 
          yyval = newExpNode(OpK); 
          yyval->attr.op = PLUS;
        }
#line 1761 "y.tab.c"
    break;

  case 53: /* addop: MINUS  */
#line 365 "cminus.y"
        { 
          yyval = newExpNode(OpK); 
          yyval->attr.op = MINUS;
        }
#line 1770 "y.tab.c"
    break;

  case 54: /* term: term mulop factor  */
#line 373 "cminus.y"
        {
            yyval = newExpNode(OpK);
            yyval->child[0] = yyvsp[-2];
            yyval->attr.op = yyvsp[-1]->attr.op;
            yyval->child[1] = yyvsp[0];
        }
#line 1781 "y.tab.c"
    break;

  case 55: /* term: factor  */
#line 380 "cminus.y"
        { yyval = yyvsp[0]; }
#line 1787 "y.tab.c"
    break;

  case 56: /* mulop: TIMES  */
#line 385 "cminus.y"
        { 
          yyval = newExpNode(OpK); 
          yyval->attr.op = TIMES;
        }
#line 1796 "y.tab.c"
    break;

  case 57: /* mulop: OVER  */
#line 390 "cminus.y"
        { 
          yyval = newExpNode(OpK); 
          yyval->attr.op = OVER;
        }
#line 1805 "y.tab.c"
    break;

  case 58: /* factor: LPAREN expression RPAREN  */
#line 398 "cminus.y"
        { yyval = yyvsp[-1]; }
#line 1811 "y.tab.c"
    break;

  case 59: /* factor: var  */
#line 400 "cminus.y"
        { yyval = yyvsp[0]; }
#line 1817 "y.tab.c"
    break;

  case 60: /* factor: call  */
#line 402 "cminus.y"
        { yyval = yyvsp[0]; }
#line 1823 "y.tab.c"
    break;

  case 61: /* factor: number  */
#line 404 "cminus.y"
        {
            yyval = newExpNode(ConstK);
            yyval->attr.val = savedNumber;
        }
#line 1832 "y.tab.c"
    break;

  case 62: /* call: identifier LPAREN args RPAREN  */
#line 412 "cminus.y"
        {
            yyval = newExpNode(CallK);
            yyval->attr.name = savedName;
            yyval->child[0] = yyvsp[-1];  
        }
#line 1842 "y.tab.c"
    break;

  case 63: /* args: arg_list  */
#line 421 "cminus.y"
        { yyval = yyvsp[0]; }
#line 1848 "y.tab.c"
    break;

  case 64: /* args: %empty  */
#line 423 "cminus.y"
        { yyval = NULL; }
#line 1854 "y.tab.c"
    break;

  case 65: /* arg_list: arg_list COMMA expression  */
#line 428 "cminus.y"
        {
            YYSTYPE t = yyvsp[-2];
            if (t != NULL) {
                while (t->sibling != NULL) t = t->sibling;
                t->sibling = yyvsp[0];
                yyval = yyvsp[-2];
            } else {
                yyval = yyvsp[0];
            }
        }
#line 1869 "y.tab.c"
    break;

  case 66: /* arg_list: expression  */
#line 439 "cminus.y"
        { yyval = yyvsp[0]; }
#line 1875 "y.tab.c"
    break;


#line 1879 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 443 "cminus.y"


int yyerror(char * message)
{ fprintf(listing,"Syntax error at line %d: %s\n",lineno,message);
  fprintf(listing,"Current token: ");
  printToken(yychar,tokenString);
  Error = TRUE;
  return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 */
static int yylex(void)
{ 
    return getToken(); 
}

TreeNode * parse(void)
{ 
    yyparse();
  return savedTree;
}

