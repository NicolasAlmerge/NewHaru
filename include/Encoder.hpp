#ifndef __HARUPP_ENCODER_HPP__
#define __HARUPP_ENCODER_HPP__
#include "Constants.hpp"
#include "PdfObject.hpp"
#include "hpdf.h"
#include "string"

namespace pdf {
    class Encoder final: public PdfObject {
        mutable HPDF_Encoder innerContent = nullptr;
        Encoder(const HPDF_Encoder coors);
        friend class PdfDocument;
        friend class PdfPage;

    public:
        bool isEmpty() const noexcept override;
        EncoderType getType() const;
        ByteType getByteType(const std::string& text, unsigned int index) const;
        unsigned short getUnicode(unsigned short code) const;
        WritingMode getWritingMode() const;
    };
}

#endif // __HARUPP_ENCODER_HPP__
