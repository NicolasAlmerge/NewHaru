#ifndef __HARUPP_COLOR_HPP__
#define __HARUPP_COLOR_HPP__
#include "PdfObject.hpp"

namespace pdf {
    class RGBColor;
    class CMYKColor;

    struct Color: public PdfObject {
        virtual ~Color() = 0;
        virtual RGBColor toRGB() const = 0;
        virtual CMYKColor toCMYK() const = 0;
    };
}

#endif // __HARUPP_COLOR_HPP__
