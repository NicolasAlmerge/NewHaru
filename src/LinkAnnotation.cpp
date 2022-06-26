#include "../include/LinkAnnotation.hpp"
using namespace pdf;


LinkAnnotation::LinkAnnotation(const HPDF_Annotation destination): Annotation(destination) {}

void LinkAnnotation::setHighlightMode(AnnotationHighlightMode mode) {
    HPDF_LinkAnnot_SetHighlightMode(innerContent, (HPDF_AnnotHighlightMode) mode);
}

void LinkAnnotation::setBorderStyle(float width, unsigned short dashOn, unsigned short dashOff) {
    HPDF_LinkAnnot_SetBorderStyle(innerContent, width, dashOn, dashOff);
}
