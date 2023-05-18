#include "../include/Utils.hpp"
#include "hpdf.h"


std::string pdf::utils::getLibHaruVersion() {
    return HPDF_GetVersion();
}
