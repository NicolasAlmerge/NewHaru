#pragma once
#include "PdfObject.hpp"


namespace pdf {
    class LinkAnnotation;
    class TextAnnotation;

    class Color: public PdfObject {
    public:
        virtual ~Color() = 0;
    };
}
