#ifndef __HARUPP_DOCUMENT_HPP__
#define __HARUPP_DOCUMENT_HPP__
#include "Box.hpp"
#include "CMYKColor.hpp"
#include "CompressionMode.hpp"
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
#include "Exception.hpp"
#include "Page.hpp"
#include "Permissions.hpp"
#include "RGBColor.hpp"
#include "TextAnnotation.hpp"
#include "TextWidth.hpp"
#include "TransposeMatrix.hpp"
#include "Utils.hpp"
#include "ViewerPreferences.hpp"
#include "vector"

struct _HPDF_Doc_Rec;

namespace pdf {

    /**
     * \class  Document
     * @brief  Represents a pdf document.
     * @file   Document.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class Document: public Object {
        mutable _HPDF_Doc_Rec* pdfDoc = nullptr;
        std::vector<bool> imports;

    public:

        /**
         * @brief Creates a new Document.
         * @note  The object is initially empty and a new document should be opened with ::open.
        */
        Document() noexcept;

        /**
         * @brief   Frees all the allocated resources.
         * @details This calls the ::close function.
        */
        ~Document();

        /**
         * @brief Opens a new document.
         * @throw excepts::MemoryAllocationFailedException if the opening failed.
        */
        void open();

        /**
         * @brief Closes the document and frees all allocated resources.
         * @note  This is automatically called when ::~Document gets called and should be rarely used.
        */
        void close();

        /**
         * @brief Closes the current document (if any) and creates a new document.
         * @note  The new document will not be opened. Call ::open after this function call to open it.
         * @throw excepts::MemoryAllocationFailedException if the opening failed.
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
         * @note  This will overwrite the temporary stream with new data.
        */
        void saveToStream();

        /**
         * @brief  Gets the temporary stream size.
         * @note   This returns `0` if data was never written to the stream, or if the document has been closed.
         * @return Temporary stream size.
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
         * @details This is equivalent to `readFromStream(getStreamSize())`.
         * @return  Vector of bytes read. The vector size will be smaller or equal to ::getStreamSize().
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
        std::vector<unsigned char> getContent(unsigned int size = UINT_MAX) const;

        /**
         * @brief  Checks whether a document is present.
         * @return `true` if a document is present, `false` otherwise.
        */
        bool hasDocument() const;

        /**
         * @brief  Checks whether a document has been opened.
         * @return `true` if a document has been opened, `false` otherwise.
        */
        bool isEmpty() const noexcept final override;

        /**
         * @brief  Gets the last error code raised.
         * @note   This will return `0` if no error has been raised.
         * @return Last error code.
        */
        unsigned long getLastErrorCode() const;

        /**
         * @brief  Gets the last error detail code.
         * @note   This will return `0` if no error has been raised or no detail code has been set for the last error.
         * @return Last error detail code.
        */
        unsigned long getLastErrorDetail() const;

        /**
         * @brief Resets the error code and detail code.
         * @note  The ::getLastErrorCode and ::getLastErrorDetail functions will not return `0` until another error has been raised.
        */
        void resetErrorCode();

        /**
         * @brief Sets the number of page per pages.
         * @param pagePerPages Value to use.
        */
        void setPageConfiguration(unsigned int pagePerPages);

        /**
         * @brief  Gets the Page at a specified index.
         * @param  index Index to use.
         * @return Page at specified index `index`.
        */
        Page getPageAtIndex(unsigned int index) const;

        /**
         * @brief Sets the page layout.
         * @param layout Layout to set.
        */
        void setPageLayout(enums::PageLayout layout);

        /**
         * @brief  Gets the page layout.
         * @return Current page layout.
        */
        enums::PageLayout getPageLayout() const;

        /**
         * @brief Sets the page mode.
         * @param mode Mode to set.
        */
        void setPageMode(enums::PageMode mode);

        /**
         * @brief  Gets the page mode.
         * @return Current page mode.
        */
        enums::PageMode getPageMode() const;

        /**
         * @brief Sets the viewer preferences.
         * @param preferences Preferences to use.
        */
        void setViewerPreferences(const ViewerPreferences& preferences);

        /**
         * @brief  Gets the ViewerPreferences.
         * @return Current ViewerPreferences.
        */
        ViewerPreferences getViewerPreferences() const;

        /**
         * @brief Sets the destination to go to upon opening.
         * @param destination Destination to use.
        */
        void setOpenDestination(const Destination& destination);

        /**
         * @brief  Gets the current Page.
         * @return Current Page.
        */
        Page getCurrentPage() const;

        /**
         * @brief  Appends a Page at the end of the document.
         * @return Newly created Page.
        */
        Page addPage();

        /**
         * @brief  Adds a Page before another one.
         * @param  page Page that should follow.
         * @return Newly created Page.
        */
        Page insertPageBefore(const Page& page);

