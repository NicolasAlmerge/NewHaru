#ifndef __HARUPP_PDFOBJECT_HPP__
#define __HARUPP_PDFOBJECT_HPP__
#include "hpdf.h"

namespace pdf {
    struct PdfObject {
        virtual ~PdfObject();
        virtual bool isEmpty() const = 0;
        virtual operator bool() const final;
    };
}

#endif // __HARUPP_PDFOBJECT_HPP__
