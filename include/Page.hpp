#ifndef __HARUPP_PAGE_HPP__
#define __HARUPP_PAGE_HPP__
#include "ContentStream.hpp"
#include "Color.hpp"
#include "DashMode.hpp"
#include "Destination.hpp"
#include "Font.hpp"
#include "Encoder.hpp"
#include "Enums.hpp"
#include "Image.hpp"
#include "LinkAnnotation.hpp"
#include "TextAnnotation.hpp"
#include "TransposeMatrix.hpp"
#include "string"
#include "utility"

namespace pdf {

    /**
     * \class  Page
     * @brief  Represents a pdf document page.
     * @file   Page.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class Page final: public ContentStream {
        explicit Page(_HPDF_Dict_Rec* content) noexcept;
        friend class Document;

    public:

        /**
         * @brief Sets the page width.
         * @param width Value to use for the width.
        */
        void setWidth(float width);

        /**
         * @brief Sets the page height.
         * @param height Value to use for the height.
        */
        void setHeight(float height);

        /**
         * @brief Sets the page size and orientation.
         * @param size enums::PageSize to use.
         * @param orientation enums::PageOrientation to use.
        */
        void setSize(enums::PageSize size, enums::PageOrientation orientation = enums::PageOrientation::PORTRAIT);

        /**
         * @brief Sets the page rotation.
         * @param rotation enums::PageRotation to use.
        */
        void setRotation(enums::PageRotation rotation);

        /**
         * @brief  Gets the page width.
         * @return Page width.
        */
        float getWidth() const;

        /**
         * @brief  Gets the page height.
         * @return Page height.
        */
        float getHeight() const;

        /**
         * @brief  Creates a Destination to this page.
         * @return Newly created Destination.
        */
        Destination createDestination();

        /**
         * @brief   Creates a TextAnnotation on this page.
         * @details By default, the TextAnnotation will have the AnnotationIcon::NOTE icon.
         * @param   text String content of the annotation.
         * @param   box Bounding box to use.
         * @param   encoder Encoder to use.
         * @return  Newly created TextAnnotation.
        */
        TextAnnotation createTextAnnotation(const std::string& text, const Box& box, const Encoder& encoder);

        /**
         * @brief   Creates a TextAnnotation on this page.
         * @details By default, the TextAnnotation will have the AnnotationIcon::NOTE icon.
         * @param   text String content of the annotation.
         * @param   box Bounding box to use.
         * @return  Newly created TextAnnotation.
        */
        TextAnnotation createTextAnnotation(const std::string& text, const Box& box);

        /**
         * @brief  Creates a LinkAnnotation on this page.
         * @param  destination Destination the annotation will point to.
         * @param  box Bounding box to use.
         * @return Newly created LinkAnnotation.
        */
        LinkAnnotation createLinkAnnotation(const Destination& destination, const Box& box);

        /**
         * @brief  Creates a LinkAnnotation on this page.
         * @param  uri URI the annotation will point to.
         * @param  box Bounding box to use.
         * @return Newly created LinkAnnotation.
        */
        LinkAnnotation createURILinkAnnotation(const std::string& uri, const Box& box);

        /**
         * @brief  Gets the width of a text.
         * @return Width of `text`.
        */
        float getTextWidth(const std::string& text) const;

        /**
         * @brief  Measures calculates the byte length which can be included within the specified width.
         * @param  text Text to get width from.
         * @param  width Width of the area to put the text.
         * @param  wordWrap When `text` contains the words `"ABCDE"`, `"FGH"` and `"IJKL"`, and the substring until `"J"` can be included within the width,
         *         if `wordWrap` is `false` it returns `12`, else it returns `10` (the end of the previous word).
         * @return Data pair containing, in this order:
         *         - Byte length which can be included within the specified width in current fontsize, character spacing and word spacing
         *         - The real widths of `text`
        */
        std::pair<unsigned int, float> measureText(const std::string& text, float width, bool wordWrap) const;

