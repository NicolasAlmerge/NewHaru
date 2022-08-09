#pragma once
#include "PdfObject.hpp"
#include "iostream"
#include "Constants.hpp"
#include "ContentStream.hpp"


namespace pdf {
    class PdfDocument;
    class Destination;
    class TextAnnotation;
    class LinkAnnotation;
    class Box;
    class Encoder;
    class Coor2D;
    class Font;
    class TransposeMatrix;
    class RGBColor;
    class CMYKColor;
    class DashMode;
    class ContentStream;

    class PdfPage: public ContentStream {
        PdfPage(const HPDF_Page content);
        friend class PdfDocument;

    public:
        void setWidth(float value);
        void setHeight(float value);
        void setSizeAndOrientation(PageSize size, PageOrientation orientation);
        void setRotation(PageRotation rotation);

        float getWidth() const;
        float getHeight() const;

        Destination createDestination();

        TextAnnotation createTextAnnotation(const Box& box, const char* text, const Encoder& encoder);
        TextAnnotation createTextAnnotation(const Box& box, const std::string& text, const Encoder& encoder);
        TextAnnotation createTextAnnotation(const Box& box, const char* text);
        TextAnnotation createTextAnnotation(const Box& box, const std::string& text);

        LinkAnnotation createLinkAnnotation(const Box& box, const Destination& destination);
        LinkAnnotation createURILinkAnnotation(const Box& box, const char* uri);
        LinkAnnotation createURILinkAnnotation(const Box& box, const std::string& uri);

        float getTextWidth(const char* text) const;
        float getTextWidth(const std::string& text) const;

        unsigned int measureText(
            const char* text, float width,
            bool wordWrap, float* realWidth = nullptr
        ) const;
        unsigned int measureText(
            const std::string& text, float width,
            bool wordWrap, float* realWidth = nullptr
        ) const;

        unsigned short getGMode() const;

        Coor2D getCurrentPos() const;
        Coor2D getCurrentTextPos() const;

        Font getCurrentFont() const;
        float getCurrentFontSize() const;

        TransposeMatrix getTransposeMatrix() const;

        float getLineWidth() const;
        LineCap getLineCap() const;
        LineJoin getLineJoin() const;
        float getMiterLimit() const;

        DashMode getDash() const;
        float getFlatness() const;
        float getCharSpace() const;
        float getWordSpace() const;
        float getHorizontalScalling() const;
        float getTextLeading() const;
        TextRenderingMode getTextRenderingMode() const;
        float getTextRise() const;

        RGBColor getRGBFill() const;
        RGBColor getRGBStroke() const;
        CMYKColor getCMYKFill() const;
        CMYKColor getCMYKStroke() const;

        float getGrayFill() const;
        float getGrayStroke() const;

        ColorSpace getStrokingColorSpace() const;
        ColorSpace getFillingColorSpace() const;

        TransposeMatrix getTextMatrix() const;
        unsigned int getGStateDepth() const;
        void setSlideShow(TransitionStyle type, float dispTime, float transTime);

        void newContentStream(const ContentStream& newStream);
        void insertSharedContentStream(const ContentStream& sharedStream);

        void arc(float x, float y, float radius, float ang1, float ang2);
        void arc(const Coor2D& coors, float radius, float ang1, float ang2);

        void beginText();

        void circle(float x, float y, float radius);
        void circle(const Coor2D& coors, float radius);

        void clip();

        void closePath();
        void closePathStroke();
        void closePathEofillStroke();
        void closePathFillStroke();

        void concat(float a, float b, float c, float d, float x, float y);
        void concat(const TransposeMatrix& matrix);

        void curveTo(float x1, float y1, float x2, float y2, float x3, float y3);
        void curveTo2(float x2, float y2, float x3, float y3);
        void curveTo3(float x1, float y1, float x3, float y3);

        void drawImage(const Image& image, float x, float y, float width, float height);
        void drawImage(const Image& image, const Coor2D& coors, float width, float height);
        void ellipse(float x, float y, float xRadius, float yRadius);
        void ellipse(const Coor2D& coors, float xRadius, float yRadius);

        void endPath();
        void endText();

        void eoClip();
        void eoFill();
        void eoFillStroke();

        void executeContentStream(const ContentStream& stream);

        void fill();
        void fillStroke();

        void gRestore();
        void gSave();

        void lineTo(float x, float y);
        void lineTo(const Coor2D& coors);
        void moveTextPos(float x, float y);
        void moveTextPos(const Coor2D& coors);
        void moveTextPos2(float x, float y);
        void moveTextPos2(const Coor2D& coors);
        void moveTo(float x, float y);
        void moveTo(const Coor2D& coors);
        void moveToNextLine();

        void rectangle(float x, float y, float width, float height);
        void setCharSpace(float value);

        void setCMYKFill(float c, float m, float y, float k);
        void setCMYKFill(const CMYKColor& color);
        void setCMYKStroke(float c, float m, float y, float k);
        void setCMYKStroke(const CMYKColor& color);

        void setDash(const unsigned short* dashPtn, unsigned int numElem, unsigned int phase = 0U);
        void setDash(const unsigned short* dashPtn, DashModeNumberElements numElem, unsigned int phase = 0U);
        void setDash(const DashMode& mode);

        void setExternGState(const ContentStream& stream);

        void setFontAndSize(const Font& font, float size);
        void setGrayFill(float gray);
        void setGrayStroke(float gray);

        void setHorizontalScalling(float value);
        void setLineCap(LineCap lineCap);
        void setLineJoin(LineJoin lineJoin);
        void setLineWidth(float lineWidth);
        void setMiterLimit(float miterLimit);

        void setRGBFill(float r, float g, float b);
        void setRGBFill(const RGBColor& color);
        void setRGBStroke(float r, float g, float b);
        void setRGBStroke(const RGBColor& color);

        void setTextLeading(float value);

        void setTextMatrix(float a, float b, float c, float d, float x, float y);
        void setTextMatrix(const TransposeMatrix& matrix);

        void setTextRenderingMode(TextRenderingMode mode);

        void setTextRise(float value);
        void setWordSpace(float value);

        void showText(const char* text);
        void showText(const std::string& text);
        void showTextNewLine(const char* text);
        void showTextNewLine(const std::string& text);
        void showTextNewLine(float wordSpace, float charSpace, const char* text);
        void showTextNewLine(float wordSpace, float charSpace, const std::string& text);

        void stroke();
        void textOut(float xPos, float yPos, const char* text);
        void textOut(float xPos, float yPos, const std::string& text);
        void textOut(const Coor2D& coors, const char* text);
        void textOut(const Coor2D& coors, const std::string& text);

        unsigned int textRect(float left, float top, float right, float bottom, const char* text, TextAlignment alignment = TextAlignment::LEFT);
        unsigned int textRect(float left, float top, float right, float bottom, const std::string& text, TextAlignment alignment = TextAlignment::LEFT);
        unsigned int textRect(const Box& box, const char* text, TextAlignment alignment = TextAlignment::LEFT);
        unsigned int textRect(const Box& box, const std::string& text, TextAlignment alignment = TextAlignment::LEFT);

        void writeText(const char* text, const Coor2D& position);
        void writeText(const char* text, int xPos, int yPos);
        void writeText(const std::string& text, const Coor2D& position);
        void writeText(const std::string& text, int xPos, int yPos);
    };
}
