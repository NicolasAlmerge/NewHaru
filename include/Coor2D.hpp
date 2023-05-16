#ifndef __HARUPP_COOR2D_HPP__
#define __HARUPP_COOR2D_HPP__
#include "PdfObject.hpp"
#include "hpdf.h"

namespace pdf {
    class Coor2D final: public PdfObject {
        HPDF_Point innerContent;
        Coor2D(HPDF_Point&& coors);
        friend class Image;
        friend class PdfPage;

    public:
        Coor2D() noexcept;
        Coor2D(float x, float y) noexcept;

        bool isEmpty() const noexcept override;

        float getX() const noexcept;
        float getY() const noexcept;
        void setX(float value) noexcept;
        void setY(float value) noexcept;
    };
}

#endif // __HARUPP_COOR2D_HPP__
