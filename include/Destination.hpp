#ifndef __HARUPP_DESTINATION_HPP__
#define __HARUPP_DESTINATION_HPP__
#include "Object.hpp"

struct _HPDF_Array_Rec;

namespace pdf {

    /**
     * \class  Destination
     * @brief  Represents a destination.
     * @note   Note that this class cannot be instantiated manually. Rather, it is created when calling Page::createDestination.
     * @file   Destination.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class Destination final: public Object {
        _HPDF_Array_Rec* __innerContent = nullptr;
        explicit Destination(_HPDF_Array_Rec* content) noexcept;
        friend class Outline;
        friend class Document;
        friend class Page;

    public:

        /**
         * @brief   Checks whether a destination has been set.
         * @return `true` if destination is not set, `false` otherwise.
        */
        bool isEmpty() const noexcept override;

        /**
         * @brief Defines the appearance of the page with left, top and zoom values.
         * @param left Left value.
         * @param top Top value.
         * @param zoom Zoom value (must be between `0.08` and `0.32` included).
        */
        void setXYZ(float left, float top, float zoom);

        /**
         * @brief   Sets the appearance of the page to display the entire page.
         * @details The entire page will be shown within the window.
        */
        void setFit();

        /**
         * @brief   Defines the appearance of a page to magnify to fit the width of the page within the window.
         * @details This sets the top position of the page to the value of the parameter.
         * @param   top Top value.
        */
        void setFitH(float top);

        /**
         * @brief   Defines the appearance of a page to magnify to fit the height of the page within the window.
         * @details This sets the top position of the page to the value of the parameter.
         * @param   left Left value.
        */
        void setFitV(float left);

        /**
         * @brief   Defines the appearance of a page to magnify the page to fit a rectangle specified by the parameters.
         * @param   left Left value.
         * @param   bottom Bottom value.
         * @param   right Right value.
         * @param   top Top value.
        */
        void setFitR(float left, float bottom, float right, float top);

        /**
         * @brief   Sets the appearance of the page to magnify to fit the bounding box of the page within the window.
         * @details The top and left positions of the page will be automatically determined.
        */
        void setFitB();

        /**
         * @brief   Defines the appearance of a page to magnify to fit the width of the bounding box of the page within the window.
         * @details This sets the top position of the page to the value of the parameter.
        */
        void setFitBH(float top);

        /**
         * @brief   Defines the appearance of a page to magnify to fit the height of the bounding box of the page within the window.
         * @details This sets the left position of the page to the value of the parameter.
        */
        void setFitBV(float left);
    };
}

#endif // __HARUPP_DESTINATION_HPP__
