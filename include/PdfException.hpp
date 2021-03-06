#pragma once
#include "iostream"


namespace pdf {
    // Base pdf exception class
    class PdfException: public std::exception {
        const char* errorMessage;
        unsigned long errorCode;
        unsigned long detailCode;
        bool _hasDetailCode;

    public:
        PdfException(const char* data, unsigned long errorCode, unsigned long detailCode, bool hasDetailCode = false) noexcept;
        PdfException(const std::string& data, unsigned long errorCode, unsigned long detailCode, bool hasDetailCode = false) noexcept;
        virtual ~PdfException() noexcept = 0;

        virtual const char* what() const noexcept override final;
        virtual unsigned long getErrorCode() const noexcept final;
        virtual unsigned long getDetailCode() const noexcept final;
        virtual bool hasDetailCode() const noexcept final;

        virtual const char* getName() const noexcept = 0;
        virtual std::string getFullDescription() const noexcept final;
    };

    // Failed to create a new pdf
    class NewPdfCreationFailedException: public PdfException {
        using PdfException::PdfException;
        public: const char* getName() const noexcept override {
            return "NewPdfCreationFailedException";
        }
    };

    // Stream related exceptions
    class StreamException: public PdfException {
        using PdfException::PdfException;
        public: virtual ~StreamException() noexcept = 0;
    };

    // Array related exceptions
    class ArrayException: public PdfException {
        using PdfException::PdfException;
        public: virtual ~ArrayException() noexcept = 0;
    };

    // Error code 0x1001
    class ArrayCountException: public ArrayException {
        using ArrayException::ArrayException;
        public: const char* getName() const noexcept override {
            return "ArrayCountException";
        }
    };

    // Error code 0x1002
    class ArrayItemNotFoundException: public ArrayException {
        using ArrayException::ArrayException;
        public: const char* getName() const noexcept override {
            return "ArrayItemNotFoundException";
        }
    };

    // Error code 0x1003
    class ArrayItemUnexpectedTypeException: public ArrayException {
        using ArrayException::ArrayException;
        public: const char* getName() const noexcept override {
            return "ArrayItemUnexpectedTypeException";
        }
    };

    // Error code 0x1004
    class BinaryLengthException: public PdfException {
        using PdfException::PdfException;
        public: const char* getName() const noexcept override {
            return "BinaryLengthException";
        }
    };

    // Image related exceptions
    class ImageException: public StreamException {
        using StreamException::StreamException;
        public: virtual ~ImageException() noexcept = 0;
    };

    // Error code 0x1005
    class CannotGetPNGImagePalletException: public ImageException {
        using ImageException::ImageException;
        public: const char* getName() const noexcept override {
            return "CannotGetPNGImagePalletException";
        }
    };

    // Dictionary related exceptions
    class DictException: public PdfException {
        using PdfException::PdfException;
        public: virtual ~DictException() noexcept = 0;
    };

    // Error code 0x1007
    class DictCountException: public DictException {
        using DictException::DictException;
        public: const char* getName() const noexcept override {
            return "DictCountException";
        }
    };

    // Error code 0x1008
    class DictItemNotFoundException: public DictException {
        using DictException::DictException;
        public: const char* getName() const noexcept override {
            return "DictItemNotFoundException";
        }
    };

    // Error code 0x1009
    class DictItemUnexpectedTypeException: public DictException {
        using DictException::DictException;
        public: const char* getName() const noexcept override {
            return "DictItemUnexpectedTypeException";
        }
    };

    // Error code 0x100A
    class DictStreamLengthNotFoundException: public DictException {
        using DictException::DictException;
        public: const char* getName() const noexcept override {
            return "DictStreamLengthNotFoundException";
        }
    };

    // Error code 0x100B
    class EncryptionNotSetException: public PdfException {
        using PdfException::PdfException;
        public: const char* getName() const noexcept override {
            return "EncryptionNotSetException";
        }
    };

    // File related exceptions
    class DocumentException: public PdfException {
        using PdfException::PdfException;
        public: virtual ~DocumentException() noexcept = 0;
    };

    // Error code 0x100C
    class DocInvalidObjectException: public DocumentException {
        using DocumentException::DocumentException;
        public: const char* getName() const noexcept override {
            return "DocInvalidObjectException";
        }
    };

    // Font related exceptions
    class FontException: public StreamException {
        using StreamException::StreamException;
        public: virtual ~FontException() noexcept = 0;
    };

    // Error code 0x100E
    class FontDuplicateRegistrationException: public FontException {
        using FontException::FontException;
        public: const char* getName() const noexcept override {
            return "FontDuplicateRegistrationException";
        }
    };

