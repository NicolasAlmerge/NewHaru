#ifndef __HARUPP_COLOR_HPP__
#define __HARUPP_COLOR_HPP__
#include "PdfObject.hpp"

namespace pdf {
    class LinkAnnotation;
    class TextAnnotation;

    class Color: public PdfObject {
    public:
        virtual ~Color() = 0;
    };
}

#endif // __HARUPP_COLOR_HPP__
