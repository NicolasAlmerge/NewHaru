#pragma once
#include "PdfObject.hpp"


namespace pdf {
    class PdfPage;
    class Annotation;
    class LinkAnnotation;
    class TextAnnotation;
    class Image;
    class Font;
    class Outline;
    class PdfDocument;

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
        bool isEmpty() const final override;
        bool operator==(const ContentStream& other) const;
    };
}
