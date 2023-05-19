#include "../include/CompressionMode.hpp"
using namespace pdf;


CompressionMode::CompressionMode() noexcept: ValueSet() {}

CompressionMode::CompressionMode(unsigned int v): ValueSet(v) {}

CompressionMode::CompressionMode(bool text, bool images, bool metadata) noexcept:
    ValueSet((text << 0) | (images << 1) | (metadata << 2)) {}

CompressionMode CompressionMode::operator +(const CompressionMode& other) const noexcept {
    return CompressionMode(value | other.value);
}

CompressionMode CompressionMode::operator -(const CompressionMode& other) const noexcept {
    return CompressionMode(value & ~other.value);
}

bool CompressionMode::operator ==(const CompressionMode& other) const noexcept {
    return value == other.value;
}

bool CompressionMode::operator !=(const CompressionMode& other) const noexcept {
    return !operator==(other);
}

const CompressionMode CompressionMode::NONE = CompressionMode();
const CompressionMode CompressionMode::TEXT = CompressionMode(1 << 0);
const CompressionMode CompressionMode::IMAGES = CompressionMode(1 << 1);
const CompressionMode CompressionMode::METADATA = CompressionMode(1 << 2);
const CompressionMode CompressionMode::ALL = CompressionMode((1 << 0) | (1 << 1) | (1 << 2));
