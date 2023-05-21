#include "../include/Utils.hpp"
#include "hpdf.h"


#define __HARUPP_VERSION "1.0.0"

std::string pdf::utils::getLibHaruVersion() {
    return HPDF_GetVersion();
}

std::string pdf::utils::getHaruPPVersion() {
    return __HARUPP_VERSION;
}
