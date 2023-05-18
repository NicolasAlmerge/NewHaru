#ifndef __HARUPP_COOR2D_HPP__
#define __HARUPP_COOR2D_HPP__
#include "PdfObject.hpp"

namespace pdf {

    /**
     * \class  Coor2D
     * @brief  Represents 2D coordinates.
     * @file   Coor2D.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class Coor2D final: public PdfObject {
        float x = 0.f;
        float y = 0.f;

    public:

        /**
         * @brief Creates a new empty Coor2D.
         * @details This is equivalent to `Coor2D(0, 0)`.
        */
        Coor2D() noexcept;

        /**
         * @brief Creates a new Coor2D with given coordinates.
         * @param x X coordinate.
         * @param y Y coordinate.
        */
        Coor2D(float x, float y) noexcept;

        /**
         * @brief Always returns `false`.
         * @return `false`
        */
        bool isEmpty() const noexcept override;

        /**
         * @brief  Gets the X coordinate.
         * @return X coordinate.
        */
        float getX() const noexcept;

        /**
         * @brief  Gets the Y coordinate.
         * @return X coordinate.
        */
        float getY() const noexcept;
    };
}

#endif // __HARUPP_COOR2D_HPP__
