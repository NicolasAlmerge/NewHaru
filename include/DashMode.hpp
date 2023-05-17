#ifndef __HARUPP_DASHMODE_HPP__
#define __HARUPP_DASHMODE_HPP__
#include "PdfObject.hpp"
#include "hpdf.h"
#include "vector"

namespace pdf {
    /// Represents the maximum length of a dash mode.
    constexpr unsigned int MAX_DASH_MODE_LENGTH = 8UL;

    /**
     * \class  DashMode
     * @brief  Represents a dash mode.
     * @file   DashMode.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class DashMode final: public PdfObject {
        HPDF_DashMode innerContent;
        static DashMode __from(HPDF_DashMode&& value);
        friend class PdfPage;

    public:

        /**
         * @brief   Creates a new default DashMode.
         * @details This is equivalent to `DashMode({})`.
        */
        DashMode();

        /**
         * @brief Creates a new DashMode with corresponding values.
         * @param values Point coordinates to use.
         * @param phase  Phase to use. Will be set to `0.0` if no values are set.
        */
        DashMode(const std::vector<float>& values, float phase = 0.0);

        /**
         * @brief  Gets the vector of points.
         * @return Vector of points.
        */
        std::vector<float> getPoints() const;

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
