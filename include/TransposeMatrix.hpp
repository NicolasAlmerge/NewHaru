#ifndef __HARUPP_TRANSPOSEMATRIX_HPP__
#define __HARUPP_TRANSPOSEMATRIX_HPP__
#include "Object.hpp"

namespace pdf {

    /**
     * \class  TransposeMatrix
     * @brief  Represents a transpose matrix.
     * @file   TransposeMatrix.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class TransposeMatrix final: public Object {
        float a = 0.f;
        float b = 0.f;
        float c = 0.f;
        float d = 0.f;
        float x = 0.f;
        float y = 0.f;

    public:

        /**
         * @brief   Creates a new empty TransposeMatrix.
         * @details This is equivalent to `TransposeMatrix(0, 0, 0, 0, 0, 0)`.
        */
        TransposeMatrix() noexcept;

        /**
         * @brief Creates a new TransposeMatrix with coordinates.
         * @param a A coordinate.
         * @param b B coordinate.
         * @param c C coordinate.
         * @param d D coordinate.
         * @param x X coordinate.
         * @param y Y coordinate.
        */
        TransposeMatrix(float a, float b, float c, float d, float x, float y) noexcept;

        /**
         * @brief Checks whether the matrix is empty.
         * @return `true` if all coordinates are `0.0`, `false` otherwise.
        */
        bool isEmpty() const noexcept override;

        /**
         * @brief  Gets the A coordinate.
         * @return A coordinate.
        */
        float getA() const noexcept;

        /**
         * @brief  Gets the B coordinate.
         * @return B coordinate.
        */
        float getB() const noexcept;

        /**
         * @brief  Gets the C coordinate.
         * @return C coordinate.
        */
        float getC() const noexcept;

        /**
         * @brief  Gets the D coordinate.
         * @return D coordinate.
        */
        float getD() const noexcept;

        /**
         * @brief  Gets the X coordinate.
         * @return X coordinate.
        */
        float getX() const noexcept;

        /**
         * @brief  Gets the Y coordinate.
         * @return Y coordinate.
        */
        float getY() const noexcept;
    };
}

#endif // __HARUPP_TRANSPOSEMATRIX_HPP__
