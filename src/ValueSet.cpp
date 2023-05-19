#include "../include/ValueSet.hpp"
using namespace pdf;


ValueSet::ValueSet() noexcept {}

ValueSet::ValueSet(unsigned int v) noexcept: value(v) {}

ValueSet::~ValueSet() noexcept {}

bool ValueSet::isEmpty() const noexcept {
    return value != 0U;
}
