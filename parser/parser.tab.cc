
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008 Free Software
   Foundation, Inc.
   
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


/* First part of user declarations.  */

/* Line 311 of lalr1.cc  */
#line 1 "parser.yy"

#include <string>
#include "../Driver.h"
#include "../scanner/Scanner.h"
#include "../environment/ast/ValueExpression.h"
#include "../environment/ast/VariableExpression.h"
#include "../environment/ast/OperatorExpression.h"
#include "../environment/ast/AssignmentInstruction.h"
#include "../environment/ast/ConditionalInstruction.h"
#include "../environment/ast/Instruction.h"
#include "../environment/ast/Expression.h"
#include "../environment/ast/FunctionCall.h"
#include "../environment/descriptor/FunctionDescriptor.h"
#include "../environment/ast/LoopInstruction.h"
#include "../environment/data/Value.h"
#include "../environment/ast/MatrixExpression.h"
#include "../environment/ast/MatrixElementExpression.h"
using namespace matryca;

// typedefy dla elementow ast

typedef Instruction::InstructionPtr InstructionPtr;
typedef Instruction::InstructionPtrList InstructionPtrList;
typedef Expression::ExpressionPtr ExpressionPtr;
typedef Expression::ExpressionPtrList ExpressionPtrList;
typedef Expression::ExpressionPtrMatrix ExpressionPtrMatrix;
typedef FunctionDescriptor::IDList IDList;
typedef SymbolDescriptor::SymbolDescPtr SymbolDescPtr;

#undef yylex
#define yylex driver.getScanner()->yylex
// parser bedzie pobieral tokeny posrednio przez driver


/* Line 311 of lalr1.cc  */
#line 76 "parser.tab.cc"


#include "parser.tab.hh"

/* User implementation prologue.  */


/* Line 317 of lalr1.cc  */
#line 85 "parser.tab.cc"

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


/* Line 380 of lalr1.cc  */
#line 39 "parser.yy"
namespace matryca {

/* Line 380 of lalr1.cc  */
#line 153 "parser.tab.cc"
#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              /* Fall through.  */
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

#endif

  /// Build a parser object.
  Parser::Parser (matryca::Driver &driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {
  }

  Parser::~Parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  Parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  Parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  Parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
  
	default:
	  break;
      }
  }

  void
  Parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  int
  Parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, &yylloc);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yyn == 0 || yyn == yytable_ninf_)
	goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 2:

/* Line 678 of lalr1.cc  */
#line 110 "parser.yy"
    {
        // nic
    }
    break;

  case 3:

