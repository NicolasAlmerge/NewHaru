#ifndef __HARUPP_COMPRESSIONMODE_HPP__
#define __HARUPP_COMPRESSIONMODE_HPP__
#include "ValueSet.hpp"

namespace pdf {

    /**
     * \class   CompressionMode
     * @brief   Represents a set of compression modes for a pdf document.
     * @file    CompressionMode.hpp
     * @author  Nicolas Almerge
     * @date    2023-05-16
    */
    class CompressionMode final: public ValueSet {
        explicit CompressionMode(unsigned int v);

    public:

        /**
         * @brief   Creates a new empty CompressionMode.
         * @details This is equivalent to `CompressionMode(false, false, false)` and CompressionMode::NONE.
        */
        CompressionMode() noexcept;

        /**
         * @brief Creates new CompressionMode with the given values.
         * @param text Whether to compress text.
         * @param images Whether to compress images.
         * @param metadata Whether to compress metadata (fonts, cmaps, …).
        */
        CompressionMode(bool text, bool images, bool metadata) noexcept;

        /**
         * @brief  Creates new CompressionMode by combining two compression sets.
         * @note   Overlapping compressions are allowed. Hence, CompressionMode::ALL + CompressionMode::TEXT is equal to CompressionMode::ALL.
         * @param  other CompressionMode to use for concatenation.
         * @return Concatenated CompressionMode.
        */
        CompressionMode operator +(const CompressionMode& other) const noexcept;

        /**
         * @brief   Creates new CompressionMode by taking the difference of two compression sets.
         * @note    This also works if subtracting compressions only included in `other`. Hence, CompressionMode::IMAGES - CompressionMode::ALL works and is equal to CompressionMode::NONE.
         * @param   other CompressionMode to use for difference.
         * @return  Difference of CompressionMode.
        */
        CompressionMode operator -(const CompressionMode& other) const noexcept;

        /**
         * @brief   Checks whether two CompressionMode are equal.
         * @return `true` if the CompressionMode are equal, `false` otherwise.
        */
        bool operator ==(const CompressionMode& other) const noexcept;

        /**
         * @brief   Checks whether two CompressionMode are not equal.
         * @details This is equivalent to `!operator==(other)`.
         * @return `true` if the CompressionMode are not equal, `false` otherwise.
        */
        bool operator !=(const CompressionMode& other) const noexcept;

        /// No compression.
        const static CompressionMode NONE;
        /// Only compress text.
        const static CompressionMode TEXT;
        /// Only compress images.
        const static CompressionMode IMAGES;
        /// Only compress metadata (fonts, cmaps, …).
        const static CompressionMode METADATA;
        /// Compress everything.
        const static CompressionMode ALL;
    };
}

#endif // __HARUPP_COMPRESSIONMODE_HPP__
