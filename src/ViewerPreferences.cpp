#include "../include/ViewerPreferences.hpp"
using namespace pdf;


ViewerPreferences::ViewerPreferences() noexcept {}

ViewerPreferences::ViewerPreferences(unsigned int v): value(v) {}

ViewerPreferences::ViewerPreferences(
    bool hideToolBar, bool hideMenuBar, bool hideWindowUI,
    bool fitWindow, bool centerWindow, bool noPrintScaling
) noexcept:
    value(
        (hideToolBar << 0) | (hideMenuBar << 1) | (hideWindowUI << 2)
        | (fitWindow << 3) | (centerWindow << 4) | (noPrintScaling << 5)
    ) {}

ViewerPreferences ViewerPreferences::operator +(const ViewerPreferences& other) const noexcept {
    return ViewerPreferences(value | other.value);
}

ViewerPreferences ViewerPreferences::operator -(const ViewerPreferences& other) const noexcept {
    return ViewerPreferences(value & ~other.value);
}

bool ViewerPreferences::operator ==(const ViewerPreferences& other) const noexcept {
    return value == other.value;
}

bool ViewerPreferences::operator !=(const ViewerPreferences& other) const noexcept {
    return !operator==(other);
}

bool ViewerPreferences::isEmpty() const noexcept {
    return value != 0;
}

const ViewerPreferences ViewerPreferences::NONE = ViewerPreferences();
const ViewerPreferences ViewerPreferences::HIDE_TOOLBAR = ViewerPreferences(1 << 0);
const ViewerPreferences ViewerPreferences::HIDE_MENUBAR = ViewerPreferences(1 << 1);
const ViewerPreferences ViewerPreferences::HIDE_WINDOW_UI = ViewerPreferences(1 << 2);
const ViewerPreferences ViewerPreferences::FIT_WINDOW = ViewerPreferences(1 << 3);
const ViewerPreferences ViewerPreferences::CENTER_WINDOW = ViewerPreferences(1 << 4);
const ViewerPreferences ViewerPreferences::NO_PRINT_SCALING = ViewerPreferences(1 << 5);
const ViewerPreferences ViewerPreferences::ALL = ViewerPreferences(
    (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5)
);
