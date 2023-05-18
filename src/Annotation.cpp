#include "../include/Annotation.hpp"
#include "hpdf.h"
using namespace pdf;


Annotation::Annotation(_HPDF_Dict_Rec* destination) noexcept: ContentStream(destination) {}

Annotation::~Annotation() noexcept {}

void Annotation::setBorderStyle(enums::BorderStyle style, float width, unsigned short dashOn, unsigned short dashOff, unsigned short dashPhase) {
    HPDF_Annotation_SetBorderStyle(__innerContent, (HPDF_BSSubtype) style, width, dashOn, dashOff, dashPhase);
}
