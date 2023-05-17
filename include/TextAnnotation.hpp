#ifndef __HARUPP_TEXTANNOTATION_HPP__
#define __HARUPP_TEXTANNOTATION_HPP__
#include "Annotation.hpp"

namespace pdf {

    /**
     * \class  TextAnnotation
     * @brief  Represents a pdf text annotation.
     * @file   TextAnnotation.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class TextAnnotation final: public Annotation {
        explicit TextAnnotation(const HPDF_Annotation destination);
        friend class PdfPage;

    public:

        /**
         * @brief Sets the annotation icon.
         * @param icon Icon to use.
        */
        void setIcon(AnnotationIcon icon);

        /**
         * @brief Sets the annotation initial open / close state.
         * @param open Whether the annotation should be open (`true`) or closed (`false`) initially.
        */
        void setOpened(bool open);
    };
}

#endif // __HARUPP_TEXTANNOTATION_HPP__
