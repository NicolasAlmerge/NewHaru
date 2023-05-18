#ifndef __HARUPP_CONSTANTS_HPP__
#define __HARUPP_CONSTANTS_HPP__
#include "string"

/// Represents the Haru++ constants.
namespace pdf::consts {
    /// Represents the maximum string length allowed.
    extern const unsigned int MAX_STRING_LEN;
    /// Represents the maximum number of indirect objects in a pdf file.
    extern const unsigned int MAX_DICT_ELEMENT;
    /// Represents the maximum G state.
    extern const unsigned int MAX_GSTATE;
    /// Represents the maximum length of a dash mode.
    extern const unsigned int MAX_DASH_MODE_LENGTH;
    /// Represents the maximum size of a dash element.
    extern const float MAX_DASH_MODE_SIZE;
}

#endif // __HARUPP_CONSTANTS_HPP__
