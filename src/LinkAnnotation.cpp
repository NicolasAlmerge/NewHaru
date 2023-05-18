#include "../include/LinkAnnotation.hpp"
#include "hpdf.h"
using namespace pdf;


LinkAnnotation::LinkAnnotation(_HPDF_Dict_Rec* content) noexcept: Annotation(content) {}

void LinkAnnotation::setHighlightMode(AnnotationHighlightMode mode) {
    HPDF_LinkAnnot_SetHighlightMode(__innerContent, (HPDF_AnnotHighlightMode) mode);
}

void LinkAnnotation::setBorderStyle(float width, unsigned short dashOn, unsigned short dashOff) {
    HPDF_LinkAnnot_SetBorderStyle(__innerContent, width, dashOn, dashOff);
}
