#include "../include/ContentStream.hpp"
using namespace pdf;


ContentStream::ContentStream(const HPDF_Dict dict): innerContent(dict) {}

ContentStream::~ContentStream() {}

bool ContentStream::isEmpty() const {
    return innerContent == nullptr;
}
