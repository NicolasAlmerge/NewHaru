#include "../include/Box.hpp"
using namespace pdf;


Box::Box() noexcept {}

Box::Box(float left, float bottom, float right, float top) noexcept: left(left), bottom(bottom), right(right), top(top) {}

bool Box::isEmpty() const noexcept {
    return left == 0.f && bottom == 0.f && right == 0.f && top == 0.f;
}

float Box::getLeft() const noexcept {
    return left;
}

float Box::getBottom() const noexcept {
    return bottom;
}

float Box::getRight() const noexcept {
    return right;
}

float Box::getTop() const noexcept {
    return top;
}
