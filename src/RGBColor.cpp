#include "../include/RGBColor.hpp"
#include "../include/CMYKColor.hpp"
using namespace pdf;


#define MIN(a, b) ((a < b)? a: b)
#define MAX(a, b) ((a < b)? b: a)

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

RGBColor RGBColor::toRGB() const {
    return RGBColor(innerContent.r, innerContent.g, innerContent.b);
}

CMYKColor RGBColor::toCMYK() const {
    const float R = getR() / 255.f;
    const float G = getG() / 255.f;
    const float B = getB() / 255.f;
    const float _maxGB = MAX(G, B);
    const float K = 1.f - MAX(R, _maxGB);
    const float invK = 1.f - K;
    return CMYKColor((1-R-K)/invK, (1-G-K)/invK, (1-B-K)/invK, K);
}

const RGBColor RGBColor::WHITE(1, 1, 1);
const RGBColor RGBColor::BLACK(0, 0, 0);
const RGBColor RGBColor::RED(1, 0, 0);
const RGBColor RGBColor::GREEN(0, 1, 0);
const RGBColor RGBColor::BLUE(0, 0, 1);
const RGBColor RGBColor::CYAN(0, 1, 1);
const RGBColor RGBColor::MAGENTA(1, 0, 1);
const RGBColor RGBColor::YELLOW(1, 1, 0);
const RGBColor RGBColor::GRAY(128/255, 128/255, 128/255);
