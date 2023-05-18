#ifndef __HARUPP_PDFDOCUMENT_HPP__
#define __HARUPP_PDFDOCUMENT_HPP__
#include "Box.hpp"
#include "CMYKColor.hpp"
#include "Constants.hpp"
#include "Coor2D.hpp"
#include "DashMode.hpp"
#include "DateTime.hpp"
#include "Destination.hpp"
#include "Encoder.hpp"
#include "Enums.hpp"
#include "Font.hpp"
#include "Image.hpp"
#include "LinkAnnotation.hpp"
#include "Outline.hpp"
#include "PdfException.hpp"
#include "PdfPage.hpp"
#include "Permissions.hpp"
#include "RGBColor.hpp"
#include "TextAnnotation.hpp"
#include "TextWidth.hpp"
#include "TransposeMatrix.hpp"
#include "Utils.hpp"
#include "vector"

struct _HPDF_Doc_Rec;

namespace pdf {

    /**
     * \class  PdfDocument
     * @brief  Represents a pdf document.
     * @file   PdfDocument.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class PdfDocument: public PdfObject {
        mutable _HPDF_Doc_Rec* pdfDoc = nullptr;
        std::vector<bool> imports;

    public:

        /**
         * @brief Creates a new PdfDocument.
         * @note  The object is initially empty and a new document should be opened with ::open.
        */
        PdfDocument() noexcept;

        /**
         * @brief   Frees all the allocated resources.
         * @details This calls the ::close function.
        */
        ~PdfDocument();

        /**
         * @brief Opens a new document.
         * @throw except::MemoryAllocationFailedException if the opening failed.
        */
        void open();

        /**
         * @brief Closes the document and frees all allocated resources.
         * @note  This is automatically called when ::~PdfDocument gets called and should be rarely used.
        */
        void close();

        /**
         * @brief Closes the current document (if any) and creates a new document.
         * @note  The new document will not be opened. Call ::open after this function call to open it.
         * @throw except::MemoryAllocationFailedException if the opening failed.
        */
        void newDocument();

        /**
         * @brief   Checks whether a document has been opened.
         * @return `true` if a document is currently open, `false` otherwise.
        */
        bool isOpen() const noexcept;

        /**
         * @brief Revokes the current document.
         * @note  Unlike ::freeAllResources, loaded resources such as fonts and encodings are kept and recycled when a new document requires them.
        */
        void freeResources();

        /**
         * @brief Revokes the current document and resources.
         * @note  Unlike ::freeResources, all loaded resources are also revoked.
        */
        void freeAllResources();

        /**
         * @brief Save the pdf document to a file.
         * @param fileName Relative or absolute file path to use.
        */
        void saveToFile(const std::string& fileName);

        /**
         * @brief Saves the document to the temporary stream.
         * @note  This will overwrite the previous temporary stream with new data.
        */
        void saveToStream();

        /**
         * @brief  Gets the temporary stream size.
         * @return Stream size.
        */
        unsigned int getStreamSize() const;

        /**
         * @brief  Reads up to a certain number of bytes from the stream.
         * @param  size Size limit.
         * @return Vector of bytes read. The vector size will be smaller or equal to `size`.
         * @note   If ::saveToStream has never been called, this will return an empty vector.
        */
        std::vector<unsigned char> readFromStream(unsigned int size);

        /**
         * @brief   Reads from the stream.
         * @details This is equivalent to `readFromStream(UINT_MAX)`.
         * @return  Vector of bytes read. The vector size will be smaller or equal to `UINT_MAX`.
         * @note    If ::saveToStream has never been called, this will return an empty vector.
        */
        std::vector<unsigned char> readFromStream();

        /**
         * @brief Rewinds the temporary stream to the beginning.
         * @note  This has no effect if no stream has been saved.
        */
        void rewindStream();

        /**
         * @brief  Reads the pdf content up to a certain number of bytes.
         * @param  size Size limit.
         * @return Vector of bytes read.
         * @note   The vector size will be smaller or equal to `size`.
        */
        std::vector<unsigned char> getContent(unsigned int size) const;

        /**
         * @brief   Reads the pdf content.
         * @details This is equivalent to `getContent(UINT_MAX)`.
         * @return  Vector of bytes read.
         * @note    The vector size will be smaller or equal to `UINT_MAX`.
        */
        std::vector<unsigned char> getContent() const;

        bool hasDocument() const;
        bool isEmpty() const noexcept final override;

        unsigned long getLastErrorCode() const;
        unsigned long getLastErrorDetail() const;
        void resetErrorCode();

