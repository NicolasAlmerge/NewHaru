#ifndef __HARUPP_ENUMS_HPP__
#define __HARUPP_ENUMS_HPP__

/// Represents the Haru++ enumerations.
namespace pdf::enums {

    /// Represents a page boundary.
    enum class PageBoundary {
        /// Mediabox boundary.
        MEDIABOX = 0,
        /// Cropbox boundary.
        CROPBOX,
        /// Bleedbox boundary.
        BLEEDBOX,
        /// Trimbox boundary.
        TRIMBOX,
        /// Artbox boundary.
        ARTBOX
    };

    /// Represents a graphics mode.
    enum class GraphicsMode: unsigned short {
        /// Page description mode.
        PAGE_DESCRIPTION = 0x0001,
        /// Path object mode.
        PATH_OBJECT = 0x0002,
        /// Text object mode.
        TEXT_OBJECT = 0x0004,
        /// Clipping path mode.
        CLIPPING_PATH = 0x0008,
        /// Shading mode.
        SHADING = 0x0010,
        /// Inline image mode.
        INLINE_IMAGE = 0x0020,
        /// External object mode.
        EXTERNAL_OBJECT = 0x0040
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
        FULL_SCREEN
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

    /// Represents a UTC Indicator.
    enum class UTCIndicator: char {
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
        TWO_PAGE_RIGHT
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

    /// Represents an encoder type.
    enum class EncoderType {
        /// Single byte encoder type.
        SINGLE_BYTE = 0,
        /// Double byte encoder type.
        DOUBLE_BYTE,
        /// Uninitialized encoder type.
        UNINITIALIZED,
        /// Unknown encoder type.
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
        VERTICAL
    };

    /// Represents a border style.
    enum class BorderStyle {
        /// Solid style.
        SOLID,
        /// Dashed style.
        DASHED,
        /// Beveled style.
        BEVELED,
        /// Inset style.
        INSET,
        /// Underlined style.
        UNDERLINED
    };

    /// Represents the icon of an annotation.
    enum class AnnotationIcon {
        /// \image html "annotation-icon-0.png" height=30px
        COMMENT = 0,
        /// \image html "annotation-icon-1.png" height=30px
        KEY,
        /// \image html "annotation-icon-2.png" height=30px
        NOTE,
        /// \image html "annotation-icon-3.png" height=30px
        HELP,
        /// \image html "annotation-icon-4.png" height=30px
        NEW_PARAGRAPH,
        /// \image html "annotation-icon-5.png" height=30px
        PARAGRAPH,
        /// \image html "annotation-icon-6.png" height=30px
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
        /// Line is squared off at path endpoint.
        BUTT_END = 0,
        /// End of line becomes a semicircle whose center is at path endpoint.
        ROUND_END,
        /// Line continues beyond endpoint, goes on half the endpoint stroke width.
        PROJECTING_SQUARE_END
    };

    /// Represents a line join.
    enum class LineJoin {
        /// Miter join.
        MITER_JOIN = 0,
        /// Round join.
        ROUND_JOIN,
        /// Bevel join.
        BEVEL_JOIN
    };

    /// Represents a color space.
    enum class ColorSpace {
        /// Device gray.
        DEVICE_GRAY = 0,
        /// Device RGB.
        DEVICE_RGB,
        /// Device CMYK.
        DEVICE_CMYK,
        /// Cal gray.
        CAL_GRAY,
        /// Cal RGB.
        CAL_RGB,
        /// Lab.
        LAB,
        /// ICC based.
        ICC_BASED,
        /// Separation.
        SEPARATION,
        /// Device N.
        DEVICE_N,
        /// Indexed.
        INDEXED,
        /// Pattern.
        PATTERN
    };

    /// Represents a transition style.
    enum class TransitionStyle {
        /// Wipe right transition.
        WIPE_RIGHT = 0,
        /// Wipe up transition.
        WIPE_UP,
        /// Wipe left transition.
        WIPE_LEFT,
        /// Wipe down transition.
        WIPE_DOWN,
        /// Barn doors horizontal out transition.
        BARN_DOORS_HORIZONTAL_OUT,
        /// Barn doors horizontal in transition.
        BARN_DOORS_HORIZONTAL_IN,
        /// Barn doors vertical out transition.
        BARN_DOORS_VERTICAL_OUT,
        /// Barn doors horizontal in transition.
        BARN_DOORS_VERTICAL_IN,
        /// Box out transition.
        BOX_OUT,
        /// Box in transition.
        BOX_IN,
        /// Blinds horizontal transition.
        BLINDS_HORIZONTAL,
        /// Blinds vertical transition.
        BLINDS_VERTICAL,
        /// Dissolve transition.
        DISSOLVE,
        /// Glitter right transition.
        GLITTER_RIGHT,
        /// Glitter down transition.
        GLITTER_DOWN,
        /// Glitter top left to bottom right transition.
        GLITTER_TOP_LEFT_TO_BOTTOM_RIGHT,
        /// Replace transition.
        REPLACE
    };

    /// Represents a text rendering mode.
    enum class TextRenderingMode {
        /// Fill mode.
        FILL = 0,
        /// Stroke mode.
        STROKE,
        /// Fill then stroke mode.
        FILL_THEN_STROKE,
        /// Invisible mode.
        INVISIBLE,
        /// Fill clipping mode.
        FILL_CLIPPING,
        /// Stroke clipping mode.
        STROKE_CLIPPING,
        /// Fill and stroke clipping mode.
        FILL_STROKE_CLIPPING,
        /// Clipping mode.
        CLIPPING
    };
}

#endif // __HARUPP_ENUMS_HPP__
