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

#include "slgh_compile.hh"

using namespace std;

#define YYERROR_VERBOSE

  extern SleighCompile *slgh;
  extern int4 actionon;
  extern FILE *yyin;
  extern int yydebug;
  extern int yylex(void);
  extern int yyerror(const char *str );


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

#include "slghparse.hh"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_OP_BOOL_OR = 3,                 /* OP_BOOL_OR  */
  YYSYMBOL_OP_BOOL_AND = 4,                /* OP_BOOL_AND  */
  YYSYMBOL_OP_BOOL_XOR = 5,                /* OP_BOOL_XOR  */
  YYSYMBOL_6_ = 6,                         /* '|'  */
  YYSYMBOL_OP_OR = 7,                      /* OP_OR  */
  YYSYMBOL_8_ = 8,                         /* ';'  */
  YYSYMBOL_9_ = 9,                         /* '^'  */
  YYSYMBOL_OP_XOR = 10,                    /* OP_XOR  */
  YYSYMBOL_11_ = 11,                       /* '&'  */
  YYSYMBOL_OP_AND = 12,                    /* OP_AND  */
  YYSYMBOL_OP_EQUAL = 13,                  /* OP_EQUAL  */
  YYSYMBOL_OP_NOTEQUAL = 14,               /* OP_NOTEQUAL  */
  YYSYMBOL_OP_FEQUAL = 15,                 /* OP_FEQUAL  */
  YYSYMBOL_OP_FNOTEQUAL = 16,              /* OP_FNOTEQUAL  */
  YYSYMBOL_17_ = 17,                       /* '<'  */
  YYSYMBOL_18_ = 18,                       /* '>'  */
  YYSYMBOL_OP_GREATEQUAL = 19,             /* OP_GREATEQUAL  */
  YYSYMBOL_OP_LESSEQUAL = 20,              /* OP_LESSEQUAL  */
  YYSYMBOL_OP_SLESS = 21,                  /* OP_SLESS  */
  YYSYMBOL_OP_SGREATEQUAL = 22,            /* OP_SGREATEQUAL  */
  YYSYMBOL_OP_SLESSEQUAL = 23,             /* OP_SLESSEQUAL  */
  YYSYMBOL_OP_SGREAT = 24,                 /* OP_SGREAT  */
  YYSYMBOL_OP_FLESS = 25,                  /* OP_FLESS  */
  YYSYMBOL_OP_FGREAT = 26,                 /* OP_FGREAT  */
  YYSYMBOL_OP_FLESSEQUAL = 27,             /* OP_FLESSEQUAL  */
  YYSYMBOL_OP_FGREATEQUAL = 28,            /* OP_FGREATEQUAL  */
  YYSYMBOL_OP_LEFT = 29,                   /* OP_LEFT  */
  YYSYMBOL_OP_RIGHT = 30,                  /* OP_RIGHT  */
  YYSYMBOL_OP_SRIGHT = 31,                 /* OP_SRIGHT  */
  YYSYMBOL_32_ = 32,                       /* '+'  */
  YYSYMBOL_33_ = 33,                       /* '-'  */
  YYSYMBOL_OP_FADD = 34,                   /* OP_FADD  */
  YYSYMBOL_OP_FSUB = 35,                   /* OP_FSUB  */
  YYSYMBOL_36_ = 36,                       /* '*'  */
  YYSYMBOL_37_ = 37,                       /* '/'  */
  YYSYMBOL_38_ = 38,                       /* '%'  */
  YYSYMBOL_OP_SDIV = 39,                   /* OP_SDIV  */
  YYSYMBOL_OP_SREM = 40,                   /* OP_SREM  */
  YYSYMBOL_OP_FMULT = 41,                  /* OP_FMULT  */
  YYSYMBOL_OP_FDIV = 42,                   /* OP_FDIV  */
  YYSYMBOL_43_ = 43,                       /* '!'  */
  YYSYMBOL_44_ = 44,                       /* '~'  */
  YYSYMBOL_OP_ZEXT = 45,                   /* OP_ZEXT  */
  YYSYMBOL_OP_CARRY = 46,                  /* OP_CARRY  */
  YYSYMBOL_OP_BORROW = 47,                 /* OP_BORROW  */
  YYSYMBOL_OP_SEXT = 48,                   /* OP_SEXT  */
  YYSYMBOL_OP_SCARRY = 49,                 /* OP_SCARRY  */
  YYSYMBOL_OP_SBORROW = 50,                /* OP_SBORROW  */
  YYSYMBOL_OP_NAN = 51,                    /* OP_NAN  */
  YYSYMBOL_OP_ABS = 52,                    /* OP_ABS  */
  YYSYMBOL_OP_SQRT = 53,                   /* OP_SQRT  */
  YYSYMBOL_OP_CEIL = 54,                   /* OP_CEIL  */
  YYSYMBOL_OP_FLOOR = 55,                  /* OP_FLOOR  */
  YYSYMBOL_OP_ROUND = 56,                  /* OP_ROUND  */
  YYSYMBOL_OP_INT2FLOAT = 57,              /* OP_INT2FLOAT  */
  YYSYMBOL_OP_FLOAT2FLOAT = 58,            /* OP_FLOAT2FLOAT  */
  YYSYMBOL_OP_TRUNC = 59,                  /* OP_TRUNC  */
  YYSYMBOL_OP_CPOOLREF = 60,               /* OP_CPOOLREF  */
  YYSYMBOL_OP_NEW = 61,                    /* OP_NEW  */
  YYSYMBOL_OP_POPCOUNT = 62,               /* OP_POPCOUNT  */
  YYSYMBOL_OP_LZCOUNT = 63,                /* OP_LZCOUNT  */
  YYSYMBOL_BADINTEGER = 64,                /* BADINTEGER  */
  YYSYMBOL_GOTO_KEY = 65,                  /* GOTO_KEY  */
  YYSYMBOL_CALL_KEY = 66,                  /* CALL_KEY  */
  YYSYMBOL_RETURN_KEY = 67,                /* RETURN_KEY  */
  YYSYMBOL_IF_KEY = 68,                    /* IF_KEY  */
  YYSYMBOL_DEFINE_KEY = 69,                /* DEFINE_KEY  */
  YYSYMBOL_ATTACH_KEY = 70,                /* ATTACH_KEY  */
  YYSYMBOL_MACRO_KEY = 71,                 /* MACRO_KEY  */
  YYSYMBOL_SPACE_KEY = 72,                 /* SPACE_KEY  */
  YYSYMBOL_TYPE_KEY = 73,                  /* TYPE_KEY  */
  YYSYMBOL_RAM_KEY = 74,                   /* RAM_KEY  */
  YYSYMBOL_DEFAULT_KEY = 75,               /* DEFAULT_KEY  */
  YYSYMBOL_REGISTER_KEY = 76,              /* REGISTER_KEY  */
  YYSYMBOL_ENDIAN_KEY = 77,                /* ENDIAN_KEY  */
  YYSYMBOL_WITH_KEY = 78,                  /* WITH_KEY  */
  YYSYMBOL_ALIGN_KEY = 79,                 /* ALIGN_KEY  */
  YYSYMBOL_OP_UNIMPL = 80,                 /* OP_UNIMPL  */
  YYSYMBOL_TOKEN_KEY = 81,                 /* TOKEN_KEY  */
  YYSYMBOL_SIGNED_KEY = 82,                /* SIGNED_KEY  */
  YYSYMBOL_NOFLOW_KEY = 83,                /* NOFLOW_KEY  */
  YYSYMBOL_HEX_KEY = 84,                   /* HEX_KEY  */
  YYSYMBOL_DEC_KEY = 85,                   /* DEC_KEY  */
  YYSYMBOL_OCT_KEY = 86,                   /* OCT_KEY  */
  YYSYMBOL_BIN_KEY = 87,                   /* BIN_KEY  */
  YYSYMBOL_BIG_KEY = 88,                   /* BIG_KEY  */
  YYSYMBOL_LITTLE_KEY = 89,                /* LITTLE_KEY  */
  YYSYMBOL_SIZE_KEY = 90,                  /* SIZE_KEY  */
  YYSYMBOL_WORDSIZE_KEY = 91,              /* WORDSIZE_KEY  */
  YYSYMBOL_OFFSET_KEY = 92,                /* OFFSET_KEY  */
  YYSYMBOL_NAMES_KEY = 93,                 /* NAMES_KEY  */
  YYSYMBOL_VALUES_KEY = 94,                /* VALUES_KEY  */
  YYSYMBOL_VARIABLES_KEY = 95,             /* VARIABLES_KEY  */
  YYSYMBOL_PCODEOP_KEY = 96,               /* PCODEOP_KEY  */
  YYSYMBOL_IS_KEY = 97,                    /* IS_KEY  */
  YYSYMBOL_LOCAL_KEY = 98,                 /* LOCAL_KEY  */
  YYSYMBOL_DELAYSLOT_KEY = 99,             /* DELAYSLOT_KEY  */
  YYSYMBOL_CROSSBUILD_KEY = 100,           /* CROSSBUILD_KEY  */
  YYSYMBOL_EXPORT_KEY = 101,               /* EXPORT_KEY  */
  YYSYMBOL_BUILD_KEY = 102,                /* BUILD_KEY  */
  YYSYMBOL_CONTEXT_KEY = 103,              /* CONTEXT_KEY  */
  YYSYMBOL_ELLIPSIS_KEY = 104,             /* ELLIPSIS_KEY  */
  YYSYMBOL_GLOBALSET_KEY = 105,            /* GLOBALSET_KEY  */
  YYSYMBOL_BITRANGE_KEY = 106,             /* BITRANGE_KEY  */
  YYSYMBOL_CHAR = 107,                     /* CHAR  */
  YYSYMBOL_INTEGER = 108,                  /* INTEGER  */
  YYSYMBOL_INTB = 109,                     /* INTB  */
  YYSYMBOL_STRING = 110,                   /* STRING  */
  YYSYMBOL_SYMBOLSTRING = 111,             /* SYMBOLSTRING  */
  YYSYMBOL_SPACESYM = 112,                 /* SPACESYM  */
  YYSYMBOL_SECTIONSYM = 113,               /* SECTIONSYM  */
  YYSYMBOL_TOKENSYM = 114,                 /* TOKENSYM  */
  YYSYMBOL_USEROPSYM = 115,                /* USEROPSYM  */
  YYSYMBOL_VALUESYM = 116,                 /* VALUESYM  */
  YYSYMBOL_VALUEMAPSYM = 117,              /* VALUEMAPSYM  */
  YYSYMBOL_CONTEXTSYM = 118,               /* CONTEXTSYM  */
  YYSYMBOL_NAMESYM = 119,                  /* NAMESYM  */
  YYSYMBOL_VARSYM = 120,                   /* VARSYM  */
  YYSYMBOL_BITSYM = 121,                   /* BITSYM  */
  YYSYMBOL_SPECSYM = 122,                  /* SPECSYM  */
  YYSYMBOL_VARLISTSYM = 123,               /* VARLISTSYM  */
  YYSYMBOL_OPERANDSYM = 124,               /* OPERANDSYM  */
  YYSYMBOL_STARTSYM = 125,                 /* STARTSYM  */
  YYSYMBOL_OFFSETSYM = 126,                /* OFFSETSYM  */
  YYSYMBOL_ENDSYM = 127,                   /* ENDSYM  */
  YYSYMBOL_NEXT2SYM = 128,                 /* NEXT2SYM  */
  YYSYMBOL_MACROSYM = 129,                 /* MACROSYM  */
  YYSYMBOL_LABELSYM = 130,                 /* LABELSYM  */
  YYSYMBOL_SUBTABLESYM = 131,              /* SUBTABLESYM  */
  YYSYMBOL_132_ = 132,                     /* '}'  */
  YYSYMBOL_133_ = 133,                     /* '='  */
  YYSYMBOL_134_ = 134,                     /* '('  */
  YYSYMBOL_135_ = 135,                     /* ')'  */
  YYSYMBOL_136_ = 136,                     /* ','  */
  YYSYMBOL_137_ = 137,                     /* '['  */
  YYSYMBOL_138_ = 138,                     /* ']'  */
  YYSYMBOL_139_ = 139,                     /* '{'  */
  YYSYMBOL_140_ = 140,                     /* ':'  */
  YYSYMBOL_141_ = 141,                     /* ' '  */
  YYSYMBOL_YYACCEPT = 142,                 /* $accept  */
  YYSYMBOL_spec = 143,                     /* spec  */
  YYSYMBOL_definition = 144,               /* definition  */
  YYSYMBOL_constructorlike = 145,          /* constructorlike  */
  YYSYMBOL_endiandef = 146,                /* endiandef  */
  YYSYMBOL_aligndef = 147,                 /* aligndef  */
  YYSYMBOL_tokendef = 148,                 /* tokendef  */
  YYSYMBOL_tokenprop = 149,                /* tokenprop  */
  YYSYMBOL_contextdef = 150,               /* contextdef  */
  YYSYMBOL_contextprop = 151,              /* contextprop  */
  YYSYMBOL_fielddef = 152,                 /* fielddef  */
  YYSYMBOL_contextfielddef = 153,          /* contextfielddef  */
  YYSYMBOL_spacedef = 154,                 /* spacedef  */
  YYSYMBOL_spaceprop = 155,                /* spaceprop  */
  YYSYMBOL_varnodedef = 156,               /* varnodedef  */
  YYSYMBOL_bitrangedef = 157,              /* bitrangedef  */
  YYSYMBOL_bitrangelist = 158,             /* bitrangelist  */
  YYSYMBOL_bitrangesingle = 159,           /* bitrangesingle  */
  YYSYMBOL_pcodeopdef = 160,               /* pcodeopdef  */
  YYSYMBOL_valueattach = 161,              /* valueattach  */
  YYSYMBOL_nameattach = 162,               /* nameattach  */
  YYSYMBOL_varattach = 163,                /* varattach  */
  YYSYMBOL_macrodef = 164,                 /* macrodef  */
  YYSYMBOL_withblockstart = 165,           /* withblockstart  */
  YYSYMBOL_withblockmid = 166,             /* withblockmid  */
  YYSYMBOL_withblock = 167,                /* withblock  */
  YYSYMBOL_id_or_nil = 168,                /* id_or_nil  */
  YYSYMBOL_bitpat_or_nil = 169,            /* bitpat_or_nil  */
  YYSYMBOL_macrostart = 170,               /* macrostart  */
  YYSYMBOL_rtlbody = 171,                  /* rtlbody  */
  YYSYMBOL_constructor = 172,              /* constructor  */
  YYSYMBOL_constructprint = 173,           /* constructprint  */
  YYSYMBOL_subtablestart = 174,            /* subtablestart  */
  YYSYMBOL_pexpression = 175,              /* pexpression  */
  YYSYMBOL_pequation = 176,                /* pequation  */
  YYSYMBOL_elleq = 177,                    /* elleq  */
  YYSYMBOL_ellrt = 178,                    /* ellrt  */
  YYSYMBOL_atomic = 179,                   /* atomic  */
  YYSYMBOL_constraint = 180,               /* constraint  */
  YYSYMBOL_contextblock = 181,             /* contextblock  */
  YYSYMBOL_contextlist = 182,              /* contextlist  */
  YYSYMBOL_section_def = 183,              /* section_def  */
  YYSYMBOL_rtlfirstsection = 184,          /* rtlfirstsection  */
  YYSYMBOL_rtlcontinue = 185,              /* rtlcontinue  */
  YYSYMBOL_rtl = 186,                      /* rtl  */
  YYSYMBOL_rtlmid = 187,                   /* rtlmid  */
  YYSYMBOL_statement = 188,                /* statement  */
  YYSYMBOL_expr = 189,                     /* expr  */
  YYSYMBOL_sizedstar = 190,                /* sizedstar  */
  YYSYMBOL_jumpdest = 191,                 /* jumpdest  */
  YYSYMBOL_varnode = 192,                  /* varnode  */
  YYSYMBOL_integervarnode = 193,           /* integervarnode  */
  YYSYMBOL_lhsvarnode = 194,               /* lhsvarnode  */
  YYSYMBOL_label = 195,                    /* label  */
  YYSYMBOL_exportvarnode = 196,            /* exportvarnode  */
  YYSYMBOL_familysymbol = 197,             /* familysymbol  */
  YYSYMBOL_specificsymbol = 198,           /* specificsymbol  */
  YYSYMBOL_charstring = 199,               /* charstring  */
  YYSYMBOL_intblist = 200,                 /* intblist  */
  YYSYMBOL_intbpart = 201,                 /* intbpart  */
  YYSYMBOL_stringlist = 202,               /* stringlist  */
  YYSYMBOL_stringpart = 203,               /* stringpart  */
  YYSYMBOL_anystringlist = 204,            /* anystringlist  */
  YYSYMBOL_anystringpart = 205,            /* anystringpart  */
  YYSYMBOL_valuelist = 206,                /* valuelist  */
  YYSYMBOL_valuepart = 207,                /* valuepart  */
  YYSYMBOL_varlist = 208,                  /* varlist  */
  YYSYMBOL_varpart = 209,                  /* varpart  */
  YYSYMBOL_paramlist = 210,                /* paramlist  */
  YYSYMBOL_oplist = 211,                   /* oplist  */
  YYSYMBOL_anysymbol = 212                 /* anysymbol  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2701

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  142
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  71
/* YYNRULES -- Number of rules.  */
#define YYNRULES  348
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  726

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   373


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   141,    43,     2,     2,     2,    38,    11,     2,
     134,   135,    36,    32,   136,    33,     2,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   140,     8,
      17,   133,    18,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   137,     2,   138,     9,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   139,     6,   132,    44,     2,     2,     2,
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
       5,     7,    10,    12,    13,    14,    15,    16,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    34,    35,    39,    40,    41,    42,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   160,   160,   161,   162,   163,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   176,   177,   178,   179,
     181,   182,   184,   186,   188,   189,   190,   191,   192,   194,
     196,   197,   200,   201,   202,   203,   204,   205,   206,   208,
     209,   210,   211,   212,   213,   214,   215,   217,   219,   220,
     221,   222,   223,   224,   225,   227,   229,   231,   233,   234,
     236,   239,   241,   243,   245,   247,   250,   252,   253,   254,
     256,   258,   259,   260,   263,   264,   267,   269,   270,   271,
     273,   274,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   286,   287,   288,   289,   291,   293,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     310,   311,   312,   313,   315,   316,   318,   319,   321,   322,
     324,   325,   326,   327,   328,   329,   330,   333,   334,   335,
     336,   338,   339,   341,   342,   343,   344,   345,   346,   348,
     349,   351,   353,   354,   356,   357,   358,   359,   360,   362,
     363,   364,   365,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   461,   462,   463,   464,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   476,   477,
     478,   479,   481,   482,   483,   484,   485,   487,   488,   489,
     491,   492,   494,   495,   496,   497,   498,   499,   501,   502,
     503,   504,   505,   507,   508,   509,   510,   511,   512,   513,
     515,   516,   518,   519,   520,   522,   523,   524,   526,   527,
     528,   531,   532,   534,   535,   536,   538,   540,   541,   542,
     543,   545,   546,   547,   549,   550,   551,   552,   553,   555,
     556,   558,   559,   561,   562,   565,   566,   567,   569,   570,
     571,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590
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
  "\"end of file\"", "error", "\"invalid token\"", "OP_BOOL_OR",
  "OP_BOOL_AND", "OP_BOOL_XOR", "'|'", "OP_OR", "';'", "'^'", "OP_XOR",
  "'&'", "OP_AND", "OP_EQUAL", "OP_NOTEQUAL", "OP_FEQUAL", "OP_FNOTEQUAL",
  "'<'", "'>'", "OP_GREATEQUAL", "OP_LESSEQUAL", "OP_SLESS",
  "OP_SGREATEQUAL", "OP_SLESSEQUAL", "OP_SGREAT", "OP_FLESS", "OP_FGREAT",
  "OP_FLESSEQUAL", "OP_FGREATEQUAL", "OP_LEFT", "OP_RIGHT", "OP_SRIGHT",
  "'+'", "'-'", "OP_FADD", "OP_FSUB", "'*'", "'/'", "'%'", "OP_SDIV",
  "OP_SREM", "OP_FMULT", "OP_FDIV", "'!'", "'~'", "OP_ZEXT", "OP_CARRY",
  "OP_BORROW", "OP_SEXT", "OP_SCARRY", "OP_SBORROW", "OP_NAN", "OP_ABS",
  "OP_SQRT", "OP_CEIL", "OP_FLOOR", "OP_ROUND", "OP_INT2FLOAT",
  "OP_FLOAT2FLOAT", "OP_TRUNC", "OP_CPOOLREF", "OP_NEW", "OP_POPCOUNT",
  "OP_LZCOUNT", "BADINTEGER", "GOTO_KEY", "CALL_KEY", "RETURN_KEY",
  "IF_KEY", "DEFINE_KEY", "ATTACH_KEY", "MACRO_KEY", "SPACE_KEY",
  "TYPE_KEY", "RAM_KEY", "DEFAULT_KEY", "REGISTER_KEY", "ENDIAN_KEY",
  "WITH_KEY", "ALIGN_KEY", "OP_UNIMPL", "TOKEN_KEY", "SIGNED_KEY",
  "NOFLOW_KEY", "HEX_KEY", "DEC_KEY", "OCT_KEY", "BIN_KEY", "BIG_KEY",
  "LITTLE_KEY", "SIZE_KEY", "WORDSIZE_KEY", "OFFSET_KEY", "NAMES_KEY",
  "VALUES_KEY", "VARIABLES_KEY", "PCODEOP_KEY", "IS_KEY", "LOCAL_KEY",
  "DELAYSLOT_KEY", "CROSSBUILD_KEY", "EXPORT_KEY", "BUILD_KEY",
  "CONTEXT_KEY", "ELLIPSIS_KEY", "GLOBALSET_KEY", "BITRANGE_KEY", "CHAR",
  "INTEGER", "INTB", "STRING", "SYMBOLSTRING", "SPACESYM", "SECTIONSYM",
  "TOKENSYM", "USEROPSYM", "VALUESYM", "VALUEMAPSYM", "CONTEXTSYM",
  "NAMESYM", "VARSYM", "BITSYM", "SPECSYM", "VARLISTSYM", "OPERANDSYM",
  "STARTSYM", "OFFSETSYM", "ENDSYM", "NEXT2SYM", "MACROSYM", "LABELSYM",
  "SUBTABLESYM", "'}'", "'='", "'('", "')'", "','", "'['", "']'", "'{'",
  "':'", "' '", "$accept", "spec", "definition", "constructorlike",
  "endiandef", "aligndef", "tokendef", "tokenprop", "contextdef",
  "contextprop", "fielddef", "contextfielddef", "spacedef", "spaceprop",
  "varnodedef", "bitrangedef", "bitrangelist", "bitrangesingle",
  "pcodeopdef", "valueattach", "nameattach", "varattach", "macrodef",
  "withblockstart", "withblockmid", "withblock", "id_or_nil",
  "bitpat_or_nil", "macrostart", "rtlbody", "constructor",
  "constructprint", "subtablestart", "pexpression", "pequation", "elleq",
  "ellrt", "atomic", "constraint", "contextblock", "contextlist",
  "section_def", "rtlfirstsection", "rtlcontinue", "rtl", "rtlmid",
  "statement", "expr", "sizedstar", "jumpdest", "varnode",
  "integervarnode", "lhsvarnode", "label", "exportvarnode", "familysymbol",
  "specificsymbol", "charstring", "intblist", "intbpart", "stringlist",
  "stringpart", "anystringlist", "anystringpart", "valuelist", "valuepart",
  "varlist", "varpart", "paramlist", "oplist", "anysymbol", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-327)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-277)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -53,    19,    12,  -327,   -28,  -327,     0,   215,   112,   -30,
      11,   -29,   -23,  -327,  -327,  -327,  -327,  -327,   401,  -327,
     430,  -327,   102,  -327,  -327,  -327,  -327,  -327,  -327,  -327,
    -327,    58,  -327,   -15,  -327,    -4,    23,    73,  -327,  -327,
    2530,     2,  2550,   -59,    61,    81,   189,    62,    62,    62,
     158,  -327,  -327,   170,  -327,  -327,  -327,   190,  -327,  -327,
    -327,  -327,  -327,  -327,  -327,  -327,  -327,  -327,  -327,  -327,
    -327,  -327,  -327,  -327,  -327,  -327,   451,   238,  -327,   250,
     607,   252,  -327,   267,  -327,   270,   274,   325,  -327,  -327,
    -327,  -327,  -327,   353,  -327,  -327,  -327,  -327,   230,  -327,
     353,  -327,  -327,  -327,   230,   372,   403,  -327,  -327,   309,
     284,  -327,  -327,   310,   416,  -327,   294,     3,  -327,   299,
    -327,  -327,    53,   296,   -11,   -43,   326,   353,   301,  -327,
    -327,  -327,  -327,  -327,   322,   324,  -327,  -327,  -327,  -327,
    -327,  -327,   328,   191,   332,   335,   312,  1741,  1562,  -327,
    -327,  -327,  -327,  -327,  -327,   331,  -327,   353,    18,  -327,
    -327,   357,  -327,    43,  -327,    18,  -327,  -327,   459,   351,
    -327,  2422,  -327,   359,  -327,  -327,   -19,  -327,  -327,    84,
    2570,   465,   373,  -327,    55,   475,  -327,    -1,   481,  -327,
      60,   354,   260,   396,   397,   400,   404,  -327,  -327,  -327,
    -327,  -327,   262,   -58,   148,  -327,  1651,  1750,    29,  1601,
    1621,   389,  1702,   288,   407,   399,    64,   418,  -327,   427,
    -327,  -327,  -327,  -327,  -327,  -327,   428,   -79,  -327,  1601,
    -117,  -327,   -46,  -327,   -21,  -327,  1787,    25,   353,   353,
     353,  -327,   -60,  -327,  1787,  1787,  1787,  1787,  1787,  1787,
     -60,  -327,   429,  -327,  -327,  -327,   426,  -327,   483,  -327,
    -327,  -327,  -327,  -327,  2449,  -327,  -327,  -327,   466,  -327,
    -327,   -24,  -327,  -327,  -327,   -85,  -327,  -327,   468,   437,
     477,   478,   480,   482,  -327,  -327,   545,  -327,  -327,   636,
     638,   546,   591,  -327,   563,  -327,  -327,  -327,  -327,  -327,
    1601,   694,  -327,  1601,   731,  -327,  1601,  1601,  1601,  1601,
    1601,   608,   641,   642,   650,   652,   683,   684,   689,   690,
     729,   730,   765,   766,   771,   772,   807,   812,   813,   815,
    -327,  1601,  1913,  1601,  -327,    33,    -2,   693,   632,   850,
     370,   726,   900,  -327,  1489,   981,  -327,  1014,   879,  1601,
     915,  1601,  1601,  1601,  1554,   920,   921,  1601,   923,  1787,
    1787,  -327,  1787,   283,  -327,  -327,  -327,   278,  1053,  -327,
     350,  -327,  -327,  -327,   283,   283,   283,   283,   283,   283,
    -327,   992,   962,   976,  -327,  -327,  -327,  -327,   964,  -327,
    -327,  -327,  -327,  -327,  -327,  -327,  -327,  1002,  1004,  1037,
    1038,  1702,  -327,  -327,  1013,  -327,  1040,   327,  -327,   566,
    -327,   606,  -327,  -327,  -327,  -327,  1601,  1601,  1601,  1601,
    1601,  1601,  1601,  1601,  1601,  1601,  1601,  1601,  1601,  1601,
    1601,  1601,  1601,  1601,  1601,   816,  1601,  1601,  1601,  1601,
    1601,  1601,  1601,  1601,  1601,  1601,  1601,  1601,  1601,  1601,
    1601,  1601,  1601,  1601,  1601,  1601,  1601,  1601,  1601,  1601,
    1601,  1601,  1601,  1601,  1601,  1601,  1601,  1601,  1601,  1601,
    1601,  1601,  1497,  -327,     7,  1046,  1079,  -327,  1601,  1084,
    -327,  1058,   204,  1087,  -327,  1124,  1227,  -327,  1260,  -327,
    -327,  -327,  -327,  1966,  1100,  2286,    91,  2006,   139,  1601,
    1134,  1141,  2046,  1139,  -327,  -327,    37,  1787,  1787,  1787,
    1787,  1787,  1787,  1787,  1787,  1787,  1143,  -327,  1177,  1182,
    -327,  -327,  -327,   -14,  1183,  1219,  1210,  -327,  1221,  1223,
    1256,  1257,  -327,  1258,  1259,  1392,  1425,  1430,   856,   692,
     898,   732,   774,   939,   979,  1021,  1062,  1102,  1144,  1185,
    1225,  1267,   193,   646,  1308,  1348,   199,  -327,  2325,  2362,
    2362,  2396,  2428,  2489,  2571,  2571,  2571,  2571,  2597,  2597,
    2597,  2597,  2597,  2597,  2597,  2597,  2597,  2597,  2597,  2597,
    2445,  2445,  2445,   337,   337,   337,   337,  -327,  -327,  -327,
    -327,  -327,  -327,  -327,  1433,  1304,  1342,  -327,  2086,     6,
    1473,  1507,  1512,  1702,  -327,  -327,  -327,  1601,  1515,  1601,
    -327,  1548,  2126,  -327,  -327,  -327,  1371,  -327,  1861,   470,
     247,   393,   393,   355,   355,  -327,  -327,  1840,  1787,  1787,
    1672,   212,  -327,  -327,   306,  1413,   -59,  -327,  -327,  -327,
    -327,  1454,  -327,  -327,  -327,  -327,  -327,  1601,  -327,  1601,
    1601,  -327,  -327,  -327,  -327,  -327,  -327,  -327,  -327,  -327,
    -327,  -327,  1601,  -327,  -327,  -327,  -327,  -327,  1456,  -327,
    -327,  1601,  -327,  -327,  -327,  -327,  2166,  -327,  2286,  -327,
    -327,  1459,  1462,  1464,  1662,  2464,  -327,  -327,  1571,  1572,
    -327,  -327,  1465,  1596,  -327,  1390,  1431,  1471,  1513,  1470,
    2206,  -327,  1477,  1500,  1501,  -327,  -327,  -327,  -327,  -327,
    -327,  -327,  -327,  -327,  -327,  -327,  -327,  1601,  1488,  1491,
    2246,  1619,  1620,  -327,  -327,  -327
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     0,     0,     0,     0,
      71,     0,     0,    93,     4,     5,     3,     6,     0,     7,
       0,     8,     0,     9,    10,    11,    12,    13,    14,    17,
      67,     0,    18,     0,    16,     0,     0,     0,    15,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,    72,     0,    92,    91,    23,     0,   331,   332,
     333,   334,   337,   338,   339,   340,   341,   348,   342,   343,
     344,   345,   346,   347,   335,   336,    27,     0,    29,     0,
      31,     0,    47,     0,    54,     0,     0,     0,    70,    68,
      69,   149,    86,     0,   290,    87,    90,    89,    88,    85,
       0,    82,    84,    94,    83,     0,     0,    48,    49,     0,
       0,    28,   302,     0,     0,    30,     0,     0,    58,     0,
     312,   313,     0,     0,     0,     0,   328,    74,     0,    34,
      35,    36,    37,    38,     0,     0,    41,    42,    43,    44,
      45,    46,     0,     0,     0,     0,     0,   144,     0,   278,
     279,   280,   281,   128,   282,   127,   130,     0,   131,   110,
     115,   117,   118,   129,   291,   131,    20,    21,     0,     0,
     303,     0,    61,     0,    57,    59,     0,   314,   315,     0,
       0,     0,     0,   293,     0,     0,   320,     0,     0,   329,
       0,   131,    75,     0,     0,     0,     0,    50,    51,    52,
      53,    65,     0,     0,   248,   263,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   262,   260,     0,   283,     0,
     284,   285,   286,   287,   288,   289,     0,   261,   150,     0,
       0,   259,     0,   177,   258,   114,     0,     0,     0,     0,
       0,   133,     0,   116,     0,     0,     0,     0,     0,     0,
       0,    22,     0,   304,   301,   305,     0,    56,     0,   318,
     316,   317,   311,   307,     0,   308,    63,   294,     0,   295,
     297,     0,    62,   322,   321,     0,    64,    76,     0,     0,
       0,     0,     0,     0,   260,   261,     0,   265,   258,     0,
       0,     0,     0,   253,   252,   257,   254,   249,   250,   251,
       0,     0,   256,     0,     0,   174,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     242,     0,     0,     0,   178,   258,     0,     0,     0,     0,
       0,     0,   147,   277,     0,     0,   272,     0,     0,     0,
       0,   325,     0,   325,     0,     0,     0,     0,     0,     0,
       0,    95,     0,   126,    96,    97,   119,   112,   113,   111,
       0,    79,   149,    80,   121,   122,   124,   125,   123,   120,
      81,    24,     0,     0,   309,   306,   310,   296,     0,   298,
     300,   292,   324,   323,   319,   330,    66,     0,     0,     0,
       0,     0,   271,   270,     0,   247,     0,     0,   169,     0,
     172,     0,   193,   220,   206,   194,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     325,     0,     0,     0,   325,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   179,     0,     0,     0,   151,     0,     0,
     158,     0,     0,     0,   273,     0,   148,   269,     0,   267,
     145,   165,   264,     0,     0,   326,     0,     0,     0,     0,
       0,     0,     0,     0,   108,   109,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   138,     0,     0,
     132,   142,   149,     0,     0,     0,     0,   299,     0,     0,
       0,     0,   266,   246,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   180,   209,   208,
     207,   197,   195,   196,   183,   184,   210,   211,   185,   188,
     186,   187,   189,   190,   191,   192,   212,   213,   214,   215,
     198,   199,   200,   181,   182,   216,   217,   201,   202,   204,
     203,   205,   218,   219,     0,     0,     0,   240,     0,     0,
       0,     0,     0,     0,   275,   146,   155,     0,     0,     0,
     162,     0,     0,   164,   163,   153,     0,    98,   105,   106,
     104,   102,   103,    99,   100,   101,   107,     0,     0,     0,
       0,     0,    77,   141,     0,     0,     0,    32,    33,    39,
      40,     0,   255,   171,   173,   175,   224,     0,   223,     0,
       0,   230,   221,   222,   232,   233,   234,   229,   228,   231,
     244,   235,     0,   237,   238,   243,   170,   239,     0,   154,
     152,     0,   168,   167,   166,   274,     0,   160,   327,   176,
     159,     0,     0,     0,     0,     0,    78,   143,     0,     0,
      26,    25,     0,     0,   245,     0,     0,     0,     0,     0,
       0,   157,     0,     0,     0,   134,   137,   139,   140,    60,
      55,   225,   226,   227,   236,   241,   156,     0,     0,     0,
       0,     0,     0,   161,   135,   136
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -327,  -327,  1598,  1599,  -327,  -327,  -327,  -327,  -327,  -327,
    -327,  -327,  -327,  -327,  -327,  -327,  -327,  1514,  -327,  -327,
    -327,  -327,  -327,  -327,  -327,  -327,  -327,  -327,  -327,  1382,
    -327,  -327,  -327,  -206,   -81,  -327,  1485,  -327,  -327,  -135,
    -327,  1005,  -327,  -327,  1266,  1117,  -327,  -208,  -145,  -203,
    -137,  1166,  1297,  -144,  -327,   -93,   -62,  1606,  -327,  -327,
    1007,  -327,  -327,  -327,   356,  -327,  -327,  -327,  -326,  -327,
       8
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,    14,    15,     3,    16,    17,    18,    19,    20,
      76,    80,    21,    22,    23,    24,   117,   118,    25,    26,
      27,    28,    29,    30,    31,    32,    53,   191,    33,   373,
      34,    35,    36,   363,   158,   159,   160,   161,   162,   242,
     370,   633,   521,   522,   146,   147,   228,   495,   333,   301,
     334,   231,   232,   302,   345,   364,   335,    98,   185,   271,
     114,   171,   181,   264,   123,   179,   188,   275,   496,   190,
      77
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     163,   332,   229,   233,   304,    92,   477,   163,    38,   388,
     230,   174,     5,     6,   670,   631,     1,   355,   202,   165,
     371,   354,   182,   356,   238,   392,   239,   498,    81,   240,
     250,   238,    99,   239,   163,   393,   240,   305,   374,   375,
     376,   377,   378,   379,   507,   257,   192,   508,   108,   509,
     111,   112,   289,   394,  -269,   163,   279,   244,  -269,     6,
     245,   246,   247,   248,   163,   287,   510,   511,   344,   512,
     513,   205,   290,   514,   515,   339,   237,   186,   113,   372,
      50,     7,     8,     9,   389,   234,   390,   357,   268,   258,
      10,   358,   407,    93,   187,   409,     4,   183,   411,   412,
     413,   414,   415,    94,   552,    37,    95,    96,   556,   273,
      82,    54,  -267,   116,   391,   215,  -267,    55,   632,   274,
     100,    51,    11,   435,    91,   473,   184,    87,     8,     9,
      94,   478,    39,   101,   102,   109,    10,    97,   479,   671,
     288,   493,    52,    12,   497,   163,   163,   163,   337,   502,
     288,   346,    13,   504,   505,   241,   506,   367,   368,   369,
     366,   105,   106,   269,   103,   270,   306,   474,    11,   177,
     475,   178,   617,   476,   365,    83,   249,    84,   120,   255,
     121,   115,   365,   365,   365,   365,   365,   365,   265,    12,
      88,   116,    85,    86,   259,   277,   278,   349,    13,   122,
     260,  -268,   261,   484,   350,    47,    48,    49,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   262,   553,   554,   555,   608,   609,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   532,   197,   238,   198,   239,   594,
     598,   240,   386,   202,   611,   609,   510,   511,   288,   512,
     513,   119,   489,   514,   515,   291,   239,    40,   292,   240,
     507,   612,   126,   508,    41,   509,    42,   365,   365,   340,
     365,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     127,    43,   510,   511,   601,   512,   513,   602,    44,   514,
     515,    45,   688,   128,   204,   689,   205,    46,   660,   609,
     436,   437,   438,   439,   665,   609,   440,   164,   441,   288,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     215,   134,   284,   465,   466,   467,   468,   469,   470,   471,
     166,   202,   218,   135,   220,   142,   221,   222,   223,   224,
     225,   514,   515,   285,   690,   691,   341,    40,   342,   676,
     143,   678,   286,   144,   124,   125,    42,   145,   218,    56,
     220,   167,   221,   222,   223,   224,   225,   168,   169,   343,
     170,    43,   684,   685,   172,   512,   513,   173,    44,   514,
     515,    45,   176,   180,   205,   193,   189,    46,    78,   695,
     199,   696,   697,   200,   201,   365,   365,   365,   365,   365,
     365,   365,   365,   365,   698,   516,   194,   148,   195,   252,
     517,   243,   196,   700,   236,   535,   675,   251,   518,   149,
     150,   151,   152,   266,   519,   153,   154,   155,   215,   256,
     284,   267,   509,   272,   156,   229,   233,   157,   520,   276,
     218,   241,   220,   230,   221,   222,   223,   224,   225,   510,
     511,   285,   512,   513,   280,   281,   514,   515,   282,   720,
     483,    57,   283,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,   338,    68,    69,    70,    71,    72,    73,
      74,   347,    75,   129,   682,   130,   131,   132,   133,   348,
      79,   288,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,   351,    68,    69,    70,    71,    72,    73,    74,
     352,    75,   353,   382,   381,   683,   365,   365,   234,   436,
     437,   438,   439,   383,   387,   440,   396,   441,   395,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   436,
     437,   438,   439,   397,   398,   440,   399,   441,   400,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   436,
     437,   438,   439,   401,   402,   440,   403,   441,   404,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   136,
     137,   138,   139,   140,   141,   436,   437,   438,   439,   405,
     406,   440,   408,   441,   536,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   436,   437,   438,   439,   410,
     481,   440,   416,   441,   537,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   417,   418,   436,   437,   438,
     439,   661,   662,   440,   419,   441,   420,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   421,   422,   436,
     437,   438,   439,   423,   424,   440,   480,   441,   647,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   436,
     437,   438,   439,   425,   426,   440,   485,   441,   649,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   427,
     428,   436,   437,   438,   439,   429,   430,   440,  -276,   441,
     650,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   431,   436,   437,   438,   439,   432,   433,   440,   434,
     441,   557,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   436,   437,   438,   439,   482,   492,   440,   490,
     441,   646,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   491,   494,   436,   437,   438,   439,   500,   501,
     440,   503,   441,   648,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   240,   436,   437,   438,   439,   524,
     525,   440,   527,   441,   651,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   436,   437,   438,   439,   526,
     528,   440,   529,   441,   652,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   530,   531,   436,   437,   438,
     439,   533,   534,   440,   596,   441,   653,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   597,   436,   437,
     438,   439,   599,   600,   440,   603,   441,   654,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   436,   437,
     438,   439,   604,   607,   440,  -268,   441,   655,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   605,   613,
     436,   437,   438,   439,   614,   616,   440,   627,   441,   656,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     628,   436,   437,   438,   439,   629,   634,   440,   636,   441,
     657,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   436,   437,   438,   439,   635,   637,   440,   638,   441,
     658,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   639,   640,   436,   437,   438,   439,   642,   641,   440,
     643,   441,   659,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   644,   436,   437,   438,   439,   645,   667,
     440,   666,   441,   663,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   436,   437,   438,   439,   668,   681,
     440,   672,   441,   664,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   203,   673,   436,   437,   438,   439,
     674,   692,   440,   677,   441,   711,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   679,   436,   437,   438,
     439,   293,   694,   440,   699,   441,   712,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   702,   703,   486,
     704,   707,   708,   709,   710,   294,   713,   295,   715,   218,
     717,   220,   202,   221,   222,   223,   224,   225,   718,   719,
     487,   296,   297,   721,   298,   299,   722,   724,   725,    89,
      90,   175,   380,   235,   307,   687,   308,   204,   523,   630,
     595,   488,   104,   693,   309,   310,   311,   312,   714,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   205,     0,     0,   203,   507,
     705,     0,   508,     0,   509,     0,     0,     0,   149,   150,
     151,   152,     0,   202,   153,   154,   155,   499,     0,   203,
       0,   510,   511,   156,   512,   513,   157,     0,   514,   515,
       0,   631,     0,     0,     0,     0,     0,     0,   204,   215,
       0,   284,     0,   202,     0,   293,   329,     0,     0,     0,
       0,   218,   330,   220,     0,   221,   222,   223,   224,   225,
       0,   336,   285,     0,     0,   331,   205,   206,   207,   208,
     209,   218,     0,   220,     0,   221,   222,   223,   224,   225,
       0,     0,   202,     0,     0,     0,     0,     0,   203,   294,
       0,   295,     0,     0,     0,     0,   205,   203,     0,     0,
     210,   211,   212,     0,   214,   296,   297,   204,   298,   299,
     215,     0,   216,     0,     0,     0,     0,   217,   300,     0,
       0,     0,   218,   219,   220,     0,   221,   222,   223,   224,
     225,   226,     0,   227,   686,   205,   206,   207,   208,   209,
     215,     0,   284,     0,   293,     0,     0,     0,     0,     0,
     359,     0,   218,     0,   220,     0,   221,   222,   223,   224,
     225,   360,     0,   285,     0,     0,     0,     0,     0,   210,
     211,   212,   213,   214,     0,     0,     0,     0,     0,   215,
       0,   216,     0,     0,     0,     0,   217,     0,   294,     0,
     295,   218,   219,   220,     0,   221,   222,   223,   224,   225,
     226,   508,   227,   509,   296,   297,     0,   298,   299,     0,
       0,     0,     0,     0,     0,     0,     0,   303,     0,     0,
     510,   511,     0,   512,   513,     0,   361,   514,   515,     0,
       0,     0,     0,   149,   150,   151,   152,   218,     0,   220,
     154,   221,   222,   223,   224,   225,   436,   437,   438,   439,
       0,   362,   440,     0,   441,     0,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   149,   150,   151,   152,
     218,     0,   220,   154,   221,   222,   223,   224,   225,   436,
     437,   438,   439,     0,   606,   440,     0,   441,   472,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   436,
     437,   438,   439,     0,   610,   440,     0,   441,     0,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   436,
     437,   438,   439,     0,   615,   440,     0,   441,     0,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   436,
     437,   438,   439,     0,   669,   440,     0,   441,     0,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   436,
     437,   438,   439,     0,   680,   440,     0,   441,     0,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   436,
     437,   438,   439,     0,   701,   440,     0,   441,     0,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   436,
     437,   438,   439,     0,   716,   440,     0,   441,     0,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   436,
     437,   438,   439,     0,   723,   440,     0,   441,     0,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   436,
     437,   438,   439,     0,     0,   440,     0,   441,     0,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   437,
     438,   439,     0,     0,   440,     0,   441,     0,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   439,     0,
       0,   440,     0,   441,     0,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   440,     0,   441,     0,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   441,
       0,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   507,   706,     0,   508,     0,   509,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,     0,     0,
       0,     0,     0,   510,   511,     0,   512,   513,     0,     0,
     514,   515,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   253,     0,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,    72,
      73,    74,     0,    75,     0,     0,     0,     0,     0,   384,
     254,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,    72,    73,    74,     0,
      75,     0,     0,     0,     0,     0,     0,   385,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,  -277,  -277,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     107,     0,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,    72,    73,    74,
     110,    75,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,    72,    73,    74,
     263,    75,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,    72,    73,    74,
       0,    75
};

