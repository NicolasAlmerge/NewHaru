#pragma once
#include "Annotation.hpp"


namespace pdf {
    class PdfPage;
    class LinkAnnotation: public Annotation {
        LinkAnnotation(const HPDF_Annotation destination);
        friend class PdfPage;

    public:
        void setHighlightMode(AnnotationHighlightMode mode);
        void setBorderStyle(float width, unsigned short dashOn, unsigned short dashOff);
    };
}
