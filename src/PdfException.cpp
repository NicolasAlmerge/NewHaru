#include "../include/PdfException.hpp"
using namespace pdf::except;


PdfException::PdfException(const std::string& data, unsigned long errorCode, unsigned long detailCode) noexcept:
    errorMessage(data), errorCode(errorCode), detailCode(detailCode) {}

PdfException::~PdfException() noexcept {}

unsigned long PdfException::getErrorCode() const noexcept {
    return errorCode;
}

unsigned long PdfException::getDetailCode() const noexcept {
    return detailCode;
}

const char* PdfException::what() const noexcept {
    return errorMessage.c_str();
}

bool PdfException::hasDetailCode() const noexcept {
    return detailCode != 0U;
}

std::string PdfException::getFullDescription() const noexcept {
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
