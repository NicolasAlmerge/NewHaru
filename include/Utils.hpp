#ifndef __HARUPP_UTILS_HPP__
#define __HARUPP_UTILS_HPP__
#include "string"

/// Represents the Haru++ utilities.
namespace pdf::utils {

    /**
     * @brief  Gets the LibHaru version.
     * @return LibHaru version.
    */
    std::string getLibHaruVersion();

    /**
     * @brief  Gets the Haru++ version.
     * @return Haru++ version.
    */
    std::string getHaruPPVersion();
}

#endif // __HARUPP_UTILS_HPP__
