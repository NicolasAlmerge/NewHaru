#pragma once
#include "Coor2D.hpp"
#include "ContentStream.hpp"
#include "Constants.hpp"
#include "PdfObject.hpp"

namespace pdf {
    typedef unsigned char int8;
    class PdfDocument;

    class Image final: public ContentStream {
        Image(const HPDF_Image content);
        friend class PdfDocument;

    public:
        Coor2D getSize() const;
        unsigned int getWidth() const;
        unsigned int getHeight() const;

        unsigned int getBitsPerComponent() const;
        ColorSpace getColorSpace() const;

        void setColorMask(int8 rmin, int8 rmax, int8 gmin, int8 gmax, int8 bmin, int8 bmax);
        void setMaskImage(const Image& image);
    };
}
