#pragma once
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
    };
}
