#include "../include/Color.hpp"
using namespace pdf;


Color::~Color() {}

bool Color::isEmpty() const noexcept {
    return false;
}

bool Color::operator!=(const Color& other) const noexcept {
    return !operator==(other);
}
