#ifndef __HARUPP_CONSTANTS_HPP__
#define __HARUPP_CONSTANTS_HPP__


/// Represents the Haru++ namespace.
namespace pdf {

    /// Represents a compression mode.
    enum class CompressionMode: unsigned int {
        /// No compression.
        NONE = 0x00,
        /// Only compress text.
        TEXT = 0x01,
        /// Only compress images.
        IMAGE = 0x02,
        /// Only compress metadata.
        METADATA = 0x04,
        /// Compress text and images.
        TEXT_IMAGE = TEXT | IMAGE,
        /// Compress text and metadata.
        TEXT_METADATA = TEXT | METADATA,
        /// Compress images and metadata.
        IMAGE_METADATA = IMAGE | METADATA,
        /// Compress everything.
        ALL = 0x0F
    };

    /// Represents a page mode.
    enum class PageMode {
        /// No mode.
        NONE = 0,
        /// Outline mode.
        USE_OUTLINE,
        /// Thumbs mode.
        USE_THUMBS,
        /// Full screen mode.
        FULL_SCREEN,
        /// Mode could not be determined.
        EOF_MODE
    };

    /// Represents a page size.
    enum class PageSize {
        /// Letter size.
        LETTER = 0,
        /// Legal document size.
        LEGAL,
        /// A3 size.
        A3,
        /// A4 size.
        A4,
        /// A5 size.
        A5,
        /// B4 size.
        B4,
        /// B5 size.
        B5,
        /// Executive document size.
        EXECUTIVE,
        /// US 4*6 document size.
        US4x6,
        /// US 4*8 document size.
        US4x8,
        /// US 5*7 document size.
        US5x7,
        /// COMM 10 size.
        COMM10
    };

    /// Represents a page orientation.
    enum class PageOrientation {
        /// Portrait.
        PORTRAIT = 0,
        /// Landscape.
        LANDSCAPE
    };

    /// Represents a page rotation.
    enum class PageRotation: unsigned short {
        /// No rotation.
        NONE = 0,
        /// 90° rotation.
        ONE_QUARTER = 90,
        /// 180° rotation.
        HALF = 180,
        /// 270° rotation.
        THREE_QUARTERS = 270
    };

    /// Represents a datetime attribute for pdf metadata.
    enum class DateTimeAttribute {
        /// Creation date attribute.
        CREATION_DATE = 0,
        /// Modification date attribute.
        MODIFICATION_DATE,
    };

    /// Represents a regular string attribute for pdf metadata.
    enum class StringAttribute {
        /// Author attribute.
        AUTHOR = 2,
        /// Creator attribute.
        CREATOR,
        /// Producer attribute.
        PRODUCER,
        /// Title attribute.
        TITLE,
        /// Subject attribute.
        SUBJECT,
        /// Keywords attribute.
        KEYWORDS,
        /// Trapped attribute.
        TRAPPED,
        /// GTS PDFX attribute.
        GTS_PDFX
    };

    /// Represents all allowed values for the R3 encryption when calling PdfDocument::setR3EncryptMode.
    enum class R3EncryptKeyLength: unsigned int {
        /// 5
        FIVE = 5,
        /// 6
        SIX,
        /// 7
        SEVEN,
        /// 8
        EIGHT,
        /// 9
        NINE,
        /// 10
        TEN,
        /// 11
        ELEVEN,
        /// 12
        TWELVE,
        /// 13
        THIRTEEN,
        /// 14
        FOURTEEN,
        /// 15
        FIFTEEN,
        /// 16
        SIXTEEN
    };

    /// Represents a UTC Indicator.
    enum class UTCIndicator {
        /// No indicator.
        NONE = ' ',
        /// Positive indicator.
        PLUS = '+',
        /// Negative indicator.
        MINUS = '-',
        /// Z indicator.
        Z = 'Z'
    };

    /// Represents a text alignment.
    enum class TextAlignment {
        /// Left alignment.
        LEFT = 0,
        /// Right alignment.
        RIGHT,
        /// Center alignment.
        CENTER,
        /// Justified alignment.
        JUSTIFY
    };

