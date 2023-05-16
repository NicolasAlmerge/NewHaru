#ifndef __HARUPP_CONTENTSTREAM_HPP__
#define __HARUPP_CONTENTSTREAM_HPP__
#include "PdfObject.hpp"
#include "hpdf.h"

namespace pdf {
    class ContentStream: public PdfObject {
        mutable HPDF_Dict innerContent = nullptr;
        ContentStream(const HPDF_Dict dict);
        friend class PdfPage;
        friend class Annotation;
        friend class LinkAnnotation;
        friend class TextAnnotation;
        friend class PdfDocument;
        friend class Image;
        friend class Font;
        friend class Outline;

    public:
        virtual ~ContentStream() = 0;
        bool isEmpty() const noexcept final override;
        bool operator ==(const ContentStream& other) const noexcept;
        bool operator !=(const ContentStream& other) const noexcept;
    };
}

#endif // __HARUPP_CONTENTSTREAM_HPP__
