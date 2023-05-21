#ifndef __HARUPP_EXCEPTION_HPP__
#define __HARUPP_EXCEPTION_HPP__
#include "exception"
#include "string"

/// Represents the Haru++ exception namespace.
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
         * @param errorName Error class name.
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
             * @param errorName Error class name.
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
             * @param errorName Error class name.
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
             * @param errorName Error class name.
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
             * @param errorName Error class name.
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
             * @param errorName Error class name.
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
             * @param errorName Error class name.
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
             * @param errorName Error class name.
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
             * @param errorName Error class name.
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
             * @param errorName Error class name.
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
             * @param errorName Error class name.
             * @param errorMessage Error message.
             * @param errorCode Error code.
             * @param detailCode Detail code.
            */
            ImageException(
                const char* className, const char* errorMessage,
                unsigned long errorCode, unsigned long detailCode = 0U
            ) noexcept;
    };

    // 0x1004
    class BinaryLengthTooLongException final: public Exception {
        public: BinaryLengthTooLongException() noexcept;
    };

    // 0x1007
    class TooManyIndirectObjectsException final: public Exception {
        public: TooManyIndirectObjectsException() noexcept;
    };

    // 0x100B
    class EncryptionNotSetException final: public DocumentException {
        public: EncryptionNotSetException() noexcept;
    };

    // 0x100E
    class FontDuplicateRegistrationException final: public FontException {
        public: FontDuplicateRegistrationException() noexcept;
    };

    // 0x100F
    class ExceededJWWCodeNumLimitException final: public FontException {
        public: ExceededJWWCodeNumLimitException(unsigned long detailCode) noexcept;
    };

    // 0x1011
    class InvalidPasswordException final: public DocumentException {
        public: InvalidPasswordException() noexcept;
    };

    // 0x1014
    class GStateLimitExceededException final: public GraphicsException {
        public: GStateLimitExceededException() noexcept;
    };

    // 0x1015
    class MemoryAllocationFailedException final: public Exception {
        public: MemoryAllocationFailedException() noexcept;
    };

    // 0x1016
    class FileIOException final: public FileException {
        public: FileIOException(unsigned long detailCode) noexcept;
    };

    // 0x1017
    class FileOpeningException final: public FileException {
        public: FileOpeningException(unsigned long detailCode) noexcept;
    };

    // 0x1019
    class FontAlreadyExistsException final: public FontException {
        public: FontAlreadyExistsException() noexcept;
    }; 

    // 0x101A
    class FontInvalidWidthsTableException final: public FontException {
        public: FontInvalidWidthsTableException() noexcept;
    };

    // 0x101B
    class InvalidAFMHeaderFileException final: public AFMException {
        public: InvalidAFMHeaderFileException() noexcept;
    };

    // 0x101E
    class NonMatchingBitsPerComponentException final: public ImageException {
        public: NonMatchingBitsPerComponentException() noexcept;
    };

    // 0x101F
    class InvalidAFMCharMatricsDataException final: public AFMException {
        public: InvalidAFMCharMatricsDataException() noexcept;
    };

    // 0x1020
    class InvalidColorSpaceException final: public ImageException {
        public: InvalidColorSpaceException() noexcept;
    };

    // 0x1022
    class InvalidDateTimeException final: public Exception {
        public: InvalidDateTimeException() noexcept;
    };

    // 0x1026
    class PageAlreadyExistsException final: public DocumentException {
        public: PageAlreadyExistsException() noexcept;
    };

    // 0x1028
    class InvalidEncoderTypeException final: public FontException {
        public: InvalidEncoderTypeException() noexcept;
    };

    // 0x102B
    class InvalidEncodingNameException final: public Exception {
        public: InvalidEncodingNameException() noexcept;
    };

    // 0x102C
    class InvalidR3EncryptionKeyLengthException final: public DocumentException {
        public: InvalidR3EncryptionKeyLengthException() noexcept;
    };

    // 0x102F
    class InvalidFontNameException final: public FontException {
        public: InvalidFontNameException() noexcept;
    };

    // 0x1030
    class InvalidImageException final: public ImageException {
        public: InvalidImageException() noexcept;
    };

    // 0x1032
    class InvalidAFMFileNDataException final: public AFMException {
        public: InvalidAFMFileNDataException() noexcept;
    };

    // 0x1035
    class InvalidImageOperationException final: public ImageException {
        public: InvalidImageOperationException() noexcept;
    };

    // 0x1039
    class InvalidParameterException final: public Exception {
        public: InvalidParameterException() noexcept;
    };

    // 0x103B
    class InvalidPNGImageException final: public ImageException {
        public: InvalidPNGImageException() noexcept;
    };

    // 0x103F
    class InvalidTTCFileException final: public TTCException {
        public: InvalidTTCFileException() noexcept;
    };

    // 0x1040
    class InvalidTTCIndexException final: public TTCException {
        public: InvalidTTCIndexException() noexcept;
    };

    // 0x1041
    class InvalidAFMWidthException final: public AFMException {
        public: InvalidAFMWidthException() noexcept;
    };

    // 0x1043
    class LibPNGException final: public ImageException {
        public: LibPNGException(unsigned long detailCode) noexcept;
    };

    // 0x104C
    class NoGStateException final: public GraphicsException {
        public: NoGStateException() noexcept;
    };

    // 0x104E
    class FontNotFoundException final: public FontException {
        public: FontNotFoundException() noexcept;
    };

    // 0x1050
    class InvalidFontSizeException final: public FontException {
        public: InvalidFontSizeException(unsigned long detailCode) noexcept;
    };

    // 0x1051
    class InvalidGModeException final: public GraphicsException {
        public: InvalidGModeException() noexcept;
    };

    // 0x1054
    class InvalidPageSizeException final: public PageException {
        public: InvalidPageSizeException() noexcept;
    };

    // 0x1056
    class PageValueOutOfRangeException final: public PageException {
        public: PageValueOutOfRangeException() noexcept;
    };

    // 0x1057
    class FloatValueOutOfRangeException final: public Exception {
        public:
            FloatValueOutOfRangeException() noexcept;
            FloatValueOutOfRangeException(const char* message, unsigned long detailCode) noexcept;
    };

    // 0x105B
    class StringOutOfRangeException final: public Exception {
        public: StringOutOfRangeException() noexcept;
    };

    // 0x105D
    class CannotEmbedTTFFontException final: public TTFException {
        public: CannotEmbedTTFFontException() noexcept;
    };

    // 0x105E
    class InvalidTTFCMapException final: public TTFException {
        public: InvalidTTFCMapException() noexcept;
    };

    // 0x105F
    class InvalidTTFFormatException final: public TTFException {
        public: InvalidTTFFormatException() noexcept;
    };

    // 0x1060
    class MissingTTFTableException final: public TTFException {
        public: MissingTTFTableException() noexcept;
    };

    // 0x1062
    class UnsupportedFunctionException final: public GraphicsException {
        public: UnsupportedFunctionException() noexcept;
    };

    // 0x1063
    class UnsupportedJPEGFormatException final: public ImageException {
        public: UnsupportedJPEGFormatException() noexcept;
    };

    // 0x1064
    class UnsupportedType1FontException final: public FileException {
        public: UnsupportedType1FontException() noexcept;
    };

    // 0x1066
    class ZLibException final: public Exception {
        public: ZLibException(unsigned long detailCode) noexcept;
    };

    // 0x1067
    class InvalidPageIndexException final: public DocumentException {
        public: InvalidPageIndexException() noexcept;
    };

    // 0x1068
    class EmptyURIException final: public PageException {
        public: EmptyURIException() noexcept;
    };

    // 0x1069
    class InvalidPageLayoutException final: public PageException {
        public: InvalidPageLayoutException() noexcept;
    };

    // 0x1070
    class InvalidPageModeException final: public PageException {
        public: InvalidPageModeException() noexcept;
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
        public: UndefinedException(unsigned long errorCode, unsigned long detailCode) noexcept;
    };
}

#endif // __HARUPP_EXCEPTION_HPP__