        /**
         * @brief   Gets the page's current graphics mode.
         * @details The initial graphics mode is enums::GraphicsMode::PAGE_DESCRIPTION.
         * @return  Current graphics mode.
         * @throw   excepts::InvalidGModeException if the operation failed.
        */
        enums::GraphicsMode getGraphicsMode() const;

        /**
         * @brief  Gets the current position at the page.
         * @return Current position as a Coor2D object.
        */
        Coor2D getCurrentPos() const;

        /**
         * @brief  Gets the current text position at the page.
         * @return Current text position as a Coor2D object.
        */
        Coor2D getCurrentTextPos() const;

        /**
         * @brief  Gets the currently used Font.
         * @return Currently used Font.
        */
        Font getCurrentFont() const;

        /**
         * @brief  Gets the current font size.
         * @return Current font size.
        */
        float getCurrentFontSize() const;

        /**
         * @brief Sets the page zoom.
         * @param zoom Zoom to use (`0.08 <= zoom <= 32.0`).
         * @throw excepts::InvalidParameterException if `zoom < 0.08 || zoom > 32.0`.
        */
        void setZoom(float zoom);

        /**
         * @brief  Gets the page's TransposeMatrix.
         * @return The page's TransposeMatrix.
        */
        TransposeMatrix getTransposeMatrix() const;

        /**
         * @brief   Gets the width of the line used to stroke a path.
         * @details The initial value is `1.0`.
         * @return  Line width.
        */
        float getLineWidth() const;

        /**
         * @brief  Gets the line cap.
         * @return Line cap.
        */
        enums::LineCap getLineCap() const;

        /**
         * @brief   Gets the line join.
         * @details The initial value is enums::LineJoin::MITER_JOIN.
         * @return  Line join.
        */
        enums::LineJoin getLineJoin() const;

        /**
         * @brief  Gets the current value of the page's miter limit.
         * @return Miter limit.
        */
        float getMiterLimit() const;

        /**
         * @brief  Gets the current pattern of the page.
         * @return Dash mode.
        */
        DashMode getDash() const;

        /**
         * @brief  Gets the current value of the page's flatness.
         * @return Flatness of the page.
        */
        float getFlatness() const;

        /**
         * @brief   Gets the current value of the page's character spacing.
         * @details The initial value is `0.0`.
         * @return  Character spacing.
        */
        float getCharSpace() const;

        /**
         * @brief   Gets the current value of the page's word spacing.
         * @details The initial value is `0.0`.
         * @return  Word spacing.
        */
        float getWordSpace() const;

        /**
         * @brief   Gets the current value of the page's horizontal scaling for text displaying.
         * @details The initial value is `100.0`.
         * @return  Horizontal scaling of the page.
        */
        float getHorizontalScaling() const;

        /**
         * @brief   Gets the current value of the page's line spacing.
         * @details The initial value is `0.0`.
         * @return  Line spacing of the page.
        */
        float getTextLeading() const;

        /**
         * @brief   Gets the current value of the page's text rendering mode.
         * @details The initial value is enums::TextRenderingMode::FILL.
         * @return  Text rendering mode of the page.
        */
        enums::TextRenderingMode getTextRenderingMode() const;

        /**
         * @brief  Gets the current value of the page's text rising.
         * @return Text rising of the page.
        */
        float getTextRise() const;

        /**
         * @brief   Gets the current value of the page's filling RGBColor.
         * @warning It is valid only when the page's filling color space is enums::ColorSpace::DEVICE_RGB.
         * @return  Filling RGBColor of the page.
        */
        RGBColor getRGBFill() const;

        /**
         * @brief   Gets the current value of the page's stroking RGBColor.
         * @warning It is valid only when the page's stroking color space is enums::ColorSpace::DEVICE_RGB.
         * @return  Stroking RGBColor of the page.
        */
        RGBColor getRGBStroke() const;

        /**
         * @brief   Gets the current value of the page's filling CMYKColor.
         * @warning It is valid only when the page's filling color space is enums::ColorSpace::DEVICE_CMYK.
         * @return  Filling CMYKColor of the page.
        */
        CMYKColor getCMYKFill() const;

