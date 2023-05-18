#include "../include/TextWidth.hpp"
using namespace pdf;


TextWidth::TextWidth(unsigned int numchars, unsigned int width, unsigned int numspace) noexcept:
    numchars(numchars), width(width), numspace(numspace) {}

unsigned int TextWidth::getNumberOfChars() const noexcept {
    return numchars;
}

unsigned int TextWidth::getWidth() const noexcept {
    return width;
}

unsigned int TextWidth::getNumberOfSpaces() const noexcept {
    return numspace;
}

bool TextWidth::isEmpty() const noexcept {
    return numchars == 0U && width == 0U && numspace == 0U;
}
