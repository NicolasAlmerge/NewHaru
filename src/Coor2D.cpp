#include "../include/Coor2D.hpp"
using namespace pdf;


Coor2D::Coor2D(HPDF_Point&& coors): innerContent(coors) {}

Coor2D::Coor2D(): Coor2D(HPDF_Point({0.f, 0.f})) {}

Coor2D::Coor2D(float x, float y): Coor2D(HPDF_Point({x, y})) {}

bool Coor2D::isEmpty() const {
    return innerContent.x == 0.f && innerContent.y == 0.f;
}

float Coor2D::getX() const {
    return innerContent.x;
}

float Coor2D::getY() const {
    return innerContent.y;
}

void Coor2D::setX(float value) {
    innerContent.x = value;
}

void Coor2D::setY(float value) {
    innerContent.y = value;
}
