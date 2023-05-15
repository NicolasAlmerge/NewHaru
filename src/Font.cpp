#include "../include/Font.hpp"
#include "../include/Box.hpp"
#include "../include/TextWidth.hpp"
using namespace pdf;


Font::Font(const HPDF_Font font): ContentStream(font) {}

std::string Font::getName() const {
    const char* value = HPDF_Font_GetFontName(innerContent);
    return (value == nullptr)? std::string(): value;
}

std::string Font::getEncodingName() const {
    const char* value = HPDF_Font_GetEncodingName(innerContent);
    return (value == nullptr)? std::string(): value;
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

TextWidth Font::__getTextWidth(const unsigned char* bytes, unsigned int length) const {
    return TextWidth(HPDF_Font_TextWidth(innerContent, bytes, length));
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
        innerContent,
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
