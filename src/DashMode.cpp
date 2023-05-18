#include "../include/DashMode.hpp"
#include "../include/PdfException.hpp"
using namespace pdf;


DashMode::DashMode() noexcept {}

DashMode::DashMode(const std::vector<float>& values, float phase): phase(values.empty()? 0.f: phase) {
    if (values.size() > MAX_DASH_MODE_LENGTH)
        throw except::PageModeOutOfRangeException("Values length exceed MAX_DASH_MODE_LENGTH.", 0x1070, values.size());
    points = values;
}

std::vector<float> DashMode::getPoints() const noexcept {
    return points;
}

float DashMode::getPhase() const noexcept {
    return phase;
}

bool DashMode::isEmpty() const noexcept {
    return false;
}
