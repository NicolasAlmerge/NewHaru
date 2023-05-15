#ifndef __HARUPP_RGBCOLOR_HPP__
#define __HARUPP_RGBCOLOR_HPP__
#include "Color.hpp"

namespace pdf {
    class CMYKColor;
    class PdfPage;

    class RGBColor: public Color {
        _HPDF_RGBColor innerContent;
        RGBColor(_HPDF_RGBColor&& rgbColor);
        friend class PdfPage;

    public:
        RGBColor();
        RGBColor(float r, float g, float b);

        bool isEmpty() const final override;

        float getR() const;
        float getG() const;
        float getB() const;
        void setR(float value);
        void setG(float value);
        void setB(float value);

        CMYKColor toCMYK() const;

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
