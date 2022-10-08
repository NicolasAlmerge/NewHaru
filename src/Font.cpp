#include "../include/Font.hpp"
#include "../include/Box.hpp"
#include "../include/TextWidth.hpp"
using namespace pdf;


Font::Font(const HPDF_Font font): ContentStream(font) {}

const char* Font::getName() const {
    return HPDF_Font_GetFontName(innerContent);
}

const char* Font::getEncodingName() const {
    return HPDF_Font_GetEncodingName(innerContent);
}

int Font::getUnicodeWidth(unsigned short character) const {
    return HPDF_Font_GetUnicodeWidth(innerContent, character);
}

float Font::getActualWidth(unsigned short character, float fontSize) const {
    return getUnicodeWidth(character) * fontSize / 1000.f;
}

int Font::getVerticalAscent() const {
    return HPDF_Font_GetAscent(innerContent);
}

int Font::getVerticalDescent() const {
    return HPDF_Font_GetDescent(innerContent);
}

unsigned int Font::getDistanceToLower() const {
    return HPDF_Font_GetXHeight(innerContent);
}

unsigned int Font::getDistanceToUpper() const {
    return HPDF_Font_GetCapHeight(innerContent);
}

Box Font::getBoundingBox() const {
    return Box(HPDF_Font_GetBBox(innerContent));
}

TextWidth Font::getTextWidth(const unsigned char* bytes, unsigned int length) const {
    return TextWidth(HPDF_Font_TextWidth(innerContent, bytes, length));
}

TextWidth Font::getTextWidth(const std::vector<unsigned char>& bytes, unsigned int length) const {
    return getTextWidth(bytes.data(), bytes.size());
}

TextWidth Font::getTextWidth(const std::string& text) const {
    return getTextWidth((const unsigned char*) text.c_str(), text.size());
}

std::pair<unsigned int, float> Font::measureText(
    const unsigned char* text, unsigned int len,
    float width, float fontSize,
    float charSpace, float wordSpace,
    bool wordwrap
) const {
    float realWidth;
    unsigned int value = HPDF_Font_MeasureText(
        innerContent,
        text, len,
        width, fontSize,
        charSpace, wordSpace,
        wordwrap, &realWidth
    );
    return {value, realWidth};
}

std::pair<unsigned int, float> Font::measureText(
    const std::string& text,
    float width, float fontSize,
    float charSpace, float wordSpace,
    bool wordwrap
) const {
    return measureText(
        (const unsigned char*) text.c_str(), text.size(),
        width, fontSize,
        charSpace, wordSpace,
        wordwrap
    );
}
