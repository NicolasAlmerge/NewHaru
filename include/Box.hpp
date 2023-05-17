#ifndef __HARUPP_BOX_HPP__
#define __HARUPP_BOX_HPP__
#include "PdfObject.hpp"
#include "hpdf.h"

namespace pdf {

    /**
     * \class  Box
     * @brief  Represents a pdf box.
     * @file   Box.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class Box final: public PdfObject {
        HPDF_Box innerContent;
        explicit Box(HPDF_Box&& box);
        friend class Font;
        friend class PdfPage;

    public:
        /**
         * @brief Creates an empty box.
        */
        Box() noexcept;

        /**
         * @brief Creates a box from coordinates.
         * @param left   Left value.
         * @param bottom Bottom value.
         * @param right  Right value.
         * @param top    Top value.
        */
        Box(float left, float bottom, float right, float top) noexcept;

        /**
         * @brief Checks whether the box is empty.
         * @return `true` if all coordinates are 0, `false` otherwise.
        */
        bool isEmpty() const noexcept override;

        /**
         * @brief Gets the left component.
         * @return Left component.
        */
        float getLeft() const noexcept;

        /**
         * @brief Gets the bottom component.
         * @return Bottom component.
        */
        float getBottom() const noexcept;

        /**
         * @brief Gets the right component.
         * @return Right component.
        */
        float getRight() const noexcept;

        /**
         * @brief Gets the top component.
         * @return Top component.
        */
        float getTop() const noexcept;
    };
}

#endif // __HARUPP_BOX_HPP__
