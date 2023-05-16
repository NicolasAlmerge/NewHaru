#include "../include/Color.hpp"
using namespace pdf;


Color::~Color() {}

bool Color::operator!=(const Color& other) const noexcept {
    return !operator==(other);
}
