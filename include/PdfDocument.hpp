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
        void _openPdf();

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

        void saveToFile(const char* fileName);
        void saveToFile(const std::string& fileName);

        void saveToStream();
        unsigned int getStreamSize() const;
        void readFromStream(unsigned char* buffer, unsigned int* size);
        unsigned int readFromStream(unsigned char* buffer, unsigned int size);
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

        void addPageLabel(PageNumberStyle style = PageNumberStyle::DECIMAL, unsigned int pageNumber = 0U, unsigned int firstPage = 1U, const char* prefix = nullptr);


        /******************** FONT HANDLING ********************/
        Font getFont(const char* fontName, const char* encodingName = "StandardEncoding");
        Font getFont(const char* fontName, const std::string& encodingName);
        Font getFont(const std::string& fontName, const char* encodingName = "StandardEncoding");
        Font getFont(const std::string& fontName, const std::string& encodingName);

        Font getFont(const char* fontName, const SingleByteEncoding& encodingName);
        Font getFont(const std::string& fontName, const SingleByteEncoding& encodingName);
        Font getFont(const char* fontName, const MultiByteEncoding& encodingName);
        Font getFont(const std::string& fontName, const MultiByteEncoding& encodingName);
        Font getFont(const char* fontName, const ByteEncoding& encodingName);
        Font getFont(const std::string& fontName, const ByteEncoding& encodingName);

        const char* loadType1FontFromFile(const char* AFMFileName, const char* dataFileName = nullptr);
        const char* loadType1FontFromFile(const char* AFMFileName, const std::string& dataFileName);
        const char* loadType1FontFromFile(const std::string& AFMFileName, const char* dataFileName = nullptr);
        const char* loadType1FontFromFile(const std::string& AFMFileName, const std::string& dataFileName);

        const char* loadTrueTypeFontFromFile(const char* fileName, bool embedding);
        const char* loadTrueTypeFontFromFile(const std::string& fileName, bool embedding);
        const char* loadTrueTypeFontFromFile(const char* fileName, unsigned int index, bool embedding);
        const char* loadTrueTypeFontFromFile(const std::string& fileName, unsigned int index, bool embedding);

        void useJPFonts();
        void useKRFonts();
        void useCNSFonts();
        void useCNTFonts();


        /******************** ENCODINGS ********************/
        Encoder getEncoder(const char* name);
        Encoder getEncoder(const std::string& name);
        Encoder getEncoder(SingleByteEncoding name);
        Encoder getEncoder(MultiByteEncoding name);

        Encoder getCurrentEncoder();
        void setCurrentEncoder(const char* name);
        void setCurrentEncoder(const std::string& name);

        void useJPEncodings();
        void useKREncodings();
        void useCNSEncodings();
        void useCNTEncodings();
        void useUTFEncodings();


        /******************** OUTLINE CREATION ********************/
        Outline createOutline(const char* title, const Outline* parent, const Encoder* encoder) const;
        Outline createOutline(const std::string& title, const Outline* parent, const Encoder* encoder) const;

        Outline createOutline(const char* title, const Outline& parent, const Encoder* encoder) const;
        Outline createOutline(const std::string& title, const Outline& parent, const Encoder* encoder) const;

        Outline createOutline(const char* title, const Outline* parent, const Encoder& encoder) const;
        Outline createOutline(const std::string& title, const Outline* parent, const Encoder& encoder) const;

        Outline createOutline(const char* title, const Outline& parent, const Encoder& encoder) const;
        Outline createOutline(const std::string& title, const Outline& parent, const Encoder& encoder) const;

        Outline createOutline(const char* title, const Encoder* encoder) const;
        Outline createOutline(const std::string& title, const Encoder* encoder) const;

        Outline createOutline(const char* title, const Encoder& encoder) const;
        Outline createOutline(const std::string& title, const Encoder& encoder) const;

        Outline createOutline(const char* title, const Outline* outline) const;
        Outline createOutline(const std::string& title, const Outline* outline) const;

        Outline createOutline(const char* title, const Outline& outline) const;
        Outline createOutline(const std::string& title, const Outline& outline) const;

        Outline createOutline(const char* title) const;
        Outline createOutline(const std::string& title) const;


        /******************** IMAGES LOADING ********************/
        Image loadPNGImageFromFile(const char* fileName);
        Image loadPNGImageFromFile(const std::string& fileName);

        Image loadPartialPNGImageFromFile(const char* fileName);
        Image loadPartialPNGImageFromFile(const std::string& fileName);

        Image loadRawImageFromFile(
            const char* fileName, unsigned int width,
            unsigned int height, ImageColorSpaceDevice colorSpace
        );
        Image loadRawImageFromFile(
            const std::string& fileName, unsigned int width,
            unsigned int height, ImageColorSpaceDevice colorSpace
        );

        Image loadRawImageFromMemory(
            const unsigned char* bytes, unsigned int width,
            unsigned int height, ImageColorSpaceDevice colorSpace,
            BitsPerComponent bitsPerComponent
        );

        Image loadRawImageFromMemory(
            const std::vector<unsigned char>& bytes, unsigned int width,
            unsigned int height, ImageColorSpaceDevice colorSpace,
            BitsPerComponent bitsPerComponent
        );

        Image loadPNGImageFromMemory(const unsigned char* bytes, unsigned int size);
        Image loadPNGImageFromMemory(const std::vector<unsigned char>& bytes);

        Image loadJPEGImageFromMemory(const unsigned char* bytes, unsigned int size);
        Image loadJPEGImageFromMemory(const std::vector<unsigned char>& bytes);

        Image loadJPEGImageFromFile(const char* fileName);
        Image loadJPEGImageFromFile(const std::string& fileName);


        /******************** OTHER FUNCTIONS ********************/

        void setAttribute(PdfStringAttribute parameter, const char* value);
        void setAttribute(PdfStringAttribute parameter, const std::string& value);

        const char* getInfoAttribute(PdfStringAttribute parameter);
        const char* getInfoAttribute(PdfDateTimeAttribute parameter);

        void setAttribute(PdfDateTimeAttribute parameter, const DateTime& value);

        void setPassword(const char* ownerPassword, const char* userPassword = nullptr);
        void setPassword(const char* ownerPassword, const std::string& userPassword);
        void setPassword(const std::string& ownerPassword, const char* userPassword = nullptr);
        void setPassword(const std::string& ownerPassword, const std::string& userPassword);

        void setPermission(Permissions permissions);

        void setR2EncryptMode();
        void setR3EncryptMode(R3EncryptKeyLength keyLength = R3EncryptKeyLength::SIXTEEN);

        void setCompressionMode(CompressionMode mode);


        /******************** OPERATORS ********************/
        void operator=(const PdfDocument& newDoc);
    };
}

#endif // __HARUPP_PDFDOCUMENT_HPP__
