#ifndef __HARUPP_TEXTWIDTH_HPP__
#define __HARUPP_TEXTWIDTH_HPP__
#include "PdfObject.hpp"
#include "hpdf.h"

namespace pdf {
    class TextWidth final: public PdfObject {
        const HPDF_TextWidth innerContent;
        TextWidth(HPDF_TextWidth&& textWidth);
        friend class Font;

    public:
        unsigned int getNumberOfChars() const noexcept;
        unsigned int getNumberOfWords() const noexcept;
        unsigned int getWidth() const noexcept;
        unsigned int getNumberOfSpaces() const noexcept;

        bool isEmpty() const noexcept override;
    };
}

#endif // __HARUPP_TEXTWIDTH_HPP__
