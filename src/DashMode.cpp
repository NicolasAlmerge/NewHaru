#include "../include/DashMode.hpp"
#include "../include/PdfException.hpp"
using namespace pdf;


DashMode::DashMode(HPDF_DashMode&& dashMode): innerContent(dashMode) {}

DashMode::DashMode(const std::vector<float>& values, float phase) {
    if (values.size() > MAX_DASH_MODE_LENGTH)
        throw ArrayCountException("Given vector exceeds max array length of 8", 0x1001, 0UL);

    // Set attributes
    innerContent.num_ptn = values.size();
    for (unsigned int i = 0; i < values.size(); ++i) innerContent.ptn[i] = values[i];
    innerContent.phase = phase;
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