        /**
         * @brief   Gets the current value of the page's stroking CMYKColor.
         * @warning It is valid only when the page's stroking color space is enums::ColorSpace::DEVICE_CMYK.
         * @return  Stroking CMYKColor of the page.
        */
        CMYKColor getCMYKStroke() const;

        /**
         * @brief   Gets the current value of the page's filling gray color.
         * @warning It is valid only when the page's filling color space is enums::ColorSpace::DEVICE_GRAY.
         * @return  Filling gray color of the page.
        */
        float getGrayFill() const;

        /**
         * @brief   Gets the current value of the page's stroking gray color.
         * @warning It is valid only when the page's stroking color space is enums::ColorSpace::DEVICE_GRAY.
         * @return  Stroking gray color of the page.
        */
        float getGrayStroke() const;

        /**
         * @brief  Returns the current value of the page's stroking color space.
         * @return Stroking color space of the page.
        */
        enums::ColorSpace getStrokingColorSpace() const;

        /**
         * @brief  Returns the current value of the page's filling color space.
         * @return Filling color space of the page.
        */
        enums::ColorSpace getFillingColorSpace() const;

        /**
         * @brief  Gets the current text transformation matrix of the page.
         * @return TransposeMatrix representing the transformation of the text.
        */
        TransposeMatrix getTextMatrix() const;

        /**
         * @brief  Gets the number of the page's graphics state stack.
         * @return Number of the page's graphics state stack.
        */
        unsigned int getGStateDepth() const;

        /**
         * @brief Configures the setting for slide transition of the page.
         * @param type Transition type.
         * @param dispTime Display duration of the page (in seconds).
         * @param transTime Transition effect duration of the page (in seconds).
        */
        void setSlideShow(enums::TransitionStyle type, float dispTime, float transTime = 1.0F);

        /**
         * @brief Change to a new ContentStream on the page.
         * @param newStream ContentStream to use.
        */
        void newContentStream(const ContentStream& newStream);

        /**
         * @brief Insert a new ContentStream on the page.
         * @param sharedStream ContentStream to use.
        */
        void insertSharedContentStream(const ContentStream& sharedStream);

        /**
         * @brief Appends a circle arc to the current path.
         * @param coors Center point of the circle.
         * @param radius Radius of the circle.
         * @param ang1 The angle of the begining of the arc.
         * @param ang2 The angle of the end of the arc (must be greater than `ang1`).
         * @note  Angles are given in degrees, with `0` being vertical upward from `coors`.
         * @pre   The graphics mode must be set to enums::GraphicsMode::PAGE_DESCRIPTION or enums::GraphicsMode::PATH_OBJECT before calling this function.
         * @post  The graphics mode will be set to enums::GraphicsMode::PATH_OBJECT after calling this function.
        */
        void arc(const Coor2D& coors, float radius, float ang1, float ang2);

        /**
         * @brief Begins a text object and sets the text position to `(0, 0)`.
         * @pre   The graphics mode must be set to enums::GraphicsMode::PAGE_DESCRIPTION before calling this function.
         * @post  The graphics mode will be set to enums::GraphicsMode::TEXT_OBJECT after calling this function.
        */
        void beginText();

        /**
         * @brief Appends a circle to the current path.
         * @param coors Center point of the circle.
         * @param radius Radius of the circle.
         * @pre   The graphics mode must be set to enums::GraphicsMode::PAGE_DESCRIPTION or enums::GraphicsMode::PATH_OBJECT before calling this function.
         * @post  The graphics mode will be set to enums::GraphicsMode::PATH_OBJECT after calling this function.
        */
        void circle(const Coor2D& coors, float radius);

