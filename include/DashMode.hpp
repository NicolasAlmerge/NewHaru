#pragma once
#include "PdfObject.hpp"


namespace pdf {
    class PdfPage;

    class DashMode {
        HPDF_DashMode innerContent;
        DashMode(HPDF_DashMode&& box);
        friend class PdfPage;

    public:
        float* getPtn() const;
        unsigned int getNumberPtn() const;
        unsigned int getPhase() const;
        void setPtn(unsigned short value[8]);
        void setNumberPtn(unsigned int value);
        void setPhase(unsigned int value);
    };
}
