#include "../include/Font.hpp"
#include "hpdf.h"
using namespace pdf;


Font::Font(_HPDF_Dict_Rec* content) noexcept: ContentStream(content) {}

std::string Font::getName() const {
    const char* value = HPDF_Font_GetFontName(__innerContent);
    return (value == nullptr)? std::string(): value;
}

std::string Font::getEncodingName() const {
    const char* value = HPDF_Font_GetEncodingName(__innerContent);
    return (value == nullptr)? std::string(): value;
}

int Font::getUnicodeWidth(unsigned short character) const {
    return HPDF_Font_GetUnicodeWidth(__innerContent, character);
}

float Font::getActualWidth(unsigned short character, float fontSize) const {
    return getUnicodeWidth(character) * fontSize / 1000.f;
}

int Font::getVerticalAscent() const {
    return HPDF_Font_GetAscent(__innerContent);
}

int Font::getVerticalDescent() const {
    return HPDF_Font_GetDescent(__innerContent);
}

unsigned int Font::getDistanceToLower() const {
    return HPDF_Font_GetXHeight(__innerContent);
}

unsigned int Font::getDistanceToUpper() const {
    return HPDF_Font_GetCapHeight(__innerContent);
}

Box Font::getBoundingBox() const {
    HPDF_Box box = HPDF_Font_GetBBox(__innerContent);
    return Box(box.left, box.bottom, box.right, box.top);
}

TextWidth Font::__getTextWidth(const unsigned char* bytes, unsigned int length) const {
    HPDF_TextWidth textWidth = HPDF_Font_TextWidth(__innerContent, bytes, length);
    return TextWidth(textWidth.numchars, textWidth.width, textWidth.numspace);
}

TextWidth Font::getTextWidth(const std::vector<unsigned char>& bytes) const {
    return __getTextWidth(bytes.data(), bytes.size());
}

TextWidth Font::getTextWidth(const std::string& text) const {
    return __getTextWidth((const unsigned char*) text.c_str(), text.size());
}

std::pair<unsigned int, float> Font::__measureText(
    const unsigned char* text, unsigned int len,
    float width, float fontSize,
    float charSpace, float wordSpace,
    bool wordwrap
) const {
    float realWidth;
    unsigned int value = HPDF_Font_MeasureText(
        __innerContent,
        text, len,
        width, fontSize,
        charSpace, wordSpace,
        wordwrap, &realWidth
    );
    return {value, realWidth};
}

std::pair<unsigned int, float> Font::measureText(
    const std::vector<unsigned char>& bytes,
    float width, float fontSize,
    float charSpace, float wordSpace,
    bool wordwrap
) const {
    return __measureText(
        bytes.data(), bytes.size(),
        width, fontSize,
        charSpace, wordSpace,
        wordwrap
    );
}

std::pair<unsigned int, float> Font::measureText(
    const std::string& text,
    float width, float fontSize,
    float charSpace, float wordSpace,
    bool wordwrap
) const {
    return __measureText(
        (const unsigned char*) text.c_str(), text.size(),
        width, fontSize,
        charSpace, wordSpace,
        wordwrap
    );
}