        /**
         * @brief   Modifies the current clipping path by intersecting it with the current path using the nonzero winding number rule.
         * @details The clipping path is only modified after the succeeding painting operator.
         *          To avoid painting the current path, use the ::endPath.
         * @warning Following painting operations will only affect the regions of the page contained by the clipping path.
         *          Initially, the clipping path includes the entire page. There is no way to enlarge the current clipping path,
         *          or to replace the clipping path with a new one. The functions ::gSave and ::gRestore may be used to save and
         *          restore the current graphics state, including the clipping path.
         * @pre     The graphics mode must be set to enums::GraphicsMode::PATH_OBJECT before calling this function.
        */
        void clip();

        /**
         * @brief   Appends a straight line from the current point to the start point of sub path.
         * @details The current point is moved to the start point of sub path.
         * @pre     The graphics mode must be set to enums::GraphicsMode::PATH_OBJECT before calling this function.
        */
        void closePath();

        /**
         * @brief Closes the current path then paints it.
         * @pre   The graphics mode must be set to enums::GraphicsMode::PATH_OBJECT before calling this function.
         * @post  The graphics mode will be set to enums::GraphicsMode::PAGE_DESCRIPTION after calling this function.
        */
        void closePathStroke();

        /**
         * @brief Closes the current path, fills it using the even-odd rule and then paints it.
         * @pre   The graphics mode must be set to enums::GraphicsMode::PATH_OBJECT before calling this function.
         * @post  The graphics mode will be set to enums::GraphicsMode::PAGE_DESCRIPTION after calling this function.
        */
        void closePathEofillStroke();

        /**
         * @brief Closes the current path, fills it using the nonzero winding number rule and then paints it.
         * @pre   The graphics mode must be set to enums::GraphicsMode::PATH_OBJECT before calling this function.
         * @post  The graphics mode will be set to enums::GraphicsMode::PAGE_DESCRIPTION after calling this function.
        */
        void closePathFillStroke();

        /**
         * @brief Concatenates the page's current transformation matrix with the specified matrix.
         * @param matrix Matrix to use for concatenation.
        */
        void concat(const TransposeMatrix& matrix);

        /**
         * @brief   Appends a Bézier curve to the current path.
         * @details This uses the control points `first`, `second` and `third`,
         *          then sets the current point to `third`.
         * @param   first First point to use.
         * @param   second Second point to use.
         * @param   third Third point to use.
         * @pre     The graphics mode must be set to enums::GraphicsMode::PATH_OBJECT before calling this function.
        */
        void curve(const Coor2D& first, const Coor2D& second, const Coor2D& third);

        /**
         * @brief   Appends a Bézier curve to the current path.
         * @details This uses the current point, `second` and `third`,
         *          then sets the current point to `third`.
         * @param   second Second point to use.
         * @param   third Third point to use.
         * @pre     The graphics mode must be set to enums::GraphicsMode::PATH_OBJECT before calling this function.
        */
        void curveFromCurrent(const Coor2D& second, const Coor2D& third);

        /**
         * @brief   Appends a Bézier curve to the current path.
         * @details This uses the control points `first` and `third`,
         *          then sets the current point to `third`.
         * @param   first First point to use.
         * @param   third Third point to use.
         * @pre     The graphics mode must be set to enums::GraphicsMode::PATH_OBJECT before calling this function.
        */
        void curve(const Coor2D& first, const Coor2D& third);

        /**
         * @brief Displays an Image in one operation.
         * @param image Image to use.
         * @param coors The lower left point of the region where the image should be displayed.
         * @param width Width of the region where the image should be displayed.
         * @param height Height of the region where the image should be displayed.
         * @pre   The graphics mode must be set to enums::GraphicsMode::PAGE_DESCRIPTION before calling this function.
        */
        void drawImage(const Image& image, const Coor2D& coors, float width, float height);

        /**
         * @brief Appends an ellipse to the current path.
         * @param coors Center point of the ellipse.
         * @param xRadius Horizontal radius of the ellipse.
         * @param yRadius Vertical radius of the ellipse.
         * @pre   The graphics mode must be set to enums::GraphicsMode::PATH_OBJECT before calling this function.
        */
        void ellipse(const Coor2D& coors, float xRadius, float yRadius);