    // Error code 0x100F
    class ExceededJWWCodeNumLimitException: public PdfException {
        using PdfException::PdfException;
        public: const char* getName() const noexcept override {
            return "ExceededJWWCodeNumLimitException";
        }
    };

    // Error code 0x1011
    class InvalidPasswordException: public PdfException {
        using PdfException::PdfException;
        public: const char* getName() const noexcept override {
            return "InvalidPasswordException";
        }
    };

    // Error code 0x1013
    class UnknownClassException: public PdfException {
        using PdfException::PdfException;
        public: const char* getName() const noexcept override {
            return "UnknownClassException";
        }
    };

    // Error code 0x1014
    class GStateLimitExceededException: public PdfException {
        using PdfException::PdfException;
        public: const char* getName() const noexcept override {
            return "GStateLimitExceededException";
        }
    };

    // Error code 0x1015
    class MemoryAllocationFailedException: public PdfException {
        using PdfException::PdfException;
        public: const char* getName() const noexcept override {
            return "MemoryAllocationFailedException";
        }
    };

    // File related exceptions
    class FileException: public PdfException {
        using PdfException::PdfException;
        public: virtual ~FileException() noexcept = 0;
    };

    // Error code 0x1016
    class FileIOException: public FileException {
        using FileException::FileException;
        public: const char* getName() const noexcept override {
            return "FileIOException";
        }
    };

    // Error code 0x1017
    class FileOpenException: public FileException {
        using FileException::FileException;
        public: const char* getName() const noexcept override {
            return "FileOpenException";
        }
    };

    // Error code 0x1019
    class FontExistsException: public FontException {
        using FontException::FontException;
        public: const char* getName() const noexcept override {
            return "FontExistsException";
        }
    };

    // Error code 0x101A
    class FontInvalidWidthTableException: public FontException {
        using FontException::FontException;
        public: const char* getName() const noexcept override {
            return "FontInvalidWidthTableException";
        }
    };

    // Error code 0x101B
    class InvalidAFMHeaderException: public PdfException {
        using PdfException::PdfException;
        public: const char* getName() const noexcept override {
            return "InvalidAFMHeaderException";
        }
    };

    // Error code 0x101C
    class InvalidAnnotationException: public PdfException {
        using PdfException::PdfException;
        public: const char* getName() const noexcept override {
            return "InvalidAnnotationException";
        }
    };

    // Error code 0x101E
    class InvalidBitPerComponentException: public PdfException {
        using PdfException::PdfException;
        public: const char* getName() const noexcept override {
            return "InvalidBitPerComponentException";
        }
    };

    // Error code 0x101F
    class InvalidCharMatricsDataException: public PdfException {
        using PdfException::PdfException;
        public: const char* getName() const noexcept override {
            return "InvalidCharMatricsDataException";
        }
    };

    // Error code 0x1020
    class InvalidColorSpaceException: public PdfException {
        using PdfException::PdfException;
        public: const char* getName() const noexcept override {
            return "InvalidColorSpaceException";
        }
    };

    // Error code 0x1021
    class InvalidCompressionModeException: public PdfException {
        using PdfException::PdfException;
        public: const char* getName() const noexcept override {
            return "InvalidCompressionModeException";
        }
    };

    // Error code 0x1022
    class InvalidDateTimeException: public PdfException {
        using PdfException::PdfException;
        public: const char* getName() const noexcept override {
            return "InvalidDateTimeException";
        }
    };

    // Error code 0x1023
    class InvalidDestinationException: public PdfException {
        using PdfException::PdfException;
        public: const char* getName() const noexcept override {
            return "InvalidDestinationException";
        }
    };

    // Error code 0x1025
    class InvalidDocumentException: public DocumentException {
        using DocumentException::DocumentException;
        public: const char* getName() const noexcept override {
            return "InvalidDocumentException";
        }
    };

    // Error code 0x1026
    class InvalidDocumentStateException: public DocumentException {
        using DocumentException::DocumentException;
        public: const char* getName() const noexcept override {
            return "InvalidDocumentStateException";
        }
    };

    // Encoder related exceptions
    class EncoderException: public PdfException {
        using PdfException::PdfException;
        public: virtual ~EncoderException() noexcept = 0;
    };

    // Error code 0x1027
    class InvalidEncoderException: public EncoderException {
        using EncoderException::EncoderException;
        public: const char* getName() const noexcept override {
            return "InvalidEncoderException";
        }
    };

    // Error code 0x1028
    class InvalidEncoderTypeException: public EncoderException {
        using EncoderException::EncoderException;
        public: const char* getName() const noexcept override {
            return "InvalidEncoderTypeException";
        }
    };

