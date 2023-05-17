#include "../include/Image.hpp"
#include "string.h"
using namespace pdf;


Image::Image(const HPDF_Image content): ContentStream(content) {}

Coor2D Image::getSize() const {
    return Coor2D(HPDF_Image_GetSize(innerContent));
}

unsigned int Image::getWidth() const {
    return HPDF_Image_GetWidth(innerContent);
}

unsigned int Image::getHeight() const {
    return HPDF_Image_GetHeight(innerContent);
}

unsigned int Image::getBitsPerComponent() const {
    return HPDF_Image_GetBitsPerComponent(innerContent);
}

ColorSpace Image::getColorSpace() const {
    const char* colorSpace = HPDF_Image_GetColorSpace(innerContent);
    if (colorSpace == nullptr) return ColorSpace::EOF_COLOR_SPACE;

    if (strcmp(colorSpace, "DeviceGray") == 0) return ColorSpace::DEVICE_GRAY;
    if (strcmp(colorSpace, "DeviceRGB") == 0) return ColorSpace::DEVICE_RGB;
    if (strcmp(colorSpace, "DeviceCMYK") == 0) return ColorSpace::DEVICE_CMYK;
    if (strcmp(colorSpace, "Indexed") == 0) return ColorSpace::INDEXED;
    return ColorSpace::EOF_COLOR_SPACE;
}

void Image::setColorMask(uint8 rmin, uint8 rmax, uint8 gmin, uint8 gmax, uint8 bmin, uint8 bmax) {
    HPDF_Image_SetColorMask(innerContent, rmin, rmax, gmin, gmax, bmin, bmax);
}

void Image::setMaskImage(const Image& image) {
    HPDF_Image_SetMaskImage(innerContent, image.innerContent);
}
