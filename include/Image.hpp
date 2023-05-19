#pragma once
#include "Coor2D.hpp"
#include "ContentStream.hpp"
#include "Enums.hpp"
#include "Typedefs.hpp"

namespace pdf {

    /**
     * \class  Image
     * @brief  Represents an image.
     * @note   Note that this class cannot be instantiated manually. Rather, it is created when calling
     *         Document::loadJPEGImageFromFile, Document::loadJPEGImageFromMemory,
     *         Document::loadPartialPNGImageFromFile,
     *         Document::loadPNGImageFromFile, Document::loadPNGImageFromMemory,
     *         Document::loadRawImageFromFile and Document::loadRawImageFromMemory.
     * @file   Image.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class Image final: public ContentStream {
        explicit Image(_HPDF_Dict_Rec* content) noexcept;
        friend class Document;

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
        enums::ColorSpace getColorSpace() const;

        /**
         * @brief Sets the image color mask.
         * @param rmin Lower limit of red.
         * @param rmax Upper limit of red.
         * @param gmin Lower limit of green.
         * @param gmax Upper limit of green.
         * @param bmin Lower limit of blue.
         * @param bmax Upper limit of blue.
        */
        void setColorMask(
            types::uint8 rmin, types::uint8 rmax,
            types::uint8 gmin, types::uint8 gmax,
            types::uint8 bmin, types::uint8 bmax
        );

        /**
         * @brief Sets a mask from an Image.
         * @param image The image to use.
        */
        void setMaskImage(const Image& image);
    };
}
