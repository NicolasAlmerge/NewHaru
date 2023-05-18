#include "../include/Constants.hpp"
#include "hpdf.h"


std::string pdf::getLibHaruVersion() {
    return HPDF_GetVersion();
}
