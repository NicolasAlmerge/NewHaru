#pragma once
#include "PdfObject.hpp"
#include "ContentStream.hpp"


namespace pdf {
    class PdfDocument;
    class Destination;

    class Outline: public ContentStream {
        Outline(const HPDF_Outline outline);
        friend class PdfDocument;

    public:
        void setOpen(bool opened);
        void setDestination(const Destination* destination);
        void setDestination(const Destination& destination);
    };
}
