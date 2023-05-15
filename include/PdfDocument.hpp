#ifndef __HARUPP_PDFDOCUMENT_HPP__
#define __HARUPP_PDFDOCUMENT_HPP__
#include "Annotation.hpp"
#include "Box.hpp"
#include "CMYKColor.hpp"
#include "Color.hpp"
#include "Constants.hpp"
#include "ContentStream.hpp"
#include "Coor2D.hpp"
#include "DashMode.hpp"
#include "DateTime.hpp"
#include "Destination.hpp"
#include "Encoder.hpp"
#include "Font.hpp"
#include "Image.hpp"
#include "LinkAnnotation.hpp"
#include "Outline.hpp"
#include "PdfException.hpp"
#include "PdfObject.hpp"
#include "PdfPage.hpp"
#include "RGBColor.hpp"
#include "TextAnnotation.hpp"
#include "TextWidth.hpp"
#include "TransposeMatrix.hpp"
#include "vector"

namespace pdf {
    constexpr int MAX_STRING_LEN = HPDF_LIMIT_MAX_STRING_LEN;
    constexpr int MAX_DICT_ELEMENT = HPDF_LIMIT_MAX_DICT_ELEMENT;
    constexpr int MAX_GSTATE = HPDF_LIMIT_MAX_GSTATE;

    class PdfDocument: public PdfObject {
        mutable HPDF_Doc pdfDoc = nullptr;
        bool opened = false;
        bool autoEncodingImportEnabled = false;
        bool CNSEncodingimported = false;
        bool CNTEncodingimported = false;
        bool JPEncodingimported = false;
        bool KREncodingimported = false;
        bool UTFEncodingimported = false;

    public:
        /******************** CONSTRUCTORS & DESTRUCTOR ********************/
        PdfDocument() noexcept;
        ~PdfDocument();

        /******************** BASIC FUNCTIONS ********************/
        void open();
        void open(void (&customErrorHandler)(unsigned long, unsigned long, void*), void* userData = nullptr);
        void open(
            void* (&customAllocFunc)(unsigned int), void (&customFreeFunc)(void*), unsigned int memPoolBufSize,
            void (&customErrorHandler)(unsigned long, unsigned long, void*), void* userData = nullptr
        );

        void close();
        void newDocument();
        bool isOpen() const;

        void freeResources();
        void freeAllResources();

        void saveToFile(const std::string& fileName);

        void saveToStream();
        unsigned int getStreamSize() const;
        std::vector<unsigned char> readFromStream(unsigned int size);
        void rewindStream();

        bool hasDocument() const;
        bool isEmpty() const final override;

        void resetErrorHandler();
        void setErrorHandler(void (&customErrorHandler)(unsigned long, unsigned long, void*));
        unsigned long getLastErrorCode() const;
        void resetErrorCode();

        /******************** PAGES HANDLING ********************/
        void setPageConfiguration(unsigned int pagePerPages);

        void setPageLayout(PdfPageLayout layout);
        PdfPageLayout getPageLayout() const;

        void setPageMode(PageMode mode);
        PageMode getPageMode() const;

        void setOpenDestination(const Destination& destination);

        PdfPage getCurrentPage() const;
        PdfPage addPage();
        PdfPage insertPageBefore(const PdfPage& page);

        void addPageLabel(PageNumberStyle style = PageNumberStyle::DECIMAL, unsigned int pageNumber = 0U, unsigned int firstPage = 1U);
        void addPageLabel(const std::string& prefix, PageNumberStyle style = PageNumberStyle::DECIMAL, unsigned int pageNumber = 0U, unsigned int firstPage = 1U);

        /******************** FONT HANDLING ********************/
        Font getFont(const std::string& fontName, SingleByteEncoding encoding = SingleByteEncoding::StandardEncoding);
        Font getFont(const std::string& fontName, MultiByteEncoding encoding);

        std::string loadType1FontFromFile(const std::string& AFMFileName);
        std::string loadType1FontFromFile(const std::string& AFMFileName, const std::string& dataFileName);

        std::string loadTrueTypeFontFromFile(const std::string& fileName, bool embedding);
        std::string loadTrueTypeFontFromFile(const std::string& fileName, unsigned int index, bool embedding);

        void useJPFonts();
        void useKRFonts();
        void useCNSFonts();
        void useCNTFonts();

        /******************** ENCODINGS ********************/
        Encoder getEncoder(SingleByteEncoding encoding);
        Encoder getEncoder(MultiByteEncoding encoding);

        Encoder getCurrentEncoder();
        void setCurrentEncoder(SingleByteEncoding encoding);
        void setCurrentEncoder(MultiByteEncoding encoding);

        void useJPEncodings();
        void useKREncodings();
        void useCNSEncodings();
        void useCNTEncodings();
        void useUTFEncodings();

        bool isAutoEncodingImportsEnabled() const;
        void enableAutoEncodingImports();
        void disableAutoEncodingImports();

        /******************** OUTLINE CREATION ********************/
        Outline createOutline(const std::string& title) const;
        Outline createOutline(const std::string& title, const Outline& parent) const;
        Outline createOutline(const std::string& title, const Encoder& encoder) const;
        Outline createOutline(const std::string& title, const Outline& parent, const Encoder& encoder) const;

        /******************** IMAGES LOADING ********************/
        Image loadPNGImageFromFile(const std::string& fileName);
        Image loadPartialPNGImageFromFile(const std::string& fileName);

        Image loadRawImageFromFile(
            const std::string& fileName, unsigned int width,
            unsigned int height, ImageColorSpaceDevice colorSpace
        );

        Image loadRawImageFromMemory(
            const std::vector<unsigned char>& bytes, unsigned int width,
            unsigned int height, ImageColorSpaceDevice colorSpace,
            BitsPerComponent bitsPerComponent
        );

        Image loadPNGImageFromMemory(const std::vector<unsigned char>& bytes);
        Image loadJPEGImageFromMemory(const std::vector<unsigned char>& bytes);
        Image loadJPEGImageFromFile(const std::string& fileName);

        /******************** OTHER FUNCTIONS ********************/
        void setAttribute(PdfStringAttribute parameter, const std::string& value);
        void setAttribute(PdfDateTimeAttribute parameter, const DateTime& value);

        std::optional<std::string> getInfoAttribute(PdfStringAttribute parameter);
        std::optional<std::string> getInfoAttribute(PdfDateTimeAttribute parameter);

        void setPassword(const std::string& ownerPassword);
        void setPassword(const std::string& ownerPassword, const std::string& userPassword);

        void setPermission(Permissions permissions);

        void setR2EncryptMode();
        void setR3EncryptMode(R3EncryptKeyLength keyLength = R3EncryptKeyLength::SIXTEEN);

        void setCompressionMode(CompressionMode mode);

        /******************** OPERATORS ********************/
        void operator=(const PdfDocument& newDoc);

    private:
        void __openPdf();
        Font __getFont(const char* fontName, const char* encodingName);
        std::string __loadType1FontFromFile(const char* AFMFileName, const char* dataFileName);
        Encoder __getEncoder(const char* name);
        void __setCurrentEncoder(const char* name);
        Outline __createOutline(const std::string& title, const Outline* parent, const Encoder* encoder) const;
        void __autoImportEncoding(MultiByteEncoding encoding);
    };
}

#endif // __HARUPP_PDFDOCUMENT_HPP__
