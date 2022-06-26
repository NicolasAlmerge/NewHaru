#include "../include/Destination.hpp"
using namespace pdf;


Destination::Destination(const HPDF_Destination destination): innerContent(destination) {}

bool Destination::isEmpty() const {
    return innerContent == nullptr;
}

void Destination::setXYZ(float left, float top, float zoom) {
    HPDF_Destination_SetXYZ(innerContent, left, top, zoom);
}

void Destination::setFit() {
    HPDF_Destination_SetFit(innerContent);
}

void Destination::setFitH(float top) {
    HPDF_Destination_SetFitH(innerContent, top);
}

void Destination::setFitV(float left) {
    HPDF_Destination_SetFitV(innerContent, left);
}

void Destination::setFitR(float left, float bottom, float right, float top) {
    HPDF_Destination_SetFitR(innerContent, left, bottom, right, top);
}

void Destination::setFitB() {
    HPDF_Destination_SetFitB(innerContent);
}

void Destination::setFitBH(float top) {
    HPDF_Destination_SetFitBH(innerContent, top);
}

void Destination::setFitBV(float top) {
    HPDF_Destination_SetFitBV(innerContent, top);
}
