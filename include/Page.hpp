#ifndef __HARUPP_PAGE_HPP__
#define __HARUPP_PAGE_HPP__
#include "ContentStream.hpp"
#include "Enums.hpp"
#include "string"
#include "utility"

namespace pdf {
    class Destination;
    class TextAnnotation;
    class LinkAnnotation;
    class Box;
    class Encoder;
    class Coor2D;
    class Font;
    class Image;
    class TransposeMatrix;
    class RGBColor;
    class CMYKColor;
    class DashMode;
    class ContentStream;

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
        void setWidth(float value);
        void setHeight(float value);
        void setSize(enums::PageSize size, enums::PageOrientation orientation = enums::PageOrientation::PORTRAIT);
        void setRotation(enums::PageRotation rotation);

        float getWidth() const;
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

        float getTextWidth(const std::string& text) const;

        std::pair<unsigned int, float> measureText(const std::string& text, float width, bool wordWrap) const;

        unsigned short getGMode() const;

        Coor2D getCurrentPos() const;
        Coor2D getCurrentTextPos() const;

        /**
         * @brief  Gets the currently used Font.
         * @return Currently used Font.
        */
        Font getCurrentFont() const;

        float getCurrentFontSize() const;

        /**
         * @brief Sets the page zoom.
         * @param zoom Zoom to use (between 0.08 and 32.0)
         * @throw excepts::InvalidParameterException if `zoom < 0.08 || zoom > 32.0`
        */
        void setZoom(float zoom);

        TransposeMatrix getTransposeMatrix() const;

        float getLineWidth() const;
        enums::LineCap getLineCap() const;
        enums::LineJoin getLineJoin() const;
        float getMiterLimit() const;

        DashMode getDash() const;
        float getFlatness() const;
        float getCharSpace() const;
        float getWordSpace() const;
        float getHorizontalScalling() const;
        float getTextLeading() const;
        enums::TextRenderingMode getTextRenderingMode() const;
        float getTextRise() const;

        RGBColor getRGBFill() const;
        RGBColor getRGBStroke() const;
        CMYKColor getCMYKFill() const;
        CMYKColor getCMYKStroke() const;

        float getGrayFill() const;
        float getGrayStroke() const;

        enums::ColorSpace getStrokingColorSpace() const;
        enums::ColorSpace getFillingColorSpace() const;

        TransposeMatrix getTextMatrix() const;
        unsigned int getGStateDepth() const;
        void setSlideShow(enums::TransitionStyle type, float dispTime, float transTime);

        void newContentStream(const ContentStream& newStream);
        void insertSharedContentStream(const ContentStream& sharedStream);

        void arc(const Coor2D& coors, float radius, float ang1, float ang2);

        void beginText();

        void circle(const Coor2D& coors, float radius);

        void clip();

        void closePath();
        void closePathStroke();
        void closePathEofillStroke();
        void closePathFillStroke();

        void concat(const TransposeMatrix& matrix);

        void curveTo(float x1, float y1, float x2, float y2, float x3, float y3);
        void curveTo2(float x2, float y2, float x3, float y3);
        void curveTo3(float x1, float y1, float x3, float y3);

        void drawImage(const Image& image, const Coor2D& coors, float width, float height);
        void ellipse(const Coor2D& coors, float xRadius, float yRadius);

        void endPath();
        void endText();

        void eoClip();
        void eoFill();
        void eoFillStroke();

        void fill();
        void fillStroke();

        void gRestore();
        void gSave();

        void lineTo(const Coor2D& coors);
        void moveTextPos(const Coor2D& coors);
        void moveTextPos2(const Coor2D& coors);
        void moveTo(const Coor2D& coors);
        void moveToNextLine();

        void rectangle(float x, float y, float width, float height);
        void setCharSpace(float value);

        void setCMYKFill(const CMYKColor& color);
        void setCMYKStroke(const CMYKColor& color);

        void setDash(const DashMode& mode);

        void setExternGState(const ContentStream& stream);

        void setFontAndSize(const Font& font, float size);
        void setGrayFill(float gray);
        void setGrayStroke(float gray);

        void setHorizontalScalling(float value);
        void setLineCap(enums::LineCap lineCap);
        void setLineJoin(enums::LineJoin lineJoin);
        void setLineWidth(float lineWidth);
        void setMiterLimit(float miterLimit);

        void setRGBFill(const RGBColor& color);
        void setRGBStroke(const RGBColor& color);

        void setTextLeading(float value);

        void setTextMatrix(const TransposeMatrix& matrix);

        void setTextRenderingMode(enums::TextRenderingMode mode);

        void setTextRise(float value);
        void setWordSpace(float value);

        void showText(const std::string& text);
        void showTextNewLine(const std::string& text);
        void showTextNewLine(float wordSpace, float charSpace, const std::string& text);

        void stroke();
        void textOut(const std::string& text, const Coor2D& position);
        void textOut(const std::string& text);

        unsigned int textRect(const Box& box, const std::string& text, enums::TextAlignment alignment = enums::TextAlignment::LEFT);

        void writeText(const std::string& text);
        void writeText(const std::string& text, const Coor2D& position);
    };
}

#endif // __HARUPP_PAGE_HPP__
