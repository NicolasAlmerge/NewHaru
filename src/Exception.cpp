#include "../include/Exception.hpp"
using namespace pdf::excepts;


Exception::Exception(const std::string& data, unsigned long errorCode, unsigned long detailCode) noexcept:
    errorMessage(data), errorCode(errorCode), detailCode(detailCode) {}

Exception::~Exception() noexcept {}

unsigned long Exception::getErrorCode() const noexcept {
    return errorCode;
}

unsigned long Exception::getDetailCode() const noexcept {
    return detailCode;
}

const char* Exception::what() const noexcept {
    return errorMessage.c_str();
}

bool Exception::hasDetailCode() const noexcept {
    return detailCode != 0U;
}

std::string Exception::getFullDescription() const noexcept {
    return std::string(getName()) + std::string(": ") + errorMessage;
}

StreamException::~StreamException() noexcept {}

ArrayException::~ArrayException() noexcept {}

OtherException::~OtherException() noexcept {}

ImageException::~ImageException() noexcept {}

DictException::~DictException() noexcept {}

FontException::~FontException() noexcept {}

FileException::~FileException() noexcept {}

EncoderException::~EncoderException() noexcept {}

DocumentException::~DocumentException() noexcept {}

PageException::~PageException() noexcept {}

AnnotationException::~AnnotationException() noexcept {}
