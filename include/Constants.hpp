#pragma once


namespace pdf {
    enum class CompressionMode: unsigned int {
        NONE = 0x00,
        TEXT = 0x01,
        IMAGE = 0x02,
        METADATA = 0x04,

        TEXT_IMAGE = TEXT | IMAGE,
        TEXT_METADATA = TEXT | METADATA,
        IMAGE_METADATA = IMAGE | METADATA,

        ALL = 0x0F
    };

    enum class PageMode {
        NONE = 0,
        USE_OUTLINE,
        USE_THUMBS,
        FULL_SCREEN,
        EOF_MODE
    };

    enum class PageSize {
        LETTER = 0,
        LEGAL,
        A3,
        A4,
        A5,
        B4,
        B5,
        EXECUTIVE,
        US4x6,
        US4x8,
        US5x7,
        COMM10
    };

    enum class PageOrientation {
        PORTRAIT = 0,
        LANDSCAPE
    };

    enum class PageRotation: unsigned short {
        NONE = 0,
        ONE_QUARTER = 90,
        HALF = 180,
        THREE_QUARTERS = 270
    };

    enum class PdfDateTimeAttribute {
        CREATION_DATE = 0,
        MODIFICATION_DATE,
    };

    enum class PdfStringAttribute {
        AUTHOR = 2,
        CREATOR,
        PRODUCER,
        TITLE,
        SUBJECT,
        KEYWORDS,
        TRAPPED,
        GTS_PDFX
    };

    enum class R3EncryptKeyLength: unsigned int {
        FIVE = 5,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        ELEVEN,
        TWELVE,
        THIRTEEN,
        FOURTEEN,
        FIFTEEN,
        SIXTEEN
    };

    enum class UTCIndicator {
        NONE = ' ',
        PLUS = '+',
        MINUS = '-',
        Z = 'Z'
    };

    enum class TextAlignment {
        LEFT = 0,
        RIGHT,
        CENTER,
        JUSTIFY
    };

    enum Permissions {
        READ_ONLY = 0,
        PRINT = 4,
        EDIT_CONTENT = 8,
        COPY = 16,
        EDIT_ANNOTATIONS = 32,

        EDIT_ALL = EDIT_CONTENT | EDIT_ANNOTATIONS,
        ALL_PERMS = PRINT | EDIT_ALL | COPY
    };

    enum class PdfPageLayout {
        SINGLE_PAGE = 0,
        ONE_COLUMN,
        TWO_COLUMN_LEFT,
        TWO_COLUMN_RIGHT,
        EOF_LAYOUT = 6
    };

    enum class ImageColorSpaceDevice {
        GRAY = 0,
        RGB,
        CMYK
    };

    enum class BitsPerComponent: unsigned int {
        ONE = 1,
        TWO = 2,
        FOUR = 4,
        EIGHT = 8
    };

    enum class PageNumberStyle {
        DECIMAL = 0,
        UPPER_ROMAN,
        LOWER_ROMAN,
        UPPER_LETTERS,
        LOWER_LETTERS
    };

    class ByteEncoding {
    public:
        virtual ~ByteEncoding();
        virtual const char* toString() const = 0;
    };

    class SingleByteEncoding final: public ByteEncoding {
    public:
        enum Value {
            StandardEncoding = 0,
            MacRomanEncoding,
            WinAnsiEncoding,
            FontSpecific,
            ISO8859_2,
            ISO8859_3,
            ISO8859_4,
            ISO8859_5,
            ISO8859_6,
            ISO8859_7,
            ISO8859_8,
            ISO8859_9,
            ISO8859_10,
            ISO8859_11,
            ISO8859_13,
            ISO8859_14,
            ISO8859_15,
            ISO8859_16,
            CP1250,
            CP1251,
            CP1252,
            CP1253,
            CP1254,
            CP1255,
            CP1256,
            CP1257,
            CP1258,
            KOI8_R
        };

        constexpr SingleByteEncoding(Value value): value(value) {}
        constexpr operator Value() const {return value;}
        const char* toString() const final override;

    private:
        Value value;
    };

    class MultiByteEncoding final: public ByteEncoding {
        public:
        enum Value {
            GB_EUC_H = 0,
            GB_EUC_V,
            GBK_EUC_H,
            GBK_EUC_V,
            ETen_B5_H,
            ETen_B5_V,
            NINETYms_RKSJ_H,
            NINETYms_RKSJ_V,
            NINETYmsp_RKSJ_H,
            EUC_H,
            EUC_V,
            KSC_EUC_H,
            KSC_EUC_V,
            KSCms_UHC_H,
            KSCms_UHC_HW_H,
            KSCms_UHC_HW_V
        };

        constexpr MultiByteEncoding(Value value): value(value) {}
        constexpr operator Value() const {return value;}
        const char* toString() const final override;

    private:
        Value value;
    };

    enum class EncoderType {
        SINGLE_BYTE = 0,
        DOUBLE_BYTE,
        UNINITIALIZED,
        UNKNOWN
    };

    enum class ByteType {
        SINGLE = 0,
        LEAD,
        TRAIL,
        UNKNOWN
    };

    enum class WritingMode {
        HORIZONTAL = 0,
        VERTICAL,
        EOF_MODE
    };

    enum class BorderStyle {
        SOLID,
        DASHED,
        BEVELED,
        INSET,
        UNDERLINED
    };

    enum class AnnotationIcon {
        COMMENT = 0,
        KEY,
        NOTE,
        HELP,
        NEW_PARAGRAPH,
        PARAGRAPH,
        INSERT
    };

    enum class AnnotationHighlightMode {
        NONE = 0,
        INVERT_BOX,
        INVERT_BORDER,
        DOWN_APPEARANCE
    };

    enum class LineCap {
        BUTT_END = 0,
        ROUND_END,
        PROJECTING_SQUARE_END,
        LINECAP_EOF
    };

    enum class LineJoin {
        MITER_JOIN = 0,
        ROUND_JOIN,
        BEVEL_JOIN,
        LINEJOIN_EOF
    };

    enum class ColorSpace {
        DEVICE_GRAY = 0,
        DEVICE_RGB,
        DEVICE_CMYK,
        CAL_GRAY,
        CAL_RGB,
        LAB,
        ICC_BASED,
        SEPARATION,
        DEVICE_N,
        INDEXED,
        PATTERN,
        EOF_COLOR_SPACE
    };

    enum class TransitionStyle {
        WIPE_RIGHT = 0,
        WIPE_UP,
        WIPE_LEFT,
        WIPE_DOWN,
        BARN_DOORS_HORIZONTAL_OUT,
        BARN_DOORS_HORIZONTAL_IN,
        BARN_DOORS_VERTICAL_OUT,
        BARN_DOORS_VERTICAL_IN,
        BOX_OUT,
        BOX_IN,
        BLINDS_HORIZONTAL,
        BLINDS_VERTICAL,
        DISSOLVE,
        GLITTER_RIGHT,
        GLITTER_DOWN,
        GLITTER_TOP_LEFT_TO_BOTTOM_RIGHT,
        REPLACE
    };

    enum class DashModeNumberElements: unsigned int {
        ZERO = 0,
        ONE,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT
    };

    enum class TextRenderingMode {
        FILL = 0,
        STROKE,
        FILL_THEN_STROKE,
        INVISIBLE,
        FILL_CLIPPING,
        STROKE_CLIPPING,
        FILL_STROKE_CLIPPING,
        CLIPPING,
        EOF_MODE
    };
}