        /******************** PAGES HANDLING ********************/
        void setPageConfiguration(unsigned int pagePerPages);

        void setPageLayout(enums::PageLayout layout);
        enums::PageLayout getPageLayout() const;

        void setPageMode(enums::PageMode mode);
        enums::PageMode getPageMode() const;

        void setOpenDestination(const Destination& destination);

        PdfPage getCurrentPage() const;
        PdfPage addPage();
        PdfPage insertPageBefore(const PdfPage& page);

        void addPageLabel(enums::PageNumberStyle style = enums::PageNumberStyle::DECIMAL, unsigned int pageNumber = 0U, unsigned int firstPage = 1U);
        void addPageLabel(const std::string& prefix, enums::PageNumberStyle style = enums::PageNumberStyle::DECIMAL, unsigned int pageNumber = 0U, unsigned int firstPage = 1U);

        /**
         * @brief  Gets a Font from a name and single byte encoding.
         * @param  fontName The font name.
         * @param  encoding Single byte encoding.
         * @return New Font object.
        */
        Font getFont(const std::string& fontName, enums::SingleByteEncoding encoding = enums::SingleByteEncoding::StandardEncoding);

        /**
         * @brief  Gets a Font from a name and multi byte encoding.
         * @param  fontName The font name.
         * @param  encoding Multi byte encoding.
         * @return New Font object.
        */
        Font getFont(const std::string& fontName, enums::MultiByteEncoding encoding);

        std::string loadType1FontFromFile(const std::string& AFMFileName);
        std::string loadType1FontFromFile(const std::string& AFMFileName, const std::string& dataFileName);

        std::string loadTrueTypeFontFromFile(const std::string& fileName, bool embedding);
        std::string loadTrueTypeFontFromFile(const std::string& fileName, unsigned int index, bool embedding);

        void useJPFonts();
        void useKRFonts();
        void useCNSFonts();
        void useCNTFonts();

        /******************** ENCODINGS ********************/

        /**
         * @brief  Gets the Encoder of a single byte encoding.
         * @param  encoding Single byte encoding to use.
         * @return Corresponding Encoder.
        */
        Encoder getEncoder(enums::SingleByteEncoding encoding);

        /**
         * @brief  Gets the Encoder of a multi byte encoding.
         * @param  encoding Multi byte encoding to use.
         * @return Corresponding Encoder.
        */
        Encoder getEncoder(enums::MultiByteEncoding encoding);

        /**
         * @brief  Gets the current Encoder.
         * @return Current Encoder.
        */
        Encoder getCurrentEncoder();

        void setCurrentEncoder(enums::SingleByteEncoding encoding);
        void setCurrentEncoder(enums::MultiByteEncoding encoding);

        void useJPEncodings();
        void useKREncodings();
        void useCNSEncodings();
        void useCNTEncodings();
        void useUTFEncodings();

        bool isAutoEncodingImportsEnabled() const;
        void enableAutoEncodingImports();
        void disableAutoEncodingImports();

        /**
         * @brief  Creates an Outline.
         * @param  title The title to use for the outline.
         * @return Newly created outline.
        */
        Outline createOutline(const std::string& title) const;

        /**
         * @brief  Creates an Outline.
         * @param  title The title to use for the outline.
         * @param  parent The outline to use as parent.
         * @return Newly created outline.
        */
        Outline createOutline(const std::string& title, const Outline& parent) const;

        /**
         * @brief  Creates an Outline.
         * @param  title The title to use for the outline.
         * @param  encoder The encoder to use.
         * @return Newly created outline.
        */
        Outline createOutline(const std::string& title, const Encoder& encoder) const;

        /**
         * @brief  Creates an Outline.
         * @param  title The title to use for the outline.
         * @param  parent The outline to use as parent.
         * @param  encoder The encoder to use.
         * @return Newly created outline.
        */
        Outline createOutline(const std::string& title, const Outline& parent, const Encoder& encoder) const;

        /**
         * @brief  Loads a PNG image from a file.
         * @param  fileName The image filename.
         * @return Image from the filename.
        */
        Image loadPNGImageFromFile(const std::string& fileName);

        /**
         * @brief  Loads a PNG image from memory.
         * @param  bytes Vector of bytes to use.
         * @return Image from memory.
        */
        Image loadPNGImageFromMemory(const std::vector<unsigned char>& bytes);