    // Error code 0x102B
    class InvalidEncoderNameException: public EncoderException {
        using EncoderException::EncoderException;
        public: const char* getName() const noexcept override {
            return "InvalidEncoderNameException";
        }
    };

    // Error code 0x102C
    class InvalidEncryptionKeyLengthException: public PdfException {
        using PdfException::PdfException;
        public: const char* getName() const noexcept override {
            return "InvalidEncryptionKeyLengthException";
        }
    };

    // Error code 0x102D
    class InvalidFontDefDataException: public FontException {
        using FontException::FontException;
        public: const char* getName() const noexcept override {
            return "InvalidFontDefDataException";
        }
    };

    // Error code 0x102E
    class InvalidFontDefTypeException: public FontException {
        using FontException::FontException;
        public: const char* getName() const noexcept override {
            return "InvalidFontDefTypeException";
        }
    };

    // Error code 0x102F
    class InvalidFontNameException: public FontException {
        using FontException::FontException;
        public: const char* getName() const noexcept override {
            return "InvalidFontNameException";
        }
    };

    // Error code 0x1030
    class InvalidImageException: public ImageException {
        using ImageException::ImageException;
        public: const char* getName() const noexcept override {
            return "InvalidImageException";
        }
    };

    // Error code 0x1031
    class InvalidJPEGDataException: public ImageException {
        using ImageException::ImageException;
        public: const char* getName() const noexcept override {
            return "InvalidJPEGDataException";
        }
    };

    // Error code 0x1032
    class InvalidNDataException: public PdfException {
        using PdfException::PdfException;
        public: const char* getName() const noexcept override {
            return "InvalidNDataException";
        }
    };

    // Error code 0x1033
    class InvalidObjectException: public PdfException {
        using PdfException::PdfException;
        public: const char* getName() const noexcept override {
            return "InvalidObjectException";
        }
    };

    // Error code 0x1034
    class InvalidObjectIDException: public PdfException {
        using PdfException::PdfException;
        public: const char* getName() const noexcept override {
            return "InvalidObjectIDException";
        }
    };

    // Error code 0x1035
    class InvalidImageOperationException: public ImageException {
        using ImageException::ImageException;
        public: const char* getName() const noexcept override {
            return "InvalidImageOperationException";
        }
    };

    // Error code 0x1036
    class InvalidOutlineException: public PdfException {
        using PdfException::PdfException;
        public: const char* getName() const noexcept override {
            return "InvalidOutlineException";
        }
    };

    // Page related exceptions
    class PageException: public StreamException {
        using StreamException::StreamException;
        public: virtual ~PageException() noexcept = 0;
    };

    // Error code 0x1037
    class InvalidPageException: public PageException {
        using PageException::PageException;
        public: const char* getName() const noexcept override {
            return "InvalidPageException";
        }
    };

    // Error code 0x1038
    class InvalidInternalPagesException: public PageException {
        using PageException::PageException;
        public: const char* getName() const noexcept override {
            return "InvalidInternalPagesException";
        }
    };

    // Error code 0x1039
    class InvalidParameterException: public PdfException {
        using PdfException::PdfException;
        public: const char* getName() const noexcept override {
            return "InvalidParameterException";
        }
    };

    // Error code 0x103B
    class InvalidPNGImageException: public ImageException {
        using ImageException::ImageException;
        public: const char* getName() const noexcept override {
            return "InvalidPNGImageException";
        }
    };

    // Error code 0x103C
    class InvalidStreamException: public StreamException {
        using StreamException::StreamException;
        public: const char* getName() const noexcept override {
            return "InvalidStreamException";
        }
    };

    // Error code 0x103D
    class MissingFileNameEntryException: public FileException {
        using FileException::FileException;
        public: const char* getName() const noexcept override {
            return "MissingFileNameEntryException";
        }
    };

    // Error code 0x103F
    class InvalidTTCFileException: public FileException {
        using FileException::FileException;
        public: const char* getName() const noexcept override {
            return "InvalidTTCFileException";
        }
    };

    // Error code 0x1040
    class InvalidTTCIndexException: public PdfException {
        using PdfException::PdfException;
        public: const char* getName() const noexcept override {
            return "InvalidTTCIndexException";
        }
    };

    // Error code 0x1041
    class InvalidWXDataException: public PdfException {
        using PdfException::PdfException;
        public: const char* getName() const noexcept override {
            return "InvalidWXDataException";
        }
    };

    // Error code 0x1042
    class ItemNotFoundException: public PdfException {
        using PdfException::PdfException;
        public: const char* getName() const noexcept override {
            return "ItemNotFoundException";
        }
    };

