#ifndef __HARUPP_VALUESET_HPP__
#define __HARUPP_VALUESET_HPP__
#include "Object.hpp"

namespace pdf {

    /**
     * \class   ValueSet
     * @brief   Represents a set of values.
     * @file    ValueSet.hpp
     * @author  Nicolas Almerge
     * @date    2023-05-16
    */
    class ValueSet: public Object {
        unsigned int value = 0U;
        explicit ValueSet(unsigned int v) noexcept;
        explicit ValueSet() noexcept;
        friend class CompressionMode;
        friend class Permissions;
        friend class ViewerPreferences;
        friend class Document;

    public:
        virtual ~ValueSet() noexcept = 0;

        /**
         * @brief  Checks whether the value set contain no elements.
         * @return `true` if no elements are present, `false` otherwise.
        */
        bool isEmpty() const noexcept override final;
    };
}

#endif // __HARUPP_VALUESET_HPP__
