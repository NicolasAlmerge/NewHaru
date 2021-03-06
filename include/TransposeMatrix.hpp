#pragma once
#include "PdfPage.hpp"


namespace pdf {
    class PdfPage;

    class TransposeMatrix: public PdfObject {
        _HPDF_TransMatrix innerContent;
        TransposeMatrix(_HPDF_TransMatrix&& matrix);
        friend class PdfPage;

    public:
        TransposeMatrix();
        TransposeMatrix(float a, float b, float c, float d, float x, float y);

        bool isEmpty() const final override;

        float getA() const;
        float getB() const;
        float getC() const;
        float getD() const;
        float getX() const;
        float getY() const;

        void setA(float value);
        void setB(float value);
        void setC(float value);
        void setD(float value);
        void setX(float value);
        void setY(float value);
    };
}
