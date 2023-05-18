#include "../include/TransposeMatrix.hpp"
using namespace pdf;


TransposeMatrix::TransposeMatrix() noexcept {}

TransposeMatrix::TransposeMatrix(float a, float b, float c, float d, float x, float y) noexcept:
    a(a), b(b), c(c), d(d), x(x), y(y) {}

bool TransposeMatrix::isEmpty() const noexcept {
    return a == 0.f && b == 0.f && c == 0.f && d == 0.f && x == 0.f && y == 0.f;
}

float TransposeMatrix::getA() const noexcept {
    return a;
}

float TransposeMatrix::getB() const noexcept {
    return b;
}

float TransposeMatrix::getC() const noexcept {
    return c;
}

float TransposeMatrix::getD() const noexcept {
    return d;
}

float TransposeMatrix::getX() const noexcept {
    return x;
}

float TransposeMatrix::getY() const noexcept {
    return y;
}
