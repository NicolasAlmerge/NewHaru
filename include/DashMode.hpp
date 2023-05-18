#ifndef __HARUPP_DASHMODE_HPP__
#define __HARUPP_DASHMODE_HPP__
#include "PdfObject.hpp"
#include "vector"

namespace pdf {
    /// Represents the maximum length of a dash mode.
    constexpr unsigned int MAX_DASH_MODE_LENGTH = 8UL;
    /// Represents the maximum size of a dash element.
    constexpr float MAX_DASH_MODE_SIZE = 100.f;

    /**
     * \class  DashMode
     * @brief  Represents a dash mode.
     * @file   DashMode.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class DashMode final: public PdfObject {
        std::vector<float> points;
        float phase = 0.f;
        friend class PdfPage;

    public:

        /**
         * @brief   Creates a new default DashMode.
         * @details This is equivalent to `DashMode({})`.
        */
        DashMode() noexcept;

        /**
         * @brief Creates a new DashMode with corresponding values.
         * @param values Point coordinates to use.
         * @param phase  Phase to use. Will be set to `0.0` if no values are set.
         * @throw except::PageModeOutOfRangeException if `values.size() > MAX_DASH_MODE_LENGTH`.
         * @throw except::FloatOutOfRangeException if at least one element of `values` is greater than `MAX_DASH_MODE_SIZE`.
        */
        DashMode(const std::vector<float>& values, float phase = 0.0);

        /**
         * @brief  Gets the vector of points.
         * @return Vector of points.
        */
        std::vector<float> getPoints() const noexcept;

        /**
         * @brief  Gets the phase.
         * @return Mode phase.
        */
        float getPhase() const noexcept;

        /**
         * @brief Always returns `false`.
         * @return `false`
        */
        bool isEmpty() const noexcept override;
    };
}

#endif // __HARUPP_DASHMODE_HPP__
