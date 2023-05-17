#include "../include/TextAnnotation.hpp"
using namespace pdf;


TextAnnotation::TextAnnotation(const HPDF_Annotation destination): Annotation(destination) {}

void TextAnnotation::setIcon(AnnotationIcon icon) {
    HPDF_TextAnnot_SetIcon(innerContent, (HPDF_AnnotIcon) icon);
}

void TextAnnotation::setOpen(bool open) {
    HPDF_TextAnnot_SetOpened(innerContent, open);
}
