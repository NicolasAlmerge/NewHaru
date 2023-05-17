#include "../include/ContentStream.hpp"
using namespace pdf;


ContentStream::ContentStream(const HPDF_Dict dict): innerContent(dict) {}

ContentStream::~ContentStream() noexcept {}

bool ContentStream::isEmpty() const noexcept {
    return innerContent == nullptr;
}

bool ContentStream::operator ==(const ContentStream& other) const noexcept {
    return innerContent == other.innerContent;
}

bool ContentStream::operator !=(const ContentStream& other) const noexcept {
    return !operator==(other);
}
