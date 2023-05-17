#ifndef __HARUPP_CMYKCOLOR_HPP__
#define __HARUPP_CMYKCOLOR_HPP__
#include "Color.hpp"
#include "hpdf.h"

namespace pdf {

    /**
     * \class  CMYKColor
     * @brief  Represents a CMYK Color.
     * @file   CMYKColor.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class CMYKColor final: public Color {
        HPDF_CMYKColor innerContent;
        CMYKColor(HPDF_CMYKColor&& rgbColor);
        friend class PdfPage;

    public:

        /**
         * @brief   Creates the white CMYKColor.
         * @details This is equivalent to `CMYKColor(0, 0, 0, 0)`.
        */
        CMYKColor() noexcept;

        /**
         * @brief Creates a new CMYKColor with the given attributes.
         * @param c Cyan value.
         * @param m Magenta value.
         * @param y Yellow value.
         * @param k Black value.
        */
        CMYKColor(float c, float m, float y, float k) noexcept;

        /**
         * @brief Always returns `false`.
         * @return `false`
        */
        bool isEmpty() const noexcept override;

        /**
         * @brief Gets the cyan component.
         * @return Cyan component.
        */
        float getC() const noexcept;

        /**
         * @brief Gets the magenta component.
         * @return Magenta component.
        */
        float getM() const noexcept;

        /**
         * @brief Gets the yellow component.
         * @return Yellow component.
        */
        float getY() const noexcept;

        /**
         * @brief Gets the black component.
         * @return Black component.
        */
        float getK() const noexcept;

        /**
         * @brief Converts the color to an RGBColor.
         * @see RGBColor
         * @return RGBColor representation of the color.
        */
        RGBColor toRGB() const noexcept override;

        /**
         * @brief Creates a copy of the CMYKColor.
         * @return Copy of the color.
        */
        CMYKColor toCMYK() const noexcept override;

        /**
         * @brief Checks whether two colors are equal.
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
}

#endif // __HARUPP_CMYKCOLOR_HPP__
