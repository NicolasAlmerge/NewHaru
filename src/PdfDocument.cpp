#include "../include/PdfDocument.hpp"
#include "hpdf.h"
using namespace pdf;
using namespace pdf::except;


/****************************** MACROS ******************************/
#define __HARUPP_AUTO_ENCODING_IMPORT_INDEX 0
#define __HARUPP_CNS_ENCODING_INDEX         1
#define __HARUPP_CNT_ENCODING_INDEX         2
#define __HARUPP_JP_ENCODING_INDEX          3
#define __HARUPP_KR_ENCODING_INDEX          4
#define __HARUPP_UTF_ENCODING_INDEX         5

#define __HARUPP_ENCODING_INDEX_START       1
#define __HARUPP_ENCODING_IMPORTS_LENGTH    5


/****************************** CONSTANTS ******************************/
const unsigned int pdf::MAX_STRING_LEN = HPDF_LIMIT_MAX_STRING_LEN;
const unsigned int pdf::MAX_DICT_ELEMENT = HPDF_LIMIT_MAX_DICT_ELEMENT;
const unsigned int pdf::MAX_GSTATE = HPDF_LIMIT_MAX_GSTATE;


/****************************** HELPERS ******************************/
static void __haruppErrorHandler(unsigned long errorNo, unsigned long detailNo, void* userData) {
    switch (errorNo) {
        case 0x1001: throw ArrayCountException("Internal error. Data consistency was lost.", errorNo, detailNo);
        case 0x1002: throw ArrayItemNotFoundException("Internal error. Data consistency was lost.", errorNo, detailNo);
        case 0x1003: throw ArrayItemUnexpectedTypeException("Internal error. Data consistency was lost.", errorNo, detailNo);

        case 0x1004: throw BinaryLengthException("Data length exceeded (> MAX_STRING_LEN).", errorNo, detailNo);

        case 0x1005: throw CannotGetPNGImagePalletException("Cannot get pallet data from PNG image.", errorNo, detailNo);

        case 0x1007: throw DictCountException("Dictionary elements > MAX_DICT_ELEMENT", errorNo, detailNo);
        case 0x1008: throw DictItemNotFoundException("Internal error. Data consistency was lost.", errorNo, detailNo);
        case 0x1009: throw DictItemUnexpectedTypeException("Internal error. Data consistency was lost.", errorNo, detailNo);
        case 0x100A: throw DictStreamLengthNotFoundException("Internal error. Data consistency was lost.", errorNo, detailNo);

        case 0x100B: throw EncryptionNotSetException("setR2EncryptMode, setR3EncryptMode or setPermission called before calling setPassword.", errorNo, detailNo);

        case 0x100C: throw DocInvalidObjectException("Internal error. Data consistency was lost.", errorNo, detailNo);

        case 0x100E: throw FontDuplicateRegistrationException("Tried to re-register a registered font.", errorNo, detailNo);

        case 0x100F: throw ExceededJWWCodeNumLimitException("Cannot register a character to the Japanese word wrap characters list.", errorNo, detailNo);

        case 0x1011: throw InvalidPasswordException("Tried to set the owner password to NULL, or owner and user password are the same.", errorNo, detailNo);

        case 0x1013: throw UnknownClassException("Internal error. Data consistency was lost.", errorNo, detailNo);

        case 0x1014: throw GStateLimitExceededException("Stack depth > MAX_GSTATE.", errorNo, detailNo);

        case 0x1015: throw MemoryAllocationFailedException("Memory allocation failed.", errorNo, detailNo);

        case 0x1016: throw FileIOException("File processing failed. (Detailed code is set.)", errorNo, detailNo);
        case 0x1017: throw FileOpenException("Cannot open a file. (Detailed code is set.)", errorNo, detailNo);

        case 0x1019: throw FontExistsException("Tried to load a font that has been registered.", errorNo, detailNo);

        case 0x101A: throw FontInvalidWidthTableException("Font-file format is invalid or Internal error. Data consistency was lost.", errorNo, detailNo);

        case 0x101B: throw InvalidAFMHeaderException("Cannot recognize header of afm file.", errorNo, detailNo);

        case 0x101C: throw InvalidAnnotationException("Specified annotation handle is invalid.", errorNo, detailNo);

        case 0x101E: throw InvalidBitPerComponentException("Bit-per-component of a image which was set as mask-image is invalid.", errorNo, detailNo);

        case 0x101F: throw InvalidCharMatricsDataException("Cannot recognize char-matrics-data of afm file.", errorNo, detailNo);

        case 0x1020: throw InvalidColorSpaceException("Invalid colorSpace parameter of loadRawImage, or color-space of a image which was set as mask-image is invalid or invoked function invalid in present color-space.", errorNo, detailNo);

        case 0x1021: throw InvalidCompressionModeException("Invalid value set when invoking setCommpressionMode.", errorNo, detailNo);

        case 0x1022: throw InvalidDateTimeException("An invalid date-time value was set.", errorNo, detailNo);

        case 0x1023: throw InvalidDestinationException("An invalid destination handle was set.", errorNo, detailNo);

        case 0x1025: throw InvalidDocumentException("An invalid document handle was set.", errorNo, detailNo);

        case 0x1026: throw InvalidDocumentStateException("Function invalid in the present state was invoked.", errorNo, detailNo);

        case 0x1027: throw InvalidEncoderException("An invalid encoder handle was set.", errorNo, detailNo);
        case 0x1028: throw InvalidEncoderTypeException("Combination between font and encoder is wrong.", errorNo, detailNo);
        case 0x102B: throw InvalidEncoderNameException("An invalid encoding name is specified.", errorNo, detailNo);

        case 0x102C: throw InvalidEncryptionKeyLengthException("Encryption key length is invalid.", errorNo, detailNo);

        case 0x102D: throw InvalidFontDefDataException("An invalid font handle was set or unsupported font format.", errorNo, detailNo);
        case 0x102E: throw InvalidFontDefTypeException("Internal error. Data consistency was lost.", errorNo, detailNo);
        case 0x102F: throw InvalidFontNameException("Font with the specified name is not found.", errorNo, detailNo);

        case 0x1030: throw InvalidImageException("Unsupported image format.", errorNo, detailNo);
        case 0x1031: throw InvalidJPEGDataException("Unsupported image format.", errorNo, detailNo);

        case 0x1032: throw InvalidNDataException("Cannot read a postscript-name from an afm file.", errorNo, detailNo);

        case 0x1033: throw InvalidObjectException("An invalid object is set or internal error. Data consistency was lost.", errorNo, detailNo);

        case 0x1034: throw InvalidObjectIDException("Internal error. Data consistency was lost.", errorNo, detailNo);

        case 0x1035: throw InvalidImageOperationException("Invoked setColorMask() against the image-object which was set a mask-image.", errorNo, detailNo);

        case 0x1036: throw InvalidOutlineException("An invalid outline-handle was specified.", errorNo, detailNo);

        case 0x1037: throw InvalidPageException("An invalid page-handle was specified.", errorNo, detailNo);
        case 0x1038: throw InvalidInternalPagesException("An invalid pages-handle was specified. (internal error)", errorNo, detailNo);

        case 0x1039: throw InvalidParameterException("An invalid value is set.", errorNo, detailNo);

        case 0x103B: throw InvalidPNGImageException("Invalid PNG image format.", errorNo, detailNo);

        case 0x103C: throw InvalidStreamException("Internal error. Data consistency was lost.", errorNo, detailNo);

        case 0x103D: throw MissingFileNameEntryException("Internal error. '_FILE_NAME' entry for delayed loading is missing.", errorNo, detailNo);
        case 0x103F: throw InvalidTTCFileException("Invalid .TTC file format.", errorNo, detailNo);

        case 0x1040: throw InvalidTTCIndexException("Index parameter > number of included fonts.", errorNo, detailNo);

        case 0x1041: throw InvalidWXDataException("Cannot read a width-data from an afm file.", errorNo, detailNo);

        case 0x1042: throw ItemNotFoundException("Internal error. Data consistency was lost.", errorNo, detailNo);

        case 0x1043: throw LibPNGException("Error returned from PNGLIB while loading image.", errorNo, detailNo);

        case 0x1044: throw NameInvalidValueException("Internal error. Data consistency was lost.", errorNo, detailNo);

        case 0x1045: throw NameOutOfRangeException("Internal error. Data consistency was lost.", errorNo, detailNo);

        case 0x1049: throw PagesMissingKidsEntryException("Internal error. Data consistency was lost.", errorNo, detailNo);
        case 0x104A: throw PageCannotFindObjectException("Internal error. Data consistency was lost.", errorNo, detailNo);
        case 0x104B: throw PageCannotGetRootPagesException("Internal error. Data consistency was lost.", errorNo, detailNo);
        case 0x104C: throw PageCannotRestoreGStateException("There are no graphics-states to be restored.", errorNo, detailNo);
        case 0x104D: throw PageCannotSetParentException("Internal error. Data consistency was lost.", errorNo, detailNo);
        case 0x104E: throw PageFontNotFoundException("The current font is not set.", errorNo, detailNo);
        case 0x104F: throw PageInvalidFontException("An invalid font-handle was specified.", errorNo, detailNo);
        case 0x1050: throw PageInvalidFontSizeException("An invalid font-size was set.", errorNo, detailNo);
        case 0x1051: throw PageInvalidGModeException("See Graphics mode.", errorNo, detailNo);
        case 0x1052: throw PageInvalidIndexException("Internal error. Data consistency was lost.", errorNo, detailNo);
        case 0x1053: throw PageInvalidRotateValueException("Specified value is not multiple of 90.", errorNo, detailNo);
        case 0x1054: throw PageInvalidSizeException("An invalid page-size was set.", errorNo, detailNo);
        case 0x1055: throw PageInvalidXObjectException("An invalid image-handle was set.", errorNo, detailNo);
        case 0x1056: throw PageOutOfRangeException("The specified value is out of range.", errorNo, detailNo);

        case 0x1057: throw FloatOutOfRangeException("The specified value is out of range.", errorNo, detailNo);

        case 0x1058: throw StreamEOFException("Unexpected EOF marker was detected.", errorNo, detailNo);
        case 0x1059: throw StreamReadLnContinue("Internal error. Data consistency was lost.", errorNo, detailNo);

        case 0x105B: throw StringOutOfRangeException("The length of the text is too long.", errorNo, detailNo);

        case 0x105C: throw FunctionSkippedException("Function not executed because of other errors.", errorNo, detailNo);

        case 0x105D: throw TTFCannotEmbedFontException("Font cannot be embedded. (license restriction)", errorNo, detailNo);
        case 0x105E: throw TTFInvalidCMAPException("Unsupported ttf format. (cannot find unicode cmap)", errorNo, detailNo);
        case 0x105F: throw TTFInvalidFormatException("Unsupported ttf format.", errorNo, detailNo);
        case 0x1060: throw TTFMissingTableException("Unsupported ttf format. (cannot find a necessary table)", errorNo, detailNo);

        case 0x1061: throw UnsupportedFontTypeException("Internal error. Data consistency was lost.", errorNo, detailNo);

        case 0x1062: throw UnsupportedFunctionException("Library not configured to use PNGLIB or Internal error. Data consistency was lost.", errorNo, detailNo);

        case 0x1063: throw UnsupportedJPEGFormatException("Unsupported JPEG format.", errorNo, detailNo);

        case 0x1064: throw UnsupportedType1FontException("Failed to parse .PFB file.", errorNo, detailNo);

        case 0x1065: throw XRefCountException("Internal error. Data consistency was lost.", errorNo, detailNo);

        case 0x1066: throw ZLIBException("Error while executing ZLIB function.", errorNo, detailNo);

        case 0x1067: throw InvalidPageIndexException("An invalid page index was passed.", errorNo, detailNo);

        case 0x1068: throw InvalidURIException("An invalid URI was set.", errorNo, detailNo);

        case 0x1069: throw PageLayoutOutOfRangeException("An invalid page-layout was set.", errorNo, detailNo);

        case 0x1070: throw PageModeOutOfRangeException("An invalid page-mode was set.", errorNo, detailNo);
        case 0x1071: throw PageNumStyleOutOfRangeException("An invalid page-num-style was set.", errorNo, detailNo);

        case 0x1072: throw AnnotationInvalidIconException("An invalid icon was set.", errorNo, detailNo);
        case 0x1073: throw AnnotationInvalidBorderStyleException("An invalid border-style was set.", errorNo, detailNo);

        case 0x1074: throw InvalidPageDirectionException("An invalid page-direction was set.", errorNo, detailNo);

        case 0x1075: throw InvalidFontException("An invalid font-handle was specified.", errorNo, detailNo);

        case 0x1006: case 0x100D: case 0x1010: case 0x1012:
        case 0x1018: case 0x101D: case 0x1024: case 0x1029:
        case 0x102A: case 0x103A: case 0x103E: case 0x1046:
        case 0x1047: case 0x1048: case 0x105A: case 0x106A:
        case 0x106B: case 0x106C: case 0x106D: case 0x106E:
        case 0x106F: throw UndefinedException("Error code is not defined.", errorNo, detailNo);

        default: throw InvalidException("Error code is not valid.", errorNo, detailNo);
    }
}

