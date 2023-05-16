#ifndef __HARUPP_RGBCOLOR_HPP__
#define __HARUPP_RGBCOLOR_HPP__
#include "Color.hpp"
#include "hpdf.h"

namespace pdf {
    class RGBColor final: public Color {
        HPDF_RGBColor innerContent;
        RGBColor(HPDF_RGBColor&& rgbColor);
        friend class PdfPage;

    public:
        RGBColor();
        RGBColor(float r, float g, float b);

        bool isEmpty() const override;

        float getR() const;
        float getG() const;
        float getB() const;

        RGBColor toRGB() const override;
        CMYKColor toCMYK() const override;

        const static RGBColor WHITE;
        const static RGBColor BLACK;
        const static RGBColor RED;
        const static RGBColor GREEN;
        const static RGBColor BLUE;
        const static RGBColor CYAN;
        const static RGBColor MAGENTA;
        const static RGBColor YELLOW;
        const static RGBColor GRAY;
    };
}

#endif // __HARUPP_RGBCOLOR_HPP__
