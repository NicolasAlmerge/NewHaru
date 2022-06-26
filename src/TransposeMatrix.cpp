#include "../include/TransposeMatrix.hpp"
using namespace pdf;


TransposeMatrix::TransposeMatrix(_HPDF_TransMatrix&& matrix): innerContent(matrix) {}

TransposeMatrix::TransposeMatrix(): TransposeMatrix(_HPDF_TransMatrix({0.f, 0.f, 0.f, 0.f, 0.f, 0.f})) {}

TransposeMatrix::TransposeMatrix(float a, float b, float c, float d, float x, float y): TransposeMatrix(_HPDF_TransMatrix({a, b, c, d, x, y})) {}

bool TransposeMatrix::isEmpty() const {
    return (
        innerContent.a == 0.f &&
        innerContent.b == 0.f &&
        innerContent.c == 0.f &&
        innerContent.d == 0.f &&
        innerContent.x == 0.f &&
        innerContent.y == 0.f
    );
}

float TransposeMatrix::getA() const {
    return innerContent.a;
}

float TransposeMatrix::getB() const {
    return innerContent.b;
}

float TransposeMatrix::getC() const {
    return innerContent.c;
}

float TransposeMatrix::getD() const {
    return innerContent.d;
}

float TransposeMatrix::getX() const {
    return innerContent.x;
}

float TransposeMatrix::getY() const {
    return innerContent.y;
}

void TransposeMatrix::setA(float value) {
    innerContent.a = value;
}

void TransposeMatrix::setB(float value) {
    innerContent.b = value;
}

void TransposeMatrix::setC(float value) {
    innerContent.c = value;
}

void TransposeMatrix::setD(float value) {
    innerContent.d = value;
}

void TransposeMatrix::setX(float value) {
    innerContent.x = value;
}

void TransposeMatrix::setY(float value) {
    innerContent.y = value;
}