static const char* singleByteEncodingToString(SingleByteEncoding encoding) {
    switch (encoding) {
        case SingleByteEncoding::StandardEncoding: return "StandardEncoding";
        case SingleByteEncoding::MacRomanEncoding: return "MacRomanEncoding";
        case SingleByteEncoding::WinAnsiEncoding: return "WinAnsiEncoding";
        case SingleByteEncoding::FontSpecific: return "FontSpecific";
        case SingleByteEncoding::ISO8859_2: return "ISO8859-2";
        case SingleByteEncoding::ISO8859_3: return "ISO8859-3";
        case SingleByteEncoding::ISO8859_4: return "ISO8859-4";
        case SingleByteEncoding::ISO8859_5: return "ISO8859-5";
        case SingleByteEncoding::ISO8859_6: return "ISO8859-6";
        case SingleByteEncoding::ISO8859_7: return "ISO8859-7";
        case SingleByteEncoding::ISO8859_8: return "ISO8859-8";
        case SingleByteEncoding::ISO8859_9: return "ISO8859-9";
        case SingleByteEncoding::ISO8859_10: return "ISO8859-10";
        case SingleByteEncoding::ISO8859_11: return "ISO8859-11";
        case SingleByteEncoding::ISO8859_13: return "ISO8859-13";
        case SingleByteEncoding::ISO8859_14: return "ISO8859-14";
        case SingleByteEncoding::ISO8859_15: return "ISO8859-15";
        case SingleByteEncoding::ISO8859_16: return "ISO8859-16";
        case SingleByteEncoding::CP1250: return "CP1250";
        case SingleByteEncoding::CP1251: return "CP1251";
        case SingleByteEncoding::CP1252: return "CP1252";
        case SingleByteEncoding::CP1253: return "CP1253";
        case SingleByteEncoding::CP1254: return "CP1254";
        case SingleByteEncoding::CP1255: return "CP1255";
        case SingleByteEncoding::CP1256: return "CP1256";
        case SingleByteEncoding::CP1257: return "CP1257";
        case SingleByteEncoding::CP1258: return "CP1258";
        case SingleByteEncoding::KOI8_R: return "KOI8-R";
        default: return "";
    }
}

