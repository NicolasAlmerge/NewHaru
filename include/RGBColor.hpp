#ifndef __HARUPP_RGBCOLOR_HPP__
#define __HARUPP_RGBCOLOR_HPP__
#include "Color.hpp"

namespace pdf {

    /**
     * \class  RGBColor
     * @brief  Represents a RGB color.
     * @file   RGBColor.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class RGBColor final: public Color {
        float r = 0.f;
        float g = 0.f;
        float b = 0.f;

    public:
        /**
         * @brief   Creates the black RGBColor.
         * @details This is equivalent to `RGBColor(0, 0, 0)` and RGBColor::BLACK.
        */
        RGBColor() noexcept;

        /**
         * @brief Creates a new RGBColor with the given attributes.
         * @param r Red component.
         * @param g Green component.
         * @param b Blue component.
        */
        RGBColor(float r, float g, float b) noexcept;

        /**
         * @brief  Gets the red component.
         * @return Red component.
        */
        float getR() const noexcept;

        /**
         * @brief  Gets the green component.
         * @return Green component.
        */
        float getG() const noexcept;

        /**
         * @brief  Gets the blue component.
         * @return Blue component.
        */
        float getB() const noexcept;

        /**
         * @brief  Returns the same RGBColor object.
         * @return Current object.
        */
        RGBColor toRGB() const noexcept override;

        /**
         * @brief  Converts the color to an CMYKColor.
         * @see    CMYKColor
         * @return CMYKColor representation of the color.
        */
        CMYKColor toCMYK() const noexcept override;

        /**
         * @brief  Checks whether two colors are equal.
         * @return `true` if the colors are equal, `false` otherwise.
        */
        bool operator==(const Color& other) const noexcept override;

        /// White color.
        const static RGBColor WHITE;
        /// Black color.
        const static RGBColor BLACK;
        /// Red color.
        const static RGBColor RED;
        /// Green color.
        const static RGBColor GREEN;
        /// Blue color.
        const static RGBColor BLUE;
        /// Cyan color.
        const static RGBColor CYAN;
        /// Magenta color.
        const static RGBColor MAGENTA;
        /// Yellow color.
        const static RGBColor YELLOW;
        /// Gray color.
        const static RGBColor GRAY;
    };
}

#endif // __HARUPP_RGBCOLOR_HPP__
