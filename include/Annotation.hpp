#pragma once
#include "PdfObject.hpp"
#include "Constants.hpp"
#include "ContentStream.hpp"


namespace pdf {
    class LinkAnnotation;
    class TextAnnotation;

    class Annotation: public ContentStream {
        Annotation(const HPDF_Annotation destination);
        friend class LinkAnnotation;
        friend class TextAnnotation;

    public:
        virtual ~Annotation() = 0;
        void setBorderStyle(BorderStyle style, float width, unsigned short dashOn, unsigned short dashOff, unsigned short dashPhase);
    };
}