static const char* multiByteEncodingToString(MultiByteEncoding encoding) {
    switch (encoding) {
        case MultiByteEncoding::GB_EUC_H: return "GB-EUC-H";
        case MultiByteEncoding::GB_EUC_V: return "GB-EUC-V";
        case MultiByteEncoding::GBK_EUC_H: return "GBK-EUC-H";
        case MultiByteEncoding::GBK_EUC_V: return "GBK-EUC-V";
        case MultiByteEncoding::ETen_B5_H: return "ETen-B5-H";
        case MultiByteEncoding::ETen_B5_V: return "ETen-B5-V";
        case MultiByteEncoding::NINETYms_RKSJ_H: return "90ms-RKSJ-H";
        case MultiByteEncoding::NINETYms_RKSJ_V: return "90ms-RKSJ-V";
        case MultiByteEncoding::NINETYmsp_RKSJ_H: return "90msp-RKSJ-H";
        case MultiByteEncoding::EUC_H: return "EUC-H";
        case MultiByteEncoding::EUC_V: return "EUC-V";
        case MultiByteEncoding::KSC_EUC_H: return "KSC-EUC-H";
        case MultiByteEncoding::KSC_EUC_V: return "KSC-EUC-V";
        case MultiByteEncoding::KSCms_UHC_H: return "KSCms-UHC-H";
        case MultiByteEncoding::KSCms_UHC_HW_H: return "KSCms-UHC-HW-H";
        case MultiByteEncoding::KSCms_UHC_HW_V: return "KSCms-UHC-HW-V";
        default: return "";
    }
}