        /**
         * @brief Adds a page label.
         * @param style Style to use.
         * @param pageNumber The index of the first page that applies this labeling range.
         * @param firstPage The first page number to use.
        */
        void addPageLabel(enums::PageNumberStyle style = enums::PageNumberStyle::DECIMAL, unsigned int pageNumber = 0U, unsigned int firstPage = 1U);

        /**
         * @brief Adds a page label with a prefix.
         * @param prefix Prefix to add before labels.
         * @param style Style to use.
         * @param pageNumber The index of the first page that applies this labeling range.
         * @param firstPage The first page number to use.
        */
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

        /**
         * @brief  Gets a Font from a name and an encoding name.
         * @param  fontName The font name.
         * @param  encodingName Encoding name.
         * @return New Font object.
        */
        Font getFont(const std::string& fontName, const std::string& encodingName);

        /**
         * @brief  Loads a Type1 font from an external file and registers it in the document.
         * @note   Unlike ::loadType1FontFromFile(const std::string&, const std::string&), the glyph data of font file won't be embedded to the PDF file.
         * @param  AFMFileName Path of the AFM file to use.
         * @return Name of the loaded font.
        */
        std::string loadType1FontFromFile(const std::string& AFMFileName);

        /**
         * @brief  Loads a Type1 font from an external file and registers it in the document.
         * @note   Unlike ::loadType1FontFromFile(const std::string&), the glyph data of font file will be embedded to the PDF file.
         * @param  AFMFileName Path of the AFM file to use.
         * @param  dataFileName Path of a PFA/PFB file.
         * @return Name of the loaded font.
        */
        std::string loadType1FontFromFile(const std::string& AFMFileName, const std::string& dataFileName);

        /**
         * @brief  Loads a TrueType font from an external file and registers it in the document.
         * @param  fileName Path of a TrueType font file (`.ttf`).
         * @param  embedding If set to `true`, the glyph data of the font is embedded, otherwise only the matrix data is included.
         * @return Name of the loaded font.
        */
        std::string loadTrueTypeFontFromFile(const std::string& fileName, bool embedding);

        /**
         * @brief  Loads a TrueType font from an TrueType collection file and registers it in the document.
         * @param  fileName Path of a TrueType font collection file (`.ttc`).
         * @param  index Index of the font to be loaded.
         * @param  embedding If set to `true`, the glyph data of the font is embedded, otherwise only the matrix data is included.
         * @return Name of the loaded font.
        */
        std::string loadTrueTypeFontFromFile(const std::string& fileName, unsigned int index, bool embedding);

        /**
         * @brief Loads Japanese fonts.
         * @throw excepts::MemoryAllocationFailedException if not enough memory is available.
        */
        void useJPFonts();

        /**
         * @brief Loads Korean fonts.
         * @throw excepts::MemoryAllocationFailedException if not enough memory is available.
        */
        void useKRFonts();

        /**
         * @brief Loads simplified Chinese fonts.
         * @throw excepts::MemoryAllocationFailedException if not enough memory is available.
        */
        void useCNSFonts();

        /**
         * @brief Loads traditional Chinese fonts.
         * @throw excepts::MemoryAllocationFailedException if not enough memory is available.
        */
        void useCNTFonts();

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
         * @brief  Gets the Encoder of an encoding.
         * @param  encodingName Encoding name to use.
         * @return Corresponding Encoder.
        */
        Encoder getEncoder(const std::string& encodingName);

        /**
         * @brief  Gets the current Encoder.
         * @return Current Encoder.
        */
        Encoder getCurrentEncoder() const;

        /**
         * @brief Sets the current Encoder for the document.
         * @param encoding Encoding to use.
        */
        void setCurrentEncoder(enums::SingleByteEncoding encoding);

        /**
         * @brief Sets the current Encoder for the document.
         * @param encoding Encoding to use.
        */
        void setCurrentEncoder(enums::MultiByteEncoding encoding);

        /**
         * @brief Sets the current Encoder for the document.
         * @param encodingName Encoding name to use.
        */
        void setCurrentEncoder(const std::string& encodingName);

        /**
         * @brief Enables Japanese encodings.
         * @note  This has no effect if already loaded.
        */
        void useJPEncodings();

        /**
         * @brief Enables Korean encodings.
         * @note  This has no effect if already loaded.
        */
        void useKREncodings();

        /**
         * @brief Enables simplified Chinese encodings.
         * @note  This has no effect if already loaded.
        */
        void useCNSEncodings();

        /**
         * @brief Enables traditional Chinese encodings.
         * @note  This has no effect if already loaded.
        */
        void useCNTEncodings();

        /**
         * @brief   Enables UTF-8 encodings.
         * @details After this function call, it is possible to include UTF-8 encoded Unicode text
         *          (up to 3-byte UTF-8 sequences only) and use the UTF-8 Unicode encoding with TrueType fonts.
         * @note    This has no effect if already loaded.
        */
        void useUTFEncodings();

        /**
         * @brief  Checks whether auto encoding import is enabled.
         * @note   Note that this is set to `false` by default.
         * @return `true` if auto encoding import is enabled, `false` otherwise.
        */
        bool isAutoEncodingImportsEnabled() const;

