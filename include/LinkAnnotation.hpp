#ifndef __HARUPP_LINKANNOTATION_HPP__
#define __HARUPP_LINKANNOTATION_HPP__
#include "Annotation.hpp"

namespace pdf {
    class LinkAnnotation final: public Annotation {
        LinkAnnotation(const HPDF_Annotation destination);
        friend class PdfPage;

    public:
        void setHighlightMode(AnnotationHighlightMode mode);
        void setBorderStyle(float width, unsigned short dashOn, unsigned short dashOff);
    };
}

#endif // __HARUPP_LINKANNOTATION_HPP__
