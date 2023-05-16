#ifndef __HARUPP_ANNOTATION_HPP__
#define __HARUPP_ANNOTATION_HPP__
#include "PdfObject.hpp"
#include "Constants.hpp"
#include "ContentStream.hpp"
#include "hpdf.h"

namespace pdf {
    class Annotation: public ContentStream {
        Annotation(const HPDF_Annotation destination);
        friend class LinkAnnotation;
        friend class TextAnnotation;

    public:
        virtual ~Annotation() = 0;
        void setBorderStyle(BorderStyle style, float width, unsigned short dashOn, unsigned short dashOff, unsigned short dashPhase);
    };
}

#endif // __HARUPP_ANNOTATION_HPP__
