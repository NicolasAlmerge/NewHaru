#ifndef __HARUPP_EXCEPTION_HPP__
#define __HARUPP_EXCEPTION_HPP__
#include "exception"
#include "string"

/**
 * @brief   Represents the Haru++ exception namespace.
 * @details The base class for exceptions thrown by this library is excepts::Exception.
*/
namespace pdf::excepts {

    /**
     * \class  Exception
     * @brief  Represents the base exception class.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class Exception: public std::exception {
        const char* className;
        const char* errorMessage;
        unsigned long errorCode;
        unsigned long detailCode;

    public:
        virtual ~Exception() noexcept = 0;

        /**
         * @brief Creates a new Exception with parameters.
         * @param className Error class name.
         * @param errorMessage Error message.
         * @param errorCode Error code.
         * @param detailCode Detail code.
        */
        Exception(
            const char* className, const char* errorMessage,
            unsigned long errorCode, unsigned long detailCode = 0U
        ) noexcept;

        /**
         * @brief  Returns the error message.
         * @return Error message.
        */
        virtual const char* what() const noexcept override final;

        /**
         * @brief  Returns the error code.
         * @return Error code.
        */
        virtual unsigned long getErrorCode() const noexcept final;

        /**
         * @brief  Returns the error detail code.
         * @return Error detail code.
        */
        virtual unsigned long getDetailCode() const noexcept final;

        /**
         * @brief   Returns whether a detail code has been set.
         * @details This is equivalent to `getDetailCode() != 0U`.
         * @return `true` if a detail code has been set, `false` otherwise.
        */
        virtual bool hasDetailCode() const noexcept final;

        /**
         * @brief   Returns the error name.
         * @details This is simply a string representation of the class name.
         * @return  Error name.
        */
        virtual const char* getName() const noexcept final;