        /**
         * @brief Enables auto encoding imports.
         * @note  After this function call, ::getEncoder(enums::MultiByteEncoding) will
         *        automatically import the encoding if not already loaded.
        */
        void enableAutoEncodingImports();

        /**
         * @brief Disables auto encoding imports.
         * @note  After this function call, ::getEncoder(enums::MultiByteEncoding) will
         *        no longer import the encoding if not already loaded.
        */
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
         *         Only enums::ColorSpace::DEVICE_GRAY, enums::ColorSpace::DEVICE_RGB and
         *         enums::ColorSpace::DEVICE_CMYK are allowed.
         * @return New Image object.
        */
        Image loadRawImageFromFile(
            const std::string& fileName, unsigned int width,
            unsigned int height, enums::ColorSpace colorSpace
        );

        /**
         * @brief  Loads a raw image from memory.
         * @param  bytes Vector of bytes encoding the image.
         * @param  width The width of the image.
         * @param  height The height of the image.
         * @param  colorSpace The color space to use.
         *         Only enums::ColorSpace::DEVICE_GRAY, enums::ColorSpace::DEVICE_RGB and
         *         enums::ColorSpace::DEVICE_CMYK are allowed.
         * @param  bitsPerComponent Number of bits per component (`1`, `2`, `4` or `8`).
         * @return New Image object.
         * @throw  excepts::InvalidBitsPerComponentException if the number of bits per component is invalid.
        */
        Image loadRawImageFromMemory(
            const std::vector<unsigned char>& bytes, unsigned int width,
            unsigned int height, enums::ColorSpace colorSpace,
            unsigned int bitsPerComponent
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

        /**
         * @brief Sets a document metadata regular attribute.
         * @param parameter Parameter to set.
         * @param value String value to use.
        */
        void setAttribute(enums::StringAttribute parameter, const std::string& value);

        /**
         * @brief Sets a document metadata datetime attribute.
         * @param parameter Parameter to set.
         * @param value The datetime to use.
        */
        void setAttribute(enums::DateTimeAttribute parameter, const DateTime& value);

        /**
         * @brief  Gets a document metadata regular attribute, if any.
         * @param  parameter Parameter to get the value from.
         * @return The string value of the attribute, or empty if not set.
        */
        std::optional<std::string> getInfoAttribute(enums::StringAttribute parameter);

        /**
         * @brief  Gets a document metadata datetime attribute, if any.
         * @param  parameter Parameter to get the value from.
         * @return The string value of the attribute, or empty if not set.
        */
        std::optional<std::string> getInfoAttributeAsString(enums::DateTimeAttribute parameter);

        /**
         * @brief  Gets a document metadata datetime attribute, if any.
         * @param  parameter Parameter to get the value from.
         * @return The DateTime of the attribute, or empty if not set.
        */
        std::optional<DateTime> getInfoAttribute(enums::DateTimeAttribute parameter);

        /**
         * @brief Sets the owner password for a pdf document (with no user password).
         * @param ownerPassword Owner password (cannot be empty).
         * @throw excepts::InvalidPasswordException if `ownerPassword` is empty.
        */
        void setPassword(const std::string& ownerPassword);

        /**
         * @brief Sets the owner and user passwords for a pdf document.
         * @param ownerPassword Owner password (cannot be empty).
         * @param userPassword  User password (can be empty, but cannot be equal to `ownerPassword`).
         * @throw excepts::InvalidPasswordException if `ownerPassword` is empty or `ownerPassword == userPassword`.
        */
        void setPassword(const std::string& ownerPassword, const std::string& userPassword);

        /**
         * @brief   Sets the user permissions for the document.
         * @param   permissions The permissions to use.
         * @warning A ::setPassword function must be called before calling this function.
         * @throw   excepts::EncryptionNotSetException if no password has been set.
        */
        void setPermissions(const Permissions& permissions);

        /**
         * @brief   Sets the R2 encryption mode.
         * @warning A ::setPassword function must be called before calling this function.
         * @throw   excepts::EncryptionNotSetException if no password has been set.
        */
        void setR2EncryptMode();

        /**
         * @brief   Sets the R3 encryption mode.
         * @param   keyLength Key length to use (between `5` and `16` included).
         * @note    As a side effect, this ups the version of PDF to `1.4`.
         * @warning A ::setPassword function must be called before calling this function.
         * @throw   excepts::EncryptionNotSetException if no password has been set.
         * @throw   excepts::InvalidR3EncryptionKeyLengthException if key is not between `5` and `16` included.
        */
        void setR3EncryptMode(unsigned int keyLength = 16U);

        /**
         * @brief Sets the document compression.
         * @param mode Compression mode to use.
        */
        void setCompressionMode(const CompressionMode& mode);

        /**
         * @brief Closes the current document, which will now point to a new document.
         * @param newDoc New pdf document to use.
        */
        void operator=(const Document& newDoc);

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

#endif // __HARUPP_DOCUMENT_HPP__
