/**
 * EnvironmentImpl.h
 *
 * @class EnvironmentImpl
 * @brief Brief description.
 * @author nieznany
 * @date 06-05-2012
 */

#ifndef ENVIRONMENTIMPL_H_
#define ENVIRONMENTIMPL_H_

#include <boost/unordered_map.hpp>
#include <boost/shared_ptr.hpp>
#include <iostream>
#include <vector>
#include "Environment.h"

namespace matryca
{

/**
 * Implementacja Environmenta.
 */
class EnvironmentImpl: public Environment
{
public:
    /** Tablica symboli **/
    typedef boost::unordered_map<SymbolID, SymbolDescPtr> SymbolTable;
    typedef boost::shared_ptr<SymbolTable> SymbolTablePtr;
    typedef std::vector<SymbolTablePtr> SymbolTableStack;

    EnvironmentImpl(SymbolTablePtr global, std::ostream &out, std::ostream &err);
    virtual ~EnvironmentImpl();
    std::ostream& out()
    {
        return out_;
    }

    std::ostream& err_out()
    {
        return errOut_;
    }
private:
    void doExecute(const SymbolID & id);
    /**
     * Ustawia na szczycie stosu zakresow lokalnych podana tablice symboli
     *
     * @param table
     */
    void doPushSymbolTable();
    /** usuwa ze szczytu stosu tablice symboli **/
    void doPopSymbolTable();
    /** dodaje do tablicy ze szczytu stosu nowy deskryptor symbolu **/
    void doAddLocal(SymbolDescPtr desc_ptr);
    /** szuka na szczycie stosu symbolu o podanym id **/
    SymbolDescPtr doFindLocal(const SymbolID &id);
    // to samo dla globalnej
    void doAddGlobal(SymbolDescPtr desc_ptr);
    SymbolDescPtr doFindGlobal(const SymbolID &id);
    // poszukuje najpierw na szczycie stosu zakresow lokalnych, nastepnie zakres globalny
    SymbolDescPtr doFind(const SymbolID &id);
    // najpierw probuje dodac na zakres lokalny - jezeli takiego brak, to dodaje (zamienia
    // istniejacy symbol) do zakresu globalnego
    void doAdd(SymbolDescPtr desc_ptr);

    SymbolTablePtr global_;
    SymbolTableStack local_;
    std::ostream &out_;
    /** Gdzie wypisywac bledy */
    std::ostream &errOut_;
};

} /* namespace matryca */
#endif /* ENVIRONMENTIMPL_H_ */
