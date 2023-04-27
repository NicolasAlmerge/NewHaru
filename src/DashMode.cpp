#include "../include/DashMode.hpp"
using namespace pdf;


DashMode::DashMode(HPDF_DashMode&& dashMode): innerContent(dashMode) {}

float* DashMode::getPtn() const {
    return (float*) innerContent.ptn;
}

unsigned int DashMode::getNumberPtn() const {
    return innerContent.num_ptn;
}

unsigned int DashMode::getPhase() const {
    return innerContent.phase;
}

void DashMode::setPtn(unsigned short value[8]) {
    for (unsigned short i = 0; i < 8; ++i) {
        innerContent.ptn[i] = value[i];
    }
}

void DashMode::setNumberPtn(unsigned int value) {
    innerContent.num_ptn = value;
}

void DashMode::setPhase(unsigned int value) {
    innerContent.phase = value;
}
