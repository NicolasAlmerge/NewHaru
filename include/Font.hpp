#pragma once
#include "PdfObject.hpp"
#include "iostream"
#include "vector"
#include "ContentStream.hpp"


namespace pdf {
    class PdfDocument;
    class Box;
    class TextWidth;
    class PdfPage;

    class Font: public ContentStream {
        Font(const HPDF_Font font);
        friend class PdfDocument;
        friend class PdfPage;

    public:
        const char* getName() const;
        const char* getEncodingName() const;
        int getUnicodeWidth(unsigned short character) const;
        float getActualWidth(unsigned short character, float fontSize) const;

        Box getBoundingBox() const;

        int getVerticalAscent() const;
        int getVerticalDescent() const;
        unsigned int getDistanceToLower() const;
        unsigned int getDistanceToUpper() const;

        TextWidth getTextWidth(const unsigned char* bytes, unsigned int length) const;
        TextWidth getTextWidth(const std::vector<unsigned char>& bytes, unsigned int length) const;
        TextWidth getTextWidth(const std::string& text) const;

        unsigned int measureText(
            const unsigned char* text, unsigned int len,
            float width, float fontSize,
            float charSpace, float wordSpace,
            bool wordwrap, float* realWidth = nullptr
        ) const;

        unsigned int measureText(
            const std::string& text,
            float width, float fontSize,
            float charSpace, float wordSpace,
            bool wordwrap, float* realWidth = nullptr
        ) const;
    };
}
