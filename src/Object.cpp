#include "../include/Object.hpp"
using namespace pdf;


Object::~Object() noexcept {}

Object::operator bool() const noexcept {
    return !isEmpty();
}
