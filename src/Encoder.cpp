#include "../include/Encoder.hpp"
using namespace pdf;

Encoder::Encoder(const HPDF_Encoder coors) {}

Encoder::Encoder() {}

bool Encoder::isEmpty() const {
    return innerContent == nullptr;
}

EncoderType Encoder::getType() const {
    switch (HPDF_Encoder_GetType(innerContent)) {
        case HPDF_ENCODER_TYPE_SINGLE_BYTE: return EncoderType::SINGLE_BYTE;
        case HPDF_ENCODER_TYPE_DOUBLE_BYTE: return EncoderType::DOUBLE_BYTE;
        case HPDF_ENCODER_TYPE_UNINITIALIZED: return EncoderType::UNINITIALIZED;
        default: return EncoderType::UNKNOWN;
    }
}

ByteType Encoder::getByteType(const char* text, unsigned int index) const {
    switch (HPDF_Encoder_GetByteType(innerContent, text, index)) {
        case HPDF_BYTE_TYPE_SINGLE: return ByteType::SINGLE;
        case HPDF_BYTE_TYPE_LEAD: return ByteType::LEAD;
        case HPDF_BYTE_TYPE_TRIAL: return ByteType::TRIAL;
        default: return ByteType::UNKNOWN;
    }
}

ByteType Encoder::getByteType(const std::string& text, unsigned int index) const {
    return getByteType(text.c_str(), index);
}

unsigned short Encoder::getUnicode(unsigned short code) const {
    return HPDF_Encoder_GetUnicode(innerContent, code);
}

WritingMode Encoder::getWritingMode() const {
    switch (HPDF_Encoder_GetWritingMode(innerContent)) {
        case HPDF_WMODE_HORIZONTAL: return WritingMode::HORIZONTAL;
        case HPDF_WMODE_VERTICAL: return WritingMode::VERTICAL;
        default: return WritingMode::EOF_MODE;
    }
}
