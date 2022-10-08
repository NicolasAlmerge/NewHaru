#include "../include/CMYKColor.hpp"
#include "../include/RGBColor.hpp"
using namespace pdf;


CMYKColor::CMYKColor(_HPDF_CMYKColor&& cmykColor): innerContent(cmykColor) {}

CMYKColor::CMYKColor(): CMYKColor(_HPDF_CMYKColor({0.f, 0.f, 0.f, 0.f})) {}

CMYKColor::CMYKColor(float c, float m, float y, float k): CMYKColor(_HPDF_CMYKColor({c, m, y, k})) {}

bool CMYKColor::isEmpty() const {
    return (
        innerContent.c == 0.f &&
        innerContent.m == 0.f &&
        innerContent.y == 0.f &&
        innerContent.k == 0.f
    );
}

float CMYKColor::getC() const {
    return innerContent.c;
}

float CMYKColor::getM() const {
    return innerContent.m;
}

float CMYKColor::getY() const {
    return innerContent.y;
}

float CMYKColor::getK() const {
    return innerContent.k;
}

void CMYKColor::setC(float value) {
    innerContent.c = value;
}

void CMYKColor::setM(float value) {
    innerContent.m = value;
}

void CMYKColor::setY(float value) {
    innerContent.y = value;
}

void CMYKColor::setK(float value) {
    innerContent.k = value;
}

RGBColor CMYKColor::toRGB() const {
    const float K = 255.f*(1.f-getK());
    return RGBColor((1.f-getC())*K, (1.f-getM())*K, (1.f-getY())*K);
}
