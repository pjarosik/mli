/**
 * MatrycaScanner.h
 *
 * @class MatrycaScanner
 * @brief Brief description.
 * @author Piotr Jarosik
 * @date 05-05-2012
 */

#ifndef SCANNER_H_
#define SCANNER_H_
// includy potrzebne dla unii pliku parser.yy
#include "../environment/ast/Instruction.h"
#include "../environment/ast/Expression.h"
#include "../environment/ast/FunctionCall.h"
#include "../environment/descriptor/FunctionDescriptor.h"
#include "../parser/parser.tab.hh"

#ifndef yyFlexLexerOnce // zeby scanner.ll nie deklaraowal po raz drugi yyFlexLexer
#include <FlexLexer.h>
#endif

// przedefinioniowanie yylex dla parsera
#undef YY_DECL
#define YY_DECL int matryca::Scanner::yylex(Parser::semantic_type *yylval, Parser::location_type *yylloc)

namespace matryca
{
class Scanner: public yyFlexLexer
{
public:
    Scanner(std::istream *in, std::ostream *out) :
            yyFlexLexer(in, out)
    {
    }
    virtual ~Scanner()
    {
    }
    virtual int yylex(Parser::semantic_type *yylval, Parser::location_type* yylloc);
};
}

#endif /* SCANNER_H_ */
