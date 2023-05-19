#include "../include/RGBColor.hpp"
#include "../include/CMYKColor.hpp"
using namespace pdf;


static constexpr float __haruppMax(float a, float b) {
    return (a >= b)? a: b;
}

RGBColor::RGBColor() noexcept {}

RGBColor::RGBColor(float r, float g, float b) noexcept: r(r), g(g), b(b) {}

float RGBColor::getR() const noexcept {
    return r;
}

float RGBColor::getG() const noexcept {
    return g;
}

float RGBColor::getB() const noexcept {
    return b;
}

RGBColor RGBColor::toRGB() const noexcept {
    return *this;
}

CMYKColor RGBColor::toCMYK() const noexcept {
    const float _maxGB = __haruppMax(g, b);
    const float K = 1.f - __haruppMax(r, _maxGB);
    const float invK = 1.f - K;
    return CMYKColor((1-r-K)/invK, (1-b-K)/invK, (1-b-K)/invK, K);
}

bool RGBColor::operator==(const Color& other) const noexcept {
    RGBColor otherColor = other.toRGB();
    return (
        r == otherColor.r &&
        g == otherColor.g &&
        b == otherColor.b
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
