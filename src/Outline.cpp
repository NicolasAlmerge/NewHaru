#include "../include/Outline.hpp"
#include "../include/Destination.hpp"
#include "hpdf.h"
using namespace pdf;


Outline::Outline(_HPDF_Dict_Rec* content) noexcept: ContentStream(content) {}

void Outline::setOpen(bool opened) {
    HPDF_Outline_SetOpened(__innerContent, opened);
}

void Outline::setDestination(const Destination& destination) {
    HPDF_Outline_SetDestination(__innerContent, destination.__innerContent);
}
