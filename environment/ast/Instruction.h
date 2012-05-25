/**
 * Instruction.h
 *
 * @class Instruction
 * @brief Brief description.
 * @author nieznany
 * @date 06-05-2012
 */

#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

#include <boost/shared_ptr.hpp>
#include <list>
#include <iostream>
#include "../Environment.h"
#include "../data/Value.h"
#include "../../parser/location.hh"

namespace matryca
{
class Instruction
{
public:
    typedef boost::shared_ptr<Instruction> InstructionPtr;
    typedef std::list<InstructionPtr> InstructionPtrList;

    /**
     * Wykonuje dana funkcje w kontekscie podanego interpretera.
     *
     * @param interpreter
     * TODO te zwracanie int dla instrukcji na razie potrzebne, gdyz
     * inaczej ciezko jest wygodnie zrobic FunctionCall, zawsze wynik
     * mozna zignorowac (jak ktos jego uzyje to jego sprawa, moze
     * to byc cokolwiek nic nie wartosciowego).
     */
    Value execute(Environment &env)
    {
        try
        {
//            std::cout << "pozycja: " << loc_ << std::endl;
            return doExecute(env);
        }
        catch (EnvironmentException& e)
        {
            if(!e.captured_)
            {
                e.loc_ = loc_; // podpiecie pozycji gdzie byl blad
                e.captured_ = true; // juz przechwycone, dalej nie zmieniaj juz loc_
                env.err_out() << "pozycja " << e.loc_ << " -- ";
                env.err_out() << e.what() << std::endl;
            }
            throw e; // i przekaz dalej
        }
    }

    void setLocation(location& l)
    {
        loc_ = l;
    }

    location getLocation()
    {
        return loc_;
    }
protected:
    virtual Value doExecute(Environment &interpreter) = 0;
    location loc_;
};

} /* namespace matryca */
#endif /* INSTRUCTION_H_ */