        /**
         * @brief Ends the path object without filling or painting.
         * @pre   The graphics mode must be set to enums::GraphicsMode::PATH_OBJECT before calling this function.
         * @post  The graphics mode will be set to enums::GraphicsMode::PAGE_DESCRIPTION after calling this function.
        */
        void endPath();

        /**
         * @brief Ends a text object.
         * @pre   The graphics mode must be set to enums::GraphicsMode::TEXT_OBJECT before calling this function.
         * @post  The graphics mode will be set to enums::GraphicsMode::PAGE_DESCRIPTION after calling this function.
        */
        void endText();

        /**
         * @brief   Modifies the current clipping path by intersecting it with the current path using the even-odd rule.
         * @details The clipping path is only modified after the succeeding painting operator.
         *          To avoid painting the current path, use the ::endPath.
         * @warning Following painting operations will only affect the regions of the page contained by the clipping path.
         *          Initially, the clipping path includes the entire page. There is no way to enlarge the current clipping path,
         *          or to replace the clipping path with a new one. The functions ::gSave and ::gRestore may be used to save and restore
         *          the current graphics state, including the clipping path.
         * @pre     The graphics mode must be set to enums::GraphicsMode::PATH_OBJECT before calling this function.
        */
        void eoClip();

        /**
         * @brief Fills the current path using the even-odd rule.
         * @pre   The graphics mode must be set to enums::GraphicsMode::PATH_OBJECT before calling this function.
         * @post  The graphics mode will be set to enums::GraphicsMode::PAGE_DESCRIPTION after calling this function.
        */
        void eoFill();

        /**
         * @brief Fills the current path using the even-odd rule, then paints the path.
         * @pre   The graphics mode must be set to enums::GraphicsMode::PATH_OBJECT before calling this function.
         * @post  The graphics mode will be set to enums::GraphicsMode::PAGE_DESCRIPTION after calling this function.
        */
        void eoFillStroke();

        /**
         * @brief   Draws a ContentStream using the current graphics context.
         * @details This is used by ::drawImage to draw an Image by first calling ::gSave and ::concat, and then calling
         *          ::gRestore after this function call. It could be used manually to rotate an Image.
         * @param   stream The ContentStream to execute.
         * @pre     The graphics mode must be set to enums::GraphicsMode::PAGE_DESCRIPTION before calling this function.
        */
        void executeContentStream(const ContentStream& stream);

        /**
         * @brief Fills the current path using the nonzero winding number rule.
         * @pre   The graphics mode must be set to enums::GraphicsMode::PATH_OBJECT before calling this function.
         * @post  The graphics mode will be set to enums::GraphicsMode::PAGE_DESCRIPTION after calling this function.
        */
        void fill();

        /**
         * @brief Fills the current path using the nonzero winding number rule, then paints the path.
         * @pre   The graphics mode must be set to enums::GraphicsMode::PATH_OBJECT before calling this function.
         * @post  The graphics mode will be set to enums::GraphicsMode::PAGE_DESCRIPTION after calling this function.
        */
        void fillStroke();

        /**
         * @brief Restores the graphics state which was saved by ::gSave.
         * @throw excepts::NoGStateException if no graphics state was stored.
         * @pre   The graphics mode must be set to enums::GraphicsMode::PAGE_DESCRIPTION before calling this function.
        */
        void gRestore();

        /**
         * @brief   Saves the page's current graphics parameter to the stack.
         * @details An application can invoke this function up to consts::MAX_GSTATE times and can restore the saved parameter by invoking ::gRestore.
         *          The parameters that are saved are:
         *          - Character spacing
         *          - Clipping path
         *          - DashMode
         *          - Filling color
         *          - Flatness
         *          - Font
         *          - The font size
         *          - Horizontal scalling
         *          - Line width
         *          - enums::LineCap style
         *          - enums::LineJoin Style
         *          - Miter limit
         *          - Rendering mode
         *          - Stroking color
         *          - Text leading
         *          - Text rise
         *          - TransformationMatrix (TransposeMatrix)
         *          - Word spacing
         * @throw   excepts::GStateLimitExceededException if the G stack depth is already at consts::MAX_GSTATE.
         * @pre     The graphics mode must be set to enums::GraphicsMode::PAGE_DESCRIPTION before calling this function.
        */
        void gSave();