    // Error code 0x1043
    class LibPNGException: public PdfException {
        using PdfException::PdfException;
        public: const char* getName() const noexcept override {
            return "LibPNGException";
        }
    };

    // Error code 0x1044
    class NameInvalidValueException: public PdfException {
        using PdfException::PdfException;
        public: const char* getName() const noexcept override {
            return "NameInvalidValueException";
        }
    };

    // Error code 0x1045
    class NameOutOfRangeException: public PdfException {
        using PdfException::PdfException;
        public: const char* getName() const noexcept override {
            return "NameOutOfRangeException";
        }
    };

    // Error code 0x1049
    class PagesMissingKidsEntryException: public PageException {
        using PageException::PageException;
        public: const char* getName() const noexcept override {
            return "PagesMissingKidsEntryException";
        }
    };

    // Error code 0x104A
    class PageCannotFindObjectException: public PageException {
        using PageException::PageException;
        public: const char* getName() const noexcept override {
            return "PageCannotFindObjectException";
        }
    };

    // Error code 0x104B
    class PageCannotGetRootPagesException: public PageException {
        using PageException::PageException;
        public: const char* getName() const noexcept override {
            return "PageCannotGetRootPagesException";
        }
    };

    // Error code 0x104C
    class PageCannotRestoreGStateException: public PageException {
        using PageException::PageException;
        public: const char* getName() const noexcept override {
            return "PageCannotRestoreGStateException";
        }
    };

    // Error code 0x104D
    class PageCannotSetParentException: public PageException {
        using PageException::PageException;
        public: const char* getName() const noexcept override {
            return "PageCannotSetParentException";
        }
    };

    // Error code 0x104E
    class PageFontNotFoundException: public PageException {
        using PageException::PageException;
        public: const char* getName() const noexcept override {
            return "PageFontNotFoundException";
        }
    };

    // Error code 0x104F
    class PageInvalidFontException: public PageException {
        using PageException::PageException;
        public: const char* getName() const noexcept override {
            return "PageInvalidFontException";
        }
    };

    // Error code 0x1050
    class PageInvalidFontSizeException: public PageException {
        using PageException::PageException;
        public: const char* getName() const noexcept override {
            return "PageInvalidFontSizeException";
        }
    };

    // Error code 0x1051
    class PageInvalidGModeException: public PageException {
        using PageException::PageException;
        public: const char* getName() const noexcept override {
            return "PageInvalidGModeException";
        }
    };

    // Error code 0x1052
    class PageInvalidIndexException: public PageException {
        using PageException::PageException;
        public: const char* getName() const noexcept override {
            return "PageInvalidIndexException";
        }
    };

    // Error code 0x1053
    class PageInvalidRotateValueException: public PageException {
        using PageException::PageException;
        public: const char* getName() const noexcept override {
            return "PageInvalidRotateValueException";
        }
    };

    // Error code 0x1054
    class PageInvalidSizeException: public PageException {
        using PageException::PageException;
        public: const char* getName() const noexcept override {
            return "PageInvalidSizeException";
        }
    };

    // Error code 0x1055
    class PageInvalidXObjectException: public PageException {
        using PageException::PageException;
        public: const char* getName() const noexcept override {
            return "PageInvalidXObjectException";
        }
    };

    // Error code 0x1056
    class PageOutOfRangeException: public PageException {
        using PageException::PageException;
        public: const char* getName() const noexcept override {
            return "PageOutOfRangeException";
        }
    };

    // Error code 0x1057
    class FloatOutOfRangeException: public PdfException {
        using PdfException::PdfException;
        public: const char* getName() const noexcept override {
            return "FloatOutOfRangeException";
        }
    };

    // Error code 0x1058
    class StreamEOFException: public StreamException {
        using StreamException::StreamException;
        public: const char* getName() const noexcept override {
            return "StreamEOFException";
        }
    };

    // Error code 0x1059
    class StreamReadLnContinue: public StreamException {
        using StreamException::StreamException;
        public: const char* getName() const noexcept override {
            return "StreamReadLnContinue";
        }
    };

    // Error code 0x105B
    class StringOutOfRangeException: public PdfException {
        using PdfException::PdfException;
        public: const char* getName() const noexcept override {
            return "StringOutOfRangeException";
        }
    };

    // Error code 0x105C
    class FunctionSkippedException: public PdfException {
        using PdfException::PdfException;
        public: const char* getName() const noexcept override {
            return "FunctionSkippedException";
        }
    };

