#ifndef __HARUPP_ENCODER_HPP__
#define __HARUPP_ENCODER_HPP__
#include "Constants.hpp"
#include "PdfObject.hpp"
#include "hpdf.h"
#include "string"

namespace pdf {

    /**
     * \class  Encoder
     * @brief  Represents an encoder.
     * @note   Note that this class cannot be instantiated manually. Rather, it is created when calling PdfDocument::getCurrentEncoder and PdfDocument::getEncoder.
     * @file   Encoder.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class Encoder final: public PdfObject {
        mutable HPDF_Encoder innerContent = nullptr;
        explicit Encoder(const HPDF_Encoder coors);
        friend class PdfDocument;
        friend class PdfPage;

    public:

        /**
         * @brief  Checks whether an encoder has been set.
         * @return `true` if an encoder is set, `false` otherwise.
        */
        bool isEmpty() const noexcept override;

        /**
         * @brief  Gets the encoder type.
         * @return Encoder type.
        */
        EncoderType getType() const;

        /**
         * @brief  Gets the byte type.
         * @param  text Text to use.
         * @param  index Index to use.
         * @return Byte type.
        */
        ByteType getByteType(const std::string& text, unsigned int index) const;

        /**
         * @brief  Gets the unicode of a code.
         * @param  code Code to use.
         * @return Unicode of the code.
        */
        unsigned short getUnicode(unsigned short code) const;

        /**
         * @brief  Gets the writing mode.
         * @return Writing mode.
        */
        WritingMode getWritingMode() const;
    };
}

#endif // __HARUPP_ENCODER_HPP__
