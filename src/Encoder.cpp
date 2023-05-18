#include "../include/Encoder.hpp"
#include "hpdf.h"
using namespace pdf;


Encoder::Encoder(_HPDF_Encoder_Rec* content) noexcept: __innerContent(content) {}

bool Encoder::isEmpty() const noexcept {
    return __innerContent == nullptr;
}

enums::EncoderType Encoder::getType() const {
    switch (HPDF_Encoder_GetType(__innerContent)) {
        case HPDF_ENCODER_TYPE_SINGLE_BYTE: return enums::EncoderType::SINGLE_BYTE;
        case HPDF_ENCODER_TYPE_DOUBLE_BYTE: return enums::EncoderType::DOUBLE_BYTE;
        case HPDF_ENCODER_TYPE_UNINITIALIZED: return enums::EncoderType::UNINITIALIZED;
        default: return enums::EncoderType::UNKNOWN;
    }
}

enums::ByteType Encoder::getByteType(const std::string& text, unsigned int index) const {
    switch (HPDF_Encoder_GetByteType(__innerContent, text.c_str(), index)) {
        case HPDF_BYTE_TYPE_SINGLE: return enums::ByteType::SINGLE;
        case HPDF_BYTE_TYPE_LEAD: return enums::ByteType::LEAD;
        case HPDF_BYTE_TYPE_TRAIL: return enums::ByteType::TRAIL;
        default: return enums::ByteType::UNKNOWN;
    }
}

unsigned short Encoder::getUnicode(unsigned short code) const {
    return HPDF_Encoder_GetUnicode(__innerContent, code);
}

enums::WritingMode Encoder::getWritingMode() const {
    switch (HPDF_Encoder_GetWritingMode(__innerContent)) {
        case HPDF_WMODE_HORIZONTAL: return enums::WritingMode::HORIZONTAL;
        case HPDF_WMODE_VERTICAL: return enums::WritingMode::VERTICAL;
        default: return enums::WritingMode::EOF_MODE;
    }
}