bool PdfDocument::__getImportValue(int index) const {
    return imports[index];
}

void  PdfDocument::__setImportValue(int index, bool newValue) {
    imports[index] = newValue;
}


/******************** CONSTRUCTORS & DESTRUCTOR ********************/

PdfDocument::PdfDocument() noexcept {}

PdfDocument::~PdfDocument() {
    close();
}


/******************** BASIC FUNCTIONS ********************/

void PdfDocument::open() {
    pdfDoc = HPDF_New(__haruppErrorHandler, nullptr);
    if (pdfDoc == nullptr) throw MemoryAllocationFailedException("Cannot create pdf object", 0x1015, 0);

    // Initialise imports
    imports.reserve(__HARUPP_ENCODING_IMPORTS_LENGTH);
    for (int _ = 0; _ < __HARUPP_ENCODING_IMPORTS_LENGTH; ++_) imports.push_back(false);
}

void PdfDocument::close() {
    if (pdfDoc != nullptr) {
        HPDF_Free(pdfDoc);
        pdfDoc = nullptr;
    }
}

void PdfDocument::newDocument() {
    HPDF_NewDoc(pdfDoc);
}

bool PdfDocument::isOpen() const noexcept {
    return !isEmpty();
}

void PdfDocument::freeResources() {
    HPDF_FreeDoc(pdfDoc);
}