        /**
         * @brief Appends a path from the current point to the specified point.
         * @param coors End point coordinates.
         * @pre   The graphics mode must be set to enums::GraphicsMode::PATH_OBJECT before calling this function.
        */
        void lineTo(const Coor2D& coors);

        /**
         * @brief   Changes the current text position, using the specified offset values.
         * @details If the current text position is (`x1`, `y1`), the new text position will be
         *          (`x1 + offset.getX()`, `y1 + offset.getY()`).
         * @param   offset Offset of the new text position.
         * @param   invertTextLeading If set to `true`, the text leading will be set to `-offset.getY()`, otherwise no other changes.
         * @pre     The graphics mode must be set to enums::GraphicsMode::TEXT_OBJECT before calling this function.
        */
        void moveTextPos(const Coor2D& offset, bool invertTextLeading = false);

        /**
         * @brief   Starts a new subpath and move the current point for the drawing path.
         * @details This sets the start point for the path to `coors`.
         * @param   coors Coordinates to use.
         * @pre     The graphics mode must be set to enums::GraphicsMode::PAGE_DESCRIPTION or enums::GraphicsMode::PATH_OBJECT before calling this function.
         * @post    The graphics mode will be set to enums::GraphicsMode::PATH_OBJECT after calling this function.
        */
        void moveTo(const Coor2D& coors);

        /**
         * @brief   Moves the current position for the text showing depending on current text showing point and text leading.
         * @details The new position is calculated with the current text transition matrix.
        */
        void moveToNextLine();

        /**
         * @brief Appends a rectangle to the current path.
         * @param lowerLeftCoors Lower left point of the rectangle.
         * @param width Width of the rectangle.
         * @param height Height of the rectangle.
         * @pre   The graphics mode must be set to enums::GraphicsMode::PAGE_DESCRIPTION or enums::GraphicsMode::PATH_OBJECT before calling this function.
         * @post  The graphics mode will be set to enums::GraphicsMode::PATH_OBJECT after calling this function.
        */
        void rectangle(const Coor2D& lowerLeftCoors, float width, float height);

        /**
         * @brief Sets the character spacing.
         * @param value New spacing value to use.
         * @pre   The graphics mode must be set to enums::GraphicsMode::PAGE_DESCRIPTION or enums::GraphicsMode::TEXT_OBJECT before calling this function.
        */
        void setCharSpace(float value);

        /**
         * @brief Sets the filling CMYKColor.
         * @param color CMYKColor to use for filling.
         * @pre   The graphics mode must be set to enums::GraphicsMode::PAGE_DESCRIPTION or enums::GraphicsMode::TEXT_OBJECT before calling this function.
        */
        void setCMYKFill(const CMYKColor& color);

        /**
         * @brief Sets the stroking CMYKColor.
         * @param color CMYKColor to use for stroking.
         * @pre   The graphics mode must be set to enums::GraphicsMode::PAGE_DESCRIPTION or enums::GraphicsMode::TEXT_OBJECT before calling this function.
        */
        void setCMYKStroke(const CMYKColor& color);

        /**
         * @brief Sets the dash pattern for lines in the page.
         * @param mode DashMode to use.
         * @pre   The graphics mode must be set to enums::GraphicsMode::PAGE_DESCRIPTION or enums::GraphicsMode::TEXT_OBJECT before calling this function.
        */
        void setDash(const DashMode& mode);

        /**
         * @brief Applies the graphics state to the page.
         * @param stream Extended graphics state object to use.
         * @pre   The graphics mode must be set to enums::GraphicsMode::PAGE_DESCRIPTION before calling this function.
        */
        void setExternGState(const ContentStream& stream);

