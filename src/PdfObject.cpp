#include "../include/PdfObject.hpp"
using namespace pdf;


PdfObject::~PdfObject() noexcept {}

PdfObject::operator bool() const noexcept {
    return !isEmpty();
}