/* Line 678 of lalr1.cc  */
#line 114 "parser.yy"
    {
        // nic
    }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 120 "parser.yy"
    {
        // nic
    }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 124 "parser.yy"
    {
        driver.addGlobalInstruction(InstructionPtr((yysemantic_stack_[(1) - (1)].instruction_ptr)));
    }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 130 "parser.yy"
    {
        driver.addFunction(*(yysemantic_stack_[(6) - (2)].string_val), *(yysemantic_stack_[(6) - (4)].id_list_ptr), *(yysemantic_stack_[(6) - (6)].instruction_ptr_list_ptr));
        delete (yysemantic_stack_[(6) - (2)].string_val); delete (yysemantic_stack_[(6) - (4)].id_list_ptr); delete (yysemantic_stack_[(6) - (6)].instruction_ptr_list_ptr); // juz nie potrzebne
    }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 137 "parser.yy"
    {
        (yyval.id_list_ptr) = driver.getIDList();
    }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 141 "parser.yy"
    {
        (yyval.id_list_ptr) = new IDList;
    }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 147 "parser.yy"
    {
        driver.addID(*(yysemantic_stack_[(3) - (3)].string_val));
        delete (yysemantic_stack_[(3) - (3)].string_val);
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 152 "parser.yy"
    {
        driver.addID(*(yysemantic_stack_[(1) - (1)].string_val));
        delete (yysemantic_stack_[(1) - (1)].string_val);
    }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 158 "parser.yy"
    {   // akcja przed wejsciem do bloku instrukcji
        driver.pushLocalInstructionPtrList();
    }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 162 "parser.yy"
    {
        (yyval.instruction_ptr_list_ptr) = driver.getLocalInstructionPtrList();
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 168 "parser.yy"
    {
        driver.addLocalInstruction(InstructionPtr((yysemantic_stack_[(2) - (2)].instruction_ptr)));
    }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 172 "parser.yy"
    {
        driver.addLocalInstruction(InstructionPtr((yysemantic_stack_[(1) - (1)].instruction_ptr)));
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 178 "parser.yy"
    {
        (yyval.instruction_ptr) = new AssignmentInstruction(ExpressionPtr(new VariableExpression(*(yysemantic_stack_[(4) - (1)].string_val))), ExpressionPtr((yysemantic_stack_[(4) - (3)].expression_ptr)));
        delete (yysemantic_stack_[(4) - (1)].string_val);
        (yyval.instruction_ptr)->setLocation(yylloc);
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 184 "parser.yy"
    {
        (yyval.instruction_ptr) = (yysemantic_stack_[(1) - (1)].instruction_ptr);
        (yyval.instruction_ptr)->setLocation(yylloc);
    }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 189 "parser.yy"
    {
        (yyval.instruction_ptr) = (yysemantic_stack_[(1) - (1)].instruction_ptr);
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 193 "parser.yy"
    {
        (yyval.instruction_ptr) = (yysemantic_stack_[(2) - (1)].function_call_ptr); // wywolanie funkcji to instrukcja i wyrazenie jednoczesnie
        (yyval.instruction_ptr)->setLocation(yylloc);
    }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 198 "parser.yy"
    {
        (yyval.instruction_ptr) = (yysemantic_stack_[(1) - (1)].instruction_ptr);
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 204 "parser.yy"
    { // przypisuje 0 do tworzonej na stosie wartosci lub wartosci globalnej
        (yyval.instruction_ptr) = new AssignmentInstruction(ExpressionPtr(new VariableExpression(*(yysemantic_stack_[(3) - (2)].string_val))), ExpressionPtr(new ValueExpression(0)), true);
        delete (yysemantic_stack_[(3) - (2)].string_val);
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 209 "parser.yy"
    {
        (yyval.instruction_ptr) = new AssignmentInstruction(ExpressionPtr(new VariableExpression(*(yysemantic_stack_[(5) - (2)].string_val))), ExpressionPtr((yysemantic_stack_[(5) - (4)].expression_ptr)), true);
        delete (yysemantic_stack_[(5) - (2)].string_val);
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 216 "parser.yy"
    {
        (yyval.expression_ptr) = new VariableExpression(*(yysemantic_stack_[(1) - (1)].string_val));
        delete (yysemantic_stack_[(1) - (1)].string_val);
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 221 "parser.yy"
    {
        (yyval.expression_ptr) = new MatrixElementExpression(*(yysemantic_stack_[(6) - (1)].string_val), ExpressionPtr((yysemantic_stack_[(6) - (3)].expression_ptr)), ExpressionPtr((yysemantic_stack_[(6) - (5)].expression_ptr)));
        delete (yysemantic_stack_[(6) - (1)].string_val);
    }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 228 "parser.yy"
    {driver.pushExpressionPtrMatrix();}
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 230 "parser.yy"
    {
        (yyval.expression_ptr) = new MatrixExpression(*(driver.getExpressionPtrMatrix()));
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 236 "parser.yy"
    {
        driver.addExpressionList(*(yysemantic_stack_[(3) - (3)].expression_ptr_list_ptr));
        delete (yysemantic_stack_[(3) - (3)].expression_ptr_list_ptr);
    }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 241 "parser.yy"
    {
        driver.addExpressionList(*(yysemantic_stack_[(1) - (1)].expression_ptr_list_ptr));
        delete (yysemantic_stack_[(1) - (1)].expression_ptr_list_ptr);
    }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 248 "parser.yy"
    {
        (yyval.char_val) = (yysemantic_stack_[(1) - (1)].char_val);
    }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 252 "parser.yy"
    {
        (yyval.char_val) = (yysemantic_stack_[(1) - (1)].char_val);
    }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 258 "parser.yy"
    {
        (yyval.expression_ptr) = (yysemantic_stack_[(1) - (1)].expression_ptr);
    }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 262 "parser.yy"
    {
        (yyval.expression_ptr) = new OperatorExpression((yysemantic_stack_[(3) - (2)].char_val), ExpressionPtr((yysemantic_stack_[(3) - (1)].expression_ptr)), ExpressionPtr((yysemantic_stack_[(3) - (3)].expression_ptr)));
        (yyval.expression_ptr)->setLoc(yylloc);
    }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 269 "parser.yy"
    {
        (yyval.expression_ptr) = (yysemantic_stack_[(1) - (1)].expression_ptr);
    }
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 273 "parser.yy"
    {
        (yyval.expression_ptr) = new OperatorExpression((yysemantic_stack_[(3) - (2)].char_val), ExpressionPtr((yysemantic_stack_[(3) - (1)].expression_ptr)), ExpressionPtr((yysemantic_stack_[(3) - (3)].expression_ptr)));
        (yyval.expression_ptr)->setLoc(yylloc);
    }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 280 "parser.yy"
    {
        (yyval.expression_ptr) = (yysemantic_stack_[(1) - (1)].expression_ptr);
    }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 284 "parser.yy"
    { // to jest mnozenie odpowiednio +/- 1 * czynnik
        (yyval.expression_ptr) = new OperatorExpression('*',
                                    ExpressionPtr(new OperatorExpression(
                                            (yysemantic_stack_[(2) - (1)].char_val),
                                            ExpressionPtr(new ValueExpression(0)),
                                            ExpressionPtr(new ValueExpression(1)))), // 0 +/- 1
                                    ExpressionPtr((yysemantic_stack_[(2) - (2)].expression_ptr)));
        (yyval.expression_ptr)->setLoc(yylloc);
    }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 294 "parser.yy"
    {
        (yyval.expression_ptr)->setLoc(yylloc);
        (yyval.expression_ptr) = new OperatorExpression((yysemantic_stack_[(3) - (2)].char_val), ExpressionPtr((yysemantic_stack_[(3) - (1)].expression_ptr)), ExpressionPtr((yysemantic_stack_[(3) - (3)].expression_ptr)));
    }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 301 "parser.yy"
    {
        (yyval.expression_ptr) = new ValueExpression((yysemantic_stack_[(1) - (1)].int_val));
        (yyval.expression_ptr)->setLoc(yylloc); // zapamietanie pozycji wyrazenia - strategia - jak najglebiej
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 306 "parser.yy"
    {
        (yyval.expression_ptr) = new ValueExpression((yysemantic_stack_[(1) - (1)].double_val));
        (yyval.expression_ptr)->setLoc(yylloc);
    }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 311 "parser.yy"
    {
        (yyval.expression_ptr) = (yysemantic_stack_[(1) - (1)].expression_ptr);
        (yyval.expression_ptr)->setLoc(yylloc);
    }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 316 "parser.yy"
    {
        (yyval.expression_ptr) = (yysemantic_stack_[(1) - (1)].expression_ptr);
        (yyval.expression_ptr)->setLoc(yylloc);
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 321 "parser.yy"
    {
        (yyval.expression_ptr) = (yysemantic_stack_[(1) - (1)].function_call_ptr); // wywolanie funkcji to wyrazenie i instrukcja
        (yyval.expression_ptr)->setLoc(yylloc);
    }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 326 "parser.yy"
    {
        (yyval.expression_ptr) = (yysemantic_stack_[(3) - (2)].expression_ptr);
    }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 330 "parser.yy"
    { // NOT jest operatorem oznaczanym 'n'
        (yyval.expression_ptr) = new OperatorExpression((yysemantic_stack_[(2) - (1)].char_val), ExpressionPtr(), ExpressionPtr((yysemantic_stack_[(2) - (2)].expression_ptr)));
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 336 "parser.yy"
    {
        (yyval.function_call_ptr) = new FunctionCall(*(yysemantic_stack_[(4) - (1)].string_val), *(yysemantic_stack_[(4) - (3)].expression_ptr_list_ptr));
        // argumenty skopiowane, mozna usunac
        delete (yysemantic_stack_[(4) - (1)].string_val);
        delete (yysemantic_stack_[(4) - (3)].expression_ptr_list_ptr);
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 345 "parser.yy"
    {driver.pushExpressionPtrList();}
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 347 "parser.yy"
    {
        (yyval.expression_ptr_list_ptr) = driver.getExpressionPtrList();
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 351 "parser.yy"
    {
        (yyval.expression_ptr_list_ptr) = new ExpressionPtrList; // pusta lista wyrazen
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 357 "parser.yy"
    {
        driver.addExpression(ExpressionPtr((yysemantic_stack_[(3) - (3)].expression_ptr)));
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 361 "parser.yy"
    {
        driver.addExpression(ExpressionPtr((yysemantic_stack_[(1) - (1)].expression_ptr)));
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 367 "parser.yy"
    {
        // koniec ze wskaznikami na liste instrukcji - wyluskuje...
        (yyval.instruction_ptr) = new ConditionalInstruction(ExpressionPtr((yysemantic_stack_[(5) - (3)].expression_ptr)), *(yysemantic_stack_[(5) - (5)].instruction_ptr_list_ptr));
        //... $5 skopiowane w poprzedniej instrukcji wiec stara liste usuwam
        // malo efektywne ale inaczej sie nie da
        delete (yysemantic_stack_[(5) - (5)].instruction_ptr_list_ptr);
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 375 "parser.yy"
    {
        (yyval.instruction_ptr) = new ConditionalInstruction(ExpressionPtr((yysemantic_stack_[(7) - (3)].expression_ptr)), *(yysemantic_stack_[(7) - (5)].instruction_ptr_list_ptr), *(yysemantic_stack_[(7) - (7)].instruction_ptr_list_ptr));
        // $5, $7 skopiowane w poprzedniej instrukcji
        delete (yysemantic_stack_[(7) - (5)].instruction_ptr_list_ptr);
        delete (yysemantic_stack_[(7) - (7)].instruction_ptr_list_ptr);
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 384 "parser.yy"
    {
        (yyval.instruction_ptr) = new LoopInstruction(ExpressionPtr((yysemantic_stack_[(5) - (3)].expression_ptr)), *(yysemantic_stack_[(5) - (5)].instruction_ptr_list_ptr));
        delete (yysemantic_stack_[(5) - (5)].instruction_ptr_list_ptr);
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 391 "parser.yy"
    {
        (yyval.instruction_ptr_list_ptr) = (yysemantic_stack_[(1) - (1)].instruction_ptr_list_ptr);
    }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 395 "parser.yy"
    {
        // wynikiem jest pojedyncza instrukcja
        // tu nie trzeba umieszczac nic na poczatku stosu ani z niego zdejmowac - to tylko jedna
        // instrukcja
        InstructionPtrList *instruction = new InstructionPtrList;
        instruction->push_back(InstructionPtr((yysemantic_stack_[(1) - (1)].instruction_ptr)));
        (yyval.instruction_ptr_list_ptr) = instruction;
    }
    break;



/* Line 678 of lalr1.cc  */
#line 960 "parser.tab.cc"
	default:
          break;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[0] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
	  }
      }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[0] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (yyn != yypact_ninf_)
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[0] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval, &yylloc);

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (int yystate, int tok)
  {
    std::string res;
    YYUSE (yystate);
#if YYERROR_VERBOSE
    int yyn = yypact_[yystate];
    if (yypact_ninf_ < yyn && yyn <= yylast_)
      {
	/* Start YYX at -YYN if negative to avoid negative indexes in
	   YYCHECK.  */
	int yyxbegin = yyn < 0 ? -yyn : 0;

	/* Stay within bounds of both yycheck and yytname.  */
	int yychecklim = yylast_ - yyn + 1;
	int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
	int count = 0;
	for (int x = yyxbegin; x < yyxend; ++x)
	  if (yycheck_[x + yyn] == x && x != yyterror_)
	    ++count;

	// FIXME: This method of building the message is not compatible
	// with internationalization.  It should work like yacc.c does it.
	// That is, first build a string that looks like this:
	// "syntax error, unexpected %s or %s or %s"
	// Then, invoke YY_ on this string.
	// Finally, use the string as a format to output
	// yytname_[tok], etc.
	// Until this gets fixed, this message appears in English only.
	res = "syntax error, unexpected ";
	res += yytnamerr_ (yytname_[tok]);
	if (count < 5)
	  {
	    count = 0;
	    for (int x = yyxbegin; x < yyxend; ++x)
	      if (yycheck_[x + yyn] == x && x != yyterror_)
		{
		  res += (!count++) ? ", expecting " : " or ";
		  res += yytnamerr_ (yytname_[x]);
		}
	  }
      }
    else
#endif
      res = YY_("syntax error");
    return res;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const signed char Parser::yypact_ninf_ = -59;
  const signed char
  Parser::yypact_[] =
  {
        84,    32,     1,    29,    13,    14,    65,   -59,   -59,   -59,
     -59,    -3,   -59,   -59,     8,    43,     8,     8,    26,    30,
     -59,   -59,   -59,    46,   -59,   -59,    25,    25,     8,   -59,
     -59,   -59,    16,     9,    75,   -59,   -59,    54,     8,    35,
      58,     8,   -59,    85,     8,   -59,   -59,    59,    48,     8,
     -59,   -59,   -59,     8,    25,   -59,    81,    72,    42,    42,
      18,   -59,    77,    74,    52,   -59,    57,   -59,     9,    75,
     -59,     8,   -59,    76,   -59,    86,   -59,   -59,   -59,    98,
       8,    48,   -59,    81,    42,    42,   -59,   -59,    -1,   -59,
      41,   -59,   -59,   -59,   -59,   -59
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  Parser::yydefact_[] =
  {
         0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
      16,     0,    17,    19,     0,    45,     0,     0,     0,     0,
       1,     2,    18,    22,    37,    38,     0,     0,     0,    24,
      40,    39,     0,    30,    32,    34,    41,     0,     0,     0,
       0,     0,    20,     8,     0,    35,    43,     0,    45,     0,
      15,    28,    29,     0,     0,    44,    49,    46,    11,    11,
       0,    10,     0,     7,     0,    42,     0,    27,    31,    33,
      36,     0,    53,     0,    54,    50,    52,    21,    11,     0,
       0,    45,    25,    48,     0,    11,     6,     9,     0,    26,
       0,    14,    51,    23,    12,    13
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  Parser::yypgoto_[] =
  {
       -59,   -59,    96,   -59,   -59,   -59,    27,   -59,   -59,     2,
     -59,   -59,   -59,   -59,   -59,   -59,    -7,    55,    50,   -22,
       0,   -45,   -59,   -59,   -59,   -59,   -58
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  Parser::yydefgoto_[] =
  {
        -1,     6,     7,     8,    62,    63,    72,    73,    90,    74,
      10,    30,    31,    48,    66,    53,    32,    33,    34,    35,
      36,    37,    38,    57,    12,    13,    75
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Parser::yytable_ninf_ = -48;
  const signed char
  Parser::yytable_[] =
  {
        11,    76,     9,    67,    45,    46,    11,    49,     9,    39,
      40,    23,    24,    25,    26,    51,    18,    19,    16,    22,
      52,    47,    27,    93,    49,    28,    49,    92,    23,    24,
      25,    56,    70,    29,    60,    41,    89,    64,    50,    27,
      77,    14,    28,    49,     1,     1,    17,    43,    42,    15,
      29,     2,     2,    58,     3,     3,     4,     4,    11,    11,
      49,   -47,    94,    15,    83,    20,    49,    49,     1,    44,
     -47,    80,    55,    88,   -47,     2,    59,    65,     3,    81,
       4,     5,    54,    82,    11,    11,    91,     1,    61,    49,
      11,    71,    95,    79,     2,    78,    84,     3,    85,     4,
       5,    87,    21,    69,    68,    86
  };

  /* YYCHECK.  */
  const unsigned char
  Parser::yycheck_[] =
  {
         0,    59,     0,    48,    26,    27,     6,     8,     6,    16,
      17,     3,     4,     5,     6,     6,     3,     3,    17,    22,
      11,    28,    14,    24,     8,    17,     8,    85,     3,     4,
       5,    38,    54,    25,    41,     9,    81,    44,    22,    14,
      22,     9,    17,     8,     3,     3,    17,    17,    22,    17,
      25,    10,    10,    18,    13,    13,    15,    15,    58,    59,
       8,    18,    21,    17,    71,     0,     8,     8,     3,    23,
      22,    19,    18,    80,    26,    10,    18,    18,    13,    22,
      15,    16,     7,    26,    84,    85,    84,     3,     3,     8,
      90,    19,    90,    19,    10,    18,    20,    13,    12,    15,
      16,     3,     6,    53,    49,    78
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Parser::yystos_[] =
  {
         0,     3,    10,    13,    15,    16,    28,    29,    30,    36,
      37,    47,    51,    52,     9,    17,    17,    17,     3,     3,
       0,    29,    22,     3,     4,     5,     6,    14,    17,    25,
      38,    39,    43,    44,    45,    46,    47,    48,    49,    43,
      43,     9,    22,    17,    23,    46,    46,    43,    40,     8,
      22,     6,    11,    42,     7,    18,    43,    50,    18,    18,
      43,     3,    31,    32,    43,    18,    41,    48,    44,    45,
      46,    19,    33,    34,    36,    53,    53,    22,    18,    19,
      19,    22,    26,    43,    20,    12,    33,     3,    43,    48,
      35,    36,    53,    24,    21,    36
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  Parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,    40,    41,    44,
     123,   125,    59,   124,    92,    91,    93
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Parser::yyr1_[] =
  {
         0,    27,    28,    28,    29,    29,    30,    31,    31,    32,
      32,    34,    33,    35,    35,    36,    36,    36,    36,    36,
      37,    37,    38,    38,    40,    39,    41,    41,    42,    42,
      43,    43,    44,    44,    45,    45,    45,    46,    46,    46,
      46,    46,    46,    46,    47,    49,    48,    48,    50,    50,
      51,    51,    52,    53,    53
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     2,     1,     1,     1,     6,     1,     0,     3,
       1,     0,     4,     2,     1,     4,     1,     1,     2,     1,
       3,     5,     1,     6,     0,     4,     3,     1,     1,     1,
       1,     3,     1,     3,     1,     2,     3,     1,     1,     1,
       1,     1,     3,     2,     4,     0,     2,     0,     3,     1,
       5,     7,     5,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Parser::yytname_[] =
  {
    "$end", "error", "$undefined", "\"identyfikator\"", "\"liczba\"",
  "\"liczba ulamkowa\"", "\"znak\"", "\"operator multiplikatywny\"",
  "\"operator relacji\"", "\"operator przypisania\"", "\"if\"",
  "\"operator or\"", "\"else\"", "\"while\"", "\"not\"", "\"val\"",
  "\"defn\"", "'('", "')'", "','", "'{'", "'}'", "';'", "'|'", "'\\\\'",
  "'['", "']'", "$accept", "lista_operacji", "operacja",
  "definicja_funkcji", "lista_parametrow_formalnych",
  "lista_identyfikatorow", "blok_instrukcji", "$@1", "lista_instrukcji",
  "instrukcja", "utworzenie_zmiennej", "zmienna", "macierz", "$@2",
  "macierz_wyrazen", "op_addytywny", "wyrazenie", "wyrazenie_arytmetyczne",
  "skladnik", "czynnik", "wywolanie_funkcji", "argumenty", "$@3",
  "lista_wyrazen", "instrukcja_warunkowa", "instrukcja_petli",
  "wynik_warunku", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
        28,     0,    -1,    28,    29,    -1,    29,    -1,    30,    -1,
      36,    -1,    16,     3,    17,    31,    18,    33,    -1,    32,
      -1,    -1,    32,    19,     3,    -1,     3,    -1,    -1,    34,
      20,    35,    21,    -1,    35,    36,    -1,    36,    -1,     3,
       9,    43,    22,    -1,    37,    -1,    51,    -1,    47,    22,
      -1,    52,    -1,    15,     3,    22,    -1,    15,     3,     9,
      43,    22,    -1,     3,    -1,     3,    23,    43,    19,    43,
      24,    -1,    -1,    25,    40,    41,    26,    -1,    41,    22,
      48,    -1,    48,    -1,     6,    -1,    11,    -1,    44,    -1,
      43,     8,    44,    -1,    45,    -1,    44,    42,    45,    -1,
      46,    -1,     6,    46,    -1,    45,     7,    46,    -1,     4,
      -1,     5,    -1,    39,    -1,    38,    -1,    47,    -1,    17,
      43,    18,    -1,    14,    46,    -1,     3,    17,    48,    18,
      -1,    -1,    49,    50,    -1,    -1,    50,    19,    43,    -1,
      43,    -1,    10,    17,    43,    18,    53,    -1,    10,    17,
      43,    18,    53,    12,    53,    -1,    13,    17,    43,    18,
      53,    -1,    33,    -1,    36,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  Parser::yyprhs_[] =
  {
         0,     0,     3,     6,     8,    10,    12,    19,    21,    22,
      26,    28,    29,    34,    37,    39,    44,    46,    48,    51,
      53,    57,    63,    65,    72,    73,    78,    82,    84,    86,
      88,    90,    94,    96,   100,   102,   105,   109,   111,   113,
     115,   117,   119,   123,   126,   131,   132,   135,   136,   140,
     142,   148,   156,   162,   164
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   109,   109,   113,   119,   123,   129,   136,   141,   146,
     151,   158,   158,   167,   171,   177,   183,   188,   192,   197,
     203,   208,   215,   220,   228,   227,   235,   240,   247,   251,
     257,   261,   268,   272,   279,   283,   293,   300,   305,   310,
     315,   320,   325,   329,   335,   345,   345,   351,   356,   360,
     366,   374,   383,   390,   394
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      17,    18,     2,     2,    19,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    22,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    25,    24,    26,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    20,    23,    21,     2,     2,     2,     2,
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
      15,    16
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 105;
  const int Parser::yynnts_ = 27;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 20;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 27;

  const unsigned int Parser::yyuser_token_number_max_ = 271;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 39 "parser.yy"
} // matryca

/* Line 1054 of lalr1.cc  */
#line 1468 "parser.tab.cc"


/* Line 1056 of lalr1.cc  */
#line 403 "parser.yy"


void matryca::Parser::error(const matryca::Parser::location_type &loc, const std::string &msg)
{
    // TODO przerucic obsluge bledow do driver
    std::cerr << loc << " : " << msg << std::endl;
    exit(-1);
}


