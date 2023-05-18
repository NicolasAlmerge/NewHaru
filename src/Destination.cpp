#include "../include/Destination.hpp"
#include "hpdf.h"
using namespace pdf;


Destination::Destination(_HPDF_Array_Rec* content) noexcept: __innerContent(content) {}

bool Destination::isEmpty() const noexcept {
    return __innerContent == nullptr;
}

void Destination::setXYZ(float left, float top, float zoom) {
    HPDF_Destination_SetXYZ(__innerContent, left, top, zoom);
}

void Destination::setFit() {
    HPDF_Destination_SetFit(__innerContent);
}

void Destination::setFitH(float top) {
    HPDF_Destination_SetFitH(__innerContent, top);
}

void Destination::setFitV(float left) {
    HPDF_Destination_SetFitV(__innerContent, left);
}

void Destination::setFitR(float left, float bottom, float right, float top) {
    HPDF_Destination_SetFitR(__innerContent, left, bottom, right, top);
}

void Destination::setFitB() {
    HPDF_Destination_SetFitB(__innerContent);
}

void Destination::setFitBH(float top) {
    HPDF_Destination_SetFitBH(__innerContent, top);
}

void Destination::setFitBV(float left) {
    HPDF_Destination_SetFitBV(__innerContent, left);
}