        /**
         * @brief Sets the Font and size.
         * @param font Font to use.
         * @param size The font size to use (`0 < size <= consts::MAX_FONT_SIZE`).
         * @pre   The graphics mode must be set to enums::GraphicsMode::PAGE_DESCRIPTION or enums::GraphicsMode::TEXT_OBJECT before calling this function.
        */
        void setFontAndSize(const Font& font, float size);

        /**
         * @brief Sets the gray filling color.
         * @param gray Gray value to use (`0 <= gray <= 1`).
         * @pre   The graphics mode must be set to enums::GraphicsMode::PAGE_DESCRIPTION or enums::GraphicsMode::TEXT_OBJECT before calling this function.
        */
        void setGrayFill(float gray);

        /**
         * @brief Sets the gray stroking color.
         * @param gray Gray value to use (`0 <= gray <= 1`).
         * @pre   The graphics mode must be set to enums::GraphicsMode::PAGE_DESCRIPTION or enums::GraphicsMode::TEXT_OBJECT before calling this function.
        */
        void setGrayStroke(float gray);

        /**
         * @brief Sets the horizontal scaling for text displaying.
         * @param value New value of the horizontal scaling.
         * @pre   The graphics mode must be set to enums::GraphicsMode::PAGE_DESCRIPTION or enums::GraphicsMode::TEXT_OBJECT before calling this function.
        */
        void setHorizontalScaling(float value);

        /**
         * @brief Sets the shape to be used at the ends of lines.
         * @param lineCap The new enums::LineCap style.
         * @pre   The graphics mode must be set to enums::GraphicsMode::PAGE_DESCRIPTION or enums::GraphicsMode::TEXT_OBJECT before calling this function.
        */
        void setLineCap(enums::LineCap lineCap);

        /**
         * @brief Sets the line join style in the page.
         * @param lineJoin The new enums::LineJoin style.
         * @pre   The graphics mode must be set to enums::GraphicsMode::PAGE_DESCRIPTION or enums::GraphicsMode::TEXT_OBJECT before calling this function.
        */
        void setLineJoin(enums::LineJoin lineJoin);

        /**
         * @brief Sets the width of the line used to stroke a path.
         * @param lineWidth New value of the line width.
         * @pre   The graphics mode must be set to enums::GraphicsMode::PAGE_DESCRIPTION or enums::GraphicsMode::TEXT_OBJECT before calling this function.
        */
        void setLineWidth(float lineWidth);

        /**
         * @brief Sets the new miter limit value.
         * @param miterLimit New miter limit value.
        */
        void setMiterLimit(float miterLimit);

        /**
         * @brief Sets the filling RGBColor.
         * @param color RGBColor to use for filling.
         * @pre   The graphics mode must be set to enums::GraphicsMode::PAGE_DESCRIPTION or enums::GraphicsMode::TEXT_OBJECT before calling this function.
        */
        void setRGBFill(const RGBColor& color);

        /**
         * @brief Sets the stroking RGBColor.
         * @param color RGBColor to use for stroking.
         * @pre   The graphics mode must be set to enums::GraphicsMode::PAGE_DESCRIPTION or enums::GraphicsMode::TEXT_OBJECT before calling this function.
        */
        void setRGBStroke(const RGBColor& color);

        /**
         * @brief Sets the line spacing for text displaying.
         * @param value New value to use for line spacing.
         * @pre   The graphics mode must be set to enums::GraphicsMode::PAGE_DESCRIPTION or enums::GraphicsMode::TEXT_OBJECT before calling this function.
        */
        void setTextLeading(float value);

        /**
         * @brief   Sets the transformation matrix for text to be drawn when calling ::showText.
         * @note    Text is typically output using the ::showText.
         * @warning The ::textRect function does not use the active text matrix.
         * @param   matrix New TransposeMatrix to use.
         * @pre     The graphics mode must be set to enums::GraphicsMode::TEXT_OBJECT before calling this function.
        */
        void setTextMatrix(const TransposeMatrix& matrix);

