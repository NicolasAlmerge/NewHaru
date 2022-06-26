#include "../include/RGBColor.hpp"
using namespace pdf;


RGBColor::RGBColor(_HPDF_RGBColor&& rgbColor): innerContent(rgbColor) {}

RGBColor::RGBColor(): RGBColor(_HPDF_RGBColor({0.f, 0.f, 0.f})) {}

RGBColor::RGBColor(float r, float g, float b): RGBColor(_HPDF_RGBColor({r, g, b})) {}

bool RGBColor::isEmpty() const {
    return (
        innerContent.r == 0.f &&
        innerContent.g == 0.f &&
        innerContent.b == 0.f
    );
}

float RGBColor::getR() const {
    return innerContent.r;
}

float RGBColor::getG() const {
    return innerContent.g;
}

float RGBColor::getB() const {
    return innerContent.b;
}

void RGBColor::setR(float value) {
    innerContent.r = value;
}

void RGBColor::setG(float value) {
    innerContent.g = value;
}

void RGBColor::setB(float value) {
    innerContent.b = value;
}