static const yytype_int16 yycheck[] =
{
      93,   209,   147,   147,   207,     9,     8,   100,     8,    33,
     147,     8,     0,     1,     8,    29,    69,   134,    11,   100,
      80,   229,    33,   140,     6,   110,     8,   353,    20,    11,
     165,     6,     9,     8,   127,   120,    11,     8,   244,   245,
     246,   247,   248,   249,     7,    64,   127,    10,    40,    12,
      42,   110,   110,   138,   133,   148,   191,    14,   137,     1,
      17,    18,    19,    20,   157,   202,    29,    30,   213,    32,
      33,    64,   130,    36,    37,   212,   157,   120,   137,   139,
     110,    69,    70,    71,   108,   147,   110,   133,    33,   108,
      78,   137,   300,    97,   137,   303,    77,   108,   306,   307,
     308,   309,   310,   107,   430,   133,   110,   111,   434,   110,
       8,   140,   133,   110,   138,   108,   137,   140,   132,   120,
      97,   110,   110,   331,   139,   333,   137,    69,    70,    71,
     107,   133,   132,   110,   111,   133,    78,   141,   140,   133,
     202,   349,   131,   131,   352,   238,   239,   240,   210,   357,
     212,   213,   140,   359,   360,   137,   362,   238,   239,   240,
     135,    88,    89,   108,   141,   110,   137,   134,   110,   116,
     137,   118,   135,   140,   236,    73,   133,    75,   116,   171,
     118,   120,   244,   245,   246,   247,   248,   249,   180,   131,
     132,   110,    90,    91,   110,   135,   136,   133,   140,   137,
     116,   137,   118,   340,   140,    93,    94,    95,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   138,   431,   432,   433,   135,   136,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   401,    74,     6,    76,     8,   472,
     478,    11,   264,    11,   135,   136,    29,    30,   340,    32,
      33,    92,   344,    36,    37,   137,     8,    72,   140,    11,
       7,   499,   134,    10,    79,    12,    81,   359,   360,    11,
     362,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     140,    96,    29,    30,   110,    32,    33,   113,   103,    36,
      37,   106,   110,   133,    36,   113,    64,   112,   135,   136,
       3,     4,     5,     6,   135,   136,     9,   107,    11,   401,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
     108,   133,   110,    36,    37,    38,    39,    40,    41,    42,
       8,    11,   120,   133,   122,   133,   124,   125,   126,   127,
     128,    36,    37,   131,    88,    89,   108,    72,   110,   607,
     133,   609,   140,   133,    48,    49,    81,   133,   120,     8,
     122,     8,   124,   125,   126,   127,   128,   108,   134,   131,
     110,    96,   628,   629,     8,    32,    33,   133,   103,    36,
      37,   106,   133,   137,    64,   134,   110,   112,     8,   647,
     108,   649,   650,   108,   132,   507,   508,   509,   510,   511,
     512,   513,   514,   515,   662,   105,   134,   104,   134,   108,
     110,   104,   134,   671,   133,   138,   603,     8,   118,   116,
     117,   118,   119,     8,   124,   122,   123,   124,   108,   120,
     110,   108,    12,     8,   131,   630,   630,   134,   138,     8,
     120,   137,   122,   630,   124,   125,   126,   127,   128,    29,
      30,   131,    32,    33,   108,   108,    36,    37,   108,   717,
     140,   110,   108,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   134,   123,   124,   125,   126,   127,   128,
     129,   124,   131,    82,   627,    84,    85,    86,    87,   140,
     110,   603,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   134,   123,   124,   125,   126,   127,   128,   129,
     133,   131,   134,   137,   135,   627,   628,   629,   630,     3,
       4,     5,     6,    90,   108,     9,   139,    11,   110,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,     3,
       4,     5,     6,   136,   136,     9,   136,    11,   136,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,     3,
       4,     5,     6,   108,    18,     9,    18,    11,   112,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    82,
      83,    84,    85,    86,    87,     3,     4,     5,     6,   108,
     137,     9,     8,    11,   138,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,     3,     4,     5,     6,     8,
     108,     9,   134,    11,   138,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,   134,   134,     3,     4,     5,
       6,   135,   136,     9,   134,    11,   134,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,   134,   134,     3,
       4,     5,     6,   134,   134,     9,   133,    11,   136,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,     3,
       4,     5,     6,   134,   134,     9,   140,    11,   136,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,   134,
     134,     3,     4,     5,     6,   134,   134,     9,     8,    11,
     136,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   134,     3,     4,     5,     6,   134,   134,     9,   134,
      11,   135,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,     3,     4,     5,     6,   136,   108,     9,     8,
      11,   135,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,     8,   108,     3,     4,     5,     6,   108,   108,
       9,   108,    11,   135,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    11,     3,     4,     5,     6,    77,
     108,     9,   108,    11,   135,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,     3,     4,     5,     6,   133,
     108,     9,   108,    11,   135,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,   108,   108,     3,     4,     5,
       6,   138,   112,     9,   108,    11,   135,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,   108,     3,     4,
       5,     6,   108,   135,     9,   108,    11,   135,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,     3,     4,
       5,     6,   108,   133,     9,     8,    11,   135,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,     8,   135,
       3,     4,     5,     6,   133,   136,     9,   134,    11,   135,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
     133,     3,     4,     5,     6,   133,   133,     9,   108,    11,
     135,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,     3,     4,     5,     6,   136,   135,     9,   135,    11,
     135,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   135,   135,     3,     4,     5,     6,   138,   140,     9,
       8,    11,   135,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,     8,     3,     4,     5,     6,     8,   135,
       9,     8,    11,   135,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,     3,     4,     5,     6,   136,   108,
       9,     8,    11,   135,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    17,     8,     3,     4,     5,     6,
       8,   108,     9,     8,    11,   135,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,     8,     3,     4,     5,
       6,    64,   108,     9,   108,    11,   135,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,   138,   136,   110,
     136,    30,    30,   138,     8,   108,   135,   110,   138,   120,
     133,   122,    11,   124,   125,   126,   127,   128,   118,   118,
     131,   124,   125,   135,   127,   128,   135,     8,     8,    31,
      31,   117,   250,   148,    33,   630,    35,    36,   372,   522,
     474,   344,    36,   636,    43,    44,    45,    46,   135,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    -1,    -1,    17,     7,
       8,    -1,    10,    -1,    12,    -1,    -1,    -1,   116,   117,
     118,   119,    -1,    11,   122,   123,   124,   133,    -1,    17,
      -1,    29,    30,   131,    32,    33,   134,    -1,    36,    37,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    36,   108,
      -1,   110,    -1,    11,    -1,    64,   115,    -1,    -1,    -1,
      -1,   120,   121,   122,    -1,   124,   125,   126,   127,   128,
      -1,   110,   131,    -1,    -1,   134,    64,    65,    66,    67,
      68,   120,    -1,   122,    -1,   124,   125,   126,   127,   128,
      -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,   108,
      -1,   110,    -1,    -1,    -1,    -1,    64,    17,    -1,    -1,
      98,    99,   100,    -1,   102,   124,   125,    36,   127,   128,
     108,    -1,   110,    -1,    -1,    -1,    -1,   115,   137,    -1,
      -1,    -1,   120,   121,   122,    -1,   124,   125,   126,   127,
     128,   129,    -1,   131,   132,    64,    65,    66,    67,    68,
     108,    -1,   110,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      33,    -1,   120,    -1,   122,    -1,   124,   125,   126,   127,
     128,    44,    -1,   131,    -1,    -1,    -1,    -1,    -1,    98,
      99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,   108,
      -1,   110,    -1,    -1,    -1,    -1,   115,    -1,   108,    -1,
     110,   120,   121,   122,    -1,   124,   125,   126,   127,   128,
     129,    10,   131,    12,   124,   125,    -1,   127,   128,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,    -1,
      29,    30,    -1,    32,    33,    -1,   109,    36,    37,    -1,
      -1,    -1,    -1,   116,   117,   118,   119,   120,    -1,   122,
     123,   124,   125,   126,   127,   128,     3,     4,     5,     6,
      -1,   134,     9,    -1,    11,    -1,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,   116,   117,   118,   119,
     120,    -1,   122,   123,   124,   125,   126,   127,   128,     3,
       4,     5,     6,    -1,     8,     9,    -1,    11,    65,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,     3,
       4,     5,     6,    -1,     8,     9,    -1,    11,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,     3,
       4,     5,     6,    -1,     8,     9,    -1,    11,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,     3,
       4,     5,     6,    -1,     8,     9,    -1,    11,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,     3,
       4,     5,     6,    -1,     8,     9,    -1,    11,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,     3,
       4,     5,     6,    -1,     8,     9,    -1,    11,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,     3,
       4,     5,     6,    -1,     8,     9,    -1,    11,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,     3,
       4,     5,     6,    -1,     8,     9,    -1,    11,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,     3,
       4,     5,     6,    -1,    -1,     9,    -1,    11,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,     4,
       5,     6,    -1,    -1,     9,    -1,    11,    -1,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,     6,    -1,
      -1,     9,    -1,    11,    -1,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,     9,    -1,    11,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    11,
      -1,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,     7,     8,    -1,    10,    -1,    12,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,    29,    30,    -1,    32,    33,    -1,    -1,
      36,    37,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,   110,    -1,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,    -1,   123,   124,   125,   126,   127,
     128,   129,    -1,   131,    -1,    -1,    -1,    -1,    -1,   110,
     138,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,    -1,   123,   124,   125,   126,   127,   128,   129,    -1,
     131,    -1,    -1,    -1,    -1,    -1,    -1,   138,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
     110,    -1,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,    -1,   123,   124,   125,   126,   127,   128,   129,
     110,   131,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,    -1,   123,   124,   125,   126,   127,   128,   129,
     110,   131,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,    -1,   123,   124,   125,   126,   127,   128,   129,
      -1,   131
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    69,   143,   146,    77,     0,     1,    69,    70,    71,
      78,   110,   131,   140,   144,   145,   147,   148,   149,   150,
     151,   154,   155,   156,   157,   160,   161,   162,   163,   164,
     165,   166,   167,   170,   172,   173,   174,   133,     8,   132,
      72,    79,    81,    96,   103,   106,   112,    93,    94,    95,
     110,   110,   131,   168,   140,   140,     8,   110,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   123,   124,
     125,   126,   127,   128,   129,   131,   152,   212,     8,   110,
     153,   212,     8,    73,    75,    90,    91,    69,   132,   144,
     145,   139,     9,    97,   107,   110,   111,   141,   199,     9,
      97,   110,   111,   141,   199,    88,    89,   110,   212,   133,
     110,   212,   110,   137,   202,   120,   110,   158,   159,    92,
     116,   118,   137,   206,   206,   206,   134,   140,   133,    82,
      84,    85,    86,    87,   133,   133,    82,    83,    84,    85,
      86,    87,   133,   133,   133,   133,   186,   187,   104,   116,
     117,   118,   119,   122,   123,   124,   131,   134,   176,   177,
     178,   179,   180,   197,   107,   176,     8,     8,   108,   134,
     110,   203,     8,   133,     8,   159,   133,   116,   118,   207,
     137,   204,    33,   108,   137,   200,   120,   137,   208,   110,
     211,   169,   176,   134,   134,   134,   134,    74,    76,   108,
     108,   132,    11,    17,    36,    64,    65,    66,    67,    68,
      98,    99,   100,   101,   102,   108,   110,   115,   120,   121,
     122,   124,   125,   126,   127,   128,   129,   131,   188,   190,
     192,   193,   194,   195,   198,   178,   133,   176,     6,     8,
      11,   137,   181,   104,    14,    17,    18,    19,    20,   133,
     181,     8,   108,   110,   138,   212,   120,    64,   108,   110,
     116,   118,   138,   110,   205,   212,     8,   108,    33,   108,
     110,   201,     8,   110,   120,   209,     8,   135,   136,   181,
     108,   108,   108,   108,   110,   131,   140,   192,   198,   110,
     130,   137,   140,    64,   108,   110,   124,   125,   127,   128,
     137,   191,   195,   137,   191,     8,   137,    33,    35,    43,
      44,    45,    46,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,   115,
     121,   134,   189,   190,   192,   198,   110,   198,   134,   192,
      11,   108,   110,   131,   190,   196,   198,   124,   140,   133,
     140,   134,   133,   134,   189,   134,   140,   133,   137,    33,
      44,   109,   134,   175,   197,   198,   135,   176,   176,   176,
     182,    80,   139,   171,   175,   175,   175,   175,   175,   175,
     171,   135,   137,    90,   110,   138,   212,   108,    33,   108,
     110,   138,   110,   120,   138,   110,   139,   136,   136,   136,
     136,   108,    18,    18,   112,   108,   137,   189,     8,   189,
       8,   189,   189,   189,   189,   189,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   189,     3,     4,     5,     6,
       9,    11,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    65,   189,   134,   137,   140,     8,   133,   140,
     133,   108,   136,   140,   192,   140,   110,   131,   194,   198,
       8,     8,   108,   189,   108,   189,   210,   189,   210,   133,
     108,   108,   189,   108,   175,   175,   175,     7,    10,    12,
      29,    30,    32,    33,    36,    37,   105,   110,   118,   124,
     138,   184,   185,   186,    77,   108,   133,   108,   108,   108,
     108,   108,   192,   138,   112,   138,   138,   138,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   210,   189,   189,   189,   210,   135,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   191,   193,   108,   108,   189,   108,
     135,   110,   113,   108,   108,     8,     8,   133,   135,   136,
       8,   135,   189,   135,   133,     8,   136,   135,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   134,   133,   133,
     187,    29,   132,   183,   133,   136,   108,   135,   135,   135,
     135,   140,   138,     8,     8,     8,   135,   136,   135,   136,
     136,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   136,   135,   135,   135,     8,   135,   136,     8,
       8,   133,     8,     8,     8,   192,   189,     8,   189,     8,
       8,   108,   197,   198,   175,   175,   132,   183,   110,   113,
      88,    89,   108,   202,   108,   189,   189,   189,   189,   108,
     189,     8,   138,   136,   136,     8,     8,    30,    30,   138,
       8,   135,   135,   135,   135,   138,     8,   133,   118,   118,
     189,   135,   135,     8,     8,     8
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   142,   143,   143,   143,   143,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   145,   145,   145,   145,
     146,   146,   147,   148,   149,   149,   149,   149,   149,   150,
     151,   151,   152,   152,   152,   152,   152,   152,   152,   153,
     153,   153,   153,   153,   153,   153,   153,   154,   155,   155,
     155,   155,   155,   155,   155,   156,   156,   157,   158,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   166,   166,
     167,   168,   168,   168,   169,   169,   170,   171,   171,   171,
     172,   172,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   174,   174,   174,   174,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     176,   176,   176,   176,   177,   177,   178,   178,   179,   179,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   181,   181,   182,   182,   182,   182,   182,   182,   183,
     183,   184,   185,   185,   186,   186,   186,   186,   186,   187,
     187,   187,   187,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   190,   190,   190,   190,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   192,   192,
     192,   192,   193,   193,   193,   193,   193,   194,   194,   194,
     195,   195,   196,   196,   196,   196,   196,   196,   197,   197,
     197,   197,   197,   198,   198,   198,   198,   198,   198,   198,
     199,   199,   200,   200,   200,   201,   201,   201,   201,   201,
     201,   202,   202,   203,   203,   203,   204,   205,   205,   205,
     205,   206,   206,   206,   207,   207,   207,   207,   207,   208,
     208,   209,   209,   209,   209,   210,   210,   210,   211,   211,
     211,   212,   212,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   212,   212,   212
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     2,
       5,     5,     5,     2,     6,     9,     9,     2,     3,     2,
       3,     2,     7,     7,     2,     2,     2,     2,     2,     7,
       7,     2,     2,     2,     2,     2,     2,     2,     3,     3,
       4,     4,     4,     4,     2,    10,     5,     4,     1,     2,
       8,     4,     5,     5,     5,     4,     6,     1,     2,     2,
       2,     0,     1,     1,     0,     1,     5,     3,     4,     1,
       5,     5,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     2,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       1,     3,     3,     3,     2,     1,     2,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     0,     3,     0,     5,     8,     8,     5,     2,     3,
       3,     2,     1,     3,     1,     4,     5,     3,     4,     0,
       2,     4,     6,     4,     5,     4,     7,     6,     3,     5,
       5,     9,     4,     4,     4,     3,     5,     5,     5,     3,
       5,     5,     3,     5,     2,     5,     5,     1,     1,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     4,     4,     4,     4,     6,     6,     6,     4,     4,
       4,     4,     4,     4,     4,     4,     6,     4,     4,     4,
       3,     6,     1,     4,     4,     6,     4,     3,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     4,     1,     1,     1,
       3,     3,     1,     2,     4,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     1,     2,     1,     2,     1,     2,     3,
       2,     3,     1,     1,     2,     2,     3,     1,     1,     2,
       2,     3,     1,     1,     1,     1,     2,     2,     2,     3,
       1,     1,     1,     2,     2,     0,     1,     3,     0,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
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
  case 19: /* constructorlike: error '}'  */
                                       { slgh->resetConstructors(); }
    break;

  case 20: /* endiandef: DEFINE_KEY ENDIAN_KEY '=' BIG_KEY ';'  */
                                                 { slgh->setEndian(1); }
    break;

  case 21: /* endiandef: DEFINE_KEY ENDIAN_KEY '=' LITTLE_KEY ';'  */
                                             { slgh->setEndian(0); }
    break;

  case 22: /* aligndef: DEFINE_KEY ALIGN_KEY '=' INTEGER ';'  */
                                               { slgh->setAlignment(*(yyvsp[-1].i)); delete (yyvsp[-1].i); }
    break;

  case 23: /* tokendef: tokenprop ';'  */
                                       {}
    break;

  case 24: /* tokenprop: DEFINE_KEY TOKEN_KEY STRING '(' INTEGER ')'  */
                                                       { (yyval.tokensym) = slgh->defineToken((yyvsp[-3].str),(yyvsp[-1].i),0); }
    break;

  case 25: /* tokenprop: DEFINE_KEY TOKEN_KEY STRING '(' INTEGER ')' ENDIAN_KEY '=' LITTLE_KEY  */
                                                                          { (yyval.tokensym) = slgh->defineToken((yyvsp[-6].str),(yyvsp[-4].i),-1); }
    break;

  case 26: /* tokenprop: DEFINE_KEY TOKEN_KEY STRING '(' INTEGER ')' ENDIAN_KEY '=' BIG_KEY  */
                                                                       { (yyval.tokensym) = slgh->defineToken((yyvsp[-6].str),(yyvsp[-4].i),1); }
    break;

  case 27: /* tokenprop: tokenprop fielddef  */
                                       { (yyval.tokensym) = (yyvsp[-1].tokensym); slgh->addTokenField((yyvsp[-1].tokensym),(yyvsp[0].fieldqual)); }
    break;

  case 28: /* tokenprop: DEFINE_KEY TOKEN_KEY anysymbol  */
                                       { string errmsg=(yyvsp[0].anysym)->getName()+": redefined as a token"; yyerror(errmsg.c_str()); YYERROR; }
    break;

  case 29: /* contextdef: contextprop ';'  */
                                       {}
    break;

  case 30: /* contextprop: DEFINE_KEY CONTEXT_KEY VARSYM  */
                                           { (yyval.varsym) = (yyvsp[0].varsym); }
    break;

  case 31: /* contextprop: contextprop contextfielddef  */
                                         { (yyval.varsym) = (yyvsp[-1].varsym); if (!slgh->addContextField( (yyvsp[-1].varsym), (yyvsp[0].fieldqual) ))
                                            { yyerror("All context definitions must come before constructors"); YYERROR; } }
    break;

  case 32: /* fielddef: STRING '=' '(' INTEGER ',' INTEGER ')'  */
                                                 { (yyval.fieldqual) = new FieldQuality((yyvsp[-6].str),(yyvsp[-3].i),(yyvsp[-1].i)); }
    break;

  case 33: /* fielddef: anysymbol '=' '(' INTEGER ',' INTEGER ')'  */
                                              { delete (yyvsp[-3].i); delete (yyvsp[-1].i); string errmsg = (yyvsp[-6].anysym)->getName()+": redefined as field"; yyerror(errmsg.c_str()); YYERROR; }
    break;

  case 34: /* fielddef: fielddef SIGNED_KEY  */
                                        { (yyval.fieldqual) = (yyvsp[-1].fieldqual); (yyval.fieldqual)->signext = true; }
    break;

  case 35: /* fielddef: fielddef HEX_KEY  */
                                        { (yyval.fieldqual) = (yyvsp[-1].fieldqual); (yyval.fieldqual)->base = 16; }
    break;

  case 36: /* fielddef: fielddef DEC_KEY  */
                                        { (yyval.fieldqual) = (yyvsp[-1].fieldqual); (yyval.fieldqual)->base = 10; }
    break;

  case 37: /* fielddef: fielddef OCT_KEY  */
                                        { (yyval.fieldqual) = (yyvsp[-1].fieldqual); (yyval.fieldqual)->base = 8; }
    break;

  case 38: /* fielddef: fielddef BIN_KEY  */
                                        { (yyval.fieldqual) = (yyvsp[-1].fieldqual); (yyval.fieldqual)->base = 2; }
    break;

  case 39: /* contextfielddef: STRING '=' '(' INTEGER ',' INTEGER ')'  */
                                                        { (yyval.fieldqual) = new FieldQuality((yyvsp[-6].str),(yyvsp[-3].i),(yyvsp[-1].i)); }
    break;

  case 40: /* contextfielddef: anysymbol '=' '(' INTEGER ',' INTEGER ')'  */
                                              { delete (yyvsp[-3].i); delete (yyvsp[-1].i); string errmsg = (yyvsp[-6].anysym)->getName()+": redefined as field"; yyerror(errmsg.c_str()); YYERROR; }
    break;

  case 41: /* contextfielddef: contextfielddef SIGNED_KEY  */
                                                { (yyval.fieldqual) = (yyvsp[-1].fieldqual); (yyval.fieldqual)->signext = true; }
    break;

  case 42: /* contextfielddef: contextfielddef NOFLOW_KEY  */
                                                { (yyval.fieldqual) = (yyvsp[-1].fieldqual); (yyval.fieldqual)->flow = false; }
    break;

  case 43: /* contextfielddef: contextfielddef HEX_KEY  */
                                                { (yyval.fieldqual) = (yyvsp[-1].fieldqual); (yyval.fieldqual)->base = 16; }
    break;

  case 44: /* contextfielddef: contextfielddef DEC_KEY  */
                                                { (yyval.fieldqual) = (yyvsp[-1].fieldqual); (yyval.fieldqual)->base = 10; }
    break;

  case 45: /* contextfielddef: contextfielddef OCT_KEY  */
                                                { (yyval.fieldqual) = (yyvsp[-1].fieldqual); (yyval.fieldqual)->base = 8; }
    break;

  case 46: /* contextfielddef: contextfielddef BIN_KEY  */
                                                { (yyval.fieldqual) = (yyvsp[-1].fieldqual); (yyval.fieldqual)->base = 2; }
    break;

  case 47: /* spacedef: spaceprop ';'  */
                                        { slgh->newSpace((yyvsp[-1].spacequal)); }
    break;

  case 48: /* spaceprop: DEFINE_KEY SPACE_KEY STRING  */
                                        { (yyval.spacequal) = new SpaceQuality(*(yyvsp[0].str)); delete (yyvsp[0].str); }
    break;

  case 49: /* spaceprop: DEFINE_KEY SPACE_KEY anysymbol  */
                                        { string errmsg = (yyvsp[0].anysym)->getName()+": redefined as space"; yyerror(errmsg.c_str()); YYERROR; }
    break;

  case 50: /* spaceprop: spaceprop TYPE_KEY '=' RAM_KEY  */
                                        { (yyval.spacequal) = (yyvsp[-3].spacequal); (yyval.spacequal)->type = SpaceQuality::ramtype; }
    break;

  case 51: /* spaceprop: spaceprop TYPE_KEY '=' REGISTER_KEY  */
                                        { (yyval.spacequal) = (yyvsp[-3].spacequal); (yyval.spacequal)->type = SpaceQuality::registertype; }
    break;

  case 52: /* spaceprop: spaceprop SIZE_KEY '=' INTEGER  */
                                        { (yyval.spacequal) = (yyvsp[-3].spacequal); (yyval.spacequal)->size = *(yyvsp[0].i); delete (yyvsp[0].i); }
    break;

  case 53: /* spaceprop: spaceprop WORDSIZE_KEY '=' INTEGER  */
                                        { (yyval.spacequal) = (yyvsp[-3].spacequal); (yyval.spacequal)->wordsize = *(yyvsp[0].i); delete (yyvsp[0].i); }
    break;

  case 54: /* spaceprop: spaceprop DEFAULT_KEY  */
                                        { (yyval.spacequal) = (yyvsp[-1].spacequal); (yyval.spacequal)->isdefault = true; }
    break;

  case 55: /* varnodedef: DEFINE_KEY SPACESYM OFFSET_KEY '=' INTEGER SIZE_KEY '=' INTEGER stringlist ';'  */
                                                                                           {
               slgh->defineVarnodes((yyvsp[-8].spacesym),(yyvsp[-5].i),(yyvsp[-2].i),(yyvsp[-1].strlist)); }
    break;

  case 56: /* varnodedef: DEFINE_KEY SPACESYM OFFSET_KEY '=' BADINTEGER  */
                                                  { yyerror("Parsed integer is too big (overflow)"); YYERROR; }
    break;

  case 60: /* bitrangesingle: STRING '=' VARSYM '[' INTEGER ',' INTEGER ']'  */
                                                              {
               slgh->defineBitrange((yyvsp[-7].str),(yyvsp[-5].varsym),(uint4)*(yyvsp[-3].i),(uint4)*(yyvsp[-1].i)); delete (yyvsp[-3].i); delete (yyvsp[-1].i); }
    break;

  case 61: /* pcodeopdef: DEFINE_KEY PCODEOP_KEY stringlist ';'  */
                                                  { slgh->addUserOp((yyvsp[-1].strlist)); }
    break;

  case 62: /* valueattach: ATTACH_KEY VALUES_KEY valuelist intblist ';'  */
                                                          { slgh->attachValues((yyvsp[-2].symlist),(yyvsp[-1].biglist)); }
    break;

  case 63: /* nameattach: ATTACH_KEY NAMES_KEY valuelist anystringlist ';'  */
                                                             { slgh->attachNames((yyvsp[-2].symlist),(yyvsp[-1].strlist)); }
    break;

  case 64: /* varattach: ATTACH_KEY VARIABLES_KEY valuelist varlist ';'  */
                                                          { slgh->attachVarnodes((yyvsp[-2].symlist),(yyvsp[-1].symlist)); }
    break;

  case 65: /* macrodef: macrostart '{' rtl '}'  */
                                        { slgh->buildMacro((yyvsp[-3].macrosym),(yyvsp[-1].sem)); }
    break;

  case 66: /* withblockstart: WITH_KEY id_or_nil ':' bitpat_or_nil contextblock '{'  */
                                                                       {  slgh->pushWith((yyvsp[-4].subtablesym),(yyvsp[-2].pateq),(yyvsp[-1].contop)); }
    break;

  case 70: /* withblock: withblockmid '}'  */
                             { slgh->popWith(); }
    break;

  case 71: /* id_or_nil: %empty  */
                        { (yyval.subtablesym) = (SubtableSymbol *)0; }
    break;

  case 72: /* id_or_nil: SUBTABLESYM  */
                        { (yyval.subtablesym) = (yyvsp[0].subtablesym); }
    break;

  case 73: /* id_or_nil: STRING  */
                        { (yyval.subtablesym) = slgh->newTable((yyvsp[0].str)); }
    break;

  case 74: /* bitpat_or_nil: %empty  */
                           { (yyval.pateq) = (PatternEquation *)0; }
    break;

  case 75: /* bitpat_or_nil: pequation  */
                           { (yyval.pateq) = (yyvsp[0].pateq); }
    break;

  case 76: /* macrostart: MACRO_KEY STRING '(' oplist ')'  */
                                            { (yyval.macrosym) = slgh->createMacro((yyvsp[-3].str),(yyvsp[-1].strlist)); }
    break;

  case 77: /* rtlbody: '{' rtl '}'  */
                     { (yyval.sectionstart) = slgh->standaloneSection((yyvsp[-1].sem)); }
    break;

  case 78: /* rtlbody: '{' rtlcontinue rtlmid '}'  */
                               { (yyval.sectionstart) = slgh->finalNamedSection((yyvsp[-2].sectionstart),(yyvsp[-1].sem)); }
    break;

  case 79: /* rtlbody: OP_UNIMPL  */
                     { (yyval.sectionstart) = (SectionVector *)0; }
    break;

  case 80: /* constructor: constructprint IS_KEY pequation contextblock rtlbody  */
                                                                  { slgh->buildConstructor((yyvsp[-4].construct),(yyvsp[-2].pateq),(yyvsp[-1].contop),(yyvsp[0].sectionstart)); }
    break;

  case 81: /* constructor: subtablestart IS_KEY pequation contextblock rtlbody  */
                                                                  { slgh->buildConstructor((yyvsp[-4].construct),(yyvsp[-2].pateq),(yyvsp[-1].contop),(yyvsp[0].sectionstart)); }
    break;

  case 82: /* constructprint: subtablestart STRING  */
                                        { (yyval.construct) = (yyvsp[-1].construct); (yyval.construct)->addSyntax(*(yyvsp[0].str)); delete (yyvsp[0].str); }
    break;

  case 83: /* constructprint: subtablestart charstring  */
                                        { (yyval.construct) = (yyvsp[-1].construct); (yyval.construct)->addSyntax(*(yyvsp[0].str)); delete (yyvsp[0].str); }
    break;

  case 84: /* constructprint: subtablestart SYMBOLSTRING  */
                                        { (yyval.construct) = (yyvsp[-1].construct); if (slgh->isInRoot((yyvsp[-1].construct))) { (yyval.construct)->addSyntax(*(yyvsp[0].str)); delete (yyvsp[0].str); } else slgh->newOperand((yyvsp[-1].construct),(yyvsp[0].str)); }
    break;

  case 85: /* constructprint: subtablestart '^'  */
                                                { (yyval.construct) = (yyvsp[-1].construct); if (!slgh->isInRoot((yyvsp[-1].construct))) { yyerror("Unexpected '^' at start of print pieces");  YYERROR; } }
    break;

  case 86: /* constructprint: constructprint '^'  */
                                                { (yyval.construct) = (yyvsp[-1].construct); }
    break;

  case 87: /* constructprint: constructprint STRING  */
                                                { (yyval.construct) = (yyvsp[-1].construct); (yyval.construct)->addSyntax(*(yyvsp[0].str)); delete (yyvsp[0].str); }
    break;

  case 88: /* constructprint: constructprint charstring  */
                                        { (yyval.construct) = (yyvsp[-1].construct); (yyval.construct)->addSyntax(*(yyvsp[0].str)); delete (yyvsp[0].str); }
    break;

  case 89: /* constructprint: constructprint ' '  */
                                                { (yyval.construct) = (yyvsp[-1].construct); (yyval.construct)->addSyntax(string(" ")); }
    break;

  case 90: /* constructprint: constructprint SYMBOLSTRING  */
                                        { (yyval.construct) = (yyvsp[-1].construct); slgh->newOperand((yyvsp[-1].construct),(yyvsp[0].str)); }
    break;

  case 91: /* subtablestart: SUBTABLESYM ':'  */
                                { (yyval.construct) = slgh->createConstructor((yyvsp[-1].subtablesym)); }
    break;

  case 92: /* subtablestart: STRING ':'  */
                                                { SubtableSymbol *sym=slgh->newTable((yyvsp[-1].str)); (yyval.construct) = slgh->createConstructor(sym); }
    break;

  case 93: /* subtablestart: ':'  */
                                                        { (yyval.construct) = slgh->createConstructor((SubtableSymbol *)0); }
    break;

  case 94: /* subtablestart: subtablestart ' '  */
                                        { (yyval.construct) = (yyvsp[-1].construct); }
    break;

  case 95: /* pexpression: INTB  */
                                        { (yyval.patexp) = new ConstantValue(*(yyvsp[0].big)); delete (yyvsp[0].big); }
    break;

  case 96: /* pexpression: familysymbol  */
                                        { if ((actionon==1)&&((yyvsp[0].famsym)->getType() != SleighSymbol::context_symbol))
                                             { string errmsg="Global symbol "+(yyvsp[0].famsym)->getName(); errmsg += " is not allowed in action expression"; yyerror(errmsg.c_str()); } (yyval.patexp) = (yyvsp[0].famsym)->getPatternValue(); }
    break;

  case 97: /* pexpression: specificsymbol  */
                                        { (yyval.patexp) = (yyvsp[0].specsym)->getPatternExpression(); }
    break;

  case 98: /* pexpression: '(' pexpression ')'  */
                                        { (yyval.patexp) = (yyvsp[-1].patexp); }
    break;

  case 99: /* pexpression: pexpression '+' pexpression  */
                                        { (yyval.patexp) = new PlusExpression((yyvsp[-2].patexp),(yyvsp[0].patexp)); }
    break;

  case 100: /* pexpression: pexpression '-' pexpression  */
                                        { (yyval.patexp) = new SubExpression((yyvsp[-2].patexp),(yyvsp[0].patexp)); }
    break;

  case 101: /* pexpression: pexpression '*' pexpression  */
                                        { (yyval.patexp) = new MultExpression((yyvsp[-2].patexp),(yyvsp[0].patexp)); }
    break;

  case 102: /* pexpression: pexpression OP_LEFT pexpression  */
                                        { (yyval.patexp) = new LeftShiftExpression((yyvsp[-2].patexp),(yyvsp[0].patexp)); }
    break;

  case 103: /* pexpression: pexpression OP_RIGHT pexpression  */
                                        { (yyval.patexp) = new RightShiftExpression((yyvsp[-2].patexp),(yyvsp[0].patexp)); }
    break;

  case 104: /* pexpression: pexpression OP_AND pexpression  */
                                        { (yyval.patexp) = new AndExpression((yyvsp[-2].patexp),(yyvsp[0].patexp)); }
    break;

  case 105: /* pexpression: pexpression OP_OR pexpression  */
                                        { (yyval.patexp) = new OrExpression((yyvsp[-2].patexp),(yyvsp[0].patexp)); }
    break;

  case 106: /* pexpression: pexpression OP_XOR pexpression  */
                                        { (yyval.patexp) = new XorExpression((yyvsp[-2].patexp),(yyvsp[0].patexp)); }
    break;

  case 107: /* pexpression: pexpression '/' pexpression  */
                                        { (yyval.patexp) = new DivExpression((yyvsp[-2].patexp),(yyvsp[0].patexp)); }
    break;

  case 108: /* pexpression: '-' pexpression  */
                                        { (yyval.patexp) = new MinusExpression((yyvsp[0].patexp)); }
    break;

  case 109: /* pexpression: '~' pexpression  */
                                        { (yyval.patexp) = new NotExpression((yyvsp[0].patexp)); }
    break;

  case 111: /* pequation: pequation '&' pequation  */
                                        { (yyval.pateq) = new EquationAnd((yyvsp[-2].pateq),(yyvsp[0].pateq)); }
    break;

  case 112: /* pequation: pequation '|' pequation  */
                                        { (yyval.pateq) = new EquationOr((yyvsp[-2].pateq),(yyvsp[0].pateq)); }
    break;

  case 113: /* pequation: pequation ';' pequation  */
                                        { (yyval.pateq) = new EquationCat((yyvsp[-2].pateq),(yyvsp[0].pateq)); }
    break;

  case 114: /* elleq: ELLIPSIS_KEY ellrt  */
                                        { (yyval.pateq) = new EquationLeftEllipsis((yyvsp[0].pateq)); }
    break;

  case 116: /* ellrt: atomic ELLIPSIS_KEY  */
                                        { (yyval.pateq) = new EquationRightEllipsis((yyvsp[-1].pateq)); }
    break;

  case 119: /* atomic: '(' pequation ')'  */
                                        { (yyval.pateq) = (yyvsp[-1].pateq); }
    break;

  case 120: /* constraint: familysymbol '=' pexpression  */
                                         { (yyval.pateq) = new EqualEquation((yyvsp[-2].famsym)->getPatternValue(),(yyvsp[0].patexp)); }
    break;

  case 121: /* constraint: familysymbol OP_NOTEQUAL pexpression  */
                                         { (yyval.pateq) = new NotEqualEquation((yyvsp[-2].famsym)->getPatternValue(),(yyvsp[0].patexp)); }
    break;

  case 122: /* constraint: familysymbol '<' pexpression  */
                                        { (yyval.pateq) = new LessEquation((yyvsp[-2].famsym)->getPatternValue(),(yyvsp[0].patexp)); }
    break;

  case 123: /* constraint: familysymbol OP_LESSEQUAL pexpression  */
                                          { (yyval.pateq) = new LessEqualEquation((yyvsp[-2].famsym)->getPatternValue(),(yyvsp[0].patexp)); }
    break;

  case 124: /* constraint: familysymbol '>' pexpression  */
                                        { (yyval.pateq) = new GreaterEquation((yyvsp[-2].famsym)->getPatternValue(),(yyvsp[0].patexp)); }
    break;

  case 125: /* constraint: familysymbol OP_GREATEQUAL pexpression  */
                                           { (yyval.pateq) = new GreaterEqualEquation((yyvsp[-2].famsym)->getPatternValue(),(yyvsp[0].patexp)); }
    break;

  case 126: /* constraint: OPERANDSYM '=' pexpression  */
                                        { (yyval.pateq) = slgh->constrainOperand((yyvsp[-2].operandsym),(yyvsp[0].patexp));
                                          if ((yyval.pateq) == (PatternEquation *)0)
                                            { string errmsg="Constraining currently undefined operand "+(yyvsp[-2].operandsym)->getName(); yyerror(errmsg.c_str()); } }
    break;

  case 127: /* constraint: OPERANDSYM  */
                                        { (yyval.pateq) = new OperandEquation((yyvsp[0].operandsym)->getIndex()); slgh->selfDefine((yyvsp[0].operandsym)); }
    break;

  case 128: /* constraint: SPECSYM  */
                                        { (yyval.pateq) = new UnconstrainedEquation((yyvsp[0].specsym)->getPatternExpression()); }
    break;

  case 129: /* constraint: familysymbol  */
                                        { (yyval.pateq) = slgh->defineInvisibleOperand((yyvsp[0].famsym)); }
    break;

  case 130: /* constraint: SUBTABLESYM  */
                                        { (yyval.pateq) = slgh->defineInvisibleOperand((yyvsp[0].subtablesym)); }
    break;

  case 131: /* contextblock: %empty  */
                                        { (yyval.contop) = (vector<ContextChange *> *)0; }
    break;

  case 132: /* contextblock: '[' contextlist ']'  */
                                        { (yyval.contop) = (yyvsp[-1].contop); }
    break;

  case 133: /* contextlist: %empty  */
                                        { (yyval.contop) = new vector<ContextChange *>; }
    break;

  case 134: /* contextlist: contextlist CONTEXTSYM '=' pexpression ';'  */
                                                { (yyval.contop) = (yyvsp[-4].contop); if (!slgh->contextMod((yyvsp[-4].contop),(yyvsp[-3].contextsym),(yyvsp[-1].patexp))) { string errmsg="Cannot use 'inst_next' or 'inst_next2' to set context variable: "+(yyvsp[-3].contextsym)->getName(); yyerror(errmsg.c_str()); YYERROR; } }
    break;

  case 135: /* contextlist: contextlist GLOBALSET_KEY '(' familysymbol ',' CONTEXTSYM ')' ';'  */
                                                                      { (yyval.contop) = (yyvsp[-7].contop); slgh->contextSet((yyvsp[-7].contop),(yyvsp[-4].famsym),(yyvsp[-2].contextsym)); }
    break;

  case 136: /* contextlist: contextlist GLOBALSET_KEY '(' specificsymbol ',' CONTEXTSYM ')' ';'  */
                                                                        { (yyval.contop) = (yyvsp[-7].contop); slgh->contextSet((yyvsp[-7].contop),(yyvsp[-4].specsym),(yyvsp[-2].contextsym)); }
    break;

  case 137: /* contextlist: contextlist OPERANDSYM '=' pexpression ';'  */
                                               { (yyval.contop) = (yyvsp[-4].contop); slgh->defineOperand((yyvsp[-3].operandsym),(yyvsp[-1].patexp)); }
    break;

  case 138: /* contextlist: contextlist STRING  */
                                        { string errmsg="Expecting context symbol, not "+*(yyvsp[0].str); delete (yyvsp[0].str); yyerror(errmsg.c_str()); YYERROR; }
    break;

  case 139: /* section_def: OP_LEFT STRING OP_RIGHT  */
                                        { (yyval.sectionsym) = slgh->newSectionSymbol( *(yyvsp[-1].str) ); delete (yyvsp[-1].str); }
    break;

  case 140: /* section_def: OP_LEFT SECTIONSYM OP_RIGHT  */
                                        { (yyval.sectionsym) = (yyvsp[-1].sectionsym); }
    break;

  case 141: /* rtlfirstsection: rtl section_def  */
                                        { (yyval.sectionstart) = slgh->firstNamedSection((yyvsp[-1].sem),(yyvsp[0].sectionsym)); }
    break;

  case 142: /* rtlcontinue: rtlfirstsection  */
                             { (yyval.sectionstart) = (yyvsp[0].sectionstart); }
    break;

  case 143: /* rtlcontinue: rtlcontinue rtlmid section_def  */
                                        { (yyval.sectionstart) = slgh->nextNamedSection((yyvsp[-2].sectionstart),(yyvsp[-1].sem),(yyvsp[0].sectionsym)); }
    break;

  case 144: /* rtl: rtlmid  */
            { (yyval.sem) = (yyvsp[0].sem); if ((yyval.sem)->getOpvec().empty() && ((yyval.sem)->getResult() == (HandleTpl *)0)) slgh->recordNop(); }
    break;

  case 145: /* rtl: rtlmid EXPORT_KEY exportvarnode ';'  */
                                        { (yyval.sem) = slgh->setResultVarnode((yyvsp[-3].sem),(yyvsp[-1].varnode)); }
    break;

  case 146: /* rtl: rtlmid EXPORT_KEY sizedstar lhsvarnode ';'  */
                                               { (yyval.sem) = slgh->setResultStarVarnode((yyvsp[-4].sem),(yyvsp[-2].starqual),(yyvsp[-1].varnode)); }
    break;

  case 147: /* rtl: rtlmid EXPORT_KEY STRING  */
                                        { string errmsg="Unknown export varnode: "+*(yyvsp[0].str); delete (yyvsp[0].str); yyerror(errmsg.c_str()); YYERROR; }
    break;

  case 148: /* rtl: rtlmid EXPORT_KEY sizedstar STRING  */
                                        { string errmsg="Unknown pointer varnode: "+*(yyvsp[0].str); delete (yyvsp[-1].starqual); delete (yyvsp[0].str); yyerror(errmsg.c_str()); YYERROR; }
    break;

  case 149: /* rtlmid: %empty  */
                                        { (yyval.sem) = new ConstructTpl(); }
    break;

  case 150: /* rtlmid: rtlmid statement  */
                                        { (yyval.sem) = (yyvsp[-1].sem); if (!(yyval.sem)->addOpList(*(yyvsp[0].stmt))) { delete (yyvsp[0].stmt); yyerror("Multiple delayslot declarations"); YYERROR; } delete (yyvsp[0].stmt); }
    break;

  case 151: /* rtlmid: rtlmid LOCAL_KEY STRING ';'  */
                                { (yyval.sem) = (yyvsp[-3].sem); slgh->pcode.newLocalDefinition((yyvsp[-1].str)); }
    break;

  case 152: /* rtlmid: rtlmid LOCAL_KEY STRING ':' INTEGER ';'  */
                                            { (yyval.sem) = (yyvsp[-5].sem); slgh->pcode.newLocalDefinition((yyvsp[-3].str),*(yyvsp[-1].i)); delete (yyvsp[-1].i); }
    break;

  case 153: /* statement: lhsvarnode '=' expr ';'  */
                                        { (yyvsp[-1].tree)->setOutput((yyvsp[-3].varnode)); (yyval.stmt) = ExprTree::toVector((yyvsp[-1].tree)); }
    break;

  case 154: /* statement: LOCAL_KEY STRING '=' expr ';'  */
                                        { (yyval.stmt) = slgh->pcode.newOutput(true,(yyvsp[-1].tree),(yyvsp[-3].str)); }
    break;

  case 155: /* statement: STRING '=' expr ';'  */
                                        { (yyval.stmt) = slgh->pcode.newOutput(false,(yyvsp[-1].tree),(yyvsp[-3].str)); }
    break;

  case 156: /* statement: LOCAL_KEY STRING ':' INTEGER '=' expr ';'  */
                                                { (yyval.stmt) = slgh->pcode.newOutput(true,(yyvsp[-1].tree),(yyvsp[-5].str),*(yyvsp[-3].i)); delete (yyvsp[-3].i); }
    break;

  case 157: /* statement: STRING ':' INTEGER '=' expr ';'  */
                                        { (yyval.stmt) = slgh->pcode.newOutput(true,(yyvsp[-1].tree),(yyvsp[-5].str),*(yyvsp[-3].i)); delete (yyvsp[-3].i); }
    break;

  case 158: /* statement: LOCAL_KEY specificsymbol '='  */
                                 { (yyval.stmt) = (vector<OpTpl *> *)0; string errmsg = "Redefinition of symbol: "+(yyvsp[-1].specsym)->getName(); yyerror(errmsg.c_str()); YYERROR; }
    break;

  case 159: /* statement: sizedstar expr '=' expr ';'  */
                                        { (yyval.stmt) = slgh->pcode.createStore((yyvsp[-4].starqual),(yyvsp[-3].tree),(yyvsp[-1].tree)); }
    break;

  case 160: /* statement: USEROPSYM '(' paramlist ')' ';'  */
                                        { (yyval.stmt) = slgh->pcode.createUserOpNoOut((yyvsp[-4].useropsym),(yyvsp[-2].param)); }
    break;

  case 161: /* statement: lhsvarnode '[' INTEGER ',' INTEGER ']' '=' expr ';'  */
                                                        { (yyval.stmt) = slgh->pcode.assignBitRange((yyvsp[-8].varnode),(uint4)*(yyvsp[-6].i),(uint4)*(yyvsp[-4].i),(yyvsp[-1].tree)); delete (yyvsp[-6].i), delete (yyvsp[-4].i); }
    break;

  case 162: /* statement: BITSYM '=' expr ';'  */
                                        { (yyval.stmt)=slgh->pcode.assignBitRange((yyvsp[-3].bitsym)->getParentSymbol()->getVarnode(),(yyvsp[-3].bitsym)->getBitOffset(),(yyvsp[-3].bitsym)->numBits(),(yyvsp[-1].tree)); }
    break;

  case 163: /* statement: varnode ':' INTEGER '='  */
                                        { delete (yyvsp[-3].varnode); delete (yyvsp[-1].i); yyerror("Illegal truncation on left-hand side of assignment"); YYERROR; }
    break;

  case 164: /* statement: varnode '(' INTEGER ')'  */
                                        { delete (yyvsp[-3].varnode); delete (yyvsp[-1].i); yyerror("Illegal subpiece on left-hand side of assignment"); YYERROR; }
    break;

  case 165: /* statement: BUILD_KEY OPERANDSYM ';'  */
                                        { (yyval.stmt) = slgh->pcode.createOpConst(BUILD,(yyvsp[-1].operandsym)->getIndex()); }
    break;

  case 166: /* statement: CROSSBUILD_KEY varnode ',' SECTIONSYM ';'  */
                                              { (yyval.stmt) = slgh->createCrossBuild((yyvsp[-3].varnode),(yyvsp[-1].sectionsym)); }
    break;

  case 167: /* statement: CROSSBUILD_KEY varnode ',' STRING ';'  */
                                            { (yyval.stmt) = slgh->createCrossBuild((yyvsp[-3].varnode),slgh->newSectionSymbol(*(yyvsp[-1].str))); delete (yyvsp[-1].str); }
    break;

  case 168: /* statement: DELAYSLOT_KEY '(' INTEGER ')' ';'  */
                                        { (yyval.stmt) = slgh->pcode.createOpConst(DELAY_SLOT,*(yyvsp[-2].i)); delete (yyvsp[-2].i); }
    break;

  case 169: /* statement: GOTO_KEY jumpdest ';'  */
                                        { (yyval.stmt) = slgh->pcode.createOpNoOut(CPUI_BRANCH,new ExprTree((yyvsp[-1].varnode))); }
    break;

  case 170: /* statement: IF_KEY expr GOTO_KEY jumpdest ';'  */
                                        { (yyval.stmt) = slgh->pcode.createOpNoOut(CPUI_CBRANCH,new ExprTree((yyvsp[-1].varnode)),(yyvsp[-3].tree)); }
    break;

  case 171: /* statement: GOTO_KEY '[' expr ']' ';'  */
                                        { (yyval.stmt) = slgh->pcode.createOpNoOut(CPUI_BRANCHIND,(yyvsp[-2].tree)); }
    break;

  case 172: /* statement: CALL_KEY jumpdest ';'  */
                                        { (yyval.stmt) = slgh->pcode.createOpNoOut(CPUI_CALL,new ExprTree((yyvsp[-1].varnode))); }
    break;

  case 173: /* statement: CALL_KEY '[' expr ']' ';'  */
                                        { (yyval.stmt) = slgh->pcode.createOpNoOut(CPUI_CALLIND,(yyvsp[-2].tree)); }
    break;

  case 174: /* statement: RETURN_KEY ';'  */
                                        { yyerror("Must specify an indirect parameter for return"); YYERROR; }
    break;

  case 175: /* statement: RETURN_KEY '[' expr ']' ';'  */
                                        { (yyval.stmt) = slgh->pcode.createOpNoOut(CPUI_RETURN,(yyvsp[-2].tree)); }
    break;

  case 176: /* statement: MACROSYM '(' paramlist ')' ';'  */
                                        { (yyval.stmt) = slgh->createMacroUse((yyvsp[-4].macrosym),(yyvsp[-2].param)); }
    break;

  case 177: /* statement: label  */
                                        { (yyval.stmt) = slgh->pcode.placeLabel( (yyvsp[0].labelsym) ); }
    break;

  case 178: /* expr: varnode  */
              { (yyval.tree) = new ExprTree((yyvsp[0].varnode)); }
    break;

  case 179: /* expr: sizedstar expr  */
                                { (yyval.tree) = slgh->pcode.createLoad((yyvsp[-1].starqual),(yyvsp[0].tree)); }
    break;

  case 180: /* expr: '(' expr ')'  */
                                { (yyval.tree) = (yyvsp[-1].tree); }
    break;

  case 181: /* expr: expr '+' expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_ADD,(yyvsp[-2].tree),(yyvsp[0].tree)); }
    break;

  case 182: /* expr: expr '-' expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_SUB,(yyvsp[-2].tree),(yyvsp[0].tree)); }
    break;

  case 183: /* expr: expr OP_EQUAL expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_EQUAL,(yyvsp[-2].tree),(yyvsp[0].tree)); }
    break;

  case 184: /* expr: expr OP_NOTEQUAL expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_NOTEQUAL,(yyvsp[-2].tree),(yyvsp[0].tree)); }
    break;

  case 185: /* expr: expr '<' expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_LESS,(yyvsp[-2].tree),(yyvsp[0].tree)); }
    break;

  case 186: /* expr: expr OP_GREATEQUAL expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_LESSEQUAL,(yyvsp[0].tree),(yyvsp[-2].tree)); }
    break;

  case 187: /* expr: expr OP_LESSEQUAL expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_LESSEQUAL,(yyvsp[-2].tree),(yyvsp[0].tree)); }
    break;

  case 188: /* expr: expr '>' expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_LESS,(yyvsp[0].tree),(yyvsp[-2].tree)); }
    break;

  case 189: /* expr: expr OP_SLESS expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_SLESS,(yyvsp[-2].tree),(yyvsp[0].tree)); }
    break;

  case 190: /* expr: expr OP_SGREATEQUAL expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_SLESSEQUAL,(yyvsp[0].tree),(yyvsp[-2].tree)); }
    break;

  case 191: /* expr: expr OP_SLESSEQUAL expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_SLESSEQUAL,(yyvsp[-2].tree),(yyvsp[0].tree)); }
    break;

  case 192: /* expr: expr OP_SGREAT expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_SLESS,(yyvsp[0].tree),(yyvsp[-2].tree)); }
    break;

  case 193: /* expr: '-' expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_2COMP,(yyvsp[0].tree)); }
    break;

  case 194: /* expr: '~' expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_NEGATE,(yyvsp[0].tree)); }
    break;

  case 195: /* expr: expr '^' expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_XOR,(yyvsp[-2].tree),(yyvsp[0].tree)); }
    break;

  case 196: /* expr: expr '&' expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_AND,(yyvsp[-2].tree),(yyvsp[0].tree)); }
    break;

  case 197: /* expr: expr '|' expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_OR,(yyvsp[-2].tree),(yyvsp[0].tree)); }
    break;

  case 198: /* expr: expr OP_LEFT expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_LEFT,(yyvsp[-2].tree),(yyvsp[0].tree)); }
    break;

  case 199: /* expr: expr OP_RIGHT expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_RIGHT,(yyvsp[-2].tree),(yyvsp[0].tree)); }
    break;

  case 200: /* expr: expr OP_SRIGHT expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_SRIGHT,(yyvsp[-2].tree),(yyvsp[0].tree)); }
    break;

  case 201: /* expr: expr '*' expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_MULT,(yyvsp[-2].tree),(yyvsp[0].tree)); }
    break;

  case 202: /* expr: expr '/' expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_DIV,(yyvsp[-2].tree),(yyvsp[0].tree)); }
    break;

  case 203: /* expr: expr OP_SDIV expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_SDIV,(yyvsp[-2].tree),(yyvsp[0].tree)); }
    break;

  case 204: /* expr: expr '%' expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_REM,(yyvsp[-2].tree),(yyvsp[0].tree)); }
    break;

  case 205: /* expr: expr OP_SREM expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_SREM,(yyvsp[-2].tree),(yyvsp[0].tree)); }
    break;

  case 206: /* expr: '!' expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_BOOL_NEGATE,(yyvsp[0].tree)); }
    break;

  case 207: /* expr: expr OP_BOOL_XOR expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_BOOL_XOR,(yyvsp[-2].tree),(yyvsp[0].tree)); }
    break;

  case 208: /* expr: expr OP_BOOL_AND expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_BOOL_AND,(yyvsp[-2].tree),(yyvsp[0].tree)); }
    break;

  case 209: /* expr: expr OP_BOOL_OR expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_BOOL_OR,(yyvsp[-2].tree),(yyvsp[0].tree)); }
    break;

  case 210: /* expr: expr OP_FEQUAL expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_EQUAL,(yyvsp[-2].tree),(yyvsp[0].tree)); }
    break;

  case 211: /* expr: expr OP_FNOTEQUAL expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_NOTEQUAL,(yyvsp[-2].tree),(yyvsp[0].tree)); }
    break;

  case 212: /* expr: expr OP_FLESS expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_LESS,(yyvsp[-2].tree),(yyvsp[0].tree)); }
    break;

  case 213: /* expr: expr OP_FGREAT expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_LESS,(yyvsp[0].tree),(yyvsp[-2].tree)); }
    break;

  case 214: /* expr: expr OP_FLESSEQUAL expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_LESSEQUAL,(yyvsp[-2].tree),(yyvsp[0].tree)); }
    break;

  case 215: /* expr: expr OP_FGREATEQUAL expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_LESSEQUAL,(yyvsp[0].tree),(yyvsp[-2].tree)); }
    break;

  case 216: /* expr: expr OP_FADD expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_ADD,(yyvsp[-2].tree),(yyvsp[0].tree)); }
    break;

  case 217: /* expr: expr OP_FSUB expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_SUB,(yyvsp[-2].tree),(yyvsp[0].tree)); }
    break;

  case 218: /* expr: expr OP_FMULT expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_MULT,(yyvsp[-2].tree),(yyvsp[0].tree)); }
    break;

  case 219: /* expr: expr OP_FDIV expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_DIV,(yyvsp[-2].tree),(yyvsp[0].tree)); }
    break;

  case 220: /* expr: OP_FSUB expr  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_NEG,(yyvsp[0].tree)); }
    break;

  case 221: /* expr: OP_ABS '(' expr ')'  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_ABS,(yyvsp[-1].tree)); }
    break;

  case 222: /* expr: OP_SQRT '(' expr ')'  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_SQRT,(yyvsp[-1].tree)); }
    break;

  case 223: /* expr: OP_SEXT '(' expr ')'  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_SEXT,(yyvsp[-1].tree)); }
    break;

  case 224: /* expr: OP_ZEXT '(' expr ')'  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_ZEXT,(yyvsp[-1].tree)); }
    break;

  case 225: /* expr: OP_CARRY '(' expr ',' expr ')'  */
                                   { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_CARRY,(yyvsp[-3].tree),(yyvsp[-1].tree)); }
    break;

  case 226: /* expr: OP_SCARRY '(' expr ',' expr ')'  */
                                    { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_SCARRY,(yyvsp[-3].tree),(yyvsp[-1].tree)); }
    break;

  case 227: /* expr: OP_SBORROW '(' expr ',' expr ')'  */
                                     { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_SBORROW,(yyvsp[-3].tree),(yyvsp[-1].tree)); }
    break;

  case 228: /* expr: OP_FLOAT2FLOAT '(' expr ')'  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_FLOAT2FLOAT,(yyvsp[-1].tree)); }
    break;

  case 229: /* expr: OP_INT2FLOAT '(' expr ')'  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_INT2FLOAT,(yyvsp[-1].tree)); }
    break;

  case 230: /* expr: OP_NAN '(' expr ')'  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_NAN,(yyvsp[-1].tree)); }
    break;

  case 231: /* expr: OP_TRUNC '(' expr ')'  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_TRUNC,(yyvsp[-1].tree)); }
    break;

  case 232: /* expr: OP_CEIL '(' expr ')'  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_CEIL,(yyvsp[-1].tree)); }
    break;

  case 233: /* expr: OP_FLOOR '(' expr ')'  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_FLOOR,(yyvsp[-1].tree)); }
    break;

  case 234: /* expr: OP_ROUND '(' expr ')'  */
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_ROUND,(yyvsp[-1].tree)); }
    break;

  case 235: /* expr: OP_NEW '(' expr ')'  */
                            { (yyval.tree) = slgh->pcode.createOp(CPUI_NEW,(yyvsp[-1].tree)); }
    break;

  case 236: /* expr: OP_NEW '(' expr ',' expr ')'  */
                                 { (yyval.tree) = slgh->pcode.createOp(CPUI_NEW,(yyvsp[-3].tree),(yyvsp[-1].tree)); }
    break;

  case 237: /* expr: OP_POPCOUNT '(' expr ')'  */
                             { (yyval.tree) = slgh->pcode.createOp(CPUI_POPCOUNT,(yyvsp[-1].tree)); }
    break;

  case 238: /* expr: OP_LZCOUNT '(' expr ')'  */
                            { (yyval.tree) = slgh->pcode.createOp(CPUI_LZCOUNT,(yyvsp[-1].tree)); }
    break;

  case 239: /* expr: specificsymbol '(' integervarnode ')'  */
                                          { (yyval.tree) = slgh->pcode.createOp(CPUI_SUBPIECE,new ExprTree((yyvsp[-3].specsym)->getVarnode()),new ExprTree((yyvsp[-1].varnode))); }
    break;

  case 240: /* expr: specificsymbol ':' INTEGER  */
                                { (yyval.tree) = slgh->pcode.createBitRange((yyvsp[-2].specsym),0,(uint4)(*(yyvsp[0].i) * 8)); delete (yyvsp[0].i); }
    break;

  case 241: /* expr: specificsymbol '[' INTEGER ',' INTEGER ']'  */
                                               { (yyval.tree) = slgh->pcode.createBitRange((yyvsp[-5].specsym),(uint4)*(yyvsp[-3].i),(uint4)*(yyvsp[-1].i)); delete (yyvsp[-3].i), delete (yyvsp[-1].i); }
    break;

  case 242: /* expr: BITSYM  */
                                { (yyval.tree)=slgh->pcode.createBitRange((yyvsp[0].bitsym)->getParentSymbol(),(yyvsp[0].bitsym)->getBitOffset(),(yyvsp[0].bitsym)->numBits()); }
    break;

  case 243: /* expr: USEROPSYM '(' paramlist ')'  */
                                { (yyval.tree) = slgh->pcode.createUserOp((yyvsp[-3].useropsym),(yyvsp[-1].param)); }
    break;

  case 244: /* expr: OP_CPOOLREF '(' paramlist ')'  */
                                   { if ((*(yyvsp[-1].param)).size() < 2) { string errmsg = "Must at least two inputs to cpool"; yyerror(errmsg.c_str()); YYERROR; } (yyval.tree) = slgh->pcode.createVariadic(CPUI_CPOOLREF,(yyvsp[-1].param)); }
    break;

  case 245: /* sizedstar: '*' '[' SPACESYM ']' ':' INTEGER  */
                                            { (yyval.starqual) = new StarQuality; (yyval.starqual)->size = *(yyvsp[0].i); delete (yyvsp[0].i); (yyval.starqual)->id=ConstTpl((yyvsp[-3].spacesym)->getSpace()); }
    break;

  case 246: /* sizedstar: '*' '[' SPACESYM ']'  */
                                { (yyval.starqual) = new StarQuality; (yyval.starqual)->size = 0; (yyval.starqual)->id=ConstTpl((yyvsp[-1].spacesym)->getSpace()); }
    break;

  case 247: /* sizedstar: '*' ':' INTEGER  */
                                { (yyval.starqual) = new StarQuality; (yyval.starqual)->size = *(yyvsp[0].i); delete (yyvsp[0].i); (yyval.starqual)->id=ConstTpl(slgh->getDefaultCodeSpace()); }
    break;

  case 248: /* sizedstar: '*'  */
                                { (yyval.starqual) = new StarQuality; (yyval.starqual)->size = 0; (yyval.starqual)->id=ConstTpl(slgh->getDefaultCodeSpace()); }
    break;

  case 249: /* jumpdest: STARTSYM  */
                                { VarnodeTpl *sym = (yyvsp[0].startsym)->getVarnode(); (yyval.varnode) = new VarnodeTpl(ConstTpl(ConstTpl::j_curspace),sym->getOffset(),ConstTpl(ConstTpl::j_curspace_size)); delete sym; }
    break;

  case 250: /* jumpdest: ENDSYM  */
                                { VarnodeTpl *sym = (yyvsp[0].endsym)->getVarnode(); (yyval.varnode) = new VarnodeTpl(ConstTpl(ConstTpl::j_curspace),sym->getOffset(),ConstTpl(ConstTpl::j_curspace_size)); delete sym; }
    break;

  case 251: /* jumpdest: NEXT2SYM  */
                                { VarnodeTpl *sym = (yyvsp[0].next2sym)->getVarnode(); (yyval.varnode) = new VarnodeTpl(ConstTpl(ConstTpl::j_curspace),sym->getOffset(),ConstTpl(ConstTpl::j_curspace_size)); delete sym; }
    break;

  case 252: /* jumpdest: INTEGER  */
                                { (yyval.varnode) = new VarnodeTpl(ConstTpl(ConstTpl::j_curspace),ConstTpl(ConstTpl::real,*(yyvsp[0].i)),ConstTpl(ConstTpl::j_curspace_size)); delete (yyvsp[0].i); }
    break;

  case 253: /* jumpdest: BADINTEGER  */
                                { (yyval.varnode) = new VarnodeTpl(ConstTpl(ConstTpl::j_curspace),ConstTpl(ConstTpl::real,0),ConstTpl(ConstTpl::j_curspace_size)); yyerror("Parsed integer is too big (overflow)"); }
    break;

  case 254: /* jumpdest: OPERANDSYM  */
                                { (yyval.varnode) = (yyvsp[0].operandsym)->getVarnode(); (yyvsp[0].operandsym)->setCodeAddress(); }
    break;

  case 255: /* jumpdest: INTEGER '[' SPACESYM ']'  */
                                { AddrSpace *spc = (yyvsp[-1].spacesym)->getSpace(); (yyval.varnode) = new VarnodeTpl(ConstTpl(spc),ConstTpl(ConstTpl::real,*(yyvsp[-3].i)),ConstTpl(ConstTpl::real,spc->getAddrSize())); delete (yyvsp[-3].i); }
    break;

  case 256: /* jumpdest: label  */
                                { (yyval.varnode) = new VarnodeTpl(ConstTpl(slgh->getConstantSpace()),ConstTpl(ConstTpl::j_relative,(yyvsp[0].labelsym)->getIndex()),ConstTpl(ConstTpl::real,sizeof(uintm))); (yyvsp[0].labelsym)->incrementRefCount(); }
    break;

  case 257: /* jumpdest: STRING  */
                                { string errmsg = "Unknown jump destination: "+*(yyvsp[0].str); delete (yyvsp[0].str); yyerror(errmsg.c_str()); YYERROR; }
    break;

  case 258: /* varnode: specificsymbol  */
                                { (yyval.varnode) = (yyvsp[0].specsym)->getVarnode(); }
    break;

  case 259: /* varnode: integervarnode  */
                                { (yyval.varnode) = (yyvsp[0].varnode); }
    break;

  case 260: /* varnode: STRING  */
                                { string errmsg = "Unknown varnode parameter: "+*(yyvsp[0].str); delete (yyvsp[0].str); yyerror(errmsg.c_str()); YYERROR; }
    break;

  case 261: /* varnode: SUBTABLESYM  */
                                { string errmsg = "Subtable not attached to operand: "+(yyvsp[0].subtablesym)->getName(); yyerror(errmsg.c_str()); YYERROR; }
    break;

  case 262: /* integervarnode: INTEGER  */
                                { (yyval.varnode) = new VarnodeTpl(ConstTpl(slgh->getConstantSpace()),ConstTpl(ConstTpl::real,*(yyvsp[0].i)),ConstTpl(ConstTpl::real,0)); delete (yyvsp[0].i); }
    break;

  case 263: /* integervarnode: BADINTEGER  */
                                { (yyval.varnode) = new VarnodeTpl(ConstTpl(slgh->getConstantSpace()),ConstTpl(ConstTpl::real,0),ConstTpl(ConstTpl::real,0)); yyerror("Parsed integer is too big (overflow)"); }
    break;

  case 264: /* integervarnode: INTEGER ':' INTEGER  */
                                { (yyval.varnode) = new VarnodeTpl(ConstTpl(slgh->getConstantSpace()),ConstTpl(ConstTpl::real,*(yyvsp[-2].i)),ConstTpl(ConstTpl::real,*(yyvsp[0].i))); delete (yyvsp[-2].i); delete (yyvsp[0].i); }
    break;

  case 265: /* integervarnode: '&' varnode  */
                                { (yyval.varnode) = slgh->pcode.addressOf((yyvsp[0].varnode),0); }
    break;

  case 266: /* integervarnode: '&' ':' INTEGER varnode  */
                                { (yyval.varnode) = slgh->pcode.addressOf((yyvsp[0].varnode),*(yyvsp[-1].i)); delete (yyvsp[-1].i); }
    break;

  case 267: /* lhsvarnode: specificsymbol  */
                                { (yyval.varnode) = (yyvsp[0].specsym)->getVarnode(); }
    break;

  case 268: /* lhsvarnode: STRING  */
                                { string errmsg = "Unknown assignment varnode: "+*(yyvsp[0].str); delete (yyvsp[0].str); yyerror(errmsg.c_str()); YYERROR; }
    break;

  case 269: /* lhsvarnode: SUBTABLESYM  */
                                { string errmsg = "Subtable not attached to operand: "+(yyvsp[0].subtablesym)->getName(); yyerror(errmsg.c_str()); YYERROR; }
    break;

  case 270: /* label: '<' LABELSYM '>'  */
                                { (yyval.labelsym) = (yyvsp[-1].labelsym); }
    break;

  case 271: /* label: '<' STRING '>'  */
                                { (yyval.labelsym) = slgh->pcode.defineLabel( (yyvsp[-1].str) ); }
    break;

  case 272: /* exportvarnode: specificsymbol  */
                                { (yyval.varnode) = (yyvsp[0].specsym)->getVarnode(); }
    break;

  case 273: /* exportvarnode: '&' varnode  */
                                { (yyval.varnode) = slgh->pcode.addressOf((yyvsp[0].varnode),0); }
    break;

  case 274: /* exportvarnode: '&' ':' INTEGER varnode  */
                                { (yyval.varnode) = slgh->pcode.addressOf((yyvsp[0].varnode),*(yyvsp[-1].i)); delete (yyvsp[-1].i); }
    break;

  case 275: /* exportvarnode: INTEGER ':' INTEGER  */
                                { (yyval.varnode) = new VarnodeTpl(ConstTpl(slgh->getConstantSpace()),ConstTpl(ConstTpl::real,*(yyvsp[-2].i)),ConstTpl(ConstTpl::real,*(yyvsp[0].i))); delete (yyvsp[-2].i); delete (yyvsp[0].i); }
    break;

  case 276: /* exportvarnode: STRING  */
                                { string errmsg="Unknown export varnode: "+*(yyvsp[0].str); delete (yyvsp[0].str); yyerror(errmsg.c_str()); YYERROR; }
    break;

  case 277: /* exportvarnode: SUBTABLESYM  */
                                { string errmsg = "Subtable not attached to operand: "+(yyvsp[0].subtablesym)->getName(); yyerror(errmsg.c_str()); YYERROR; }
    break;

  case 278: /* familysymbol: VALUESYM  */
                                { (yyval.famsym) = (yyvsp[0].valuesym); }
    break;

  case 279: /* familysymbol: VALUEMAPSYM  */
                                { (yyval.famsym) = (yyvsp[0].valuemapsym); }
    break;

  case 280: /* familysymbol: CONTEXTSYM  */
                                { (yyval.famsym) = (yyvsp[0].contextsym); }
    break;

  case 281: /* familysymbol: NAMESYM  */
                                { (yyval.famsym) = (yyvsp[0].namesym); }
    break;

  case 282: /* familysymbol: VARLISTSYM  */
                                { (yyval.famsym) = (yyvsp[0].varlistsym); }
    break;

  case 283: /* specificsymbol: VARSYM  */
                                { (yyval.specsym) = (yyvsp[0].varsym); }
    break;

  case 284: /* specificsymbol: SPECSYM  */
                                { (yyval.specsym) = (yyvsp[0].specsym); }
    break;

  case 285: /* specificsymbol: OPERANDSYM  */
                                { (yyval.specsym) = (yyvsp[0].operandsym); }
    break;

  case 286: /* specificsymbol: STARTSYM  */
                                { (yyval.specsym) = (yyvsp[0].startsym); }
    break;

  case 287: /* specificsymbol: OFFSETSYM  */
                                { (yyval.specsym) = (yyvsp[0].offsetsym); }
    break;

  case 288: /* specificsymbol: ENDSYM  */
                                { (yyval.specsym) = (yyvsp[0].endsym); }
    break;

  case 289: /* specificsymbol: NEXT2SYM  */
                                { (yyval.specsym) = (yyvsp[0].next2sym); }
    break;

  case 290: /* charstring: CHAR  */
                                { (yyval.str) = new string; (*(yyval.str)) += (yyvsp[0].ch); }
    break;

  case 291: /* charstring: charstring CHAR  */
                                { (yyval.str) = (yyvsp[-1].str); (*(yyval.str)) += (yyvsp[0].ch); }
    break;

  case 292: /* intblist: '[' intbpart ']'  */
                                { (yyval.biglist) = (yyvsp[-1].biglist); }
    break;

  case 293: /* intblist: INTEGER  */
                                { (yyval.biglist) = new vector<intb>; (yyval.biglist)->push_back(intb(*(yyvsp[0].i))); delete (yyvsp[0].i); }
    break;

  case 294: /* intblist: '-' INTEGER  */
                                { (yyval.biglist) = new vector<intb>; (yyval.biglist)->push_back(-intb(*(yyvsp[0].i))); delete (yyvsp[0].i); }
    break;

  case 295: /* intbpart: INTEGER  */
                                { (yyval.biglist) = new vector<intb>; (yyval.biglist)->push_back(intb(*(yyvsp[0].i))); delete (yyvsp[0].i); }
    break;

  case 296: /* intbpart: '-' INTEGER  */
                                { (yyval.biglist) = new vector<intb>; (yyval.biglist)->push_back(-intb(*(yyvsp[0].i))); delete (yyvsp[0].i); }
    break;

  case 297: /* intbpart: STRING  */
                                { if (*(yyvsp[0].str)!="_") { string errmsg = "Expecting integer but saw: "+*(yyvsp[0].str); delete (yyvsp[0].str); yyerror(errmsg.c_str()); YYERROR; }
                                  (yyval.biglist) = new vector<intb>; (yyval.biglist)->push_back((intb)0xBADBEEF); delete (yyvsp[0].str); }
    break;

  case 298: /* intbpart: intbpart INTEGER  */
                                { (yyval.biglist) = (yyvsp[-1].biglist); (yyval.biglist)->push_back(intb(*(yyvsp[0].i))); delete (yyvsp[0].i); }
    break;

  case 299: /* intbpart: intbpart '-' INTEGER  */
                                { (yyval.biglist) = (yyvsp[-2].biglist); (yyval.biglist)->push_back(-intb(*(yyvsp[0].i))); delete (yyvsp[0].i); }
    break;

  case 300: /* intbpart: intbpart STRING  */
                                { if (*(yyvsp[0].str)!="_") { string errmsg = "Expecting integer but saw: "+*(yyvsp[0].str); delete (yyvsp[0].str); yyerror(errmsg.c_str()); YYERROR; }
                                  (yyval.biglist) = (yyvsp[-1].biglist); (yyval.biglist)->push_back((intb)0xBADBEEF); delete (yyvsp[0].str); }
    break;

  case 301: /* stringlist: '[' stringpart ']'  */
                                { (yyval.strlist) = (yyvsp[-1].strlist); }
    break;

  case 302: /* stringlist: STRING  */
                                { (yyval.strlist) = new vector<string>; (yyval.strlist)->push_back(*(yyvsp[0].str)); delete (yyvsp[0].str); }
    break;

  case 303: /* stringpart: STRING  */
                                { (yyval.strlist) = new vector<string>; (yyval.strlist)->push_back( *(yyvsp[0].str) ); delete (yyvsp[0].str); }
    break;

  case 304: /* stringpart: stringpart STRING  */
                                { (yyval.strlist) = (yyvsp[-1].strlist); (yyval.strlist)->push_back(*(yyvsp[0].str)); delete (yyvsp[0].str); }
    break;

  case 305: /* stringpart: stringpart anysymbol  */
                                { string errmsg = (yyvsp[0].anysym)->getName()+": redefined"; yyerror(errmsg.c_str()); YYERROR; }
    break;

  case 306: /* anystringlist: '[' anystringpart ']'  */
                                     { (yyval.strlist) = (yyvsp[-1].strlist); }
    break;

  case 307: /* anystringpart: STRING  */
                                { (yyval.strlist) = new vector<string>; (yyval.strlist)->push_back( *(yyvsp[0].str) ); delete (yyvsp[0].str); }
    break;

  case 308: /* anystringpart: anysymbol  */
                                { (yyval.strlist) = new vector<string>; (yyval.strlist)->push_back( (yyvsp[0].anysym)->getName() ); }
    break;

  case 309: /* anystringpart: anystringpart STRING  */
                                { (yyval.strlist) = (yyvsp[-1].strlist); (yyval.strlist)->push_back(*(yyvsp[0].str)); delete (yyvsp[0].str); }
    break;

  case 310: /* anystringpart: anystringpart anysymbol  */
                                { (yyval.strlist) = (yyvsp[-1].strlist); (yyval.strlist)->push_back((yyvsp[0].anysym)->getName()); }
    break;

  case 311: /* valuelist: '[' valuepart ']'  */
                                { (yyval.symlist) = (yyvsp[-1].symlist); }
    break;

  case 312: /* valuelist: VALUESYM  */
                                { (yyval.symlist) = new vector<SleighSymbol *>; (yyval.symlist)->push_back((yyvsp[0].valuesym)); }
    break;

  case 313: /* valuelist: CONTEXTSYM  */
                                { (yyval.symlist) = new vector<SleighSymbol *>; (yyval.symlist)->push_back((yyvsp[0].contextsym)); }
    break;

  case 314: /* valuepart: VALUESYM  */
                                { (yyval.symlist) = new vector<SleighSymbol *>; (yyval.symlist)->push_back( (yyvsp[0].valuesym) ); }
    break;

  case 315: /* valuepart: CONTEXTSYM  */
                                { (yyval.symlist) = new vector<SleighSymbol *>; (yyval.symlist)->push_back((yyvsp[0].contextsym)); }
    break;

  case 316: /* valuepart: valuepart VALUESYM  */
                                { (yyval.symlist) = (yyvsp[-1].symlist); (yyval.symlist)->push_back((yyvsp[0].valuesym)); }
    break;

  case 317: /* valuepart: valuepart CONTEXTSYM  */
                                { (yyval.symlist) = (yyvsp[-1].symlist); (yyval.symlist)->push_back((yyvsp[0].contextsym)); }
    break;

  case 318: /* valuepart: valuepart STRING  */
                                { string errmsg = *(yyvsp[0].str)+": is not a value pattern"; delete (yyvsp[0].str); yyerror(errmsg.c_str()); YYERROR; }
    break;

  case 319: /* varlist: '[' varpart ']'  */
                                { (yyval.symlist) = (yyvsp[-1].symlist); }
    break;

  case 320: /* varlist: VARSYM  */
                                { (yyval.symlist) = new vector<SleighSymbol *>; (yyval.symlist)->push_back((yyvsp[0].varsym)); }
    break;

  case 321: /* varpart: VARSYM  */
                                { (yyval.symlist) = new vector<SleighSymbol *>; (yyval.symlist)->push_back((yyvsp[0].varsym)); }
    break;

  case 322: /* varpart: STRING  */
                                { if (*(yyvsp[0].str)!="_") { string errmsg = *(yyvsp[0].str)+": is not a varnode symbol"; delete (yyvsp[0].str); yyerror(errmsg.c_str()); YYERROR; }
				  (yyval.symlist) = new vector<SleighSymbol *>; (yyval.symlist)->push_back((SleighSymbol *)0); delete (yyvsp[0].str); }
    break;

  case 323: /* varpart: varpart VARSYM  */
                                { (yyval.symlist) = (yyvsp[-1].symlist); (yyval.symlist)->push_back((yyvsp[0].varsym)); }
    break;

  case 324: /* varpart: varpart STRING  */
                                { if (*(yyvsp[0].str)!="_") { string errmsg = *(yyvsp[0].str)+": is not a varnode symbol"; delete (yyvsp[0].str); yyerror(errmsg.c_str()); YYERROR; }
                                  (yyval.symlist) = (yyvsp[-1].symlist); (yyval.symlist)->push_back((SleighSymbol *)0); delete (yyvsp[0].str); }
    break;

  case 325: /* paramlist: %empty  */
                                { (yyval.param) = new vector<ExprTree *>; }
    break;

  case 326: /* paramlist: expr  */
                                { (yyval.param) = new vector<ExprTree *>; (yyval.param)->push_back((yyvsp[0].tree)); }
    break;

  case 327: /* paramlist: paramlist ',' expr  */
                                { (yyval.param) = (yyvsp[-2].param); (yyval.param)->push_back((yyvsp[0].tree)); }
    break;

  case 328: /* oplist: %empty  */
                                { (yyval.strlist) = new vector<string>; }
    break;

  case 329: /* oplist: STRING  */
                                { (yyval.strlist) = new vector<string>; (yyval.strlist)->push_back(*(yyvsp[0].str)); delete (yyvsp[0].str); }
    break;

  case 330: /* oplist: oplist ',' STRING  */
                                { (yyval.strlist) = (yyvsp[-2].strlist); (yyval.strlist)->push_back(*(yyvsp[0].str)); delete (yyvsp[0].str); }
    break;

  case 331: /* anysymbol: SPACESYM  */
                                { (yyval.anysym) = (yyvsp[0].spacesym); }
    break;

  case 332: /* anysymbol: SECTIONSYM  */
                                { (yyval.anysym) = (yyvsp[0].sectionsym); }
    break;

  case 333: /* anysymbol: TOKENSYM  */
                                { (yyval.anysym) = (yyvsp[0].tokensym); }
    break;

  case 334: /* anysymbol: USEROPSYM  */
                                { (yyval.anysym) = (yyvsp[0].useropsym); }
    break;

  case 335: /* anysymbol: MACROSYM  */
                                { (yyval.anysym) = (yyvsp[0].macrosym); }
    break;

  case 336: /* anysymbol: SUBTABLESYM  */
                                { (yyval.anysym) = (yyvsp[0].subtablesym); }
    break;

  case 337: /* anysymbol: VALUESYM  */
                                { (yyval.anysym) = (yyvsp[0].valuesym); }
    break;

  case 338: /* anysymbol: VALUEMAPSYM  */
                                { (yyval.anysym) = (yyvsp[0].valuemapsym); }
    break;

  case 339: /* anysymbol: CONTEXTSYM  */
                                { (yyval.anysym) = (yyvsp[0].contextsym); }
    break;

  case 340: /* anysymbol: NAMESYM  */
                                { (yyval.anysym) = (yyvsp[0].namesym); }
    break;

  case 341: /* anysymbol: VARSYM  */
                                { (yyval.anysym) = (yyvsp[0].varsym); }
    break;

  case 342: /* anysymbol: VARLISTSYM  */
                                { (yyval.anysym) = (yyvsp[0].varlistsym); }
    break;

  case 343: /* anysymbol: OPERANDSYM  */
                                { (yyval.anysym) = (yyvsp[0].operandsym); }
    break;

  case 344: /* anysymbol: STARTSYM  */
                                { (yyval.anysym) = (yyvsp[0].startsym); }
    break;

  case 345: /* anysymbol: OFFSETSYM  */
                                { (yyval.anysym) = (yyvsp[0].offsetsym); }
    break;

  case 346: /* anysymbol: ENDSYM  */
                                { (yyval.anysym) = (yyvsp[0].endsym); }
    break;

  case 347: /* anysymbol: NEXT2SYM  */
                                { (yyval.anysym) = (yyvsp[0].next2sym); }
    break;

  case 348: /* anysymbol: BITSYM  */
                                { (yyval.anysym) = (yyvsp[0].bitsym); }
    break;



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



int yyerror(const char *s)

{
  slgh->reportError(s);
  return 0;
}
