#include "../include/TextAnnotation.hpp"
#include "hpdf.h"
using namespace pdf;


TextAnnotation::TextAnnotation(_HPDF_Dict_Rec* content) noexcept: Annotation(content) {}

void TextAnnotation::setIcon(AnnotationIcon icon) {
    HPDF_TextAnnot_SetIcon(__innerContent, (HPDF_AnnotIcon) icon);
}

void TextAnnotation::setOpen(bool open) {
    HPDF_TextAnnot_SetOpened(__innerContent, open);
}
