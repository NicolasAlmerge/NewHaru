#include "../include/PdfDocument.hpp"
using namespace pdf;


void errorHandler(unsigned long errorNo, unsigned long detailNo, void* userData) {
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

        case 0x1016: throw FileIOException("File processing failed. (Detailed code is set.)", errorNo, detailNo, true);
        case 0x1017: throw FileOpenException("Cannot open a file. (Detailed code is set.)", errorNo, detailNo, true);

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


/******************** CONSTRUCTORS & DESTRUCTOR ********************/

PdfDocument::PdfDocument() noexcept {}

PdfDocument::~PdfDocument() {
    close();
}


/******************** BASIC FUNCTIONS ********************/

void PdfDocument::open() {
    open(errorHandler, nullptr);
}

void PdfDocument::open(void (&customErrorHandler)(unsigned long, unsigned long, void*), void* userData) {
    pdfDoc = HPDF_New(customErrorHandler, userData);
    if (!pdfDoc) {
        throw NewPdfCreationFailedException("Cannot create pdf object", 0x1000, 0);
    }
    opened = true;
}

void PdfDocument::open(
    void* (&customAllocFunc)(unsigned int), void (&customFreeFunc)(void*), unsigned int memPoolBufSize,
    void (&customErrorHandler)(unsigned long, unsigned long, void*), void* userData
) {
    pdfDoc = HPDF_NewEx(customErrorHandler, customAllocFunc, customFreeFunc, memPoolBufSize, userData);
    if (!pdfDoc) {
        throw NewPdfCreationFailedException("Cannot create pdf object", 0x1000, 0);
    }
    opened = true;
}

void PdfDocument::close() {
    if (!opened) return;
    HPDF_Free(pdfDoc);
    opened = false;
}

void PdfDocument::newDocument() {
    HPDF_NewDoc(pdfDoc);
}

bool PdfDocument::isOpen() const {
    return opened;
}

void PdfDocument::freeResources() {
    HPDF_FreeDoc(pdfDoc);
}

void PdfDocument::freeAllResources() {
    HPDF_FreeDocAll(pdfDoc);
}

void PdfDocument::saveToFile(const char* fileName) {
    HPDF_SaveToFile(pdfDoc, fileName);
}

void PdfDocument::saveToFile(const std::string& fileName) {
    saveToFile(fileName.c_str());
}

void PdfDocument::saveToStream() {
    HPDF_SaveToStream(pdfDoc);
}

unsigned int PdfDocument::getStreamSize() const {
    return HPDF_GetStreamSize(pdfDoc);
}

void PdfDocument::readFromStream(unsigned char* buffer, unsigned int* size) {
    HPDF_ReadFromStream(pdfDoc, buffer, size);
}

unsigned int PdfDocument::readFromStream(unsigned char* buffer, unsigned int size) {
    unsigned int newSize = size;
    readFromStream(buffer, &newSize);
    return newSize;
}

std::vector<unsigned char> PdfDocument::readFromStream(unsigned int size) {
    std::vector<unsigned char> result;
    result.reserve(size);
    unsigned int newSize = size;
    HPDF_ReadFromStream(pdfDoc, result.data(), &newSize);
    return result;
}

void PdfDocument::rewindStream() {
    HPDF_ResetStream(pdfDoc);
}

bool PdfDocument::assertHasNullOrValidDocument() const {
    return HPDF_HasDoc(pdfDoc);
}

bool PdfDocument::isEmpty() const {
    return pdfDoc == nullptr;
}

void PdfDocument::resetErrorHandler() {
    HPDF_SetErrorHandler(pdfDoc, nullptr);
}

void PdfDocument::setErrorHandler(void (&customErrorHandler)(unsigned long, unsigned long, void*)) {
    HPDF_SetErrorHandler(pdfDoc, customErrorHandler);
}

unsigned long PdfDocument::getLastErrorCode() const {
    return HPDF_GetError(pdfDoc);
}

void PdfDocument::resetErrorCode() {
    HPDF_ResetError(pdfDoc);
}

void PdfDocument::setCompressionMode(CompressionMode mode) {
    HPDF_SetCompressionMode(pdfDoc, (unsigned int) mode);
}

void PdfDocument::setR2EncryptMode() {
    HPDF_SetEncryptionMode(pdfDoc, HPDF_ENCRYPT_R2, 5U);
}

void PdfDocument::setR3EncryptMode(unsigned int keyLength) {
    HPDF_SetEncryptionMode(pdfDoc, HPDF_ENCRYPT_R3, keyLength);
}

void PdfDocument::setR3EncryptMode(R3EncryptKeyLength keyLength) {
    setR3EncryptMode((unsigned int) keyLength);
}

void PdfDocument::setPassword(const char* ownerPassword, const char* userPassword) {
    HPDF_SetPassword(pdfDoc, ownerPassword, userPassword);
}

void PdfDocument::setPassword(const char* ownerPassword, const std::string& userPassword) {
    setPassword(ownerPassword, userPassword.c_str());
}

void PdfDocument::setPassword(const std::string& ownerPassword, const char* userPassword) {
    setPassword(ownerPassword.c_str(), userPassword);
}

void PdfDocument::setPassword(const std::string& ownerPassword, const std::string& userPassword) {
    setPassword(ownerPassword.c_str(), userPassword.c_str());
}


/******************** PAGES HANDLING ********************/

void PdfDocument::setPageConfiguration(unsigned int pagePerPages) {
    HPDF_SetPagesConfiguration(pdfDoc, pagePerPages);
}

void PdfDocument::setPageLayout(PdfPageLayout layout) {
    HPDF_SetPageLayout(pdfDoc, (HPDF_PageLayout) layout);
}

PdfPageLayout PdfDocument::getPageLayout() const {
    switch (HPDF_GetPageLayout(pdfDoc)) {
        case HPDF_PAGE_LAYOUT_SINGLE: return PdfPageLayout::SINGLE_PAGE;
        case HPDF_PAGE_LAYOUT_ONE_COLUMN: return PdfPageLayout::ONE_COLUMN;
        case HPDF_PAGE_LAYOUT_TWO_COLUMN_LEFT: return PdfPageLayout::TWO_COLUMN_LEFT;
        case HPDF_PAGE_LAYOUT_TWO_COLUMN_RIGHT: return PdfPageLayout::TWO_COLUMN_RIGHT;
        default: return PdfPageLayout::EOF_LAYOUT;
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
    HPDF_SetOpenAction(pdfDoc, destination.innerContent);
}

PdfPage PdfDocument::getCurrentPage() const {
    return HPDF_GetCurrentPage(pdfDoc);
}

PdfPage PdfDocument::addPage() {
    return PdfPage(HPDF_AddPage(pdfDoc));
}

PdfPage PdfDocument::insertPageBefore(const PdfPage& page) {
    return PdfPage(HPDF_InsertPage(pdfDoc, page.innerContent));
}

void PdfDocument::addPageLabel(PageNumberStyle style, unsigned int pageNumber, unsigned int firstPage, const char* prefix) {
    HPDF_AddPageLabel(pdfDoc, pageNumber, (HPDF_PageNumStyle) style, firstPage, prefix);
}


/******************** FONT HANDLING ********************/

Font PdfDocument::getFont(const char* fontName, const char* encodingName) {
    return Font(HPDF_GetFont(pdfDoc, fontName, encodingName));
}

Font PdfDocument::getFont(const char* fontName, const std::string& encodingName) {
    return getFont(fontName, encodingName.c_str());
}

Font PdfDocument::getFont(const std::string& fontName, const char* encodingName) {
    return getFont(fontName.c_str(), encodingName);
}

Font PdfDocument::getFont(const std::string& fontName, const std::string& encodingName) {
    return getFont(fontName.c_str(), encodingName.c_str());
}

Font PdfDocument::getFont(const char* fontName, const SingleByteEncoding& encodingName) {
    return getFont(fontName, encodingName.toString());
}

Font PdfDocument::getFont(const std::string& fontName, const SingleByteEncoding& encodingName) {
    return getFont(fontName.c_str(), encodingName.toString());
}

Font PdfDocument::getFont(const char* fontName, const MultiByteEncoding& encodingName) {
    return getFont(fontName, encodingName.toString());
}

Font PdfDocument::getFont(const std::string& fontName, const MultiByteEncoding& encodingName) {
    return getFont(fontName.c_str(), encodingName.toString());
}

Font PdfDocument::getFont(const char* fontName, const ByteEncoding& encodingName) {
    return getFont(fontName, encodingName.toString());
}

Font PdfDocument::getFont(const std::string& fontName, const ByteEncoding& encodingName) {
    return getFont(fontName.c_str(), encodingName.toString());
}

const char* PdfDocument::loadType1FontFromFile(const char* AFMFileName, const char* dataFileName) {
    return HPDF_LoadType1FontFromFile(pdfDoc, AFMFileName, dataFileName);
}

const char* PdfDocument::loadType1FontFromFile(const char* AFMFileName, const std::string& dataFileName) {
    return loadType1FontFromFile(AFMFileName, dataFileName.c_str());
}

const char* PdfDocument::loadType1FontFromFile(const std::string& AFMFileName, const char* dataFileName) {
    return loadType1FontFromFile(AFMFileName.c_str(), dataFileName);
}

const char* PdfDocument::loadType1FontFromFile(const std::string& AFMFileName, const std::string& dataFileName) {
    return loadType1FontFromFile(AFMFileName.c_str(), dataFileName.c_str());
}

const char* PdfDocument::loadTrueTypeFontFromFile(const char* fileName, bool embedding) {
    return HPDF_LoadTTFontFromFile(pdfDoc, fileName, embedding);
}

const char* PdfDocument::loadTrueTypeFontFromFile(const std::string& fileName, bool embedding) {
    return loadTrueTypeFontFromFile(fileName.c_str(), embedding);
}

const char* PdfDocument::loadTrueTypeFontFromFile(const char* fileName, unsigned int index, bool embedding) {
    return HPDF_LoadTTFontFromFile2(pdfDoc, fileName, index, embedding);
}

const char* PdfDocument::loadTrueTypeFontFromFile(const std::string& fileName, unsigned int index, bool embedding) {
    return loadTrueTypeFontFromFile(fileName.c_str(), index, embedding);
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
Encoder PdfDocument::getEncoder(const char* name) {
    return Encoder(HPDF_GetEncoder(pdfDoc, name));
}

Encoder PdfDocument::getEncoder(const std::string& name) {
    return getEncoder(name.c_str());
}

Encoder PdfDocument::getEncoder(SingleByteEncoding name) {
    return getEncoder(name.toString());
}

Encoder PdfDocument::getEncoder(MultiByteEncoding name) {
    return getEncoder(name.toString());
}

Encoder PdfDocument::getCurrentEncoder() {
    return Encoder(HPDF_GetCurrentEncoder(pdfDoc));
}

void PdfDocument::setCurrentEncoder(const char* name) {
    HPDF_SetCurrentEncoder(pdfDoc, name);
}

void PdfDocument::setCurrentEncoder(const std::string& name) {
    setCurrentEncoder(name.c_str());
}

void PdfDocument::useJPEncodings() {
    HPDF_UseJPEncodings(pdfDoc);
}

void PdfDocument::useKREncodings() {
    HPDF_UseKREncodings(pdfDoc);
}

void PdfDocument::useCNSEncodings() {
    HPDF_UseCNSEncodings(pdfDoc);
}

void PdfDocument::useCNTEncodings() {
    HPDF_UseCNTEncodings(pdfDoc);
}

void PdfDocument::useUTFEncodings() {
    HPDF_UseUTFEncodings(pdfDoc);
}


/******************** IMAGES LOADING ********************/
Image PdfDocument::loadPNGImageFromFile(const char* fileName) {
    return Image(HPDF_LoadPngImageFromFile(pdfDoc, fileName));
}

Image PdfDocument::loadPNGImageFromFile(const std::string& fileName) {
    return loadPNGImageFromFile(fileName.c_str());
}

Image PdfDocument::loadPartialPNGImageFromFile(const char* fileName) {
    return Image(HPDF_LoadPngImageFromFile2(pdfDoc, fileName));
}

Image PdfDocument::loadPartialPNGImageFromFile(const std::string& fileName) {
    return loadPartialPNGImageFromFile(fileName.c_str());
}

Image PdfDocument::loadJPEGImageFromFile(const char* fileName) {
    return Image(HPDF_LoadJpegImageFromFile(pdfDoc, fileName));
}

Image PdfDocument::loadJPEGImageFromFile(const std::string& fileName) {
    return loadJPEGImageFromFile(fileName.c_str());
}

Image PdfDocument::loadRawImageFromFile(
    const char* fileName, unsigned int width,
    unsigned int height, ImageColorSpaceDevice colorSpace
) {
    return Image(HPDF_LoadRawImageFromFile(pdfDoc, fileName, width, height, (HPDF_ColorSpace) colorSpace));
}

Image PdfDocument::loadRawImageFromFile(
    const std::string& fileName, unsigned int width,
    unsigned int height, ImageColorSpaceDevice colorSpace
) {
    return loadRawImageFromFile(fileName.c_str(), width, height, colorSpace);
}

Image PdfDocument::loadRawImageFromMemory(
    const unsigned char* bytes, unsigned int width,
    unsigned int height, ImageColorSpaceDevice colorSpace,
    BitsPerComponent bitsPerComponent
) {
    return Image(HPDF_LoadRawImageFromMem(pdfDoc, bytes, width, height, (HPDF_ColorSpace) colorSpace, (HPDF_UINT) bitsPerComponent));
}

Image PdfDocument::loadRawImageFromMemory(
    const std::vector<unsigned char>& bytes, unsigned int width,
    unsigned int height, ImageColorSpaceDevice colorSpace,
    BitsPerComponent bitsPerComponent
) {
    return loadRawImageFromMemory(bytes.data(), width, height, colorSpace, bitsPerComponent);
}

Image PdfDocument::loadPNGImageFromMemory(const unsigned char* bytes, unsigned int size) {
    return Image(HPDF_LoadPngImageFromMem(pdfDoc, bytes, size));
}

Image PdfDocument::loadPNGImageFromMemory(const std::vector<unsigned char>& bytes) {
    return loadPNGImageFromMemory(bytes.data(), bytes.size());
}

Image PdfDocument::loadJPEGImageFromMemory(const unsigned char* bytes, unsigned int size) {
    return Image(HPDF_LoadJpegImageFromMem(pdfDoc, bytes, size));
}

Image PdfDocument::loadJPEGImageFromMemory(const std::vector<unsigned char>& bytes) {
    return loadJPEGImageFromMemory(bytes.data(), bytes.size());
}


/******************** ATTRIBUTES ********************/

void PdfDocument::setPermission(Permissions permissions) {
    HPDF_SetPermission(pdfDoc, permissions);
}

void PdfDocument::setAttribute(PdfDateTimeAttribute parameter, const DateTime& value) {
    HPDF_SetInfoDateAttr(pdfDoc, (HPDF_InfoType) parameter, value.innerContent);
}

void PdfDocument::setAttribute(PdfStringAttribute parameter, const char* value) {
    HPDF_SetInfoAttr(pdfDoc, (HPDF_InfoType) parameter, value);
}

void PdfDocument::setAttribute(PdfStringAttribute parameter, const std::string& value) {
    setAttribute(parameter, value.c_str());
}

const char* PdfDocument::getInfoAttribute(PdfDateTimeAttribute parameter) {
    return HPDF_GetInfoAttr(pdfDoc, (HPDF_InfoType) parameter);
}

const char* PdfDocument::getInfoAttribute(PdfStringAttribute parameter) {
    return HPDF_GetInfoAttr(pdfDoc, (HPDF_InfoType) parameter);
}


/******************** OUTLINE CREATION ********************/

Outline PdfDocument::createOutline(const char* title, const Outline* parent, const Encoder* encoder) const {
    return Outline(HPDF_CreateOutline(pdfDoc, parent? parent->innerContent: nullptr, title, encoder? encoder->innerContent: nullptr));
}

Outline PdfDocument::createOutline(const std::string& title, const Outline* parent, const Encoder* encoder) const {
    return createOutline(title.c_str(), parent, encoder);
}

Outline PdfDocument::createOutline(const char* title, const Outline& parent, const Encoder* encoder) const {
    return Outline(HPDF_CreateOutline(pdfDoc, parent.innerContent, title, encoder? encoder->innerContent: nullptr));
}

Outline PdfDocument::createOutline(const std::string& title, const Outline& parent, const Encoder* encoder) const {
    return createOutline(title.c_str(), parent, encoder);
}

Outline PdfDocument::createOutline(const char* title, const Outline* parent, const Encoder& encoder) const {
    return Outline(HPDF_CreateOutline(pdfDoc, parent? parent->innerContent: nullptr, title, encoder.innerContent));
}

Outline PdfDocument::createOutline(const std::string& title, const Outline* parent, const Encoder& encoder) const {
    return createOutline(title.c_str(), parent, encoder);
}

Outline PdfDocument::createOutline(const char* title, const Outline& parent, const Encoder& encoder) const {
    return Outline(HPDF_CreateOutline(pdfDoc, parent.innerContent, title, encoder.innerContent));
}

Outline PdfDocument::createOutline(const std::string& title, const Outline& parent, const Encoder& encoder) const {
    return createOutline(title.c_str(), parent, encoder);
}

Outline PdfDocument::createOutline(const char* title, const Encoder* encoder) const {
    return Outline(HPDF_CreateOutline(pdfDoc, nullptr, title, encoder? encoder->innerContent: nullptr));
}

Outline PdfDocument::createOutline(const std::string& title, const Encoder* encoder) const {
    return createOutline(title.c_str(), encoder);
}

Outline PdfDocument::createOutline(const char* title, const Encoder& encoder) const {
    return Outline(HPDF_CreateOutline(pdfDoc, nullptr, title, encoder.innerContent));
}

Outline PdfDocument::createOutline(const std::string& title, const Encoder& encoder) const {
    return createOutline(title.c_str(), encoder);
}

Outline PdfDocument::createOutline(const char* title, const Outline* outline) const {
    return Outline(HPDF_CreateOutline(pdfDoc, outline? outline->innerContent: nullptr, title, nullptr));
}

Outline PdfDocument::createOutline(const std::string& title, const Outline* outline) const {
    return createOutline(title.c_str(), outline);
}

Outline PdfDocument::createOutline(const char* title, const Outline& outline) const {
    return Outline(HPDF_CreateOutline(pdfDoc, outline.innerContent, title, nullptr));
}

Outline PdfDocument::createOutline(const std::string& title, const Outline& outline) const {
    return createOutline(title.c_str(), outline);
}

Outline PdfDocument::createOutline(const char* title) const {
    return Outline(HPDF_CreateOutline(pdfDoc, nullptr, title, nullptr));
}

Outline PdfDocument::createOutline(const std::string& title) const {
    return createOutline(title.c_str());
}


/******************** OPERATORS ********************/
void PdfDocument::operator=(const PdfDocument& newDoc) {
    close();
    pdfDoc = newDoc.pdfDoc;
}
