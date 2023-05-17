#ifndef __HARUPP_LINKANNOTATION_HPP__
#define __HARUPP_LINKANNOTATION_HPP__
#include "Annotation.hpp"

namespace pdf {

    /**
     * \class  LinkAnnotation
     * @brief  Represents a pdf link annotation.
     * @file   LinkAnnotation.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class LinkAnnotation final: public Annotation {
        explicit LinkAnnotation(const HPDF_Annotation destination);
        friend class PdfPage;

    public:

        /**
         * @brief Sets the highlight mode.
         * @param mode Highlight mode to use.
        */
        void setHighlightMode(AnnotationHighlightMode mode);

        /**
         * @brief Sets the border style.
         * @param width     Border width to use.
         * @param dashOn    Dash on size.
         * @param dashOff   Dash off size.
        */
        void setBorderStyle(float width, unsigned short dashOn, unsigned short dashOff);
    };
}

#endif // __HARUPP_LINKANNOTATION_HPP__
