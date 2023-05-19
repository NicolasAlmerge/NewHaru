#include "../include/Page.hpp"
#include "../include/Destination.hpp"
#include "../include/TextAnnotation.hpp"
#include "../include/LinkAnnotation.hpp"
#include "../include/Box.hpp"
#include "../include/Encoder.hpp"
#include "../include/Coor2D.hpp"
#include "../include/Font.hpp"
#include "../include/TransposeMatrix.hpp"
#include "../include/DashMode.hpp"
#include "../include/RGBColor.hpp"
#include "../include/CMYKColor.hpp"
#include "../include/Image.hpp"
#include "../include/Constants.hpp"
#include "hpdf.h"
using namespace pdf;
using namespace pdf::enums;


static constexpr unsigned int __haruppMin(unsigned int a, unsigned int b) {
    return (a <= b)? a: b;
}


static std::vector<float> __vectorFromValues(unsigned int numPtn, float* ptn) {
    unsigned int minValue = __haruppMin(numPtn, consts::MAX_DASH_MODE_LENGTH);
    std::vector<float> points;
    points.reserve(minValue);
    for (unsigned int i = 0U; i < minValue; ++i) points.push_back(ptn[i]);
    return points;
}


static HPDF_Rect __toRect(const Box& box) {
    HPDF_Rect rect;
    rect.left = box.getLeft();
    rect.bottom = box.getBottom();
    rect.right = box.getRight();
    rect.top = box.getTop();
    return rect;
}


static ColorSpace convertToColorSpace(HPDF_ColorSpace colorSpace) {
    switch (colorSpace) {
        case HPDF_CS_DEVICE_GRAY: return ColorSpace::DEVICE_GRAY;
        case HPDF_CS_DEVICE_RGB: return ColorSpace::DEVICE_RGB;
        case HPDF_CS_DEVICE_CMYK: return ColorSpace::DEVICE_CMYK;
        case HPDF_CS_CAL_GRAY: return ColorSpace::CAL_GRAY;
        case HPDF_CS_CAL_RGB: return ColorSpace::CAL_RGB;
        case HPDF_CS_LAB: return ColorSpace::LAB;
        case HPDF_CS_ICC_BASED: return ColorSpace::ICC_BASED;
        case HPDF_CS_SEPARATION: return ColorSpace::SEPARATION;
        case HPDF_CS_DEVICE_N: return ColorSpace::DEVICE_N;
        case HPDF_CS_INDEXED: return ColorSpace::INDEXED;
        case HPDF_CS_PATTERN: return ColorSpace::PATTERN;
        default: return ColorSpace::EOF_COLOR_SPACE;
    }
}


Page::Page(_HPDF_Dict_Rec* content) noexcept: ContentStream(content) {}

void Page::setWidth(float value) {
    HPDF_Page_SetWidth(__innerContent, value);
}

void Page::setHeight(float value) {
    HPDF_Page_SetHeight(__innerContent, value);
}

void Page::setSize(PageSize size, PageOrientation orientation) {
    HPDF_Page_SetSize(__innerContent, (HPDF_PageSizes) size, (HPDF_PageDirection) orientation);
}

void Page::setRotation(PageRotation rotation) {
    HPDF_Page_SetRotate(__innerContent, (unsigned short) rotation);
}

float Page::getWidth() const {
    return HPDF_Page_GetWidth(__innerContent);
}

float Page::getHeight() const {
    return HPDF_Page_GetHeight(__innerContent);
}

Destination Page::createDestination() {
    return Destination(HPDF_Page_CreateDestination(__innerContent));
}

TextAnnotation Page::createTextAnnotation(const std::string& text, const Box& box, const Encoder& encoder) {
    return TextAnnotation(HPDF_Page_CreateTextAnnot(__innerContent, __toRect(box), text.c_str(), encoder.__innerContent));
}

