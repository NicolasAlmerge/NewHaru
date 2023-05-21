#include "../include/Exception.hpp"
using namespace pdf::excepts;


Exception::Exception(const char* className, const char* errorMessage, unsigned long errorCode, unsigned long detailCode) noexcept:
    className(className), errorMessage(errorMessage), errorCode(errorCode), detailCode(detailCode) {}

Exception::~Exception() noexcept {}

unsigned long Exception::getErrorCode() const noexcept {
    return errorCode;
}

unsigned long Exception::getDetailCode() const noexcept {
    return detailCode;
}

const char* Exception::what() const noexcept {
    return errorMessage;
}

bool Exception::hasDetailCode() const noexcept {
    return detailCode != 0U;
}

const char* Exception::getName() const noexcept {
    return className;
}

std::string Exception::getFullDescription() const noexcept {
    return std::string(getName()) + std::string(": ") + errorMessage;
}

DocumentException::DocumentException(const char* className, const char* errorMessage, unsigned long errorCode, unsigned long detailCode) noexcept:
    Exception(className, errorMessage, errorCode, detailCode) {}

DocumentException::~DocumentException() noexcept {}

FileException::FileException(const char* className, const char* errorMessage, unsigned long errorCode, unsigned long detailCode) noexcept:
    Exception(className, errorMessage, errorCode, detailCode) {}

FileException::~FileException() noexcept {}

AFMException::AFMException(const char* className, const char* errorMessage, unsigned long errorCode, unsigned long detailCode) noexcept:
    FileException(className, errorMessage, errorCode, detailCode) {}

AFMException::~AFMException() noexcept {}

TTCException::TTCException(const char* className, const char* errorMessage, unsigned long errorCode, unsigned long detailCode) noexcept:
    FileException(className, errorMessage, errorCode, detailCode) {}

TTCException::~TTCException() noexcept {}

TTFException::TTFException(const char* className, const char* errorMessage, unsigned long errorCode, unsigned long detailCode) noexcept:
    FileException(className, errorMessage, errorCode, detailCode) {}

TTFException::~TTFException() noexcept {}

GraphicsException::GraphicsException(const char* className, const char* errorMessage, unsigned long errorCode, unsigned long detailCode) noexcept:
    Exception(className, errorMessage, errorCode, detailCode) {}

GraphicsException::~GraphicsException() noexcept {}

StreamException::StreamException(const char* className, const char* errorMessage, unsigned long errorCode, unsigned long detailCode) noexcept:
    Exception(className, errorMessage, errorCode, detailCode) {}

StreamException::~StreamException() noexcept {}

FontException::FontException(const char* className, const char* errorMessage, unsigned long errorCode, unsigned long detailCode) noexcept:
    StreamException(className, errorMessage, errorCode, detailCode) {}

FontException::~FontException() noexcept {}

PageException::PageException(const char* className, const char* errorMessage, unsigned long errorCode, unsigned long detailCode) noexcept:
    StreamException(className, errorMessage, errorCode, detailCode) {}

PageException::~PageException() noexcept {}

ImageException::ImageException(const char* className, const char* errorMessage, unsigned long errorCode, unsigned long detailCode) noexcept:
    StreamException(className, errorMessage, errorCode, detailCode) {}

ImageException::~ImageException() noexcept {}

OutOfRangeException::OutOfRangeException(const char* className, const char* errorMessage, unsigned long errorCode, unsigned long detailCode) noexcept:
    Exception(className, errorMessage, errorCode, detailCode) {}

OutOfRangeException::~OutOfRangeException() noexcept {}

BinaryLengthTooLongException::BinaryLengthTooLongException() noexcept: OutOfRangeException(
    "BinaryLengthTooLongException",
    "Data length > pdf::consts::MAX_STRING_LEN.",
    0x1004
) {}

TooManyIndirectObjectsException::TooManyIndirectObjectsException() noexcept: OutOfRangeException(
    "TooManyIndirectObjectsException",
    "Dictionary elements > consts::MAX_DICT_ELEMENT",
    0x1007
) {}

EncryptionNotSetException::EncryptionNotSetException() noexcept: DocumentException(
    "EncryptionNotSetException",
    "Document::setR2EncryptMode, Document::setR3EncryptMode or Document::setPermission "
    "has been called before calling Document::setPassword.",
    0x100B
) {}

FontDuplicateRegistrationException::FontDuplicateRegistrationException() noexcept: FontException(
    "FontDuplicateRegistrationException",
    "Tried to re-register a registered font.",
    0x100E
) {}

ExceededJWWCodeNumLimitException::ExceededJWWCodeNumLimitException(unsigned long detailCode) noexcept: FontException(
    "ExceededJWWCodeNumLimitException",
    "Cannot register a character to the Japanese word wrap characters list.",
    0x100F,
    detailCode
) {}

