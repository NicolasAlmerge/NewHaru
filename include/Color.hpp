#ifndef __HARUPP_COLOR_HPP__
#define __HARUPP_COLOR_HPP__
#include "PdfObject.hpp"

namespace pdf {
    class RGBColor;
    class CMYKColor;

    struct Color: public PdfObject {
        virtual ~Color() = 0;
        virtual RGBColor toRGB() const noexcept = 0;
        virtual CMYKColor toCMYK() const noexcept = 0;

        virtual bool operator==(const Color& other) const noexcept = 0;
        virtual bool operator!=(const Color& other) const noexcept final;
    };
}

#endif // __HARUPP_COLOR_HPP__