    // Error code 0x105D
    class TTFCannotEmbedFontException: public FontException {
        using FontException::FontException;
        public: const char* getName() const noexcept override {
            return "TTFCannotEmbedFontException";
        }
    };

    // Error code 0x105E
    class TTFInvalidCMAPException: public FontException {
        using FontException::FontException;
        public: const char* getName() const noexcept override {
            return "TTFInvalidCMAPException";
        }
    };

    // Error code 0x105F
    class TTFInvalidFormatException: public FontException {
        using FontException::FontException;
        public: const char* getName() const noexcept override {
            return "TTFInvalidFormatException";
        }
    };

    // Error code 0x1060
    class TTFMissingTableException: public FontException {
        using FontException::FontException;
        public: const char* getName() const noexcept override {
            return "TTFMissingTableException";
        }
    };

    // Error code 0x1061
    class UnsupportedFontTypeException: public FontException {
        using FontException::FontException;
        public: const char* getName() const noexcept override {
            return "UnsupportedFontTypeException";
        }
    };

    // Error code 0x1062
    class UnsupportedFunctionException: public PdfException {
        using PdfException::PdfException;
        public: const char* getName() const noexcept override {
            return "UnsupportedFunctionException";
        }
    };

    // Error code 0x1063
    class UnsupportedJPEGFormatException: public ImageException {
        using ImageException::ImageException;
        public: const char* getName() const noexcept override {
            return "UnsupportedJPEGFormatException";
        }
    };

    // Error code 0x1064
    class UnsupportedType1FontException: public FontException {
        using FontException::FontException;
        public: const char* getName() const noexcept override {
            return "UnsupportedType1FontException";
        }
    };

    // Error code 0x1065
    class XRefCountException: public PdfException {
        using PdfException::PdfException;
        public: const char* getName() const noexcept override {
            return "XRefCountException";
        }
    };

    // Error code 0x1066
    class ZLIBException: public PdfException {
        using PdfException::PdfException;
        public: const char* getName() const noexcept override {
            return "ZLIBException";
        }
    };

    // Error code 0x1067
    class InvalidPageIndexException: public PageException {
        using PageException::PageException;
        public: const char* getName() const noexcept override {
            return "InvalidPageIndexException";
        }
    };

    // Error code 0x1068
    class InvalidURIException: public PdfException {
        using PdfException::PdfException;
        public: const char* getName() const noexcept override {
            return "InvalidURIException";
        }
    };

    // Error code 0x1069
    class PageLayoutOutOfRangeException: public PdfException {
        using PdfException::PdfException;
        public: const char* getName() const noexcept override {
            return "PageLayoutOutOfRangeException";
        }
    };

    // Error code 0x1070
    class PageModeOutOfRangeException: public PageException {
        using PageException::PageException;
        public: const char* getName() const noexcept override {
            return "PageModeOutOfRangeException";
        }
    };

    // Error code 0x1071
    class PageNumStyleOutOfRangeException: public PageException {
        using PageException::PageException;
        public: const char* getName() const noexcept override {
            return "PageNumStyleOutOfRangeException";
        }
    };

    // Annotation related exceptions
    class AnnotationException: public PdfException {
        using PdfException::PdfException;
        public: virtual ~AnnotationException() noexcept = 0;
    };

    // Error code 0x1072
    class AnnotationInvalidIconException: public AnnotationException {
        using AnnotationException::AnnotationException;
        public: const char* getName() const noexcept override {
            return "AnnotationInvalidIconException";
        }
    };

    // Error code 0x1073
    class AnnotationInvalidBorderStyleException: public AnnotationException {
        using AnnotationException::AnnotationException;
        public: const char* getName() const noexcept override {
            return "AnnotationInvalidBorderStyleException";
        }
    };

    // Error code 0x1074
    class InvalidPageDirectionException: public PageException {
        using PageException::PageException;
        public: const char* getName() const noexcept override {
            return "InvalidPageDirectionException";
        }
    };

    // Error code 0x1075
    class InvalidFontException: public FontException {
        using FontException::FontException;
        public: const char* getName() const noexcept override {
            return "InvalidFontException";
        }
    };

    // Other exceptions
    class OtherException: public PdfException {
        using PdfException::PdfException;
        public: virtual ~OtherException() noexcept = 0;
    };

    // Undefined error codes
    class UndefinedException: public OtherException {
        using OtherException::OtherException;
        public: const char* getName() const noexcept override {
            return "UndefinedException";
        }
    };

    // Invalid error codes
    class InvalidException: public OtherException {
        using OtherException::OtherException;
        public: const char* getName() const noexcept override {
            return "InvalidException";
        }
    };
}
