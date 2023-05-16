#include "../include/TextWidth.hpp"
using namespace pdf;


TextWidth::TextWidth(HPDF_TextWidth&& textWidth): innerContent(textWidth) {}

unsigned int TextWidth::getNumberOfChars() const noexcept {
    return innerContent.numchars;
}

unsigned int TextWidth::getNumberOfWords() const noexcept {
    return innerContent.numwords;
}

unsigned int TextWidth::getWidth() const noexcept {
    return innerContent.width;
}

unsigned int TextWidth::getNumberOfSpaces() const noexcept {
    return innerContent.numspace;
}

bool TextWidth::isEmpty() const noexcept {
    return (
        innerContent.numchars == 0U &&
        innerContent.numwords == 0U &&
        innerContent.width == 0U &&
        innerContent.numspace == 0U
    );
}