void PdfDocument::freeAllResources() {
    HPDF_FreeDocAll(pdfDoc);
    for (int i = __HARUPP_ENCODING_INDEX_START; i < __HARUPP_ENCODING_IMPORTS_LENGTH; ++i)
        imports[i] = false;
}

void PdfDocument::saveToFile(const std::string& fileName) {
    HPDF_SaveToFile(pdfDoc, fileName.c_str());
}

void PdfDocument::saveToStream() {
    HPDF_SaveToStream(pdfDoc);
}

unsigned int PdfDocument::getStreamSize() const {
    return HPDF_GetStreamSize(pdfDoc);
}

std::vector<unsigned char> PdfDocument::readFromStream(unsigned int size) {
    std::vector<unsigned char> result;
    result.reserve(size);
    HPDF_ReadFromStream(pdfDoc, result.data(), &size);
    return result;
}

void PdfDocument::rewindStream() {
    HPDF_ResetStream(pdfDoc);
}

bool PdfDocument::hasDocument() const {
    return HPDF_HasDoc(pdfDoc);
}

bool PdfDocument::isEmpty() const noexcept {
    return pdfDoc == nullptr;
}

unsigned long PdfDocument::getLastErrorCode() const {
    return HPDF_GetError(pdfDoc);
}

unsigned long PdfDocument::getLastErrorDetail() const {
    return HPDF_GetErrorDetail(pdfDoc);
}

void PdfDocument::resetErrorCode() {
    HPDF_ResetError(pdfDoc);
}


/******************** PAGES HANDLING ********************/

void PdfDocument::setPageConfiguration(unsigned int pagePerPages) {
    HPDF_SetPagesConfiguration(pdfDoc, pagePerPages);
}

void PdfDocument::setPageLayout(PageLayout layout) {
    HPDF_SetPageLayout(pdfDoc, (HPDF_PageLayout) layout);
}

PageLayout PdfDocument::getPageLayout() const {
    switch (HPDF_GetPageLayout(pdfDoc)) {
        case HPDF_PAGE_LAYOUT_SINGLE: return PageLayout::SINGLE_PAGE;
        case HPDF_PAGE_LAYOUT_ONE_COLUMN: return PageLayout::ONE_COLUMN;
        case HPDF_PAGE_LAYOUT_TWO_COLUMN_LEFT: return PageLayout::TWO_COLUMN_LEFT;
        case HPDF_PAGE_LAYOUT_TWO_COLUMN_RIGHT: return PageLayout::TWO_COLUMN_RIGHT;
        case HPDF_PAGE_LAYOUT_TWO_PAGE_LEFT: return PageLayout::TWO_PAGE_LEFT;
        case HPDF_PAGE_LAYOUT_TWO_PAGE_RIGHT: return PageLayout::TWO_PAGE_RIGHT;
        default: return PageLayout::EOF_LAYOUT;
    }
}

void PdfDocument::setPageMode(PageMode mode) {
    HPDF_SetPageMode(pdfDoc, (HPDF_PageMode) mode);
}

PageMode PdfDocument::getPageMode() const {
    switch (HPDF_GetPageMode(pdfDoc)) {
        case HPDF_PAGE_MODE_USE_NONE: return PageMode::NONE;
        case HPDF_PAGE_MODE_USE_OUTLINE: return PageMode::USE_OUTLINE;
        case HPDF_PAGE_MODE_USE_THUMBS: return PageMode::USE_THUMBS;
        case HPDF_PAGE_MODE_FULL_SCREEN: return PageMode::FULL_SCREEN;
        default: return PageMode::EOF_MODE;
    }
}