        /**
         * @brief Loads a PNG image from a file.
         * @note  Unlike ::loadPNGImageFromFile, only the size and color properties are loaded.
         *        The main data is loaded just before the image object is written to PDF, then deleted immediately.
         * @param  fileName The image filename.
         * @return Image from the filename.
        */
        Image loadPartialPNGImageFromFile(const std::string& fileName);

        /**
         * @brief  Loads a raw image from a file.
         * @param  fileName The image filename.
         * @param  width The width of the image.
         * @param  height The height of the image.
         * @param  colorSpace Color space to use.
         * @return New Image object.
        */
        Image loadRawImageFromFile(
            const std::string& fileName, unsigned int width,
            unsigned int height, enums::ImageColorSpaceDevice colorSpace
        );

        /**
         * @brief  Loads a raw image from memory.
         * @param  bytes Vector of bytes encoding the image.
         * @param  width The width of the image.
         * @param  height The height of the image.
         * @param  colorSpace The color space to use.
         * @param  bitsPerComponent Number of bits per component.
         * @return New Image object.
        */
        Image loadRawImageFromMemory(
            const std::vector<unsigned char>& bytes, unsigned int width,
            unsigned int height, enums::ImageColorSpaceDevice colorSpace,
            enums::BitsPerComponent bitsPerComponent
        );

        /**
         * @brief  Loads a JPEG image from memory.
         * @param  bytes Vector of bytes to use.
         * @return Image from memory.
        */
        Image loadJPEGImageFromMemory(const std::vector<unsigned char>& bytes);

        /**
         * @brief  Loads a JPEG image from a file.
         * @param  fileName The image filename.
         * @return Image from the filename.
        */
        Image loadJPEGImageFromFile(const std::string& fileName);

        /******************** OTHER FUNCTIONS ********************/
        void setAttribute(enums::StringAttribute parameter, const std::string& value);
        void setAttribute(enums::DateTimeAttribute parameter, const DateTime& value);

        std::optional<std::string> getInfoAttribute(enums::StringAttribute parameter);
        std::optional<std::string> getInfoAttribute(enums::DateTimeAttribute parameter);

        /**
         * @brief Sets the owner password for a pdf document (with no user password).
         * @param ownerPassword Owner password (cannot be empty).
         * @throw except::InvalidPasswordException if `ownerPassword` is empty.
        */
        void setPassword(const std::string& ownerPassword);

        /**
         * @brief Sets the owner and user passwords for a pdf document.
         * @param ownerPassword Owner password (cannot be empty).
         * @param userPassword  User password (can be empty, but cannot be equal to `ownerPassword`).
         * @throw except::InvalidPasswordException if `ownerPassword` is empty or `ownerPassword` equals `userPassword`.
        */
        void setPassword(const std::string& ownerPassword, const std::string& userPassword);

        /**
         * @brief   Sets the pdf document permissions.
         * @param   permissions The permissions to use.
         * @warning A ::setPassword function must be called before calling this function.
         * @throws  except::EncryptionNotSetException if no password has been set.
        */
        void setPermissions(const Permissions& permissions);

        /**
         * @brief   Sets the R2 encryption mode.
         * @warning A ::setPassword function must be called before calling this function.
         * @throws  except::EncryptionNotSetException if no password has been set.
        */
        void setR2EncryptMode();

        /**
         * @brief   Sets the R3 encryption mode.
         * @param   keyLength Key length to use.
         * @warning A ::setPassword function must be called before calling this function.
         * @throws  except::EncryptionNotSetException if no password has been set.
        */
        void setR3EncryptMode(enums::R3EncryptKeyLength keyLength = enums::R3EncryptKeyLength::SIXTEEN);

        /**
         * @brief Sets the document compression.
         * @param mode Compression mode to use.
        */
        void setCompressionMode(enums::CompressionMode mode);

        /**
         * @brief Closes the current document, which will now point to a new document.
         * @param newDoc New pdf document to use.
        */
        void operator=(const PdfDocument& newDoc);

    private:
        bool __getImportValue(int index) const;
        void __setImportValue(int index, bool newValue);
        Font __getFont(const char* fontName, const char* encodingName);
        std::string __loadType1FontFromFile(const char* AFMFileName, const char* dataFileName);
        Encoder __getEncoder(const char* name);
        void __setCurrentEncoder(const char* name);
        Outline __createOutline(const std::string& title, const Outline* parent, const Encoder* encoder) const;
        void __autoImportEncoding(enums::MultiByteEncoding encoding);
    };
}

#endif // __HARUPP_PDFDOCUMENT_HPP__
