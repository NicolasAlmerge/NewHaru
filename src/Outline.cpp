#include "../include/Outline.hpp"
#include "../include/Destination.hpp"
using namespace pdf;


Outline::Outline(const HPDF_Outline outline): ContentStream(outline) {}

void Outline::setOpen(bool opened) {
    HPDF_Outline_SetOpened(innerContent, opened);
}

void Outline::setDestination(const Destination& destination) {
    HPDF_Outline_SetDestination(innerContent, destination.innerContent);
}
