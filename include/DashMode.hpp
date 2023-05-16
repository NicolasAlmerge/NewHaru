#ifndef __HARUPP_DASHMODE_HPP__
#define __HARUPP_DASHMODE_HPP__
#include "PdfObject.hpp"
#include "hpdf.h"
#include "vector"

namespace pdf {
    /// Represents the maximum length of a dash mode.
    constexpr unsigned int MAX_DASH_MODE_LENGTH = 8UL;

    class DashMode final: public PdfObject {
        HPDF_DashMode innerContent;
        DashMode(HPDF_DashMode&& dashMode);
        friend class PdfPage;

    public:
        DashMode(const std::vector<float>& values = {}, float phase = 0.0);

        std::vector<float> getPoints() const;
        float getPhase() const noexcept;

        bool isEmpty() const noexcept override;
    };
}

#endif // __HARUPP_DASHMODE_HPP__
