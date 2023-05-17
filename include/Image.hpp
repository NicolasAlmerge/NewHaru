#pragma once
#include "Coor2D.hpp"
#include "ContentStream.hpp"
#include "Constants.hpp"
#include "PdfObject.hpp"

namespace pdf {

    /**
     * @brief   Represents a 1-byte unsigned integer.
     * @details This can hold values from `0` to `255` included.
    */
    typedef unsigned char uint8;

    /**
     * \class  Image
     * @brief  Represents an image.
     * @note   Note that this class cannot be instantiated manually. Rather, it is created when calling
     *         PdfDocument::loadJPEGImageFromFile, PdfDocument::loadJPEGImageFromMemory,
     *         PdfDocument::loadPartialPNGImageFromFile,
     *         PdfDocument::loadPNGImageFromFile, PdfDocument::loadPNGImageFromMemory,
     *         PdfDocument::loadRawImageFromFile and PdfDocument::loadRawImageFromMemory.
     * @file   Image.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class Image final: public ContentStream {
        explicit Image(const HPDF_Image content);
        friend class PdfDocument;

    public:

        /**
         * @brief  Gets the image size.
         * @return The image size as a Coor2D object.
        */
        Coor2D getSize() const;

        /**
         * @brief  Gets the image width.
         * @return The image width.
        */
        unsigned int getWidth() const;

        /**
         * @brief  Gets the image height.
         * @return The image height.
        */
        unsigned int getHeight() const;

        /**
         * @brief  Gets the number of bits per component.
         * @return Number of bits per component.
        */
        unsigned int getBitsPerComponent() const;

        /**
         * @brief  Gets the image color space.
         * @return The image color space.
        */
        ColorSpace getColorSpace() const;

        /**
         * @brief Sets the image color mask.
         * @param rmin Lower limit of red.
         * @param rmax Upper limit of red.
         * @param gmin Lower limit of green.
         * @param gmax Upper limit of green.
         * @param bmin Lower limit of blue.
         * @param bmax Upper limit of blue.
        */
        void setColorMask(uint8 rmin, uint8 rmax, uint8 gmin, uint8 gmax, uint8 bmin, uint8 bmax);

        /**
         * @brief Sets a mask from an Image.
         * @param image The image to use.
        */
        void setMaskImage(const Image& image);
    };
}
