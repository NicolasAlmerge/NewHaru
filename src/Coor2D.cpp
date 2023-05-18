#include "../include/Coor2D.hpp"
using namespace pdf;


Coor2D::Coor2D() noexcept {}

Coor2D::Coor2D(float x, float y) noexcept: x(x), y(y) {}

bool Coor2D::isEmpty() const noexcept {
    return false;
}

float Coor2D::getX() const noexcept {
    return x;
}

float Coor2D::getY() const noexcept {
    return y;
}
