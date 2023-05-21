#include "../include/DashMode.hpp"
#include "../include/Exception.hpp"
#include "../include/Constants.hpp"
using namespace pdf;


DashMode::DashMode() noexcept {}

DashMode::DashMode(const std::vector<float>& values, float phase): phase(values.empty()? 0.f: phase) {
    if (values.size() > consts::MAX_DASH_MODE_LENGTH)
        throw excepts::FloatValueOutOfRangeException("Values length exceed MAX_DASH_MODE_LENGTH.", values.size());
    for (int i = 0; i < values.size(); ++i) {
        if (values[i] > consts::MAX_DASH_MODE_SIZE)
            throw excepts::FloatValueOutOfRangeException("Value exceed MAX_DASH_MODE_SIZE.", values[i]);
    }
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
