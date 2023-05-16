#ifndef __HARUPP_TEXTANNOTATION_HPP__
#define __HARUPP_TEXTANNOTATION_HPP__
#include "Annotation.hpp"

namespace pdf {
    class TextAnnotation final: public Annotation {
        TextAnnotation(const HPDF_Annotation destination);
        friend class PdfPage;

    public:
        void setIcon(AnnotationIcon icon);
        void setOpened(bool open);
    };
}

#endif // __HARUPP_TEXTANNOTATION_HPP__
