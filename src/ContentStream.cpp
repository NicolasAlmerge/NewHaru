#include "../include/ContentStream.hpp"
#include "hpdf.h"
using namespace pdf;


ContentStream::ContentStream(_HPDF_Dict_Rec* content) noexcept: __innerContent(content) {}

ContentStream::~ContentStream() noexcept {}

bool ContentStream::isEmpty() const noexcept {
    return __innerContent == nullptr;
}

bool ContentStream::operator ==(const ContentStream& other) const noexcept {
    return __innerContent == other.__innerContent;
}

bool ContentStream::operator !=(const ContentStream& other) const noexcept {
    return !operator==(other);
}
