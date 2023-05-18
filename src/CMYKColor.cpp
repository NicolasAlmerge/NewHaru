#include "../include/CMYKColor.hpp"
#include "../include/RGBColor.hpp"
using namespace pdf;


CMYKColor::CMYKColor() noexcept {}

CMYKColor::CMYKColor(float c, float m, float y, float k) noexcept: c(c), m(m), y(y), k(k) {}

bool CMYKColor::isEmpty() const noexcept {
    return false;
}

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
