#ifndef __HARUPP_TEXTWIDTH_HPP__
#define __HARUPP_TEXTWIDTH_HPP__
#include "Object.hpp"

namespace pdf {

    /**
     * \class  TextWidth
     * @brief  Represents a text width.
     * @note   Note that this class cannot be instantiated manually. Rather, it is created when calling Font::getTextWidth.
     * @file   TextWidth.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class TextWidth final: public Object {
        unsigned int numchars = 0U;
        unsigned int width = 0U;
        unsigned int numspace = 0U;
        explicit TextWidth(unsigned int numchars, unsigned int width, unsigned int numspace) noexcept;
        friend class Font;

    public:

        /**
         * @brief  Gets the number of characters present.
         * @return Number of characters.
        */
        unsigned int getNumberOfChars() const noexcept;

        /**
         * @brief  Gets the text width.
         * @return Text width.
        */
        unsigned int getWidth() const noexcept;

        /**
         * @brief  Gets the number of spaces present.
         * @return Number of spaces.
        */
        unsigned int getNumberOfSpaces() const noexcept;

        /**
         * @brief  Checks whether the text width is empty.
         * @return `true` if all values are `0`, `false` otherwise.
        */
        bool isEmpty() const noexcept override;
    };
}

#endif // __HARUPP_TEXTWIDTH_HPP__