TextAnnotation Page::createTextAnnotation(const std::string& text, const Box& box) {
    return TextAnnotation(HPDF_Page_CreateTextAnnot(__innerContent, __toRect(box), text.c_str(), nullptr));
}

LinkAnnotation Page::createLinkAnnotation(const Destination& destination, const Box& box) {
    return LinkAnnotation(HPDF_Page_CreateLinkAnnot(__innerContent, __toRect(box), destination.__innerContent));
}

LinkAnnotation Page::createURILinkAnnotation(const std::string& uri, const Box& box) {
    return LinkAnnotation(HPDF_Page_CreateURILinkAnnot(__innerContent, __toRect(box), uri.c_str()));
}

float Page::getTextWidth(const std::string& text) const {
    return HPDF_Page_TextWidth(__innerContent, text.c_str());
}

std::pair<unsigned int, float> Page::measureText(const std::string& text, float width, bool wordWrap) const {
    float realWidth;
    unsigned int val = HPDF_Page_MeasureText(__innerContent, text.c_str(), width, wordWrap, &realWidth);
    return {val, realWidth};
}

unsigned short Page::getGMode() const {
    return HPDF_Page_GetGMode(__innerContent);
}

Coor2D Page::getCurrentPos() const {
    HPDF_Point point = HPDF_Page_GetCurrentPos(__innerContent);
    return Coor2D(point.x, point.y);
}

Coor2D Page::getCurrentTextPos() const {
    HPDF_Point point = HPDF_Page_GetCurrentTextPos(__innerContent);
    return Coor2D(point.x, point.y);
}

Font Page::getCurrentFont() const {
    return Font(HPDF_Page_GetCurrentFont(__innerContent));
}

float Page::getCurrentFontSize() const {
    return HPDF_Page_GetCurrentFontSize(__innerContent);
}

TransposeMatrix Page::getTransposeMatrix() const {
    HPDF_TransMatrix matrix = HPDF_Page_GetTransMatrix(__innerContent);
    return TransposeMatrix(matrix.a, matrix.b, matrix.c, matrix.d, matrix.x, matrix.y);
}

float Page::getLineWidth() const {
    return HPDF_Page_GetLineWidth(__innerContent);
}

LineCap Page::getLineCap() const {
    switch (HPDF_Page_GetLineCap(__innerContent)) {
        case HPDF_BUTT_END: return LineCap::BUTT_END;
        case HPDF_ROUND_END: return LineCap::ROUND_END;
        case HPDF_PROJECTING_SQUARE_END: return LineCap::PROJECTING_SQUARE_END;
        default: return LineCap::LINECAP_EOF;
    }
}

LineJoin Page::getLineJoin() const {
    switch (HPDF_Page_GetLineJoin(__innerContent)) {
        case HPDF_MITER_JOIN: return LineJoin::MITER_JOIN;
        case HPDF_ROUND_JOIN: return LineJoin::ROUND_JOIN;
        case HPDF_BEVEL_JOIN: return LineJoin::BEVEL_JOIN;
        default: return LineJoin::LINEJOIN_EOF;
    }
}

float Page::getMiterLimit() const {
    return HPDF_Page_GetMiterLimit(__innerContent);
}

DashMode Page::getDash() const {
    HPDF_DashMode mode = HPDF_Page_GetDash(__innerContent);
    DashMode dashMode;
    dashMode.points = __vectorFromValues(mode.num_ptn, mode.ptn);
    dashMode.phase = mode.phase;
    return dashMode;
}

float Page::getFlatness() const {
    return HPDF_Page_GetFlat(__innerContent);
}

float Page::getCharSpace() const {
    return HPDF_Page_GetCharSpace(__innerContent);
}

float Page::getWordSpace() const {
    return HPDF_Page_GetWordSpace(__innerContent);
}

float Page::getHorizontalScalling() const {
    return HPDF_Page_GetHorizontalScalling(__innerContent);
}

