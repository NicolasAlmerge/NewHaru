#pragma once
#include "PdfObject.hpp"


namespace pdf {
    class Outline;
    class PdfDocument;
    class PdfPage;

    class Destination: public PdfObject {
        HPDF_Destination innerContent = nullptr;
        Destination(const HPDF_Destination destination);
        friend class Outline;
        friend class PdfDocument;
        friend class PdfPage;

    public:
        bool isEmpty() const final override;
        void setXYZ(float left, float top, float zoom);
        void setFit();
        void setFitH(float top);
        void setFitV(float left);
        void setFitR(float left, float bottom, float right, float top);
        void setFitB();
        void setFitBH(float top);
        void setFitBV(float top);
    };
}
