#include "../include/Coor2D.hpp"
using namespace pdf;


Coor2D::Coor2D(HPDF_Point&& coors): innerContent(coors) {}

Coor2D::Coor2D() noexcept: Coor2D(HPDF_Point({0.f, 0.f})) {}

Coor2D::Coor2D(float x, float y) noexcept: Coor2D(HPDF_Point({x, y})) {}

bool Coor2D::isEmpty() const noexcept {
    return false;
}

float Coor2D::getX() const noexcept {
    return innerContent.x;
}

float Coor2D::getY() const noexcept {
    return innerContent.y;
}

void Coor2D::setX(float value) noexcept {
    innerContent.x = value;
}

void Coor2D::setY(float value) noexcept {
    innerContent.y = value;
}
