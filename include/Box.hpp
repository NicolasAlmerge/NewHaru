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
        Box() noexcept;
        Box(float left, float bottom, float right, float top) noexcept;
        bool isEmpty() const noexcept override;
        float getLeft() const noexcept;
        float getBottom() const noexcept;
        float getRight() const noexcept;
        float getTop() const noexcept;
    };
}

#endif // __HARUPP_BOX_HPP__
