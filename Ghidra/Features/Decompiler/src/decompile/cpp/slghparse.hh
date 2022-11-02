/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SLGHPARSE_HH_INCLUDED
# define YY_YY_SLGHPARSE_HH_INCLUDED
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
    OP_BOOL_OR = 258,              /* OP_BOOL_OR  */
    OP_BOOL_AND = 259,             /* OP_BOOL_AND  */
    OP_BOOL_XOR = 260,             /* OP_BOOL_XOR  */
    OP_OR = 261,                   /* OP_OR  */
    OP_XOR = 262,                  /* OP_XOR  */
    OP_AND = 263,                  /* OP_AND  */
    OP_EQUAL = 264,                /* OP_EQUAL  */
    OP_NOTEQUAL = 265,             /* OP_NOTEQUAL  */
    OP_FEQUAL = 266,               /* OP_FEQUAL  */
    OP_FNOTEQUAL = 267,            /* OP_FNOTEQUAL  */
    OP_GREATEQUAL = 268,           /* OP_GREATEQUAL  */
    OP_LESSEQUAL = 269,            /* OP_LESSEQUAL  */
    OP_SLESS = 270,                /* OP_SLESS  */
    OP_SGREATEQUAL = 271,          /* OP_SGREATEQUAL  */
    OP_SLESSEQUAL = 272,           /* OP_SLESSEQUAL  */
    OP_SGREAT = 273,               /* OP_SGREAT  */
    OP_FLESS = 274,                /* OP_FLESS  */
    OP_FGREAT = 275,               /* OP_FGREAT  */
    OP_FLESSEQUAL = 276,           /* OP_FLESSEQUAL  */
    OP_FGREATEQUAL = 277,          /* OP_FGREATEQUAL  */
    OP_LEFT = 278,                 /* OP_LEFT  */
    OP_RIGHT = 279,                /* OP_RIGHT  */
    OP_SRIGHT = 280,               /* OP_SRIGHT  */
    OP_FADD = 281,                 /* OP_FADD  */
    OP_FSUB = 282,                 /* OP_FSUB  */
    OP_SDIV = 283,                 /* OP_SDIV  */
    OP_SREM = 284,                 /* OP_SREM  */
    OP_FMULT = 285,                /* OP_FMULT  */
    OP_FDIV = 286,                 /* OP_FDIV  */
    OP_ZEXT = 287,                 /* OP_ZEXT  */
    OP_CARRY = 288,                /* OP_CARRY  */
    OP_BORROW = 289,               /* OP_BORROW  */
    OP_SEXT = 290,                 /* OP_SEXT  */
    OP_SCARRY = 291,               /* OP_SCARRY  */
    OP_SBORROW = 292,              /* OP_SBORROW  */
    OP_NAN = 293,                  /* OP_NAN  */
    OP_ABS = 294,                  /* OP_ABS  */
    OP_SQRT = 295,                 /* OP_SQRT  */
    OP_CEIL = 296,                 /* OP_CEIL  */
    OP_FLOOR = 297,                /* OP_FLOOR  */
    OP_ROUND = 298,                /* OP_ROUND  */
    OP_INT2FLOAT = 299,            /* OP_INT2FLOAT  */
    OP_FLOAT2FLOAT = 300,          /* OP_FLOAT2FLOAT  */
    OP_TRUNC = 301,                /* OP_TRUNC  */
    OP_CPOOLREF = 302,             /* OP_CPOOLREF  */
    OP_NEW = 303,                  /* OP_NEW  */
    OP_POPCOUNT = 304,             /* OP_POPCOUNT  */
    OP_LZCOUNT = 305,              /* OP_LZCOUNT  */
    BADINTEGER = 306,              /* BADINTEGER  */
    GOTO_KEY = 307,                /* GOTO_KEY  */
    CALL_KEY = 308,                /* CALL_KEY  */
    RETURN_KEY = 309,              /* RETURN_KEY  */
    IF_KEY = 310,                  /* IF_KEY  */
    DEFINE_KEY = 311,              /* DEFINE_KEY  */
    ATTACH_KEY = 312,              /* ATTACH_KEY  */
    MACRO_KEY = 313,               /* MACRO_KEY  */
    SPACE_KEY = 314,               /* SPACE_KEY  */
    TYPE_KEY = 315,                /* TYPE_KEY  */
    RAM_KEY = 316,                 /* RAM_KEY  */
    DEFAULT_KEY = 317,             /* DEFAULT_KEY  */
    REGISTER_KEY = 318,            /* REGISTER_KEY  */
    ENDIAN_KEY = 319,              /* ENDIAN_KEY  */
    WITH_KEY = 320,                /* WITH_KEY  */
    ALIGN_KEY = 321,               /* ALIGN_KEY  */
    OP_UNIMPL = 322,               /* OP_UNIMPL  */
    TOKEN_KEY = 323,               /* TOKEN_KEY  */
    SIGNED_KEY = 324,              /* SIGNED_KEY  */
    NOFLOW_KEY = 325,              /* NOFLOW_KEY  */
    HEX_KEY = 326,                 /* HEX_KEY  */
    DEC_KEY = 327,                 /* DEC_KEY  */
    OCT_KEY = 328,                 /* OCT_KEY  */
    BIN_KEY = 329,                 /* BIN_KEY  */
    BIG_KEY = 330,                 /* BIG_KEY  */
    LITTLE_KEY = 331,              /* LITTLE_KEY  */
    SIZE_KEY = 332,                /* SIZE_KEY  */
    WORDSIZE_KEY = 333,            /* WORDSIZE_KEY  */
    OFFSET_KEY = 334,              /* OFFSET_KEY  */
    NAMES_KEY = 335,               /* NAMES_KEY  */
    VALUES_KEY = 336,              /* VALUES_KEY  */
    VARIABLES_KEY = 337,           /* VARIABLES_KEY  */
    PCODEOP_KEY = 338,             /* PCODEOP_KEY  */
    IS_KEY = 339,                  /* IS_KEY  */
    LOCAL_KEY = 340,               /* LOCAL_KEY  */
    DELAYSLOT_KEY = 341,           /* DELAYSLOT_KEY  */
    CROSSBUILD_KEY = 342,          /* CROSSBUILD_KEY  */
    EXPORT_KEY = 343,              /* EXPORT_KEY  */
    BUILD_KEY = 344,               /* BUILD_KEY  */
    CONTEXT_KEY = 345,             /* CONTEXT_KEY  */
    ELLIPSIS_KEY = 346,            /* ELLIPSIS_KEY  */
    GLOBALSET_KEY = 347,           /* GLOBALSET_KEY  */
    BITRANGE_KEY = 348,            /* BITRANGE_KEY  */
    CHAR = 349,                    /* CHAR  */
    INTEGER = 350,                 /* INTEGER  */
    INTB = 351,                    /* INTB  */
    STRING = 352,                  /* STRING  */
    SYMBOLSTRING = 353,            /* SYMBOLSTRING  */
    SPACESYM = 354,                /* SPACESYM  */
    SECTIONSYM = 355,              /* SECTIONSYM  */
    TOKENSYM = 356,                /* TOKENSYM  */
    USEROPSYM = 357,               /* USEROPSYM  */
    VALUESYM = 358,                /* VALUESYM  */
    VALUEMAPSYM = 359,             /* VALUEMAPSYM  */
    CONTEXTSYM = 360,              /* CONTEXTSYM  */
    NAMESYM = 361,                 /* NAMESYM  */
    VARSYM = 362,                  /* VARSYM  */
    BITSYM = 363,                  /* BITSYM  */
    SPECSYM = 364,                 /* SPECSYM  */
    VARLISTSYM = 365,              /* VARLISTSYM  */
    OPERANDSYM = 366,              /* OPERANDSYM  */
    STARTSYM = 367,                /* STARTSYM  */
    OFFSETSYM = 368,               /* OFFSETSYM  */
    ENDSYM = 369,                  /* ENDSYM  */
    NEXT2SYM = 370,                /* NEXT2SYM  */
    MACROSYM = 371,                /* MACROSYM  */
    LABELSYM = 372,                /* LABELSYM  */
    SUBTABLESYM = 373              /* SUBTABLESYM  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{

  char ch;
  uintb *i;
  intb *big;
  std::string *str;
  std::vector<std::string> *strlist;
  std::vector<intb> *biglist;
  std::vector<ExprTree *> *param;
  SpaceQuality *spacequal;
  FieldQuality *fieldqual;
  StarQuality *starqual;
  VarnodeTpl *varnode;
  ExprTree *tree;
  std::vector<OpTpl *> *stmt;
  ConstructTpl *sem;
  SectionVector *sectionstart;
  Constructor *construct;
  PatternEquation *pateq;
  PatternExpression *patexp;

  std::vector<SleighSymbol *> *symlist;
  std::vector<ContextChange *> *contop;
  SleighSymbol *anysym;
  SpaceSymbol *spacesym;
  SectionSymbol *sectionsym;
  TokenSymbol *tokensym;
  UserOpSymbol *useropsym;
  MacroSymbol *macrosym;
  LabelSymbol *labelsym;
  SubtableSymbol *subtablesym;
  StartSymbol *startsym;
  OffsetSymbol *offsetsym;
  EndSymbol *endsym;
  Next2Symbol *next2sym;
  OperandSymbol *operandsym;
  VarnodeListSymbol *varlistsym;
  VarnodeSymbol *varsym;
  BitrangeSymbol *bitsym;
  NameSymbol *namesym;
  ValueSymbol *valuesym;
  ValueMapSymbol *valuemapsym;
  ContextSymbol *contextsym;
  FamilySymbol *famsym;
  SpecificSymbol *specsym;


};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SLGHPARSE_HH_INCLUDED  */
