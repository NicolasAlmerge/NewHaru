#ifndef __HARUPP_COLOR_HPP__
#define __HARUPP_COLOR_HPP__
#include "PdfObject.hpp"

namespace pdf {
    class RGBColor;
    class CMYKColor;

    /**
     * \class  Color
     * @brief  Represents a color.
     * @file   Color.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class Color: public PdfObject {
    public:
        virtual ~Color() = 0;

        /**
         * @brief  Converts the color to an RGBColor.
         * @see    RGBColor
         * @return RGBColor representation of the color.
        */
        virtual RGBColor toRGB() const noexcept = 0;

        /**
         * @brief  Converts the color to an CMYKColor.
         * @see    CMYKColor
         * @return CMYKColor representation of the color.
        */
        virtual CMYKColor toCMYK() const noexcept = 0;

        /**
         * @brief   Checks whether two colors are equal.
         * @return `true` if the colors are equal, `false` otherwise.
        */
        virtual bool operator==(const Color& other) const noexcept = 0;

        /**
         * @brief   Checks whether two colors are not equal.
         * @details This is equivalent to `!operator==(other)`.
         * @return `true` if the colors are not equal, `false` otherwise.
        */
        virtual bool operator!=(const Color& other) const noexcept final;
    };
}

#endif // __HARUPP_COLOR_HPP__
