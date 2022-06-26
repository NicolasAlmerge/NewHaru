#include "../include/Box.hpp"
using namespace pdf;


Box::Box(HPDF_Box&& box): innerContent(box) {}

Box::Box(): Box(HPDF_Box({0.f, 0.f, 0.f, 0.f})) {}

Box::Box(float left, float bottom, float right, float top): Box(HPDF_Box({left, bottom, right, top})) {}

bool Box::isEmpty() const {
    return (
        innerContent.left == 0.f && innerContent.bottom == 0.f &&
        innerContent.right == 0.f && innerContent.top == 0.f
    );
}

float Box::getLeft() const {
    return innerContent.left;
}

float Box::getBottom() const {
    return innerContent.bottom;
}

float Box::getRight() const {
    return innerContent.right;
}

float Box::getTop() const {
    return innerContent.top;
}
