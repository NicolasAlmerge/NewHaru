#include "../include/Box.hpp"
using namespace pdf;


Box::Box(HPDF_Box&& box): innerContent(box) {}

Box::Box() noexcept: Box(HPDF_Box({0.f, 0.f, 0.f, 0.f})) {}

Box::Box(float left, float bottom, float right, float top) noexcept: Box(HPDF_Box({left, bottom, right, top})) {}

bool Box::isEmpty() const noexcept {
    return (
        innerContent.left == 0.f && innerContent.bottom == 0.f &&
        innerContent.right == 0.f && innerContent.top == 0.f
    );
}

float Box::getLeft() const noexcept {
    return innerContent.left;
}

float Box::getBottom() const noexcept {
    return innerContent.bottom;
}

float Box::getRight() const noexcept {
    return innerContent.right;
}

float Box::getTop() const noexcept {
    return innerContent.top;
}