float Page::getTextLeading() const {
    return HPDF_Page_GetTextLeading(__innerContent);
}

TextRenderingMode Page::getTextRenderingMode() const {
    switch (HPDF_Page_GetTextRenderingMode(__innerContent)) {
        case HPDF_FILL: return TextRenderingMode::FILL;
        case HPDF_STROKE: return TextRenderingMode::STROKE;
        case HPDF_FILL_THEN_STROKE: return TextRenderingMode::FILL_THEN_STROKE;
        case HPDF_INVISIBLE: return TextRenderingMode::INVISIBLE;
        case HPDF_FILL_CLIPPING: return TextRenderingMode::FILL_CLIPPING;
        case HPDF_STROKE_CLIPPING: return TextRenderingMode::STROKE_CLIPPING;
        case HPDF_FILL_STROKE_CLIPPING: return TextRenderingMode::FILL_STROKE_CLIPPING;
        case HPDF_CLIPPING: return TextRenderingMode::CLIPPING;
        default: return TextRenderingMode::EOF_MODE;
    }
}

float Page::getTextRise() const {
    return HPDF_Page_GetTextRise(__innerContent);
}

RGBColor Page::getRGBFill() const {
    HPDF_RGBColor color = HPDF_Page_GetRGBFill(__innerContent);
    return RGBColor(color.r, color.g, color.b);
}

RGBColor Page::getRGBStroke() const {
    HPDF_RGBColor color = HPDF_Page_GetRGBStroke(__innerContent);
    return RGBColor(color.r, color.g, color.b);
}

CMYKColor Page::getCMYKFill() const {
    HPDF_CMYKColor color = HPDF_Page_GetCMYKFill(__innerContent);
    return CMYKColor(color.c, color.m, color.y, color.k);
}

CMYKColor Page::getCMYKStroke() const {
    HPDF_CMYKColor color = HPDF_Page_GetCMYKStroke(__innerContent);
    return CMYKColor(color.c, color.m, color.y, color.k);
}

float Page::getGrayFill() const {
    return HPDF_Page_GetGrayFill(__innerContent);
}

float Page::getGrayStroke() const {
    return HPDF_Page_GetGrayStroke(__innerContent);
}

ColorSpace Page::getStrokingColorSpace() const {
    return convertToColorSpace(HPDF_Page_GetStrokingColorSpace(__innerContent));
}

ColorSpace Page::getFillingColorSpace() const {
    return convertToColorSpace(HPDF_Page_GetFillingColorSpace(__innerContent));
}

TransposeMatrix Page::getTextMatrix() const {
    HPDF_TransMatrix matrix = HPDF_Page_GetTextMatrix(__innerContent);
    return TransposeMatrix(matrix.a, matrix.b, matrix.c, matrix.d, matrix.x, matrix.y);
}

unsigned int Page::getGStateDepth() const {
    return HPDF_Page_GetGStateDepth(__innerContent);
}

void Page::setSlideShow(TransitionStyle type, float dispTime, float transTime) {
    HPDF_Page_SetSlideShow(__innerContent, (HPDF_TransitionStyle) type, dispTime, transTime);
}

void Page::newContentStream(const ContentStream& newStream) {
    HPDF_Page_New_Content_Stream(__innerContent, &newStream.__innerContent);
}

void Page::insertSharedContentStream(const ContentStream& sharedStream) {
    HPDF_Page_Insert_Shared_Content_Stream(__innerContent, sharedStream.__innerContent);
}

void Page::arc(const Coor2D& coors, float radius, float ang1, float ang2) {
    HPDF_Page_Arc(__innerContent, coors.getX(), coors.getY(), radius, ang1, ang2);
}

void Page::beginText() {
    HPDF_Page_BeginText(__innerContent);
}

void Page::circle(const Coor2D& coors, float radius) {
    HPDF_Page_Circle(__innerContent, coors.getX(), coors.getY(), radius);
}

