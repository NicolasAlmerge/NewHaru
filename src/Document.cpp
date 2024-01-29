#include "../include/Document.hpp"
#include "../include/Exception.hpp"
#include "hpdf.h"
using namespace pdf;
using namespace pdf::excepts;
using namespace pdf::enums;


/****************************** MACROS ******************************/
#define __HARUPP_AUTO_ENCODING_IMPORT_INDEX 0
#define __HARUPP_CNS_ENCODING_INDEX         1
#define __HARUPP_CNT_ENCODING_INDEX         2
#define __HARUPP_JP_ENCODING_INDEX          3
#define __HARUPP_KR_ENCODING_INDEX          4
#define __HARUPP_UTF_ENCODING_INDEX         5

#define __HARUPP_ENCODING_INDEX_START       1
#define __HARUPP_ENCODING_IMPORTS_LENGTH    5


/****************************** HELPERS ******************************/
static void __haruppErrorHandler(unsigned long errorNo, unsigned long detailNo, void*) {
    switch (errorNo) {
        case 0x1004: throw BinaryLengthTooLongException();
        case 0x1007: throw TooManyIndirectObjectsException();
        case 0x100B: throw EncryptionNotSetException();
        case 0x100E: throw FontDuplicateRegistrationException();
        case 0x100F: throw ExceededJWWCodeNumLimitException(detailNo);
        case 0x1011: throw InvalidPasswordException();
        case 0x1014: throw GStateLimitExceededException();
        case 0x1015: throw MemoryAllocationFailedException();
        case 0x1016: throw FileIOException(detailNo);
        case 0x1017: throw FileOpeningException(detailNo);
        case 0x1019: throw FontAlreadyExistsException();
        case 0x101A: throw FontInvalidWidthsTableException();
        case 0x101B: throw InvalidAFMHeaderFileException();
        case 0x101E: throw NonMatchingBitsPerComponentException();
        case 0x101F: throw InvalidAFMCharMatricsDataException();
        case 0x1020: throw InvalidColorSpaceException();
        case 0x1022: throw InvalidDateTimeException();
        case 0x1026: throw PageAlreadyExistsException();
        case 0x1028: throw InvalidEncoderTypeException();
        case 0x102B: throw InvalidEncodingNameException();
        case 0x102C: throw InvalidR3EncryptionKeyLengthException();
        case 0x102F: throw InvalidFontNameException();
        case 0x1030: throw InvalidImageException();
        case 0x1032: throw InvalidAFMFileNDataException();
        case 0x1035: throw InvalidImageOperationException();
        case 0x1039: throw InvalidParameterException();
        case 0x103B: throw InvalidPNGImageException();
        case 0x103F: throw InvalidTTCFileException();
        case 0x1040: throw InvalidTTCIndexException();
        case 0x1041: throw InvalidAFMWidthException();
        case 0x1043: throw LibPNGException(detailNo);
        case 0x104C: throw NoGStateException();
        case 0x104E: throw FontNotFoundException();
        case 0x1050: throw InvalidFontSizeException(detailNo);
        case 0x1051: throw InvalidGModeException();
        case 0x1054: throw InvalidPageSizeException();
        case 0x1056: throw PageValueOutOfRangeException();
        case 0x1057: throw FloatValueOutOfRangeException();
        case 0x105B: throw StringOutOfRangeException();
        case 0x105D: throw CannotEmbedTTFFontException();
        case 0x105E: throw InvalidTTFCMapException();
        case 0x105F: throw InvalidTTFFormatException();
        case 0x1060: throw MissingTTFTableException();
        case 0x1062: throw UnsupportedFunctionException();
        case 0x1063: throw UnsupportedJPEGFormatException();
        case 0x1064: throw UnsupportedType1FontException();
        case 0x1066: throw ZLibException(detailNo);
        case 0x1067: throw InvalidPageIndexException();
        case 0x1068: throw EmptyURIException();
        case 0x1069: throw InvalidPageLayoutException();
        default: throw UndefinedException(errorNo, detailNo);
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

static std::vector<unsigned char> __execAndGetVector(unsigned long (&fn)(HPDF_Doc, unsigned char*, unsigned int*), HPDF_Doc pdfDoc, unsigned int size) {
    if (size == 0U || pdfDoc == nullptr) return std::vector<unsigned char>();

    // Allocate data
    std::vector<unsigned char> data;
    data.reserve(size);

    // Call the function
    unsigned int newSize = size;
    fn(pdfDoc, data.data(), &newSize);

    // Safety check
    if (newSize > size) newSize = size;

    // Put everything into a vector and return
    return std::vector<unsigned char>(data.begin(), data.begin() + newSize);
}

static UTCIndicator __toUTCInd(char c) {
    switch (c) {
        case (char) UTCIndicator::PLUS: return UTCIndicator::PLUS;
        case (char) UTCIndicator::MINUS: return UTCIndicator::MINUS;
        case (char) UTCIndicator::Z: return UTCIndicator::Z;
        default: return UTCIndicator::NONE;
    }
}

bool Document::__getImportValue(int index) const {
    return imports[index];
}

void Document::__setImportValue(int index, bool newValue) {
    imports[index] = newValue;
}


/******************** CONSTRUCTORS & DESTRUCTOR ********************/

Document::Document() noexcept {}

Document::~Document() {
    close();
}


/******************** BASIC FUNCTIONS ********************/

void Document::open() {
    pdfDoc = HPDF_New(__haruppErrorHandler, nullptr);
    if (pdfDoc == nullptr) throw MemoryAllocationFailedException();

    // Initialise imports
    imports.reserve(__HARUPP_ENCODING_IMPORTS_LENGTH);
    for (int _ = 0; _ < __HARUPP_ENCODING_IMPORTS_LENGTH; ++_) imports.push_back(false);
}

void Document::close() {
    if (pdfDoc != nullptr) {
        HPDF_Free(pdfDoc);
        pdfDoc = nullptr;
    }
}

void Document::newDocument() {
    HPDF_NewDoc(pdfDoc);
}

bool Document::isOpen() const noexcept {
    return !isEmpty();
}

void Document::freeResources() {
    HPDF_FreeDoc(pdfDoc);
}

void Document::freeAllResources() {
    HPDF_FreeDocAll(pdfDoc);
    for (int i = __HARUPP_ENCODING_INDEX_START; i < __HARUPP_ENCODING_IMPORTS_LENGTH; ++i)
        imports[i] = false;
}

void Document::saveToFile(const std::string& fileName) {
    HPDF_SaveToFile(pdfDoc, fileName.c_str());
}

void Document::saveToStream() {
    HPDF_SaveToStream(pdfDoc);
}

unsigned int Document::getStreamSize() const {
    if (pdfDoc == nullptr) return 0U;
    return HPDF_GetStreamSize(pdfDoc);
}

std::vector<unsigned char> Document::readFromStream(unsigned int size) {
    if (getStreamSize() == 0U) return std::vector<unsigned char>();
    return __execAndGetVector(HPDF_ReadFromStream, pdfDoc, size);
}

std::vector<unsigned char> Document::readFromStream() {
    return readFromStream(getStreamSize());
}

void Document::rewindStream() {
    if (getStreamSize() > 0U) HPDF_ResetStream(pdfDoc);
}

bool Document::hasDocument() const {
    return HPDF_HasDoc(pdfDoc);
}

bool Document::isEmpty() const noexcept {
    return pdfDoc == nullptr;
}

unsigned long Document::getLastErrorCode() const {
    if (pdfDoc == nullptr) return 0U;
    return HPDF_GetError(pdfDoc);
}

unsigned long Document::getLastErrorDetail() const {
    if (pdfDoc == nullptr) return 0U;
    return HPDF_GetErrorDetail(pdfDoc);
}

void Document::resetErrorCode() {
    HPDF_ResetError(pdfDoc);
}

std::vector<unsigned char> Document::getContent(unsigned int size) const {
    return __execAndGetVector(HPDF_GetContents, pdfDoc, size);
}


/******************** PAGES HANDLING ********************/

void Document::setPageConfiguration(unsigned int pagePerPages) {
    HPDF_SetPagesConfiguration(pdfDoc, pagePerPages);
}

Page Document::getPageAtIndex(unsigned int index) const {
    HPDF_Page page = HPDF_GetPageByIndex(pdfDoc, index);
    if (page == nullptr) throw InvalidPageIndexException();
    return Page(page);
}

void Document::setPageLayout(PageLayout layout) {
    HPDF_SetPageLayout(pdfDoc, (HPDF_PageLayout) layout);
}

PageLayout Document::getPageLayout() const {
    switch (HPDF_GetPageLayout(pdfDoc)) {
        case HPDF_PAGE_LAYOUT_SINGLE: return PageLayout::SINGLE_PAGE;
        case HPDF_PAGE_LAYOUT_ONE_COLUMN: return PageLayout::ONE_COLUMN;
        case HPDF_PAGE_LAYOUT_TWO_COLUMN_LEFT: return PageLayout::TWO_COLUMN_LEFT;
        case HPDF_PAGE_LAYOUT_TWO_COLUMN_RIGHT: return PageLayout::TWO_COLUMN_RIGHT;
        case HPDF_PAGE_LAYOUT_TWO_PAGE_LEFT: return PageLayout::TWO_PAGE_LEFT;
        case HPDF_PAGE_LAYOUT_TWO_PAGE_RIGHT: return PageLayout::TWO_PAGE_RIGHT;
        default: throw InvalidPageLayoutException();
    }
}

void Document::setPageMode(PageMode mode) {
    HPDF_SetPageMode(pdfDoc, (HPDF_PageMode) mode);
}

PageMode Document::getPageMode() const {
    switch (HPDF_GetPageMode(pdfDoc)) {
        case HPDF_PAGE_MODE_USE_NONE: return PageMode::NONE;
        case HPDF_PAGE_MODE_USE_OUTLINE: return PageMode::USE_OUTLINE;
        case HPDF_PAGE_MODE_USE_THUMBS: return PageMode::USE_THUMBS;
        case HPDF_PAGE_MODE_FULL_SCREEN: return PageMode::FULL_SCREEN;
        default: return PageMode::NONE;
    }
}

void Document::setViewerPreferences(const ViewerPreferences& preferences) {
    HPDF_SetViewerPreference(pdfDoc, preferences.value);
}

ViewerPreferences Document::getViewerPreferences() const {
    return ViewerPreferences(HPDF_GetViewerPreference(pdfDoc));
}

void Document::setOpenDestination(const Destination& destination) {
    HPDF_SetOpenAction(pdfDoc, destination.__innerContent);
}

Page Document::getCurrentPage() const {
    HPDF_Page page = HPDF_GetCurrentPage(pdfDoc);
    if (page == nullptr) throw InvalidPageIndexException();
    return Page(page);
}

Page Document::addPage() {
    return Page(HPDF_AddPage(pdfDoc));
}

Page Document::insertPageBefore(const Page& page) {
    return Page(HPDF_InsertPage(pdfDoc, page.__innerContent));
}

void __addPageLabel(HPDF_Doc pdfDoc, PageNumberStyle style, unsigned int pageNumber, unsigned int firstPage, const char* prefix) {
    HPDF_AddPageLabel(pdfDoc, pageNumber, (HPDF_PageNumStyle) style, firstPage, prefix);
}

void Document::addPageLabel(PageNumberStyle style, unsigned int pageNumber, unsigned int firstPage) {
    __addPageLabel(pdfDoc, style, pageNumber, firstPage, nullptr);
}

void Document::addPageLabel(const std::string& prefix, PageNumberStyle style, unsigned int pageNumber, unsigned int firstPage) {
    __addPageLabel(pdfDoc, style, pageNumber, firstPage, prefix.c_str());
}


/******************** FONT HANDLING ********************/

Font Document::__getFont(const char* fontName, const char* encodingName) {
    return Font(HPDF_GetFont(pdfDoc, fontName, encodingName));
}

Font Document::getFont(const std::string& fontName, SingleByteEncoding encoding) {
    return __getFont(fontName.c_str(), singleByteEncodingToString(encoding));
}

Font Document::getFont(const std::string& fontName, MultiByteEncoding encoding) {
    return __getFont(fontName.c_str(), multiByteEncodingToString(encoding));
}

Font Document::getFont(const std::string& fontName, const std::string& encodingName) {
    return __getFont(fontName.c_str(), encodingName.c_str());
}

std::string Document::__loadType1FontFromFile(const char* AFMFileName, const char* dataFileName) {
    const char* res = HPDF_LoadType1FontFromFile(pdfDoc, AFMFileName, dataFileName);
    return (res == nullptr)? std::string(): res;
}

std::string Document::loadType1FontFromFile(const std::string& AFMFileName) {
    return __loadType1FontFromFile(AFMFileName.c_str(), nullptr);
}

std::string Document::loadType1FontFromFile(const std::string& AFMFileName, const std::string& dataFileName) {
    return __loadType1FontFromFile(AFMFileName.c_str(), dataFileName.c_str());
}

std::string Document::loadTrueTypeFontFromFile(const std::string& fileName, bool embedding) {
    const char* res = HPDF_LoadTTFontFromFile(pdfDoc, fileName.c_str(), embedding);
    return (res == nullptr)? std::string(): res;
}

std::string Document::loadTrueTypeFontFromFile(const std::string& fileName, unsigned int index, bool embedding) {
    const char* res = HPDF_LoadTTFontFromFile2(pdfDoc, fileName.c_str(), index, embedding);
    return (res == nullptr)? std::string(): res;
}

void Document::useJPFonts() {
    HPDF_UseJPFonts(pdfDoc);
}

void Document::useKRFonts() {
    HPDF_UseKRFonts(pdfDoc);
}

void Document::useCNSFonts() {
    HPDF_UseCNSFonts(pdfDoc);
}

void Document::useCNTFonts() {
    HPDF_UseCNTFonts(pdfDoc);
}


/******************** ENCODINGS ********************/

void Document::__autoImportEncoding(MultiByteEncoding encoding) {
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

Encoder Document::__getEncoder(const char* name) {
    return Encoder(HPDF_GetEncoder(pdfDoc, name));
}

Encoder Document::getEncoder(SingleByteEncoding encoding) {
    return __getEncoder(singleByteEncodingToString(encoding));
}

Encoder Document::getEncoder(MultiByteEncoding encoding) {
    if (__getImportValue(__HARUPP_AUTO_ENCODING_IMPORT_INDEX)) __autoImportEncoding(encoding);
    return __getEncoder(multiByteEncodingToString(encoding));
}

Encoder Document::getEncoder(const std::string& encodingName) {
    return __getEncoder(encodingName.c_str());
}

Encoder Document::getCurrentEncoder() const {
    return Encoder(HPDF_GetCurrentEncoder(pdfDoc));
}

void Document::__setCurrentEncoder(const char* name) {
    HPDF_SetCurrentEncoder(pdfDoc, name);
}

void Document::setCurrentEncoder(SingleByteEncoding encoding) {
    __setCurrentEncoder(singleByteEncodingToString(encoding));
}

void Document::setCurrentEncoder(MultiByteEncoding encoding) {
    __setCurrentEncoder(multiByteEncodingToString(encoding));
}

void Document::setCurrentEncoder(const std::string& encodingName) {
    __setCurrentEncoder(encodingName.c_str());
}

void Document::useJPEncodings() {
    if (!__getImportValue(__HARUPP_JP_ENCODING_INDEX)) {
        HPDF_UseJPEncodings(pdfDoc);
        __setImportValue(__HARUPP_JP_ENCODING_INDEX, true);
    }
}

void Document::useKREncodings() {
    if (!__getImportValue(__HARUPP_KR_ENCODING_INDEX)) {
        HPDF_UseKREncodings(pdfDoc);
        __setImportValue(__HARUPP_KR_ENCODING_INDEX, true);
    }
}

void Document::useCNSEncodings() {
    if (!__getImportValue(__HARUPP_CNS_ENCODING_INDEX)) {
        HPDF_UseCNSEncodings(pdfDoc);
        __setImportValue(__HARUPP_CNS_ENCODING_INDEX, true);
    }
}

void Document::useCNTEncodings() {
    if (!__getImportValue(__HARUPP_CNT_ENCODING_INDEX)) {
        HPDF_UseCNTEncodings(pdfDoc);
        __setImportValue(__HARUPP_CNT_ENCODING_INDEX, true);
    }
}

void Document::useUTFEncodings() {
    if (!__getImportValue(__HARUPP_UTF_ENCODING_INDEX)) {
        HPDF_UseUTFEncodings(pdfDoc);
        __setImportValue(__HARUPP_UTF_ENCODING_INDEX, true);
    }
}

bool Document::isAutoEncodingImportsEnabled() const {
    return __getImportValue(__HARUPP_AUTO_ENCODING_IMPORT_INDEX);
}

void Document::enableAutoEncodingImports() {
    __setImportValue(__HARUPP_AUTO_ENCODING_IMPORT_INDEX, true);
}

void Document::disableAutoEncodingImports() {
    __setImportValue(__HARUPP_AUTO_ENCODING_IMPORT_INDEX, false);
}


/******************** OUTLINE CREATION ********************/

Outline Document::__createOutline(const std::string& title, const Outline* parent, const Encoder* encoder) const {
    return Outline(HPDF_CreateOutline(pdfDoc, parent? parent->__innerContent: nullptr, title.c_str(), encoder? encoder->__innerContent: nullptr));
}

Outline Document::createOutline(const std::string& title) const {
    return __createOutline(title.c_str(), nullptr, nullptr);
}

Outline Document::createOutline(const std::string& title, const Outline& parent) const {
    return __createOutline(title.c_str(), &parent, nullptr);
}

Outline Document::createOutline(const std::string& title, const Encoder& encoder) const {
    return __createOutline(title, nullptr, &encoder);
}

Outline Document::createOutline(const std::string& title, const Outline& parent, const Encoder& encoder) const {
    return __createOutline(title, &parent, &encoder);
}


/******************** IMAGES LOADING ********************/

Image Document::loadPNGImageFromFile(const std::string& fileName) {
    return Image(HPDF_LoadPngImageFromFile(pdfDoc, fileName.c_str()));
}

Image Document::loadPartialPNGImageFromFile(const std::string& fileName) {
    return Image(HPDF_LoadPngImageFromFile2(pdfDoc, fileName.c_str()));
}

Image Document::loadJPEGImageFromFile(const std::string& fileName) {
    return Image(HPDF_LoadJpegImageFromFile(pdfDoc, fileName.c_str()));
}

Image Document::loadRawImageFromFile(
    const std::string& fileName, unsigned int width,
    unsigned int height, ColorSpace colorSpace
) {
    return Image(HPDF_LoadRawImageFromFile(pdfDoc, fileName.c_str(), width, height, (HPDF_ColorSpace) colorSpace));
}

Image Document::loadRawImageFromMemory(
    const std::vector<unsigned char>& bytes, unsigned int width,
    unsigned int height, ColorSpace colorSpace,
    unsigned int bitsPerComponent
) {
    if (bitsPerComponent != 1U && bitsPerComponent != 2U && bitsPerComponent != 4U && bitsPerComponent != 8U)
        throw InvalidBitsPerComponentException();
    return Image(HPDF_LoadRawImageFromMem(pdfDoc, bytes.data(), width, height, (HPDF_ColorSpace) colorSpace, bitsPerComponent));
}

Image Document::loadPNGImageFromMemory(const std::vector<unsigned char>& bytes) {
    return Image(HPDF_LoadPngImageFromMem(pdfDoc, bytes.data(), bytes.size()));
}

Image Document::loadJPEGImageFromMemory(const std::vector<unsigned char>& bytes) {
    return Image(HPDF_LoadJpegImageFromMem(pdfDoc, bytes.data(), bytes.size()));
}


/******************** OTHER FUNCTIONS ********************/

void Document::setAttribute(StringAttribute parameter, const std::string& value) {
    HPDF_SetInfoAttr(pdfDoc, (HPDF_InfoType) parameter, value.c_str());
}

void Document::setAttribute(DateTimeAttribute parameter, const DateTime& value) {
    if (value.getYear() > 9999) throw InvalidDateTimeException();

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

std::optional<std::string> Document::getInfoAttribute(StringAttribute parameter) {
    return __getInfoAttribute(pdfDoc, (HPDF_InfoType) parameter);
}

std::optional<std::string> Document::getInfoAttributeAsString(DateTimeAttribute parameter) {
    return __getInfoAttribute(pdfDoc, (HPDF_InfoType) parameter);
}

std::optional<DateTime> Document::getInfoAttribute(enums::DateTimeAttribute parameter) {
    std::optional<std::string> optStringValue = getInfoAttributeAsString(parameter);
    if (!optStringValue) return {};

    // Parse attributes one by one
    std::string stringValue = *optStringValue;
    int year = stoi(stringValue.substr(2, 4));
    int month = stoi(stringValue.substr(6, 2));
    int day = stoi(stringValue.substr(8, 2));
    int hour = stoi(stringValue.substr(10, 2));
    int minutes = stoi(stringValue.substr(12, 2));
    int seconds = stoi(stringValue.substr(14, 2));
    if (stringValue.size() <= 16) return DateTime(year, month, day, hour, minutes, seconds);

    // More data to parse
    UTCIndicator utc = __toUTCInd(stringValue[16]);
    int offHours = stoi(stringValue.substr(17, 2));
    int offMinutes = stoi(stringValue.substr(20, 2));
    return DateTime(year, month, day, hour, minutes, seconds, utc, offHours, offMinutes);
}

void __setPassword(HPDF_Doc pdfDoc, const char* ownerPassword, const char* userPassword) {
    HPDF_SetPassword(pdfDoc, ownerPassword, userPassword);
}

void Document::setPassword(const std::string& ownerPassword) {
    __setPassword(pdfDoc, ownerPassword.c_str(), nullptr);
}

void Document::setPassword(const std::string& ownerPassword, const std::string& userPassword) {
    __setPassword(pdfDoc, ownerPassword.c_str(), userPassword.c_str());
}

void Document::setPermissions(const Permissions& permissions) {
    HPDF_SetPermission(pdfDoc, permissions.value);
}

void Document::setR2EncryptMode() {
    HPDF_SetEncryptionMode(pdfDoc, HPDF_ENCRYPT_R2, 5U);
}

void Document::setR3EncryptMode(unsigned int keyLength) {
    if (keyLength == 0U) throw InvalidR3EncryptionKeyLengthException(); // Disallow 0U value for clarity
    HPDF_SetEncryptionMode(pdfDoc, HPDF_ENCRYPT_R3, keyLength);
}

void Document::setCompressionMode(const CompressionMode& mode) {
    HPDF_SetCompressionMode(pdfDoc, mode.value);
}

void Document::operator=(const Document& newDoc) {
    close();
    pdfDoc = newDoc.pdfDoc;
}
