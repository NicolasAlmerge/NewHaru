#ifndef __HARUPP_COLOR_HPP__
#define __HARUPP_COLOR_HPP__
#include "Object.hpp"

namespace pdf {
    class RGBColor;
    class CMYKColor;

    /**
     * \class  Color
     * @brief  Represents a color.
     * @file   Color.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class Color: public Object {
    public:
        virtual ~Color() = 0;

        /**
         * @brief  Always returns `false`.
         * @return `false`
        */
        bool isEmpty() const noexcept override final;

        /**
         * @brief  Converts the color to an RGBColor.
         * @see    RGBColor
         * @return RGBColor representation of the color.
        */
        virtual RGBColor toRGB() const noexcept = 0;

        /**
         * @brief  Converts the color to an CMYKColor.
         * @see    CMYKColor
         * @return CMYKColor representation of the color.
        */
        virtual CMYKColor toCMYK() const noexcept = 0;

        /**
         * @brief   Checks whether two colors are equal.
         * @return `true` if the colors are equal, `false` otherwise.
        */
        virtual bool operator==(const Color& other) const noexcept = 0;

        /**
         * @brief   Checks whether two colors are not equal.
         * @details This is equivalent to `!operator==(other)`.
         * @return `true` if the colors are not equal, `false` otherwise.
        */
        virtual bool operator!=(const Color& other) const noexcept final;
    };

    /**
     * \class  CMYKColor
     * @brief  Represents a CMYK color.
     * @file   Color.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class CMYKColor final: public Color {
        float c = 0.f;
        float m = 0.f;
        float y = 0.f;
        float k = 0.f;

    public:

        /**
         * @brief   Creates the white CMYKColor.
         * @details This is equivalent to `CMYKColor(0.0, 0.0, 0.0, 0.0)` and CMYKColor::WHITE.
        */
        CMYKColor() noexcept;

        /**
         * @brief Creates a new CMYKColor with the given attributes.
         * @param c Cyan value (`0.0 <= c <= 1.0`).
         * @param m Magenta value (`0.0 <= m <= 1.0`).
         * @param y Yellow value (`0.0 <= y <= 1.0`).
         * @param k Black value (`0.0 <= k <= 1.0`).
        */
        CMYKColor(float c, float m, float y, float k) noexcept;

        /**
         * @brief  Gets the cyan component, between `0.0` and `1.0`.
         * @return Cyan component.
        */
        float getC() const noexcept;

        /**
         * @brief  Gets the magenta component, between `0.0` and `1.0`.
         * @return Magenta component.
        */
        float getM() const noexcept;

        /**
         * @brief  Gets the yellow component, between `0.0` and `1.0`.
         * @return Yellow component.
        */
        float getY() const noexcept;

        /**
         * @brief  Gets the black component, between `0.0` and `1.0`.
         * @return Black component.
        */
        float getK() const noexcept;

        /**
         * @brief  Converts the color to an RGBColor.
         * @see    RGBColor
         * @return RGBColor representation of the color.
        */
        RGBColor toRGB() const noexcept override;

        /**
         * @brief  Returns the same CMYKColor object.
         * @return Current object.
        */
        CMYKColor toCMYK() const noexcept override;

        /**
         * @brief  Checks whether two colors are equal.
         * @return `true` if the colors are equal, `false` otherwise.
        */
        bool operator==(const Color& other) const noexcept override;

        /// White color.
        const static CMYKColor WHITE;
        /// Black color.
        const static CMYKColor BLACK;
        /// Red color.
        const static CMYKColor RED;
        /// Green color.
        const static CMYKColor GREEN;
        /// Blue color.
        const static CMYKColor BLUE;
        /// Cyan color.
        const static CMYKColor CYAN;
        /// Magenta color.
        const static CMYKColor MAGENTA;
        /// Yellow color.
        const static CMYKColor YELLOW;
        /// Gray color.
        const static CMYKColor GRAY;
    };

    /**
     * \class  RGBColor
     * @brief  Represents a RGB color.
     * @file   Color.hpp
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
         * @details This is equivalent to `RGBColor(0.0, 0.0, 0.0)` and RGBColor::BLACK.
        */
        RGBColor() noexcept;

        /**
         * @brief Creates a new RGBColor with the given attributes.
         * @param r Red component (`0.0 <= r <= 1.0`).
         * @param g Green component (`0.0 <= g <= 1.0`).
         * @param b Blue component (`0.0 <= b <= 1.0`).
        */
        RGBColor(float r, float g, float b) noexcept;

        /**
         * @brief  Gets the red component, between `0.0` and `1.0`.
         * @return Red component.
        */
        float getR() const noexcept;

        /**
         * @brief  Gets the green component, between `0.0` and `1.0`.
         * @return Green component.
        */
        float getG() const noexcept;

        /**
         * @brief  Gets the blue component, between `0.0` and `1.0`.
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

#endif // __HARUPP_COLOR_HPP__
