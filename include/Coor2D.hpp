#ifndef __HARUPP_COOR2D_HPP__
#define __HARUPP_COOR2D_HPP__
#include "PdfPage.hpp"

namespace pdf {
    class Image;
    class PdfPage;

    class Coor2D final: public PdfObject {
        HPDF_Point innerContent;
        Coor2D(HPDF_Point&& coors);
        friend class Image;
        friend class PdfPage;

    public:
        Coor2D();
        Coor2D(float x, float y);

        bool isEmpty() const override;

        float getX() const;
        float getY() const;
        void setX(float value);
        void setY(float value);
    };
}

#endif // __HARUPP_COOR2D_HPP__
