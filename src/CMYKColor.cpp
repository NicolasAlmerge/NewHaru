#include "../include/CMYKColor.hpp"
#include "../include/RGBColor.hpp"
using namespace pdf;


CMYKColor::CMYKColor(HPDF_CMYKColor&& cmykColor): innerContent(cmykColor) {}

CMYKColor::CMYKColor() noexcept: CMYKColor(HPDF_CMYKColor({0.f, 0.f, 0.f, 0.f})) {}

CMYKColor::CMYKColor(float c, float m, float y, float k) noexcept: CMYKColor(HPDF_CMYKColor({c, m, y, k})) {}

bool CMYKColor::isEmpty() const noexcept {
    return false;
}

float CMYKColor::getC() const noexcept {
    return innerContent.c;
}

float CMYKColor::getM() const noexcept {
    return innerContent.m;
}

float CMYKColor::getY() const noexcept {
    return innerContent.y;
}

float CMYKColor::getK() const noexcept {
    return innerContent.k;
}

RGBColor CMYKColor::toRGB() const noexcept {
    const float K = 255.f*(1.f-getK());
    return RGBColor((1.f-getC())*K, (1.f-getM())*K, (1.f-getY())*K);
}

CMYKColor CMYKColor::toCMYK() const noexcept {
    return CMYKColor(innerContent.c, innerContent.m, innerContent.y, innerContent.k);
}

const CMYKColor CMYKColor::WHITE(0, 0, 0, 0);
const CMYKColor CMYKColor::BLACK(0, 0, 0, 1);
const CMYKColor CMYKColor::RED(0, 1, 1, 0);
const CMYKColor CMYKColor::GREEN(1, 0, 1, 0);
const CMYKColor CMYKColor::BLUE(1, 1, 0, 0);
const CMYKColor CMYKColor::CYAN(1, 0, 0, 0);
const CMYKColor CMYKColor::MAGENTA(0, 1, 0, 0);
const CMYKColor CMYKColor::YELLOW(0, 0, 1, 0);
const CMYKColor CMYKColor::GRAY(0, 0, 0, 0.5);
