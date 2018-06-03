#ifndef CRTP_H
#define CRTP_H

/**
 * Base class for Curiously Reccuring Template Pattern (CRTP).
 *
 * The Curiously Recurring Template Pattern (CRTP) is a C++ idiom whose name
 * was coined by James Coplien in 1995, in early C++ template code.
 *
 * The CRTP consists in:
 *     - inheriting from a template class,
 *     - use the derived class itself as a template parameter of the base class.
 *
 * This is what it looks like in code:
 *
 * template <typename T>
 * class Base
 * {
 *     ...
 * };
 *
 * class Derived : public Base<Derived>
 * {
 *     ...
 * };
 *
 * The purpose of doing this is using the derived class in the base class. From
 * the perspective of the base object, the derived object is itself, but
 * downcasted. Therefore the base class can access the derived class by
 * static_casting itself into the derived class.
 *
 * Writing repeated static_cast's in CRTP base classes quickly becomes
 * cumbersome, as it does not add much meaning to the code. It would be nice to
 * factor out these static_cast's. This can be achieved by forwarding the
 * underlying type to a higher hierarchy level. It also deals with the case
 * where the underlying object is const
 */
template <typename T>
struct crtp
{
    /**
     * Helper for CRTP to avoid repeating static_cast on derived type.
     *
     * This overload is made to return a reference to the derived type.
     */
    T& underlying();

    /**
     * Helper for CRTP to avoid repeating static_cast on derived type.
     *
     * This overload is made to return a constant reference to the derived type.
     */
    T const& underlying() const;
};

#include "crtp_impl.h"

#endif // CRTP_H
