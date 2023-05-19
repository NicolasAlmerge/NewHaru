#ifndef __HARUPP_VIEWERPREFERENCES_HPP__
#define __HARUPP_VIEWERPREFERENCES_HPP__
#include "Object.hpp"

namespace pdf {

    /**
     * \class   ViewerPreferences
     * @brief   Represents a set of viewer preferences for a pdf document.
     * @file    ViewerPreferences.hpp
     * @author  Nicolas Almerge
     * @date    2023-05-16
    */
    class ViewerPreferences final: public Object {
        unsigned int value = 0UL;
        explicit ViewerPreferences(unsigned int v);
        friend class Document;

    public:

        /**
         * @brief   Creates new empty ViewerPreferences.
         * @details This is equivalent to `ViewerPreferences(false, false, false, false, false, false)` and ViewerPreferences::NONE.
        */
        ViewerPreferences() noexcept;

        /**
         * @brief Creates new ViewerPreferences with the given values.
         * @param hideToolBar Whether to hide the tool bar.
         * @param hideMenuBar Whether to hide the menu bar.
         * @param hideWindowUI Whether to hide the window UI.
         * @param fitWindow Whether to fit the window.
         * @param centerWindow Whether to center the window.
         * @param noPrintScaling Whether to not scale the printing.
        */
        ViewerPreferences(
            bool hideToolBar, bool hideMenuBar, bool hideWindowUI,
            bool fitWindow, bool centerWindow, bool noPrintScaling
        ) noexcept;

        /**
         * @brief  Creates new ViewerPreferences by combining two preference sets.
         * @note   Overlapping preferences are allowed. Hence, ViewerPreferences::ALL + ViewerPreferences::HIDE_MENUBAR is equal to ViewerPreferences::ALL.
         * @param  other ViewerPreferences to use for concatenation.
         * @return Concatenated ViewerPreferences.
        */
        ViewerPreferences operator +(const ViewerPreferences& other) const noexcept;

        /**
         * @brief   Creates new ViewerPreferences by taking the difference of two preference sets.
         * @note    This also works if subtracting preferences only included in `other`. Hence, ViewerPreferences::FIT_WINDOW - ViewerPreferences::ALL works and is equal to ViewerPreferences::NONE.
         * @param   other ViewerPreferences to use for difference.
         * @return  Difference of ViewerPreferences.
        */
        ViewerPreferences operator -(const ViewerPreferences& other) const noexcept;

        /**
         * @brief   Checks whether two ViewerPreferences are equal.
         * @return `true` if the ViewerPreferences are equal, `false` otherwise.
        */
        bool operator ==(const ViewerPreferences& other) const noexcept;

        /**
         * @brief   Checks whether two ViewerPreferences are not equal.
         * @details This is equivalent to `!operator==(other)`.
         * @return `true` if the ViewerPreferences are not equal, `false` otherwise.
        */
        bool operator !=(const ViewerPreferences& other) const noexcept;

        /**
         * @brief  Checks whether the ViewerPreferences contain no preferences.
         * @return `true` if no preferences are present, `false` otherwise.
        */
        bool isEmpty() const noexcept override;

        /// No preference.
        const static ViewerPreferences NONE;
        /// Hide tool bar preference.
        const static ViewerPreferences HIDE_TOOLBAR;
        /// Hide menu bar preference.
        const static ViewerPreferences HIDE_MENUBAR;
        /// Hide window UI preference.
        const static ViewerPreferences HIDE_WINDOW_UI;
        /// Fit window preference.
        const static ViewerPreferences FIT_WINDOW;
        /// Center window preference.
        const static ViewerPreferences CENTER_WINDOW;
        /// No print scaling preference.
        const static ViewerPreferences NO_PRINT_SCALING;
        /// All preferences.
        const static ViewerPreferences ALL;
    };
}

#endif // __HARUPP_VIEWERPREFERENCES_HPP__
