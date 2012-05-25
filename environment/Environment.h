/**
 * Environment.h
 *
 * @class Environment
 * @brief Brief description.
 * @author nieznany
 * @date 06-05-2012
 */

// TODO znalezc pomysl jak trzymac wartosc value_ w variableDescriptor
// mozliwe ze variant, ale moze byc zly to pomysl (ciezko dowiedziec sie o typie w czasie wykonania)

// TODO zrobic proste expr, zeby mozna bylo w koncu przetestowac dzialanie tego gowna
#ifndef ENVIRONMENT_H_
#define ENVIRONMENT_H_

#include <string>
#include <boost/shared_ptr.hpp>
#include <iostream>

#include "descriptor/SymbolDescriptor.h"

namespace matryca
{

class Environment
{
public:
    /** Identyfikator symbolu */
    typedef boost::shared_ptr<Environment> EnvironmentPtr;
    typedef SymbolDescriptor::SymbolID SymbolID;
    typedef SymbolDescriptor::SymbolDescPtr SymbolDescPtr;


    virtual std::ostream& out() = 0;
    virtual std::ostream& err_out() = 0;
    /**
     * Wykonuje funkcje o podanym id.
     *
     * @param id - id funkcji
     */
    void execute(const SymbolID &id)
    {
        doExecute(id);
    }

    /**
     * Umieszcza symbol o podanym id i deskryptorze
     * w tablicy na szczycie stosu.
     *
     * @param desc_ptr - deskryptor nowego symbolu
     */
    void addLocal(SymbolDescPtr desc_ptr)
    {
        doAddLocal(desc_ptr);
    }

    /**
     * Zwraca wskaznik do deskryptora symbolu.
     * @param id
     * @return
     */
    SymbolDescPtr findLocal(const SymbolID &id)
    {
        return doFindLocal(id);
    }

    // analogicznie globalne
    void addGlobal(SymbolDescPtr desc_ptr)
    {
        doAddGlobal(desc_ptr);
    }

    SymbolDescPtr findGlobal(const SymbolID &id)
    {
        return doFindGlobal(id);
    }

    SymbolDescPtr find(const SymbolID &id)
    {
        return doFind(id);
    }

    void add(SymbolDescPtr desc_ptr)
    {
        doAdd(desc_ptr);
    }

    void pushSymbolTable()
    {
        doPushSymbolTable();
    }

    void popSymbolTable()
    {
        doPopSymbolTable();
    }


protected:
    virtual void doExecute(const SymbolID &) = 0;
    virtual void doAddLocal(SymbolDescPtr) = 0;
    virtual SymbolDescPtr doFindLocal(const SymbolID &) = 0;
    virtual void doAddGlobal(SymbolDescPtr) = 0;
    virtual SymbolDescPtr doFindGlobal(const SymbolID &) = 0;

    /** Szuka w obecnym zakresie, jezeli nie znajdzie, to szuka
     *  w zakresie globalnym
     *
     * @param id - szukany symbol
     * @return
     */
    virtual SymbolDescPtr doFind(const SymbolID &) = 0;
    virtual void doAdd(SymbolDescPtr desc_ptr) = 0;

    virtual void doPopSymbolTable() = 0;
    virtual void doPushSymbolTable() = 0;

};

} /* namespace matryca */
#endif /* ENVIRONMENT_H_ */
