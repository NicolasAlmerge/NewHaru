#include "../include/DashMode.hpp"
#include "../include/PdfException.hpp"
using namespace pdf;


static constexpr unsigned int __haruppMin(unsigned int a, unsigned int b) {
    return (a <= b)? a: b;
}

DashMode DashMode::__from(HPDF_DashMode&& value) {
    DashMode dashMode;
    dashMode.innerContent.num_ptn = __haruppMin(value.num_ptn, MAX_DASH_MODE_LENGTH);
    dashMode.innerContent.phase = value.phase;
    for (unsigned int i = 0; i < dashMode.innerContent.num_ptn; ++i)
        dashMode.innerContent.ptn[i] = value.ptn[i];
    return dashMode;
}

DashMode::DashMode(): DashMode(std::vector<float>()) {}

DashMode::DashMode(const std::vector<float>& values, float phase) {
    if (values.size() > MAX_DASH_MODE_LENGTH)
        throw except::PageModeOutOfRangeException("Values length exceed MAX_DASH_MODE_LENGTH.", 0x1070, values.size());
    innerContent.num_ptn = values.size();
    for (unsigned int i = 0; i < values.size(); ++i) {
        if (values[i] > MAX_DASH_MODE_SIZE) {
            throw except::FloatOutOfRangeException("One element of vector of values exceeds MAX_DASH_MODE_SIZE", 0x1057, values[i]);
        }
        innerContent.ptn[i] = values[i];
    }
    innerContent.phase = values.empty()? 0.0: phase;
}

std::vector<float> DashMode::getPoints() const {
    const float* points = innerContent.ptn;
    unsigned int numberPoints = innerContent.num_ptn;

    // Create a new vector object
    std::vector<float> vec;
    vec.reserve(numberPoints);

    // Add points one by one
    for (unsigned int i = 0; i < numberPoints; ++i) vec.push_back(points[i]);
    return vec;
}

float DashMode::getPhase() const noexcept {
    return innerContent.phase;
}

bool DashMode::isEmpty() const noexcept {
    return false;
}
