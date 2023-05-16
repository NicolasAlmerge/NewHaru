#include "../include/RGBColor.hpp"
#include "../include/CMYKColor.hpp"
using namespace pdf;

static constexpr float __haruppMax(float a, float b) {
    return (a >= b)? a: b;
}

RGBColor::RGBColor(HPDF_RGBColor&& rgbColor): innerContent(rgbColor) {}

RGBColor::RGBColor() noexcept: RGBColor(HPDF_RGBColor({0.f, 0.f, 0.f})) {}

RGBColor::RGBColor(float r, float g, float b) noexcept: RGBColor(HPDF_RGBColor({r, g, b})) {}

bool RGBColor::isEmpty() const noexcept {
    return false;
}

float RGBColor::getR() const noexcept {
    return innerContent.r;
}

float RGBColor::getG() const noexcept {
    return innerContent.g;
}

float RGBColor::getB() const noexcept {
    return innerContent.b;
}

RGBColor RGBColor::toRGB() const noexcept {
    return RGBColor(innerContent.r, innerContent.g, innerContent.b);
}

CMYKColor RGBColor::toCMYK() const noexcept {
    const float R = innerContent.r;
    const float G = innerContent.g;
    const float B = innerContent.b;
    const float _maxGB = __haruppMax(G, B);
    const float K = 1.f - __haruppMax(R, _maxGB);
    const float invK = 1.f - K;
    return CMYKColor((1-R-K)/invK, (1-G-K)/invK, (1-B-K)/invK, K);
}

bool RGBColor::operator==(const Color& other) const noexcept {
    RGBColor otherColor = other.toRGB();
    return (
        innerContent.r == otherColor.innerContent.r &&
        innerContent.g == otherColor.innerContent.g &&
        innerContent.b == otherColor.innerContent.b
    );
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
