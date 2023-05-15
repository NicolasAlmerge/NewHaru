#ifndef __HARUPP_TEXTWIDTH_HPP__
#define __HARUPP_TEXTWIDTH_HPP__
#include "hpdf.h"

namespace pdf {
    class Font;

    class TextWidth final {
        const HPDF_TextWidth innerContent;
        TextWidth(HPDF_TextWidth&& textWidth);
        friend class Font;

    public:
        unsigned int getNumberOfChars() const;
        unsigned int getNumberOfWords() const;
        unsigned int getWidth() const;
        unsigned int getNumberOfSpaces() const;
    };
}

#endif // __HARUPP_TEXTWIDTH_HPP__
