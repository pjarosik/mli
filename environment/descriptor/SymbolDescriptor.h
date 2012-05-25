/**
 * SymbolDescriptor.h
 *
 * @class SymbolDescriptor
 * @brief Brief description.
 * @author nieznany
 * @date 06-05-2012
 */

#ifndef SYMBOLDESCRIPTOR_H_
#define SYMBOLDESCRIPTOR_H_
#include <boost/shared_ptr.hpp>
#include <string>

namespace matryca
{

class SymbolDescriptor
{
public:
    /** Identyfikator symbolu */
    typedef std::string SymbolID;
    typedef boost::shared_ptr<SymbolDescriptor> SymbolDescPtr;

    /** Rodzaje deskryptorow - enum po to, aby uniknac
     *  dynamic_cast w celu ustalenia rodzaju deskryptora.
     */
    enum Type {FUNCTION, VARIABLE}; // dynamic_cast is bad and slow...

    /** zwraca typ uzytej klasy */
    virtual Type getType() const = 0;

    virtual SymbolID getSymbol() const = 0;
};

} /* namespace matryca */
#endif /* SYMBOLDESCRIPTOR_H_ */
