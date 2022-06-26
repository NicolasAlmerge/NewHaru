#include "../include/PdfException.hpp"
using namespace pdf;


PdfException::PdfException(
    const char* data, unsigned long errorCode, unsigned long detailCode, bool hasDetailCode
) noexcept: errorMessage(data), errorCode(errorCode), detailCode(detailCode), _hasDetailCode(hasDetailCode) {}

PdfException::PdfException(
    const std::string& data, unsigned long errorCode, unsigned long detailCode, bool hasDetailCode
) noexcept: errorMessage(data.c_str()), errorCode(errorCode), detailCode(detailCode), _hasDetailCode(hasDetailCode) {}

PdfException::~PdfException() noexcept {}

unsigned long PdfException::getErrorCode() const noexcept {
    return errorCode;
}

unsigned long PdfException::getDetailCode() const noexcept {
    return detailCode;
}

const char* PdfException::what() const noexcept {
    return errorMessage;
}

bool PdfException::hasDetailCode() const noexcept {
    return _hasDetailCode;
}

std::string PdfException::getFullDescription() const noexcept {
    return std::string(getName()) + std::string(": ") + std::string(what());
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