void Page::clip() {
    HPDF_Page_Clip(__innerContent);
}

void Page::closePath() {
    HPDF_Page_ClosePath(__innerContent);
}

void Page::closePathStroke() {
    HPDF_Page_ClosePathStroke(__innerContent);
}

void Page::closePathEofillStroke() {
    HPDF_Page_ClosePathEofillStroke(__innerContent);
}

void Page::closePathFillStroke() {
    HPDF_Page_ClosePathFillStroke(__innerContent);
}

void Page::concat(const TransposeMatrix& matrix) {
    HPDF_Page_Concat(__innerContent, matrix.getA(), matrix.getB(), matrix.getC(), matrix.getD(), matrix.getX(), matrix.getY());
}

void Page::curveTo(float x1, float y1, float x2, float y2, float x3, float y3) {
    HPDF_Page_CurveTo(__innerContent, x1, y1, x2, y2, x3, y3);
}

void Page::curveTo2(float x2, float y2, float x3, float y3) {
    HPDF_Page_CurveTo2(__innerContent, x2, y2, x3, y3);
}

void Page::curveTo3(float x1, float y1, float x3, float y3) {
    HPDF_Page_CurveTo3(__innerContent, x1, y1, x3, y3);
}

void Page::drawImage(const Image& image, const Coor2D& coors, float width, float height) {
    HPDF_Page_DrawImage(__innerContent, image.__innerContent, coors.getX(), coors.getY(), width, height);
}

void Page::ellipse(const Coor2D& coors, float xRadius, float yRadius) {
    HPDF_Page_Ellipse(__innerContent, coors.getX(), coors.getY(), xRadius, yRadius);
}

void Page::endPath() {
    HPDF_Page_EndPath(__innerContent);
}

void Page::endText() {
    HPDF_Page_EndText(__innerContent);
}

void Page::eoClip() {
    HPDF_Page_Eoclip(__innerContent);
}

void Page::eoFill() {
    HPDF_Page_Eofill(__innerContent);
}

void Page::eoFillStroke() {
    HPDF_Page_EofillStroke(__innerContent);
}

void Page::executeContentStream(const ContentStream& stream) {
    HPDF_Page_ExecuteXObject(__innerContent, stream.__innerContent);
}

void Page::fill() {
    HPDF_Page_Fill(__innerContent);
}

void Page::fillStroke() {
    HPDF_Page_FillStroke(__innerContent);
}

void Page::gRestore() {
    HPDF_Page_GRestore(__innerContent);
}

void Page::gSave() {
    HPDF_Page_GSave(__innerContent);
}

void Page::lineTo(const Coor2D& coors) {
    HPDF_Page_LineTo(__innerContent, coors.getX(), coors.getY());
}

void Page::moveTextPos(const Coor2D& coors) {
    HPDF_Page_MoveTextPos(__innerContent, coors.getX(), coors.getY());
}

void Page::moveTextPos2(const Coor2D& coors) {
    HPDF_Page_MoveTextPos2(__innerContent, coors.getX(), coors.getY());
}

void Page::moveTo(const Coor2D& coors) {
    HPDF_Page_MoveTo(__innerContent, coors.getX(), coors.getY());
}

void Page::moveToNextLine() {
    HPDF_Page_MoveToNextLine(__innerContent);
}

void Page::rectangle(float x, float y, float width, float height) {
    HPDF_Page_Rectangle(__innerContent, x, y, width, height);
}

void Page::setCharSpace(float value) {
    HPDF_Page_SetCharSpace(__innerContent, value);
}

void Page::setCMYKFill(const CMYKColor& color) {
    HPDF_Page_SetCMYKFill(__innerContent, color.getC(), color.getM(), color.getY(), color.getK());
}

void Page::setCMYKStroke(const CMYKColor& color) {
    HPDF_Page_SetCMYKStroke(__innerContent, color.getC(), color.getM(), color.getY(), color.getK());
}

