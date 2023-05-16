#ifndef __HARUPP_TRANSPOSEMATRIX_HPP__
#define __HARUPP_TRANSPOSEMATRIX_HPP__
#include "PdfObject.hpp"
#include "hpdf.h"

namespace pdf {
    class TransposeMatrix final: public PdfObject {
        HPDF_TransMatrix innerContent;
        TransposeMatrix(HPDF_TransMatrix&& matrix);
        friend class PdfPage;

    public:
        TransposeMatrix();
        TransposeMatrix(float a, float b, float c, float d, float x, float y);

        bool isEmpty() const override;

        float getA() const;
        float getB() const;
        float getC() const;
        float getD() const;
        float getX() const;
        float getY() const;
    };
}

#endif // __HARUPP_TRANSPOSEMATRIX_HPP__
