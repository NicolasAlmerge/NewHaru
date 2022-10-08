#pragma once
#include "Color.hpp"


namespace pdf {
    class PdfPage;
    class RGBColor;

    class CMYKColor: public Color {
        _HPDF_CMYKColor innerContent;
        CMYKColor(_HPDF_CMYKColor&& rgbColor);
        friend class PdfPage;

    public:
        CMYKColor();
        CMYKColor(float c, float m, float y, float k);

        bool isEmpty() const final override;

        float getC() const;
        float getM() const;
        float getY() const;
        float getK() const;
        void setC(float value);
        void setM(float value);
        void setY(float value);
        void setK(float value);

        RGBColor toRGB() const;

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
