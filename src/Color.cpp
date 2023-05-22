#include "../include/Color.hpp"
using namespace pdf;


static constexpr float __haruppMax(float a, float b) {
    return (a >= b)? a: b;
}


Color::~Color() {}

bool Color::isEmpty() const noexcept {
    return false;
}

bool Color::operator!=(const Color& other) const noexcept {
    return !operator==(other);
}


CMYKColor::CMYKColor() noexcept {}

CMYKColor::CMYKColor(float c, float m, float y, float k) noexcept: c(c), m(m), y(y), k(k) {}

float CMYKColor::getC() const noexcept {
    return c;
}

float CMYKColor::getM() const noexcept {
    return m;
}

float CMYKColor::getY() const noexcept {
    return y;
}

float CMYKColor::getK() const noexcept {
    return k;
}

RGBColor CMYKColor::toRGB() const noexcept {
    const float invK = 1.f-getK();
    return RGBColor((1.f-getC())*invK, (1.f-getM())*invK, (1.f-getY())*invK);
}

CMYKColor CMYKColor::toCMYK() const noexcept {
    return *this;
}

bool CMYKColor::operator==(const Color& other) const noexcept {
    CMYKColor otherColor = other.toCMYK();
    return (
        c == otherColor.c &&
        m == otherColor.m &&
        y == otherColor.y &&
        k == otherColor.k
    );
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