        /**
         * @brief Sets the text rendering mode.
         * @param mode New value to use for text rendering.
         * @pre   The graphics mode must be set to enums::GraphicsMode::PAGE_DESCRIPTION or enums::GraphicsMode::TEXT_OBJECT before calling this function.
        */
        void setTextRenderingMode(enums::TextRenderingMode mode);

        /**
         * @brief   Moves the text position in vertical direction by a certain amount.
         * @details This is useful for making subscripts or superscripts.
         * @param   value New value to use for the text rise, in user space units.
         * @pre     The graphics mode must be set to enums::GraphicsMode::PAGE_DESCRIPTION or enums::GraphicsMode::TEXT_OBJECT before calling this function.
        */
        void setTextRise(float value);

        /**
         * @brief Sets the word spacing for text.
         * @param value New value to use for the word spacing.
         * @pre   The graphics mode must be set to enums::GraphicsMode::PAGE_DESCRIPTION or enums::GraphicsMode::TEXT_OBJECT before calling this function.
        */
        void setWordSpace(float value);

        /**
         * @brief Prints the text at the current position on the page.
         * @param text Text to print.
         * @pre   The graphics mode must be set to enums::GraphicsMode::TEXT_OBJECT before calling this function.
        */
        void showText(const std::string& text);

        /**
         * @brief Moves the current text position to the start of the next line, then prints the text at the current position on the page.
         * @param text Text to print.
         * @pre   The graphics mode must be set to enums::GraphicsMode::TEXT_OBJECT before calling this function.
        */
        void showTextNewLine(const std::string& text);

        /**
         * @brief Moves the current text position to the start of the next line, then sets word spacing and character spacing, finally prints the text at the current position on the page.
         * @param wordSpace Word spacing to use.
         * @param charSpace Character spacing to use.
         * @param text Text to print.
         * @pre   The graphics mode must be set to enums::GraphicsMode::TEXT_OBJECT before calling this function.
        */
        void showTextNewLine(float wordSpace, float charSpace, const std::string& text);

        /**
         * @brief Paints the current path.
         * @pre   The graphics mode must be set to enums::GraphicsMode::PATH_OBJECT before calling this function.
         * @post  The graphics mode will be set to enums::GraphicsMode::PAGE_DESCRIPTION after calling this function.
        */
        void stroke();

        /**
         * @brief Prints the text at the specified position.
         * @param text Text to print.
         * @param position Coordinates where to print the text.
         * @pre   The graphics mode must be set to enums::GraphicsMode::TEXT_OBJECT before calling this function.
        */
        void textOut(const std::string& text, const Coor2D& position);

        /**
         * @brief   Prints the text at the current text position.
         * @details This is equivalent to `textOut(text, getCurrentTextPos())`.
         * @param   text Text to print.
         * @pre     The graphics mode must be set to enums::GraphicsMode::TEXT_OBJECT before calling this function.
        */
        void textOut(const std::string& text);

        /**
         * @brief  Prints the text inside the specified region.
         * @param  box Coordinates of the corners of the region to output text.
         * @param  text Text to print.
         * @param  alignment The text alignment to use.
         * @return The number of characters printed in the area, and whether or not the whole text fits into the declared space.
         * @pre    The graphics mode must be set to enums::GraphicsMode::TEXT_OBJECT before calling this function.
        */
        std::pair<unsigned int, bool> textRect(const Box& box, const std::string& text, enums::TextAlignment alignment = enums::TextAlignment::LEFT);

        /**
         * @brief   Begins a text object, prints the text at the specified text position and ends the text object.
         * @details This is equivalent to:
         * @code    beginText();
         *          textOut(text, position);
         *          endText();
         * @endcode
         * @param text Text to print.
         * @param position Position at which to print the text.
         * @pre   The graphics mode must be set to enums::GraphicsMode::PAGE_DESCRIPTION before calling this function.
        */
        void writeText(const std::string& text, const Coor2D& position);
    };
}

#endif // __HARUPP_PAGE_HPP__
