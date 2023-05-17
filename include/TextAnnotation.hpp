#ifndef __HARUPP_TEXTANNOTATION_HPP__
#define __HARUPP_TEXTANNOTATION_HPP__
#include "Annotation.hpp"

namespace pdf {

    /**
     * \class  TextAnnotation
     * @brief  Represents a pdf text annotation.
     * @note   Note that this class cannot be instantiated manually. Rather, it is created when calling PdfPage::createTextAnnotation.
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
        void setOpen(bool open);
    };
}

#endif // __HARUPP_TEXTANNOTATION_HPP__
