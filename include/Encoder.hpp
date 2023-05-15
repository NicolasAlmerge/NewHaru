#ifndef __HARUPP_ENCODER_HPP__
#define __HARUPP_ENCODER_HPP__
#include "PdfObject.hpp"
#include "Constants.hpp"
#include "string"

namespace pdf {
    class PdfDocument;
    class PdfPage;

    class Encoder: public PdfObject {
        mutable HPDF_Encoder innerContent = nullptr;
        Encoder(const HPDF_Encoder coors);
        friend class PdfDocument;
        friend class PdfPage;

    public:
        Encoder();
        bool isEmpty() const final override;
        EncoderType getType() const;
        ByteType getByteType(const char* text, unsigned int index) const;
        ByteType getByteType(const std::string& text, unsigned int index) const;
        unsigned short getUnicode(unsigned short code) const;
        WritingMode getWritingMode() const;
    };
}

#endif // __HARUPP_ENCODER_HPP__
