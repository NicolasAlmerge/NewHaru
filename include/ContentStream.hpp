#ifndef __HARUPP_CONTENTSTREAM_HPP__
#define __HARUPP_CONTENTSTREAM_HPP__
#include "PdfObject.hpp"
#include "hpdf.h"

namespace pdf {

    /**
     * \class  ContentStream
     * @brief  Represents a content stream.
     * @file   ContentStream.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class ContentStream: public PdfObject {
        mutable HPDF_Dict innerContent = nullptr;
        explicit ContentStream(const HPDF_Dict dict);
        friend class PdfPage;
        friend class Annotation;
        friend class LinkAnnotation;
        friend class TextAnnotation;
        friend class PdfDocument;
        friend class Image;
        friend class Font;
        friend class OpenableContent;
        friend class Outline;

    public:
        virtual ~ContentStream() noexcept = 0;

        /**
         * @brief   Checks whether an object is empty.
         * @return `true` if object is empty, `false` otherwise.
        */
        bool isEmpty() const noexcept final override;

        /**
         * @brief   Checks whether two content streams are equal.
         * @return `true` if content streams are equal, `false` otherwise.
        */
        virtual bool operator ==(const ContentStream& other) const noexcept;

        /**
         * @brief   Checks whether two content streams are not equal.
         * @details This is equivalent to `!operator==(other)`.
         * @return `true` if content streams are not equal, `false` otherwise.
        */
        virtual bool operator !=(const ContentStream& other) const noexcept final;
    };
}

#endif // __HARUPP_CONTENTSTREAM_HPP__
