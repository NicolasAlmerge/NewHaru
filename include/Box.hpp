#pragma once
#include "PdfObject.hpp"


namespace pdf {
    class Font;
    class PdfPage;

    class Box: public PdfObject {
        HPDF_Box innerContent;
        Box(HPDF_Box&& box);
        friend class Font;
        friend class PdfPage;

    public:
        Box();
        Box(float left, float bottom, float right, float top);
        bool isEmpty() const final override;
        float getLeft() const;
        float getBottom() const;
        float getRight() const;
        float getTop() const;
    };
}
