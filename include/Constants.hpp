#ifndef __HARUPP_CONSTANTS_HPP__
#define __HARUPP_CONSTANTS_HPP__
#include "string"

/// Represents the Haru++ constants.
namespace pdf::consts {
    /**
     * @brief   Represents the maximum string length allowed.
     * @details This is used internally by LibHaru.
    */
    extern const unsigned int MAX_STRING_LEN;

    /**
     * @brief   Represents the maximum number of indirect objects in a pdf file.
     * @details This is used internally by LibHaru.
    */
    extern const unsigned int MAX_DICT_ELEMENT;

    /**
     * @brief   Represents the maximum G state.
     * @details This is used internally by LibHaru.
    */
    extern const unsigned int MAX_GSTATE;

    /**
     * @brief   Represents the maximum length of a dash mode.
     * @details This is used when creating a DashMode element.
    */
    extern const unsigned int MAX_DASH_MODE_LENGTH;

    /**
     * @brief   Represents the maximum size of a dash element.
     * @details This is used when creating a DashMode element.
    */
    extern const float MAX_DASH_MODE_SIZE;

    /**
     * @brief   Represents the maximum size for a Font.
     * @details This is used when calling Page::setFontAndSize.
    */
    extern const float MAX_FONT_SIZE;
}

#endif // __HARUPP_CONSTANTS_HPP__
