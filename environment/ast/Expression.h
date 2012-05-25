/**
 * Expression.h
 *
 * @class Expression
 * @brief Brief description.
 * @author nieznany
 * @date 07-05-2012
 */

#ifndef EXPRESSION_H_
#define EXPRESSION_H_

#include <boost/shared_ptr.hpp>
#include <list>
#include "../Environment.h"
#include "../exceptions/EnvironmentException.h"
#include "../data/Value.h"
#include "../../parser/location.hh"

namespace matryca
{

class Expression
{
public:
    typedef boost::shared_ptr<Expression> ExpressionPtr;
    typedef std::list<ExpressionPtr> ExpressionPtrList;
    typedef std::list<ExpressionPtrList> ExpressionPtrMatrix;
    Value execute(Environment &env)
    {
        try
        {
            return doExecute(env);
        }
        catch (EnvironmentException &e)
        {
            if(!e.captured_)
            {
                e.loc_ = loc_;
                e.captured_ = true;
                env.err_out() << "pozycja " << e.loc_ << " -- ";
                env.err_out() << e.what() << std::endl;
            }
            throw e;
        }
    }

    // inna nazwa w celu odroznienia od Instruction (konflikt bylby w FunctionCall)
    location getLoc()
    {
        return loc_;
    }

    void setLoc(location& loc)
    {
        loc_ = loc;
    }
protected:
    virtual Value doExecute(Environment &env) = 0;
    location loc_;
};

} /* namespace matryca */
#endif /* EXPRESSION_H_ */