    /// Represents a page layout.
    enum class PageLayout {
        /// Single page layout.
        SINGLE_PAGE = 0,
        /// One column layout.
        ONE_COLUMN,
        /// Two columns on the left layout.
        TWO_COLUMN_LEFT,
        /// Two columns on the right layout.
        TWO_COLUMN_RIGHT,
        /// Two pages on the left layout.
        TWO_PAGE_LEFT,
        /// Two pages on the right layout.
        TWO_PAGE_RIGHT,
        /// Page layout could not be determined.
        EOF_LAYOUT
    };

    /// Represents the image color space device used when loading an image from memory.
    enum class ImageColorSpaceDevice {
        /// Gray color space.
        GRAY = 0,
        /// RGB color space.
        RGB,
        /// CMYK color space.
        CMYK
    };

    /// Represents all allowed values for the number of bits per components used when calling PdfDocument::loadRawImageFromMemory.
    enum class BitsPerComponent: unsigned int {
        /// 1
        ONE = 1,
        /// 2
        TWO = 2,
        /// 4
        FOUR = 4,
        /// 8
        EIGHT = 8
    };

    /// Represents a page number style.
    enum class PageNumberStyle {
        /// Decimal style.
        DECIMAL = 0,
        /// Upper roman style.
        UPPER_ROMAN,
        /// Lower roman style.
        LOWER_ROMAN,
        /// Upper letters style.
        UPPER_LETTERS,
        /// Lower letters style.
        LOWER_LETTERS
    };

    /// Represents a single byte encoding.
    enum class SingleByteEncoding {
        /// Standard Encoding.
        StandardEncoding = 0,
        /// MacOs Standard Encoding.
        MacRomanEncoding,
        /// Windows Standard Encoding.
        WinAnsiEncoding,
        /// Built-in Font Specific Encoding.
        FontSpecific,
        /// Latin Alphabet 2 Encoding.
        ISO8859_2,
        /// Latin Alphabet 3 Encoding.
        ISO8859_3,
        /// Latin Alphabet 4 Encoding.
        ISO8859_4,
        /// Latin Cyrillic Alphabet Encoding.
        ISO8859_5,
        /// Latin Arabic Alphabet Encoding.
        ISO8859_6,
        /// Latin Greek Alphabet Encoding.
        ISO8859_7,
        /// Latin Hebrew Alphabet Encoding.
        ISO8859_8,
        /// Latin Alphabet 5 Encoding.
        ISO8859_9,
        /// Latin Alphabet 6 Encoding.
        ISO8859_10,
        /// Thai, TIS 620-2569 Alphabet Encoding.
        ISO8859_11,
        /// Latin Alphabet 7 Encoding.
        ISO8859_13,
        /// Latin Alphabet 8 Encoding.
        ISO8859_14,
        /// Latin Alphabet 9 Encoding.
        ISO8859_15,
        /// Latin Alphabet 10 Encoding.
        ISO8859_16,
        /// Windows Codepage 1250 Encoding (EE).
        CP1250,
        /// Windows Codepage 1251 Encoding (Cyrl).
        CP1251,
        /// Windows Codepage 1252 Encoding (ANSI).
        CP1252,
        /// Windows Codepage 1253 Encoding (Greek).
        CP1253,
        /// Windows Codepage 1254 Encoding (Turk).
        CP1254,
        /// Windows Codepage 1255 Encoding (Hebr).
        CP1255,
        /// Windows Codepage 1256 Encoding (Arab).
        CP1256,
        /// Windows Codepage 1257 Encoding (BaltRim).
        CP1257,
        /// Windows Codepage 1258 Encoding (Viet).
        CP1258,
        /// Russian Net Encoding.
        KOI8_R
    };

