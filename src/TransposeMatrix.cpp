#include "../include/TransposeMatrix.hpp"
using namespace pdf;


TransposeMatrix::TransposeMatrix(HPDF_TransMatrix&& matrix): innerContent(matrix) {}

TransposeMatrix::TransposeMatrix() noexcept: TransposeMatrix(HPDF_TransMatrix({0.f, 0.f, 0.f, 0.f, 0.f, 0.f})) {}

TransposeMatrix::TransposeMatrix(float a, float b, float c, float d, float x, float y) noexcept: TransposeMatrix(HPDF_TransMatrix({a, b, c, d, x, y})) {}

bool TransposeMatrix::isEmpty() const noexcept {
    return (
        innerContent.a == 0.f &&
        innerContent.b == 0.f &&
        innerContent.c == 0.f &&
        innerContent.d == 0.f &&
        innerContent.x == 0.f &&
        innerContent.y == 0.f
    );
}

float TransposeMatrix::getA() const noexcept {
    return innerContent.a;
}

float TransposeMatrix::getB() const noexcept {
    return innerContent.b;
}

float TransposeMatrix::getC() const noexcept {
    return innerContent.c;
}

float TransposeMatrix::getD() const noexcept {
    return innerContent.d;
}

float TransposeMatrix::getX() const noexcept {
    return innerContent.x;
}

float TransposeMatrix::getY() const noexcept {
    return innerContent.y;
}