void Page::setDash(const DashMode& mode) {
    std::vector<float> points = mode.getPoints();
    HPDF_Page_SetDash(__innerContent, points.data(), points.size(), mode.getPhase());
}

void Page::setExternGState(const ContentStream& stream) {
    HPDF_Page_SetExtGState(__innerContent, stream.__innerContent);
}

void Page::setFontAndSize(const Font& font, float size) {
    HPDF_Page_SetFontAndSize(__innerContent, font.__innerContent, size);
}

void Page::setGrayFill(float gray) {
    HPDF_Page_SetGrayFill(__innerContent, gray);
}

void Page::setGrayStroke(float gray) {
    HPDF_Page_SetGrayStroke(__innerContent, gray);
}

void Page::setHorizontalScalling(float value) {
    HPDF_Page_SetHorizontalScalling(__innerContent, value);
}

void Page::setLineCap(LineCap lineCap) {
    HPDF_Page_SetLineCap(__innerContent, (HPDF_LineCap) lineCap);
}

void Page::setLineJoin(LineJoin lineJoin) {
    HPDF_Page_SetLineJoin(__innerContent, (HPDF_LineJoin) lineJoin);
}

void Page::setLineWidth(float lineWidth) {
    HPDF_Page_SetLineWidth(__innerContent, lineWidth);
}

void Page::setMiterLimit(float miterLimit) {
    HPDF_Page_SetMiterLimit(__innerContent, miterLimit);
}

void Page::setRGBFill(const RGBColor& color) {
    HPDF_Page_SetRGBFill(__innerContent, color.getR(), color.getG(), color.getB());
}

void Page::setRGBStroke(const RGBColor& color) {
    HPDF_Page_SetRGBStroke(__innerContent, color.getR(), color.getG(), color.getB());
}

void Page::setTextLeading(float value) {
    HPDF_Page_SetTextLeading(__innerContent, value);
}

void Page::setTextMatrix(const TransposeMatrix& matrix) {
    HPDF_Page_SetTextMatrix(__innerContent, matrix.getA(), matrix.getB(), matrix.getC(), matrix.getD(), matrix.getX(), matrix.getY());
}

void Page::setTextRenderingMode(TextRenderingMode mode) {
    HPDF_Page_SetTextRenderingMode(__innerContent, (HPDF_TextRenderingMode) mode);
}

void Page::setTextRise(float value) {
    HPDF_Page_SetTextRise(__innerContent, value);
}

void Page::setWordSpace(float value) {
    HPDF_Page_SetWordSpace(__innerContent, value);
}

void Page::showText(const std::string& text) {
    HPDF_Page_ShowText(__innerContent, text.c_str());
}

void Page::showTextNewLine(const std::string& text) {
    HPDF_Page_ShowTextNextLine(__innerContent, text.c_str());
}

void Page::showTextNewLine(float wordSpace, float charSpace, const std::string& text) {
    HPDF_Page_ShowTextNextLineEx(__innerContent, wordSpace, charSpace, text.c_str());
}

void Page::stroke() {
    HPDF_Page_Stroke(__innerContent);
}

void Page::textOut(const std::string& text, const Coor2D& position) {
    HPDF_Page_TextOut(__innerContent, position.getX(), position.getY(), text.c_str());
}

void Page::textOut(const std::string& text) {
    textOut(text, getCurrentTextPos());
}

unsigned int Page::textRect(const Box& box, const std::string& text, TextAlignment alignment) {
    unsigned int length;
    HPDF_Page_TextRect(
        __innerContent, box.getLeft(), box.getTop(), box.getRight(), box.getBottom(),
        text.c_str(), (HPDF_TextAlignment) alignment, &length
    );
    return length;
}

void Page::writeText(const std::string& text, const Coor2D& position) {
    beginText();
    textOut(text, position);
    endText();
}

void Page::writeText(const std::string& text) {
    writeText(text, getCurrentTextPos());
}
