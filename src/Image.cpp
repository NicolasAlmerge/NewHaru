#include "../include/Image.hpp"
#include "hpdf.h"
#include "string.h"
using namespace pdf;


Image::Image(_HPDF_Dict_Rec* content) noexcept: ContentStream(content) {}

Coor2D Image::getSize() const {
    HPDF_Point point = HPDF_Image_GetSize(__innerContent);
    return Coor2D(point.x, point.y);
}

unsigned int Image::getWidth() const {
    return HPDF_Image_GetWidth(__innerContent);
}

unsigned int Image::getHeight() const {
    return HPDF_Image_GetHeight(__innerContent);
}

unsigned int Image::getBitsPerComponent() const {
    return HPDF_Image_GetBitsPerComponent(__innerContent);
}

ColorSpace Image::getColorSpace() const {
    const char* colorSpace = HPDF_Image_GetColorSpace(__innerContent);
    if (colorSpace == nullptr) return ColorSpace::EOF_COLOR_SPACE;

    if (strcmp(colorSpace, "DeviceGray") == 0) return ColorSpace::DEVICE_GRAY;
    if (strcmp(colorSpace, "DeviceRGB") == 0) return ColorSpace::DEVICE_RGB;
    if (strcmp(colorSpace, "DeviceCMYK") == 0) return ColorSpace::DEVICE_CMYK;
    if (strcmp(colorSpace, "Indexed") == 0) return ColorSpace::INDEXED;
    return ColorSpace::EOF_COLOR_SPACE;
}

void Image::setColorMask(uint8 rmin, uint8 rmax, uint8 gmin, uint8 gmax, uint8 bmin, uint8 bmax) {
    HPDF_Image_SetColorMask(__innerContent, rmin, rmax, gmin, gmax, bmin, bmax);
}

void Image::setMaskImage(const Image& image) {
    HPDF_Image_SetMaskImage(__innerContent, image.__innerContent);
}
