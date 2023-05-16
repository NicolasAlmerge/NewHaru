#ifndef __HARUPP_CMYKCOLOR_HPP__
#define __HARUPP_CMYKCOLOR_HPP__
#include "Color.hpp"
#include "hpdf.h"

namespace pdf {
    class CMYKColor final: public Color {
        HPDF_CMYKColor innerContent;
        CMYKColor(HPDF_CMYKColor&& rgbColor);
        friend class PdfPage;

    public:
        CMYKColor();
        CMYKColor(float c, float m, float y, float k);

        bool isEmpty() const override;

        float getC() const;
        float getM() const;
        float getY() const;
        float getK() const;

        RGBColor toRGB() const override;
        CMYKColor toCMYK() const override;

        const static CMYKColor WHITE;
        const static CMYKColor BLACK;
        const static CMYKColor RED;
        const static CMYKColor GREEN;
        const static CMYKColor BLUE;
        const static CMYKColor CYAN;
        const static CMYKColor MAGENTA;
        const static CMYKColor YELLOW;
        const static CMYKColor GRAY;
    };
}

#endif // __HARUPP_CMYKCOLOR_HPP__