void PdfDocument::setOpenDestination(const Destination& destination) {
    HPDF_SetOpenAction(pdfDoc, destination.__innerContent);
}

PdfPage PdfDocument::getCurrentPage() const {
    return PdfPage(HPDF_GetCurrentPage(pdfDoc));
}

PdfPage PdfDocument::addPage() {
    return PdfPage(HPDF_AddPage(pdfDoc));
}

PdfPage PdfDocument::insertPageBefore(const PdfPage& page) {
    return PdfPage(HPDF_InsertPage(pdfDoc, page.__innerContent));
}

void __addPageLabel(HPDF_Doc pdfDoc, PageNumberStyle style, unsigned int pageNumber, unsigned int firstPage, const char* prefix) {
    HPDF_AddPageLabel(pdfDoc, pageNumber, (HPDF_PageNumStyle) style, firstPage, prefix);
}

void PdfDocument::addPageLabel(PageNumberStyle style, unsigned int pageNumber, unsigned int firstPage) {
    __addPageLabel(pdfDoc, style, pageNumber, firstPage, nullptr);
}

void PdfDocument::addPageLabel(const std::string& prefix, PageNumberStyle style, unsigned int pageNumber, unsigned int firstPage) {
    __addPageLabel(pdfDoc, style, pageNumber, firstPage, prefix.c_str());
}


/******************** FONT HANDLING ********************/

Font PdfDocument::__getFont(const char* fontName, const char* encodingName) {
    return Font(HPDF_GetFont(pdfDoc, fontName, encodingName));
}

Font PdfDocument::getFont(const std::string& fontName, SingleByteEncoding encoding) {
    return __getFont(fontName.c_str(), singleByteEncodingToString(encoding));
}

Font PdfDocument::getFont(const std::string& fontName, MultiByteEncoding encoding) {
    return __getFont(fontName.c_str(), multiByteEncodingToString(encoding));
}

std::string PdfDocument::__loadType1FontFromFile(const char* AFMFileName, const char* dataFileName) {
    const char* res = HPDF_LoadType1FontFromFile(pdfDoc, AFMFileName, dataFileName);
    return (res == nullptr)? std::string(): res;
}

std::string PdfDocument::loadType1FontFromFile(const std::string& AFMFileName) {
    return __loadType1FontFromFile(AFMFileName.c_str(), nullptr);
}

std::string PdfDocument::loadType1FontFromFile(const std::string& AFMFileName, const std::string& dataFileName) {
    return __loadType1FontFromFile(AFMFileName.c_str(), dataFileName.c_str());
}

std::string PdfDocument::loadTrueTypeFontFromFile(const std::string& fileName, bool embedding) {
    const char* res = HPDF_LoadTTFontFromFile(pdfDoc, fileName.c_str(), embedding);
    return (res == nullptr)? std::string(): res;
}

std::string PdfDocument::loadTrueTypeFontFromFile(const std::string& fileName, unsigned int index, bool embedding) {
    const char* res = HPDF_LoadTTFontFromFile2(pdfDoc, fileName.c_str(), index, embedding);
    return (res == nullptr)? std::string(): res;
}

void PdfDocument::useJPFonts() {
    HPDF_UseJPFonts(pdfDoc);
}

void PdfDocument::useKRFonts() {
    HPDF_UseKRFonts(pdfDoc);
}

void PdfDocument::useCNSFonts() {
    HPDF_UseCNSFonts(pdfDoc);
}

void PdfDocument::useCNTFonts() {
    HPDF_UseCNTFonts(pdfDoc);
}


/******************** ENCODINGS ********************/

void PdfDocument::__autoImportEncoding(MultiByteEncoding encoding) {
    if (encoding >= MultiByteEncoding::GB_EUC_H && encoding <= MultiByteEncoding::GBK_EUC_V) {
        useCNSEncodings();
    } else if (encoding >= MultiByteEncoding::ETen_B5_H && encoding <= MultiByteEncoding::ETen_B5_V) {
        useCNTEncodings();
    } else if (encoding >= MultiByteEncoding::NINETYms_RKSJ_H && encoding <= MultiByteEncoding::EUC_V) {
        useJPEncodings();
    } else if (encoding >= MultiByteEncoding::KSC_EUC_H && encoding <= MultiByteEncoding::KSCms_UHC_HW_V) {
        useKREncodings();
    }
}

