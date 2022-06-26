#pragma once
#include "Annotation.hpp"


namespace pdf {
    class PdfPage;

    class TextAnnotation: public Annotation {
        TextAnnotation(const HPDF_Annotation destination);
        friend class PdfPage;

    public:
        void setIcon(AnnotationIcon icon);
        void setOpened(bool open);
    };
}