InvalidPasswordException::InvalidPasswordException() noexcept: DocumentException(
    "InvalidPasswordException",
    "Tried to set the owner password to an empty string, or owner and user password are the same.",
    0x1011
) {}

GStateLimitExceededException::GStateLimitExceededException() noexcept: GraphicsException(
    "GStateLimitExceededException",
    "Stack depth > pdf::consts::MAX_GSTATE.",
    0x1014
) {}

MemoryAllocationFailedException::MemoryAllocationFailedException() noexcept: Exception(
    "MemoryAllocationFailedException",
    "Memory allocation failed.",
    0x1015
) {}

FileIOException::FileIOException(unsigned long detailCode) noexcept: FileException(
    "FileIOException",
    "File processing failed.",
    0x1016,
    detailCode
) {}

FileOpeningException::FileOpeningException(unsigned long detailCode) noexcept: FileException(
    "FileOpeningException",
    "Could not open a file.",
    0x1017,
    detailCode
) {}

FontAlreadyExistsException::FontAlreadyExistsException() noexcept: FontException(
    "FontAlreadyExistsException",
    "Tried to load a font that has been registered.",
    0x1019
) {}

FontInvalidWidthsTableException::FontInvalidWidthsTableException() noexcept: FontException(
    "FontInvalidWidthsTableException",
    "Font-file format is invalid.",
    0x101A
) {}

InvalidAFMHeaderFileException::InvalidAFMHeaderFileException() noexcept: AFMException(
    "InvalidAFMHeaderFileException",
    "Cannot recognize header of AFM file.",
    0x101B
) {}

NonMatchingBitsPerComponentException::NonMatchingBitsPerComponentException() noexcept: ImageException(
    "NonMatchingBitsPerComponentException",
    "Bit-per-component of a pdf::Image which was set as mask-image is invalid.",
    0x101E
) {}

InvalidAFMCharMatricsDataException::InvalidAFMCharMatricsDataException() noexcept: AFMException(
    "InvalidAFMCharMatricsDataException",
    "Cannot recognize char matrics data of AFM file.",
    0x101F
) {}

InvalidColorSpaceException::InvalidColorSpaceException() noexcept: ImageException(
    "InvalidColorSpaceException",
    "Invalid color space parameter when loading a pdf::Image, color space of a pdf::Image "
    "which was set as mask image is invalid or invoked function invalid in present color space.",
    0x1020
) {}

InvalidDateTimeException::InvalidDateTimeException() noexcept: Exception(
    "InvalidDateTimeException",
    "An invalid date-time value was set.",
    0x1022
) {}

PageAlreadyExistsException::PageAlreadyExistsException() noexcept: DocumentException(
    "PageAlreadyExistsException",
    "A page has already been defined in the document",
    0x1026
) {}

InvalidEncoderTypeException::InvalidEncoderTypeException() noexcept: FontException(
    "InvalidEncoderTypeException",
    "Combination between font and encoder is wrong.",
    0x1028
) {}

InvalidEncodingNameException::InvalidEncodingNameException() noexcept: Exception(
    "InvalidEncodingNameException",
    "An invalid encoding name was specified.",
    0x102B
) {}

InvalidR3EncryptionKeyLengthException::InvalidR3EncryptionKeyLengthException() noexcept: DocumentException(
    "InvalidR3EncryptionKeyLengthException",
    "R3 encryption key length is invalid.",
    0x102C
) {}

InvalidFontNameException::InvalidFontNameException() noexcept: FontException(
    "InvalidFontNameException",
    "An invalid font name was specified.",
    0x102F
) {}

InvalidImageException::InvalidImageException() noexcept: ImageException(
    "InvalidImageException",
    "Invalid image data.",
    0x1030
) {}

InvalidAFMFileNDataException::InvalidAFMFileNDataException() noexcept: AFMException(
    "InvalidAFMFileNDataException",
    "Cannot read a postscript name from an AFM file.",
    0x1032
) {}

InvalidImageOperationException::InvalidImageOperationException() noexcept: ImageException(
    "InvalidImageOperationException",
    "Invoked pdf::Image::setColorMask against the image object which was set a mask image.",
    0x1035
) {}

InvalidParameterException::InvalidParameterException() noexcept: OutOfRangeException(
    "InvalidParameterException",
    "An invalid value was set.",
    0x1039
) {}

InvalidPNGImageException::InvalidPNGImageException() noexcept: ImageException(
    "InvalidPNGImageException",
    "Invalid PNG image format.",
    0x103B
) {}

InvalidTTCFileException::InvalidTTCFileException() noexcept: TTCException(
    "InvalidTTCFileException",
    "Invalid .TTC file format.",
    0x103F
) {}