        /**
         * @brief  Returns a string consisting of the error name and description.
         * @return Error full description.
        */
        virtual std::string getFullDescription() const noexcept final;
    };

    /**
     * \class  DocumentException
     * @brief  Represents exceptions linked with Document.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class DocumentException: public Exception {
        public:
            virtual ~DocumentException() noexcept = 0;

            /**
             * @brief Creates a new DocumentException with parameters.
             * @param className Error class name.
             * @param errorMessage Error message.
             * @param errorCode Error code.
             * @param detailCode Detail code.
            */
            DocumentException(
                const char* className, const char* errorMessage,
                unsigned long errorCode, unsigned long detailCode = 0U
            ) noexcept;
    };

    /**
     * \class  FileException
     * @brief  Represents exceptions linked with files.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class FileException: public Exception {
        public:
            virtual ~FileException() noexcept = 0;

            /**
             * @brief Creates a new FileException with parameters.
             * @param className Error class name.
             * @param errorMessage Error message.
             * @param errorCode Error code.
             * @param detailCode Detail code.
            */
            FileException(
                const char* className, const char* errorMessage,
                unsigned long errorCode, unsigned long detailCode = 0U
            ) noexcept;
    };

    /**
     * \class  AFMException
     * @brief  Represents exceptions linked with AFM files.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class AFMException: public FileException {
        public:
            virtual ~AFMException() noexcept = 0;

            /**
             * @brief Creates a new AFMException with parameters.
             * @param className Error class name.
             * @param errorMessage Error message.
             * @param errorCode Error code.
             * @param detailCode Detail code.
            */
            AFMException(
                const char* className, const char* errorMessage,
                unsigned long errorCode, unsigned long detailCode = 0U
            ) noexcept;
    };

    /**
     * \class  TTCException
     * @brief  Represents exceptions linked with TTC files.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class TTCException: public FileException {
        public:
            virtual ~TTCException() noexcept = 0;

            /**
             * @brief Creates a new TTCException with parameters.
             * @param className Error class name.
             * @param errorMessage Error message.
             * @param errorCode Error code.
             * @param detailCode Detail code.
            */
            TTCException(
                const char* className, const char* errorMessage,
                unsigned long errorCode, unsigned long detailCode = 0U
            ) noexcept;
    };

    /**
     * \class  TTFException
     * @brief  Represents exceptions linked with TTF files.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class TTFException: public FileException {
        public:
            virtual ~TTFException() noexcept = 0;

            /**
             * @brief Creates a new TTFException with parameters.
             * @param className Error class name.
             * @param errorMessage Error message.
             * @param errorCode Error code.
             * @param detailCode Detail code.
            */
            TTFException(
                const char* className, const char* errorMessage,
                unsigned long errorCode, unsigned long detailCode = 0U
            ) noexcept;
    };

    /**
     * \class  GraphicsException
     * @brief  Represents exceptions linked with graphics.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class GraphicsException: public Exception {
        public:
            virtual ~GraphicsException() noexcept = 0;

            /**
             * @brief Creates a new GraphicsException with parameters.
             * @param className Error class name.
             * @param errorMessage Error message.
             * @param errorCode Error code.
             * @param detailCode Detail code.
            */
            GraphicsException(
                const char* className, const char* errorMessage,
                unsigned long errorCode, unsigned long detailCode = 0U
            ) noexcept;
    };

    /**
     * \class  StreamException
     * @brief  Represents exceptions linked with ContentStream.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class StreamException: public Exception {
        public:
            virtual ~StreamException() noexcept = 0;

            /**
             * @brief Creates a new StreamException with parameters.
             * @param className Error class name.
             * @param errorMessage Error message.
             * @param errorCode Error code.
             * @param detailCode Detail code.
            */
            StreamException(
                const char* className, const char* errorMessage,
                unsigned long errorCode, unsigned long detailCode = 0U
            ) noexcept;
    };

    /**
     * \class  FontException
     * @brief  Represents exceptions linked with Font.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class FontException: public StreamException {
        public:
            virtual ~FontException() noexcept = 0;

            /**
             * @brief Creates a new FontException with parameters.
             * @param className Error class name.
             * @param errorMessage Error message.
             * @param errorCode Error code.
             * @param detailCode Detail code.
            */
            FontException(
                const char* className, const char* errorMessage,
                unsigned long errorCode, unsigned long detailCode = 0U
            ) noexcept;
    };

    /**
     * \class  PageException
     * @brief  Represents exceptions linked with Page.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class PageException: public StreamException {
        public:
            virtual ~PageException() noexcept = 0;

            /**
             * @brief Creates a new PageException with parameters.
             * @param className Error class name.
             * @param errorMessage Error message.
             * @param errorCode Error code.
             * @param detailCode Detail code.
            */
            PageException(
                const char* className, const char* errorMessage,
                unsigned long errorCode, unsigned long detailCode = 0U
            ) noexcept;
    };

    /**
     * \class  ImageException
     * @brief  Represents exceptions linked with Image.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class ImageException: public StreamException {
        public:
            virtual ~ImageException() noexcept = 0;

            /**
             * @brief Creates a new ImageException with parameters.
             * @param className Error class name.
             * @param errorMessage Error message.
             * @param errorCode Error code.
             * @param detailCode Detail code.
            */
            ImageException(
                const char* className, const char* errorMessage,
                unsigned long errorCode, unsigned long detailCode = 0U
            ) noexcept;
    };

    /**
     * \class  OutOfRangeException
     * @brief  Represents exceptions linked with out of range values.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class OutOfRangeException: public Exception {
        public:
            virtual ~OutOfRangeException() noexcept = 0;

            /**
             * @brief Creates a new OutOfRangeException with parameters.
             * @param className Error class name.
             * @param errorMessage Error message.
             * @param errorCode Error code.
             * @param detailCode Detail code.
            */
            OutOfRangeException(
                const char* className, const char* errorMessage,
                unsigned long errorCode, unsigned long detailCode = 0U
            ) noexcept;
    };

    /**
     * \class  BinaryLengthTooLongException
     * @brief  An exception raised when a binary length exceeds consts::MAX_STRING_LEN.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class BinaryLengthTooLongException final: public OutOfRangeException {
        public:
            /**
             * @brief   Creates a new BinaryLengthTooLongException.
             * @details The error code will be set to `0x1004`.
            */
            BinaryLengthTooLongException() noexcept;
    };

    /**
     * \class  InvalidBitsPerComponentException
     * @brief  An exception raised when using an invalid value for the number of bits per component when calling Document::loadRawImageFromMemory.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class InvalidBitsPerComponentException final: public ImageException {
        public:
            /**
             * @brief   Creates a new InvalidBitsPerComponentException.
             * @details The error code will be set to `0x1006`.
            */
            InvalidBitsPerComponentException() noexcept;
    };

    /**
     * \class  TooManyIndirectObjectsException
     * @brief  An exception raised when too many indirect objects in a Document were created.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class TooManyIndirectObjectsException final: public OutOfRangeException {
        public:
            /**
             * @brief   Creates a new TooManyIndirectObjectsException.
             * @details The error code will be set to `0x1007`.
            */
            TooManyIndirectObjectsException() noexcept;
    };

    /**
     * \class  EncryptionNotSetException
     * @brief  An exception raised when calling Document::setR2EncryptMode, Document::setR3EncryptMode or Document::setPermission
     *         has been called before calling Document::setPassword.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class EncryptionNotSetException final: public DocumentException {
        public:
            /**
             * @brief   Creates a new EncryptionNotSetException.
             * @details The error code will be set to `0x100B`.
            */
            EncryptionNotSetException() noexcept;
    };

    /**
     * \class  FontDuplicateRegistrationException
     * @brief  An exception raised when trying to register a Font that has already been registered.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class FontDuplicateRegistrationException final: public FontException {
        public:
            /**
             * @brief   Creates a new FontDuplicateRegistrationException.
             * @details The error code will be set to `0x100E`.
            */
            FontDuplicateRegistrationException() noexcept;
    };

    /**
     * \class  ExceededJWWCodeNumLimitException
     * @brief  An exception raised when failure to register a character to the Japanese word wrap characters list occurred.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class ExceededJWWCodeNumLimitException final: public FontException {
        public:
            /**
             * @brief   Creates a new ExceededJWWCodeNumLimitException.
             * @details The error code will be set to `0x100F`.
            */
            ExceededJWWCodeNumLimitException(unsigned long detailCode) noexcept;
    };

    /**
     * \class  InvalidPasswordException
     * @brief  An exception when tried to set a Document owner password to an empty string, or owner and user password are the same.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class InvalidPasswordException final: public DocumentException {
        public:
            /**
             * @brief   Creates a new InvalidPasswordException.
             * @details The error code will be set to `0x1011`.
            */
            InvalidPasswordException() noexcept;
    };

    /**
     * \class  GStateLimitExceededException
     * @brief  An exception raised when the G stack depth exceeds consts::MAX_GSTATE.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class GStateLimitExceededException final: public GraphicsException {
        public:
            /**
             * @brief   Creates a new GStateLimitExceededException.
             * @details The error code will be set to `0x1014`.
            */
            GStateLimitExceededException() noexcept;
    };

    /**
     * \class  MemoryAllocationFailedException
     * @brief  An exception raised when a memory allocation failure occurred.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class MemoryAllocationFailedException final: public Exception {
        public:
            /**
             * @brief   Creates a new MemoryAllocationFailedException.
             * @details The error code will be set to `0x1015`.
            */
            MemoryAllocationFailedException() noexcept;
    };

    /**
     * \class  FileIOException
     * @brief  An exception raised when a file I/O error occurred.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class FileIOException final: public FileException {
        public:
            /**
             * @brief   Creates a new FileIOException.
             * @details The error code will be set to `0x1016`.
            */
            FileIOException(unsigned long detailCode) noexcept;
    };

    /**
     * \class  FileOpeningException
     * @brief  An exception raised when a file opening error occurred.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class FileOpeningException final: public FileException {
        public:
            /**
             * @brief   Creates a new FileOpeningException.
             * @details The error code will be set to `0x1017`.
            */
            FileOpeningException(unsigned long detailCode) noexcept;
    };

    /**
     * \class  FontAlreadyExistsException
     * @brief  An exception raised when trying to load a Font that has been registered.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class FontAlreadyExistsException final: public FontException {
        public:
            /**
             * @brief   Creates a new FontAlreadyExistsException.
             * @details The error code will be set to `0x1019`.
            */
            FontAlreadyExistsException() noexcept;
    }; 

    /**
     * \class  FontInvalidWidthsTableException
     * @brief  An exception raised when a font file format is invalid.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class FontInvalidWidthsTableException final: public FontException {
        public:
            /**
             * @brief   Creates a new FontInvalidWidthsTableException.
             * @details The error code will be set to `0x101A`.
            */
            FontInvalidWidthsTableException() noexcept;
    };

    /**
     * \class  InvalidAFMHeaderFileException
     * @brief  An exception raised when failure to recognize the header of an AFM file occurred.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class InvalidAFMHeaderFileException final: public AFMException {
        public:
            /**
             * @brief   Creates a new InvalidAFMHeaderFileException.
             * @details The error code will be set to `0x101B`.
            */
            InvalidAFMHeaderFileException() noexcept;
    };

    /**
     * \class  NonMatchingBitsPerComponentException
     * @brief  An exception raised when the number of bits per component of a pdf::Image which was set as mask image is invalid.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class NonMatchingBitsPerComponentException final: public ImageException {
        public:
            /**
             * @brief   Creates a new NonMatchingBitsPerComponentException.
             * @details The error code will be set to `0x101E`.
            */
            NonMatchingBitsPerComponentException() noexcept;
    };

    /**
     * \class  InvalidAFMCharMatricsDataException
     * @brief  An exception raised when failure to recognize the char matrics data of an AFM file occurred.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class InvalidAFMCharMatricsDataException final: public AFMException {
        public:
            /**
             * @brief   Creates a new InvalidAFMCharMatricsDataException.
             * @details The error code will be set to `0x101F`.
            */
            InvalidAFMCharMatricsDataException() noexcept;
    };

    /**
     * \class  InvalidColorSpaceException
     * @brief  An exception raised when an invalid ColorSpace of a pdf::Image was returned or set.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class InvalidColorSpaceException final: public ImageException {
        public:
            /**
             * @brief   Creates a new InvalidColorSpaceException.
             * @details The error code will be set to `0x1020`.
            */
            InvalidColorSpaceException() noexcept;
    };

    /**
     * \class  InvalidDateTimeException
     * @brief  An exception raised when an invalid DateTime has been set.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class InvalidDateTimeException final: public Exception {
        public:
            /**
             * @brief   Creates a new InvalidDateTimeException.
             * @details The error code will be set to `0x1022`.
            */
            InvalidDateTimeException() noexcept;
    };

    /**
     * \class  PageAlreadyExistsException
     * @brief  An exception raised when Document::setPageConfiguration was called and the document already contained pages.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class PageAlreadyExistsException final: public DocumentException {
        public:
            /**
             * @brief   Creates a new PageAlreadyExistsException.
             * @details The error code will be set to `0x1026`.
            */
            PageAlreadyExistsException() noexcept;
    };

    /**
     * \class  InvalidEncoderTypeException
     * @brief  An exception raised when the combination between Font and Encoder is wrong.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class InvalidEncoderTypeException final: public FontException {
        public:
            /**
             * @brief   Creates a new InvalidEncoderTypeException.
             * @details The error code will be set to `0x1028`.
            */
            InvalidEncoderTypeException() noexcept;
    };

    /**
     * \class  InvalidEncodingNameException
     * @brief  An exception raised when an invalid encoding name was given.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class InvalidEncodingNameException final: public Exception {
        public:
            /**
             * @brief   Creates a new InvalidEncodingNameException.
             * @details The error code will be set to `0x102B`.
            */
            InvalidEncodingNameException() noexcept;
    };

    /**
     * \class  InvalidR3EncryptionKeyLengthException
     * @brief  An exception raised when calling Document::setR3EncryptMode with an invalid key length.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class InvalidR3EncryptionKeyLengthException final: public DocumentException {
        public:
            /**
             * @brief   Creates a new InvalidR3EncryptionKeyLengthException.
             * @details The error code will be set to `0x102C`.
            */
            InvalidR3EncryptionKeyLengthException() noexcept;
    };

    /**
     * \class  InvalidFontNameException
     * @brief  An exception raised when a Font with the specified name was not found.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class InvalidFontNameException final: public FontException {
        public:
            /**
             * @brief   Creates a new InvalidFontNameException.
             * @details The error code will be set to `0x102F`.
            */
            InvalidFontNameException() noexcept;
    };

    /**
     * \class  InvalidImageException
     * @brief  An exception raised when an image format is unsupported.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class InvalidImageException final: public ImageException {
        public:
            /**
             * @brief   Creates a new InvalidImageException.
             * @details The error code will be set to `0x1030`.
            */
            InvalidImageException() noexcept;
    };

    /**
     * \class  InvalidAFMFileNDataException
     * @brief  An exception raised when failure to read a postscript name from an AFM file occurred.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class InvalidAFMFileNDataException final: public AFMException {
        public:
            /**
             * @brief   Creates a new InvalidAFMFileNDataException.
             * @details The error code will be set to `0x1032`.
            */
            InvalidAFMFileNDataException() noexcept;
    };

    /**
     * \class  InvalidImageOperationException
     * @brief  An exception raised when Image::setColorMask was invoked against the image object which was set a mask image.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class InvalidImageOperationException final: public ImageException {
        public:
            /**
             * @brief   Creates a new InvalidImageOperationException.
             * @details The error code will be set to `0x1035`.
            */
            InvalidImageOperationException() noexcept;
    };

    /**
     * \class  InvalidParameterException
     * @brief  An exception raised when an invalid parameter has been set.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class InvalidParameterException final: public OutOfRangeException {
        public:
            /**
             * @brief   Creates a new InvalidParameterException.
             * @details The error code will be set to `0x1039`.
            */
            InvalidParameterException() noexcept;
    };

    /**
     * \class  InvalidPNGImageException
     * @brief  An exception raised when an invalid PNG image format has been used.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class InvalidPNGImageException final: public ImageException {
        public:
            /**
             * @brief   Creates a new InvalidPNGImageException.
             * @details The error code will be set to `0x103B`.
            */
            InvalidPNGImageException() noexcept;
    };

    /**
     * \class  InvalidTTCFileException
     * @brief  An exception raised when an invalid .TTC file format was used.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class InvalidTTCFileException final: public TTCException {
        public:
            /**
             * @brief   Creates a new InvalidTTCFileException.
             * @details The error code will be set to `0x103F`.
            */
            InvalidTTCFileException() noexcept;
    };

    /**
     * \class  InvalidTTCIndexException
     * @brief  An exception raised when the index parameter exceeds the number of included fonts.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class InvalidTTCIndexException final: public TTCException {
        public:
            /**
             * @brief   Creates a new InvalidTTCIndexException.
             * @details The error code will be set to `0x1040`.
            */
            InvalidTTCIndexException() noexcept;
    };

    /**
     * \class  InvalidAFMWidthException
     * @brief  An exception raised when failure to read a width data from an AFM file.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class InvalidAFMWidthException final: public AFMException {
        public:
            /**
             * @brief   Creates a new InvalidAFMWidthException.
             * @details The error code will be set to `0x1041`.
            */
            InvalidAFMWidthException() noexcept;
    };

    /**
     * \class  LibPNGException
     * @brief  An exception raised when an error from the PNGLib library occurred while loading an image.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class LibPNGException final: public ImageException {
        public:
            /**
             * @brief   Creates a new LibPNGException.
             * @details The error code will be set to `0x1043`.
            */
            LibPNGException(unsigned long detailCode) noexcept;
    };

    /**
     * \class  NoGStateException
     * @brief  An exception raised when there are no graphics states to be restored.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class NoGStateException final: public GraphicsException {
        public:
            /**
             * @brief   Creates a new NoGStateException.
             * @details The error code will be set to `0x104C`.
            */
            NoGStateException() noexcept;
    };

    /**
     * \class  FontNotFoundException
     * @brief  An exception raised when the current Font has not been set.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class FontNotFoundException final: public FontException {
        public:
            /**
             * @brief   Creates a new FontNotFoundException.
             * @details The error code will be set to `0x104E`.
            */
            FontNotFoundException() noexcept;
    };

    /**
     * \class  InvalidFontSizeException
     * @brief  An exception raised when an invalid font size has been set.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class InvalidFontSizeException final: public FontException {
        public:
            /**
             * @brief   Creates a new InvalidFontSizeException.
             * @details The error code will be set to `0x1050`.
            */
            InvalidFontSizeException(unsigned long detailCode) noexcept;
    };

    /**
     * \class  InvalidGModeException
     * @brief  An exception raised when an invalid graphics mode was used.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class InvalidGModeException final: public GraphicsException {
        public:
            /**
             * @brief   Creates a new InvalidGModeException.
             * @details The error code will be set to `0x1051`.
            */
            InvalidGModeException() noexcept;
    };

    /**
     * \class  InvalidPageSizeException
     * @brief  An exception raised when an invalid page size was set.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class InvalidPageSizeException final: public PageException {
        public:
            /**
             * @brief   Creates a new InvalidPageSizeException.
             * @details The error code will be set to `0x1054`.
            */
            InvalidPageSizeException() noexcept;
    };

    /**
     * \class  PageValueOutOfRangeException
     * @brief  An exception raised when the specified value was out of range.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class PageValueOutOfRangeException final: public PageException {
        public:
            /**
             * @brief   Creates a new PageValueOutOfRangeException.
             * @details The error code will be set to `0x1056`.
            */
            PageValueOutOfRangeException() noexcept;
    };

    /**
     * \class  FloatValueOutOfRangeException
     * @brief  An exception raised when the specified float value was out of range.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class FloatValueOutOfRangeException final: public OutOfRangeException {
        public:
            /**
             * @brief   Creates a new FloatValueOutOfRangeException.
             * @details The error code will be set to `0x1057`.
            */
            FloatValueOutOfRangeException() noexcept;

            /**
             * @brief   Creates a new FloatValueOutOfRangeException with parameters.
             * @param   message Error message to use.
             * @param   detailCode Detail code to use.
             * @details The error code will be set to `0x1057`.
            */
            FloatValueOutOfRangeException(const char* message, unsigned long detailCode) noexcept;
    };

    /**
     * \class  StringOutOfRangeException
     * @brief  An exception raised when the length of a text is too long.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class StringOutOfRangeException final: public OutOfRangeException {
        public:
            /**
             * @brief   Creates a new StringOutOfRangeException.
             * @details The error code will be set to `0x105B`.
            */
            StringOutOfRangeException() noexcept;
    };

    /**
     * \class  CannotEmbedTTFFontException
     * @brief  An exception raised when a TTF Font cannot be embedded due to license restrictions.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class CannotEmbedTTFFontException final: public TTFException {
        public:
            /**
             * @brief   Creates a new CannotEmbedTTFFontException.
             * @details The error code will be set to `0x105D`.
            */
            CannotEmbedTTFFontException() noexcept;
    };

    /**
     * \class  InvalidTTFCMapException
     * @brief  An exception raised when an unsupported TTF format where the unicode cmap could not be found was used.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class InvalidTTFCMapException final: public TTFException {
        public:
            /**
             * @brief   Creates a new InvalidTTFCMapException.
             * @details The error code will be set to `0x105E`.
            */
            InvalidTTFCMapException() noexcept;
    };

    /**
     * \class  InvalidTTFFormatException
     * @brief  An exception raised when an unsupported TTF format was used.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class InvalidTTFFormatException final: public TTFException {
        public:
            /**
             * @brief   Creates a new InvalidTTFFormatException.
             * @details The error code will be set to `0x105F`.
            */
            InvalidTTFFormatException() noexcept;
    };

    /**
     * \class  MissingTTFTableException
     * @brief  An exception raised when an unsupported TTF format where a necessary table could not be found was used.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class MissingTTFTableException final: public TTFException {
        public:
            /**
             * @brief   Creates a new MissingTTFTableException.
             * @details The error code will be set to `0x1060`.
            */
            MissingTTFTableException() noexcept;
    };

    /**
     * \class  UnsupportedFunctionException
     * @brief  An exception raised when the library could not be configured to use PNGLib.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class UnsupportedFunctionException final: public GraphicsException {
        public:
            /**
             * @brief   Creates a new UnsupportedFunctionException.
             * @details The error code will be set to `0x1062`.
            */
            UnsupportedFunctionException() noexcept;
    };

    /**
     * \class  UnsupportedJPEGFormatException
     * @brief  An exception raised when an unsupported JPEG format occurred.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class UnsupportedJPEGFormatException final: public ImageException {
        public:
            /**
             * @brief   Creates a new UnsupportedJPEGFormatException.
             * @details The error code will be set to `0x1063`.
            */
            UnsupportedJPEGFormatException() noexcept;
    };

    /**
     * \class  UnsupportedType1FontException
     * @brief  An exception raised when failure to parse a .PFB file occurred.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class UnsupportedType1FontException final: public FileException {
        public:
            /**
             * @brief   Creates a new UnsupportedType1FontException.
             * @details The error code will be set to `0x1064`.
            */
            UnsupportedType1FontException() noexcept;
    };

    /**
     * \class  ZLibException
     * @brief  An exception raised when an error with the ZLib library occurred.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class ZLibException final: public Exception {
        public:
            /**
             * @brief   Creates a new ZLibException with a detail code parameter.
             * @details The error code will be set to `0x1066`.
             * @param   detailCode Detail code.
            */
            ZLibException(unsigned long detailCode) noexcept;
    };

    /**
     * \class  InvalidPageIndexException
     * @brief  An exception raised when an invalid page index was passed.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class InvalidPageIndexException final: public DocumentException {
        public:
            /**
             * @brief   Creates a new InvalidPageIndexException.
             * @details The error code will be set to `0x1067`.
            */
            InvalidPageIndexException() noexcept;
    };

    /**
     * \class  EmptyURIException
     * @brief  An exception raised when an invalid URI was set.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class EmptyURIException final: public PageException {
        public:
            /**
             * @brief   Creates a new EmptyURIException.
             * @details The error code will be set to `0x1068`.
            */
            EmptyURIException() noexcept;
    };

    /**
     * \class  InvalidPageLayoutException
     * @brief  An exception raised when an invalid page layout was returned.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class InvalidPageLayoutException final: public PageException {
        public:
            /**
             * @brief   Creates a new InvalidPageLayoutException.
             * @details The error code will be set to `0x1069`.
            */
            InvalidPageLayoutException() noexcept;
    };

    /**
     * \class  InvalidPageModeException
     * @brief  An exception raised when an invalid page mode was returned.
     * @file   Exception.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class InvalidPageModeException final: public PageException {
        public:
            /**
             * @brief   Creates a new InvalidPageModeException.
             * @details The error code will be set to `0x1070`.
            */
            InvalidPageModeException() noexcept;
    };

    /**
     * \class   UndefinedException
     * @brief   Represents exceptions that should not be raised.
     * @details This will only be raised by LibHaru internal errors.
     * @file    Exception.hpp
     * @author  Nicolas Almerge
     * @date    2023-05-16
    */
    class UndefinedException final: public Exception {
        public:
            /**
             * @brief Creates a new UndefinedException with parameters.
             * @param errorCode Error code.
             * @param detailCode Detail code.
            */
            UndefinedException(unsigned long errorCode, unsigned long detailCode) noexcept;
    };
}

#endif // __HARUPP_EXCEPTION_HPP__
