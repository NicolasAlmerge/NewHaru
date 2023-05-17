#ifndef __HARUPP_OUTLINE_HPP__
#define __HARUPP_OUTLINE_HPP__
#include "ContentStream.hpp"
#include "PdfObject.hpp"

namespace pdf {
    class Destination;

    class Outline: public ContentStream {
        explicit Outline(const HPDF_Outline outline);
        friend class PdfDocument;

    public:
        void setOpen(bool opened);
        void setDestination(const Destination& destination);
    };
}

#endif // __HARUPP_OUTLINE_HPP__
