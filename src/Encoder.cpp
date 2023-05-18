#include "../include/Encoder.hpp"
#include "hpdf.h"
using namespace pdf;


Encoder::Encoder(_HPDF_Encoder_Rec* content) noexcept: __innerContent(content) {}

bool Encoder::isEmpty() const noexcept {
    return __innerContent == nullptr;
}

EncoderType Encoder::getType() const {
    switch (HPDF_Encoder_GetType(__innerContent)) {
        case HPDF_ENCODER_TYPE_SINGLE_BYTE: return EncoderType::SINGLE_BYTE;
        case HPDF_ENCODER_TYPE_DOUBLE_BYTE: return EncoderType::DOUBLE_BYTE;
        case HPDF_ENCODER_TYPE_UNINITIALIZED: return EncoderType::UNINITIALIZED;
        default: return EncoderType::UNKNOWN;
    }
}

ByteType Encoder::getByteType(const std::string& text, unsigned int index) const {
    switch (HPDF_Encoder_GetByteType(__innerContent, text.c_str(), index)) {
        case HPDF_BYTE_TYPE_SINGLE: return ByteType::SINGLE;
        case HPDF_BYTE_TYPE_LEAD: return ByteType::LEAD;
        case HPDF_BYTE_TYPE_TRAIL: return ByteType::TRAIL;
        default: return ByteType::UNKNOWN;
    }
}

unsigned short Encoder::getUnicode(unsigned short code) const {
    return HPDF_Encoder_GetUnicode(__innerContent, code);
}

WritingMode Encoder::getWritingMode() const {
    switch (HPDF_Encoder_GetWritingMode(__innerContent)) {
        case HPDF_WMODE_HORIZONTAL: return WritingMode::HORIZONTAL;
        case HPDF_WMODE_VERTICAL: return WritingMode::VERTICAL;
        default: return WritingMode::EOF_MODE;
    }
}