Encoder PdfDocument::__getEncoder(const char* name) {
    return Encoder(HPDF_GetEncoder(pdfDoc, name));
}

Encoder PdfDocument::getEncoder(SingleByteEncoding encoding) {
    return __getEncoder(singleByteEncodingToString(encoding));
}

Encoder PdfDocument::getEncoder(MultiByteEncoding encoding) {
    if (__getImportValue(__HARUPP_AUTO_ENCODING_IMPORT_INDEX)) __autoImportEncoding(encoding);
    return __getEncoder(multiByteEncodingToString(encoding));
}

Encoder PdfDocument::getCurrentEncoder() {
    return Encoder(HPDF_GetCurrentEncoder(pdfDoc));
}

void PdfDocument::__setCurrentEncoder(const char* name) {
    HPDF_SetCurrentEncoder(pdfDoc, name);
}

void PdfDocument::setCurrentEncoder(SingleByteEncoding encoding) {
    __setCurrentEncoder(singleByteEncodingToString(encoding));
}

void PdfDocument::setCurrentEncoder(MultiByteEncoding encoding) {
    __setCurrentEncoder(multiByteEncodingToString(encoding));
}

void PdfDocument::useJPEncodings() {
    if (!__getImportValue(__HARUPP_JP_ENCODING_INDEX)) {
        HPDF_UseJPEncodings(pdfDoc);
        __setImportValue(__HARUPP_JP_ENCODING_INDEX, true);
    }
}

void PdfDocument::useKREncodings() {
    if (!__getImportValue(__HARUPP_KR_ENCODING_INDEX)) {
        HPDF_UseKREncodings(pdfDoc);
        __setImportValue(__HARUPP_KR_ENCODING_INDEX, true);
    }
}

void PdfDocument::useCNSEncodings() {
    if (!__getImportValue(__HARUPP_CNS_ENCODING_INDEX)) {
        HPDF_UseCNSEncodings(pdfDoc);
        __setImportValue(__HARUPP_CNS_ENCODING_INDEX, true);
    }
}

void PdfDocument::useCNTEncodings() {
    if (!__getImportValue(__HARUPP_CNT_ENCODING_INDEX)) {
        HPDF_UseCNTEncodings(pdfDoc);
        __setImportValue(__HARUPP_CNT_ENCODING_INDEX, true);
    }
}

void PdfDocument::useUTFEncodings() {
    if (!__getImportValue(__HARUPP_UTF_ENCODING_INDEX)) {
        HPDF_UseUTFEncodings(pdfDoc);
        __setImportValue(__HARUPP_UTF_ENCODING_INDEX, true);
    }
}

bool PdfDocument::isAutoEncodingImportsEnabled() const {
    return __getImportValue(__HARUPP_AUTO_ENCODING_IMPORT_INDEX);
}

void PdfDocument::enableAutoEncodingImports() {
    __setImportValue(__HARUPP_AUTO_ENCODING_IMPORT_INDEX, true);
}

void PdfDocument::disableAutoEncodingImports() {
    __setImportValue(__HARUPP_AUTO_ENCODING_IMPORT_INDEX, false);
}


/******************** OUTLINE CREATION ********************/

Outline PdfDocument::__createOutline(const std::string& title, const Outline* parent, const Encoder* encoder) const {
    return Outline(HPDF_CreateOutline(pdfDoc, parent? parent->__innerContent: nullptr, title.c_str(), encoder? encoder->__innerContent: nullptr));
}

Outline PdfDocument::createOutline(const std::string& title) const {
    return __createOutline(title.c_str(), nullptr, nullptr);
}

Outline PdfDocument::createOutline(const std::string& title, const Outline& parent) const {
    return __createOutline(title.c_str(), &parent, nullptr);
}

Outline PdfDocument::createOutline(const std::string& title, const Encoder& encoder) const {
    return __createOutline(title, nullptr, &encoder);
}

Outline PdfDocument::createOutline(const std::string& title, const Outline& parent, const Encoder& encoder) const {
    return __createOutline(title, &parent, &encoder);
}


/******************** IMAGES LOADING ********************/

Image PdfDocument::loadPNGImageFromFile(const std::string& fileName) {
    return Image(HPDF_LoadPngImageFromFile(pdfDoc, fileName.c_str()));
}

