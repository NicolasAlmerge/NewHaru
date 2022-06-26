#pragma once
#include "hpdf.h"


namespace pdf {
    class PdfObject {
        public:
            virtual ~PdfObject();
            virtual bool isEmpty() const = 0;
            virtual operator bool() const final;
    };
}
