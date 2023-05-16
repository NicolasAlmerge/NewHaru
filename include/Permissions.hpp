#ifndef __HARUPP_PERMISSIONS_HPP__
#define __HARUPP_PERMISSIONS_HPP__
#include "PdfObject.hpp"

namespace pdf {
    class Permissions final: public PdfObject {
        unsigned int value = 0UL;
        Permissions(unsigned int v);
        friend class PdfDocument;

    public:
        Permissions();
        Permissions(bool canPrint, bool canEditContent, bool canCopy, bool canEditAnnotations);

        Permissions operator +(const Permissions& other) const;
        bool operator ==(const Permissions& other) const;
        bool operator !=(const Permissions& other) const;

        bool isEmpty() const override;

        const static Permissions READ_ONLY;
        const static Permissions PRINT;
        const static Permissions EDIT_CONTENT;
        const static Permissions COPY;
        const static Permissions EDIT_ANNOTATIONS;
        const static Permissions EDIT_ALL;
        const static Permissions ALL;
    };
}

#endif // __HARUPP_PERMISSIONS_HPP__
