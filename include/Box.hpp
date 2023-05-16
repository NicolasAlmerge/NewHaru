#ifndef __HARUPP_BOX_HPP__
#define __HARUPP_BOX_HPP__
#include "PdfObject.hpp"
#include "hpdf.h"

namespace pdf {
    class Box final: public PdfObject {
        HPDF_Box innerContent;
        Box(HPDF_Box&& box);
        friend class Font;
        friend class PdfPage;

    public:
        Box();
        Box(float left, float bottom, float right, float top);
        bool isEmpty() const override;
        float getLeft() const;
        float getBottom() const;
        float getRight() const;
        float getTop() const;
    };
}

#endif // __HARUPP_BOX_HPP__
