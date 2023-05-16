#ifndef __HARUPP_FONT_HPP__
#define __HARUPP_FONT_HPP__
#include "ContentStream.hpp"
#include "PdfObject.hpp"
#include "string"
#include "utility"
#include "vector"

namespace pdf {
    class Box;
    class TextWidth;

    class Font final: public ContentStream {
        Font(const HPDF_Font font);
        friend class PdfDocument;
        friend class PdfPage;

    public:
        std::string getName() const;
        std::string getEncodingName() const;
        int getUnicodeWidth(unsigned short character) const;
        float getActualWidth(unsigned short character, float fontSize) const;

        Box getBoundingBox() const;

        int getVerticalAscent() const;
        int getVerticalDescent() const;
        unsigned int getDistanceToLower() const;
        unsigned int getDistanceToUpper() const;

        TextWidth getTextWidth(const std::vector<unsigned char>& bytes) const;
        TextWidth getTextWidth(const std::string& text) const;

        std::pair<unsigned int, float> measureText(
            const std::vector<unsigned char>& bytes,
            float width, float fontSize,
            float charSpace, float wordSpace,
            bool wordwrap
        ) const;

        std::pair<unsigned int, float> measureText(
            const std::string& text,
            float width, float fontSize,
            float charSpace, float wordSpace,
            bool wordwrap
        ) const;

    private:
        TextWidth __getTextWidth(const unsigned char* bytes, unsigned int length) const;
        std::pair<unsigned int, float> __measureText(
            const unsigned char* text, unsigned int len,
            float width, float fontSize,
            float charSpace, float wordSpace,
            bool wordwrap
        ) const;
    };
}

#endif // __HARUPP_FONT_HPP__
