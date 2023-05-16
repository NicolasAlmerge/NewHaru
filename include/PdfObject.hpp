#ifndef __HARUPP_PDFOBJECT_HPP__
#define __HARUPP_PDFOBJECT_HPP__

namespace pdf {
    struct PdfObject {
        virtual ~PdfObject();
        virtual bool isEmpty() const noexcept = 0;
        virtual operator bool() const noexcept final;
    };
}

#endif // __HARUPP_PDFOBJECT_HPP__
