#include "../include/Permissions.hpp"
using namespace pdf;


Permissions::Permissions() noexcept: ValueSet() {}

Permissions::Permissions(unsigned int v): ValueSet(v) {}

Permissions::Permissions(bool canPrint, bool canEditContent, bool canCopy, bool canEditAnnotations) noexcept:
    ValueSet((canPrint << 2) | (canEditContent << 3) | (canCopy << 4) | (canEditAnnotations << 5)) {}

Permissions Permissions::operator +(const Permissions& other) const noexcept {
    return Permissions(value | other.value);
}

Permissions Permissions::operator -(const Permissions& other) const noexcept {
    return Permissions(value & ~other.value);
}

bool Permissions::operator ==(const Permissions& other) const noexcept {
    return value == other.value;
}

bool Permissions::operator !=(const Permissions& other) const noexcept {
    return !operator==(other);
}

const Permissions Permissions::READ_ONLY = Permissions();
const Permissions Permissions::PRINT = Permissions(1 << 2);
const Permissions Permissions::EDIT_CONTENT = Permissions(1 << 3);
const Permissions Permissions::COPY = Permissions(1 << 4);
const Permissions Permissions::EDIT_ANNOTATIONS = Permissions(1 << 5);
const Permissions Permissions::EDIT_ALL = Permissions((1 << 3) | (1 << 5));
const Permissions Permissions::ALL = Permissions((1 << 2) | (1 << 3) | (1 << 4) | (1 << 5));
