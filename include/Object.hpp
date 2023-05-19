#ifndef __HARUPP_OBJECT_HPP__
#define __HARUPP_OBJECT_HPP__

/// Represents the Haru++ namespace.
namespace pdf {

    /**
     * \class  Object
     * @brief  Represents a pdf object.
     * @file   Object.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class Object {
    public:
        virtual ~Object() noexcept = 0;

        /**
         * @brief  Checks whether the object is empty.
         * @return `true` if object is empty, `false` otherwise.
        */
        virtual bool isEmpty() const noexcept = 0;

        /**
         * @brief   Checks whether the object is not empty.
         * @details This is equivalent to: `!isEmpty()`.
         * @return `true` if object is not empty, `false` otherwise.
        */
        virtual operator bool() const noexcept final;
    };
}

#endif // __HARUPP_OBJECT_HPP__
