#include "../include/Image.hpp"
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

const char* Image::getColorSpace() const {
    return HPDF_Image_GetColorSpace(innerContent);
}

void Image::setColorMask(int8 rmin, int8 rmax, int8 gmin, int8 gmax, int8 bmin, int8 bmax) {
    HPDF_Image_SetColorMask(innerContent, rmin, rmax, gmin, gmax, bmin, bmax);
}

void Image::setMaskImage(const Image& image) {
    HPDF_Image_SetMaskImage(innerContent, image.innerContent);
}