    /// Represents a multi byte encoding.
    enum class MultiByteEncoding {
        /// EUC-CN Horizontal Encoding.
        GB_EUC_H = 0,
        /// EUC-CN Vertical Encoding.
        GB_EUC_V,
        /// Windows Codepage 936 GBK Horizontal Encoding.
        GBK_EUC_H,
        /// Windows Codepage 936 GBK Vertical Encoding.
        GBK_EUC_V,
        /// Windows Codepage 950 Big Five with ETen Extensions Horizontal Encoding.
        ETen_B5_H,
        /// Windows Codepage 950 Big Five with ETen Extensions Vertical Encoding.
        ETen_B5_V,
        /// Windows Codepage 932 JIS X 0208 Horizontal Encoding.
        NINETYms_RKSJ_H,
        /// Windows Codepage 932 JIS X 0208 Vertical Encoding.
        NINETYms_RKSJ_V,
        /// Windows Codepage 932 JIS X 0208 Proportial Encoding.
        NINETYmsp_RKSJ_H,
        /// JIS X 0208 Character Set, EUC-JP Horizontal Encoding.
        EUC_H,
        /// JIS X 0208 Character Set, EUC-JP Vertical Encoding.
        EUC_V,
        /// KS X 1001:1992 Character Set, EUC-KR Horizontal Encoding.
        KSC_EUC_H,
        /// KS X 1001:1992 Character Set, EUC-KR Vertical Encoding.
        KSC_EUC_V,
        /// Windows Codepage 949 KS X 1001:1992 Character Set Plus 8822 Additional Hangul, Unified Hangul Code Proportional Encoding.
        KSCms_UHC_H,
        /// Windows Codepage 949 KS X 1001:1992 Character Set Plus 8822 Additional Hangul, Unified Hangul Code Horizontal Encoding.
        KSCms_UHC_HW_H,
        /// Windows Codepage 949 KS X 1001:1992 Character Set Plus 8822 Additional Hangul, Unified Hangul Code Vertical Encoding.
        KSCms_UHC_HW_V
    };

    enum class EncoderType {
        SINGLE_BYTE = 0,
        DOUBLE_BYTE,
        UNINITIALIZED,
        UNKNOWN
    };

    /// Represents a byte type.
    enum class ByteType {
        /// Single byte type.
        SINGLE = 0,
        /// Leading byte type.
        LEAD,
        /// Trailing byte type.
        TRAIL,
        /// Unknown byte type.
        UNKNOWN
    };

    /// Represents a writing mode.
    enum class WritingMode {
        /// Horizontal mode.
        HORIZONTAL = 0,
        /// Vertical mode.
        VERTICAL,
        /// Mode not found.
        EOF_MODE
    };

    enum class BorderStyle {
        SOLID,
        DASHED,
        BEVELED,
        INSET,
        UNDERLINED
    };

    /// Represents the icon of an annotation.
    enum class AnnotationIcon {
        /// \image html "../../docs-utils/icons/0.png" height=30px
        COMMENT = 0,
        /// \image html "../../docs-utils/icons/1.png" height=30px
        KEY,
        /// \image html "../../docs-utils/icons/2.png" height=30px
        NOTE,
        /// \image html "../../docs-utils/icons/3.png" height=30px
        HELP,
        /// \image html "../../docs-utils/icons/4.png" height=30px
        NEW_PARAGRAPH,
        /// \image html "../../docs-utils/icons/5.png" height=30px
        PARAGRAPH,
        /// \image html "../../docs-utils/icons/6.png" height=30px
        INSERT
    };

    /// Represents an annotation highlight mode.
    enum class AnnotationHighlightMode {
        /// No highlight.
        NONE = 0,
        /// Invert box.
        INVERT_BOX,
        /// Invert border.
        INVERT_BORDER,
        /// Down appearance.
        DOWN_APPEARANCE
    };

    /// Represents a line cap.
    enum class LineCap {
        /// Butt ending.
        BUTT_END = 0,
        /// Round ending.
        ROUND_END,
        /// Projecting square ending.
        PROJECTING_SQUARE_END,
        /// Linecap not found.
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

#endif // __HARUPP_CONSTANTS_HPP__
