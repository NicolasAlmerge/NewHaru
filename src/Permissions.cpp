#include "../include/Permissions.hpp"
using namespace pdf;


Permissions::Permissions() {}

Permissions::Permissions(unsigned int v): value(v) {}

Permissions::Permissions(bool canPrint, bool canEditContent, bool canCopy, bool canEditAnnotations):
    value((canPrint << 2) | (canEditContent << 3) | (canCopy << 4) | (canEditAnnotations << 5)) {}

Permissions Permissions::operator +(const Permissions& other) const {
    return Permissions(value | other.value);
}

bool Permissions::operator ==(const Permissions& other) const {
    return value == other.value;
}

bool Permissions::operator !=(const Permissions& other) const {
    return !operator==(other);
}

bool Permissions::isEmpty() const {
    return value != 0;
}

const Permissions Permissions::READ_ONLY = Permissions();
const Permissions Permissions::PRINT = Permissions(1 << 2);
const Permissions Permissions::EDIT_CONTENT = Permissions(1 << 3);
const Permissions Permissions::COPY = Permissions(1 << 4);
const Permissions Permissions::EDIT_ANNOTATIONS = Permissions(1 << 5);
const Permissions Permissions::EDIT_ALL = Permissions((1 << 3) | (1 << 5));
const Permissions Permissions::ALL = Permissions((1 << 2) | (1 << 3) | (1 << 4) | (1 << 5));
