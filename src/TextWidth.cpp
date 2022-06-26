#include "../include/TextWidth.hpp"
using namespace pdf;


TextWidth::TextWidth(HPDF_TextWidth&& textWidth): innerContent(textWidth) {}

unsigned int TextWidth::getNumberOfChars() const {
    return innerContent.numchars;
}

unsigned int TextWidth::getNumberOfWords() const {
    return innerContent.numwords;
}

unsigned int TextWidth::getWidth() const {
    return innerContent.width;
}

unsigned int TextWidth::getNumberOfSpaces() const {
    return innerContent.numspace;
}
