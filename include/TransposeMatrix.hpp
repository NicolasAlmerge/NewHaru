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
        TransposeMatrix() noexcept;
        TransposeMatrix(float a, float b, float c, float d, float x, float y) noexcept;

        bool isEmpty() const noexcept override;

        float getA() const noexcept;
        float getB() const noexcept;
        float getC() const noexcept;
        float getD() const noexcept;
        float getX() const noexcept;
        float getY() const noexcept;
    };
}

#endif // __HARUPP_TRANSPOSEMATRIX_HPP__