InvalidTTCIndexException::InvalidTTCIndexException() noexcept: TTCException(
    "InvalidTTCIndexException",
    "Index parameter > number of included fonts.",
    0x1040
) {}

InvalidAFMWidthException::InvalidAFMWidthException() noexcept: AFMException(
    "InvalidAFMWidthException",
    "Cannot read a width data from an AFM file.",
    0x1041
) {}

LibPNGException::LibPNGException(unsigned long detailCode) noexcept: ImageException(
    "LibPNGException",
    "Error returned from PNGLIB while loading a pdf::Image.",
    0x1043,
    detailCode
) {}

NoGStateException::NoGStateException() noexcept: GraphicsException(
    "NoGStateException",
    "There are no graphics states to be restored.",
    0x104C
) {}

FontNotFoundException::FontNotFoundException() noexcept: FontException(
    "FontNotFoundException",
    "The current font is not set.",
    0x104E
) {}

InvalidFontSizeException::InvalidFontSizeException(unsigned long detailCode) noexcept: FontException(
    "InvalidFontSizeException",
    "An invalid font size was set.",
    0x1050,
    detailCode
) {}

InvalidGModeException::InvalidGModeException() noexcept: GraphicsException(
    "InvalidGModeException",
    "Invalid Graphics Mode.",
    0x1051
) {}

InvalidPageSizeException::InvalidPageSizeException() noexcept: PageException(
    "InvalidPageSizeException",
    "An invalid page size was set.",
    0x1054
) {}

PageValueOutOfRangeException::PageValueOutOfRangeException() noexcept: PageException(
    "PageValueOutOfRangeException",
    "The specified value is out of range.",
    0x1056
) {}

FloatValueOutOfRangeException::FloatValueOutOfRangeException() noexcept: FloatValueOutOfRangeException(
    "The specified value is out of range.",
    0UL
) {}

FloatValueOutOfRangeException::FloatValueOutOfRangeException(const char* message, unsigned long detailCode) noexcept: OutOfRangeException(
    "FloatValueOutOfRangeException",
    message,
    0x1057,
    detailCode
) {}

StringOutOfRangeException::StringOutOfRangeException() noexcept: OutOfRangeException(
    "StringOutOfRangeException",
    "The length of the text is too long.",
    0x105B
) {}

CannotEmbedTTFFontException::CannotEmbedTTFFontException() noexcept: TTFException(
    "CannotEmbedTTFFontException",
    "Font cannot be embedded (license restriction).",
    0x105D
) {}

InvalidTTFCMapException::InvalidTTFCMapException() noexcept: TTFException(
    "InvalidTTFCMapException",
    "Unsupported TTF format (cannot find unicode cmap).",
    0x105E
) {}

InvalidTTFFormatException::InvalidTTFFormatException() noexcept: TTFException(
    "InvalidTTFFormatException",
    "Unsupported TTF format.",
    0x105F
) {}

MissingTTFTableException::MissingTTFTableException() noexcept: TTFException(
    "MissingTTFTableException",
    "Unsupported ttf format (cannot find a necessary table).",
    0x1060
) {}

UnsupportedFunctionException::UnsupportedFunctionException() noexcept: GraphicsException(
    "UnsupportedFunctionException",
    "Library not configured to use PNGLIB.",
    0x1062
) {}

UnsupportedJPEGFormatException::UnsupportedJPEGFormatException() noexcept: ImageException(
    "UnsupportedJPEGFormatException",
    "Unsupported JPEG format.",
    0x1063
) {}

UnsupportedType1FontException::UnsupportedType1FontException() noexcept: FileException(
    "UnsupportedType1FontException",
    "Failed to parse .PFB file.",
    0x1064
) {}

ZLibException::ZLibException(unsigned long detailCode) noexcept: Exception(
    "ZLibException",
    "Error while executing a ZLIB function.",
    0x1066,
    detailCode
) {}

InvalidPageIndexException::InvalidPageIndexException() noexcept: DocumentException(
    "InvalidPageIndexException",
    "An invalid page index was passed.",
    0x1067
) {}

EmptyURIException::EmptyURIException() noexcept: PageException(
    "EmptyURIException",
    "An empty URI was set.",
    0x1068
) {}

InvalidPageLayoutException::InvalidPageLayoutException() noexcept: PageException(
    "InvalidPageLayoutException",
    "Page layout could not be determined.",
    0x1069
) {}

InvalidPageModeException::InvalidPageModeException() noexcept: PageException(
    "InvalidPageModeException",
    "Page mode could not be determined.",
    0x1070
) {}

UndefinedException::UndefinedException(unsigned long errorCode, unsigned long detailCode) noexcept: Exception(
    "UndefinedException",
    "Error code is not valid.",
    errorCode,
    detailCode
) {}
