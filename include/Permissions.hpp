#ifndef __HARUPP_PERMISSIONS_HPP__
#define __HARUPP_PERMISSIONS_HPP__
#include "PdfObject.hpp"

namespace pdf {
    class Permissions final: public PdfObject {
        unsigned int value = 0UL;
        explicit Permissions(unsigned int v);
        friend class PdfDocument;

    public:
        Permissions() noexcept;
        Permissions(bool canPrint, bool canEditContent, bool canCopy, bool canEditAnnotations) noexcept;

        Permissions operator +(const Permissions& other) const noexcept;
        bool operator ==(const Permissions& other) const noexcept;
        bool operator !=(const Permissions& other) const noexcept;

        bool isEmpty() const noexcept override;

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
