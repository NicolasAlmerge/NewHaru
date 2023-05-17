#include "../include/Annotation.hpp"
using namespace pdf;


Annotation::Annotation(const HPDF_Annotation destination): ContentStream(destination) {}

Annotation::~Annotation() noexcept {}

void Annotation::setBorderStyle(BorderStyle style, float width, unsigned short dashOn, unsigned short dashOff, unsigned short dashPhase) {
    HPDF_Annotation_SetBorderStyle(innerContent, (HPDF_BSSubtype) style, width, dashOn, dashOff, dashPhase);
}