Image PdfDocument::loadPartialPNGImageFromFile(const std::string& fileName) {
    return Image(HPDF_LoadPngImageFromFile2(pdfDoc, fileName.c_str()));
}

Image PdfDocument::loadJPEGImageFromFile(const std::string& fileName) {
    return Image(HPDF_LoadJpegImageFromFile(pdfDoc, fileName.c_str()));
}

Image PdfDocument::loadRawImageFromFile(
    const std::string& fileName, unsigned int width,
    unsigned int height, ImageColorSpaceDevice colorSpace
) {
    return Image(HPDF_LoadRawImageFromFile(pdfDoc, fileName.c_str(), width, height, (HPDF_ColorSpace) colorSpace));
}

Image PdfDocument::loadRawImageFromMemory(
    const std::vector<unsigned char>& bytes, unsigned int width,
    unsigned int height, ImageColorSpaceDevice colorSpace,
    BitsPerComponent bitsPerComponent
) {
    return Image(HPDF_LoadRawImageFromMem(pdfDoc, bytes.data(), width, height, (HPDF_ColorSpace) colorSpace, (HPDF_UINT) bitsPerComponent));
}

Image PdfDocument::loadPNGImageFromMemory(const std::vector<unsigned char>& bytes) {
    return Image(HPDF_LoadPngImageFromMem(pdfDoc, bytes.data(), bytes.size()));
}

Image PdfDocument::loadJPEGImageFromMemory(const std::vector<unsigned char>& bytes) {
    return Image(HPDF_LoadJpegImageFromMem(pdfDoc, bytes.data(), bytes.size()));
}


/******************** OTHER FUNCTIONS ********************/

void PdfDocument::setAttribute(StringAttribute parameter, const std::string& value) {
    HPDF_SetInfoAttr(pdfDoc, (HPDF_InfoType) parameter, value.c_str());
}

void PdfDocument::setAttribute(DateTimeAttribute parameter, const DateTime& value) {
    HPDF_Date date;
    date.year = value.getYear();
    date.month = value.getMonth();
    date.day = value.getDay();
    date.hour = value.getHour();
    date.minutes = value.getMinutes();
    date.seconds = value.getSeconds();
    date.ind = (char) value.getUTCIndicator();
    date.off_hour = value.getOffHour();
    date.off_minutes = value.getOffMinutes();
    HPDF_SetInfoDateAttr(pdfDoc, (HPDF_InfoType) parameter, date);
}

std::optional<std::string> __getInfoAttribute(HPDF_Doc pdfDoc, int parameter) {
    const char* value = HPDF_GetInfoAttr(pdfDoc, (HPDF_InfoType) parameter);
    if (value == nullptr) return {};
    return value;
}

std::optional<std::string> PdfDocument::getInfoAttribute(StringAttribute parameter) {
    return __getInfoAttribute(pdfDoc, (HPDF_InfoType) parameter);
}

std::optional<std::string> PdfDocument::getInfoAttribute(DateTimeAttribute parameter) {
    return __getInfoAttribute(pdfDoc, (HPDF_InfoType) parameter);
}

void __setPassword(HPDF_Doc pdfDoc, const char* ownerPassword, const char* userPassword) {
    HPDF_SetPassword(pdfDoc, ownerPassword, userPassword);
}

void PdfDocument::setPassword(const std::string& ownerPassword) {
    __setPassword(pdfDoc, ownerPassword.c_str(), nullptr);
}

void PdfDocument::setPassword(const std::string& ownerPassword, const std::string& userPassword) {
    __setPassword(pdfDoc, ownerPassword.c_str(), userPassword.c_str());
}

void PdfDocument::setPermissions(const Permissions& permissions) {
    HPDF_SetPermission(pdfDoc, permissions.value);
}

void PdfDocument::setR2EncryptMode() {
    HPDF_SetEncryptionMode(pdfDoc, HPDF_ENCRYPT_R2, 5U);
}

void PdfDocument::setR3EncryptMode(R3EncryptKeyLength keyLength) {
    HPDF_SetEncryptionMode(pdfDoc, HPDF_ENCRYPT_R3, (unsigned int) keyLength);
}

void PdfDocument::setCompressionMode(CompressionMode mode) {
    HPDF_SetCompressionMode(pdfDoc, (unsigned int) mode);
}

void PdfDocument::operator=(const PdfDocument& newDoc) {
    close();
    pdfDoc = newDoc.pdfDoc;
}
