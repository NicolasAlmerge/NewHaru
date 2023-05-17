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

    /**
     * \class  Font
     * @brief  Represents a font.
     * @note   Note that this class cannot be instantiated manually. Rather, it is created when calling PdfDocument::getFont and PdfPage::getCurrentFont.
     * @file   Font.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class Font final: public ContentStream {
        explicit Font(const HPDF_Font font);
        friend class PdfDocument;
        friend class PdfPage;

    public:

        /**
         * @brief  Gets the font's name.
         * @return The font's name.
        */
        std::string getName() const;

        /**
         * @brief  Gets the font's encoding name.
         * @return The font's encoding name.
        */
        std::string getEncodingName() const;

        /**
         * @brief  Gets the unicode width of a certain character.
         * @param  character Character to use.
         * @return Character's width.
        */
        int getUnicodeWidth(unsigned short character) const;

        /**
         * @brief  Gets the actual width of a certain character and font size.
         * @param  character Character to use.
         * @param  fontSize The font size to use.
         * @return Character's actual width.
        */
        float getActualWidth(unsigned short character, float fontSize) const;

        /**
         * @brief  Gets the bounding box of the font.
         * @return Bounding box of the font.
        */
        Box getBoundingBox() const;

        /**
         * @brief  Gets the vertical ascent of the font.
         * @return Vertical ascent of the font.
        */
        int getVerticalAscent() const;

        /**
         * @brief  Gets the vertical descent of the font.
         * @return Vertical descent of the font.
        */
        int getVerticalDescent() const;

        /**
         * @brief  Gets the distance from the baseline of lowercase letters.
         * @return Distance from the baseline of lowercase letters.
        */
        unsigned int getDistanceToLower() const;

        /**
         * @brief  Gets the distance from the baseline of uppercase letters.
         * @return Distance from the baseline of uppercase letters.
        */
        unsigned int getDistanceToUpper() const;

        /**
         * @brief  Gets the TextWidth of a vector of bytes.
         * @param  bytes Vector of bytes to use.
         * @return The TextWidth of the byte vector.
        */
        TextWidth getTextWidth(const std::vector<unsigned char>& bytes) const;

        /**
         * @brief  Gets the TextWidth of a string.
         * @param  text String to use.
         * @return The TextWidth of the string.
        */
        TextWidth getTextWidth(const std::string& text) const;

        /**
         * @brief  Calculates the byte length which can be included within the specified width.
         * @param  bytes Vector of bytes to use.
         * @param  width Width to use.
         * @param  fontSize The font size to use.
         * @param  charSpace Character space to use.
         * @param  wordSpace Word space to use.
         * @param  wordwrap Whether or not to wrap words.
         * @return The byte length which can be included within the specified width, and the real width of the text in this order.
        */
        std::pair<unsigned int, float> measureText(
            const std::vector<unsigned char>& bytes,
            float width, float fontSize,
            float charSpace, float wordSpace,
            bool wordwrap
        ) const;

        /**
         * @brief  Calculates the byte length which can be included within the specified width.
         * @param  text Text to use.
         * @param  width Width to use.
         * @param  fontSize The font size to use.
         * @param  charSpace Character space to use.
         * @param  wordSpace Word space to use.
         * @param  wordwrap Whether or not to wrap words.
         * @return The byte length which can be included within the specified width, and the real width of the text in this order.
        */
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
