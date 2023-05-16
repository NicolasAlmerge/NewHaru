#ifndef __HARUPP_ANNOTATION_HPP__
#define __HARUPP_ANNOTATION_HPP__
#include "PdfObject.hpp"
#include "Constants.hpp"
#include "ContentStream.hpp"
#include "hpdf.h"

namespace pdf {

    /**
     * \class  Annotation
     * @brief  Represents a pdf annotation.
     * @file   Annotation.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class Annotation: public ContentStream {
        Annotation(const HPDF_Annotation destination);
        friend class LinkAnnotation;
        friend class TextAnnotation;

    public:
        virtual ~Annotation() = 0;

        /**
         * @brief Sets the border style.
         * @param style     Border style to use.
         * @param width     Border width to use.
         * @param dashOn    Dash on size.
         * @param dashOff   Dash off size.
         * @param dashPhase Dash phase size.
        */
        virtual void setBorderStyle(BorderStyle style, float width, unsigned short dashOn, unsigned short dashOff, unsigned short dashPhase) final;
    };
}

#endif // __HARUPP_ANNOTATION_HPP__
