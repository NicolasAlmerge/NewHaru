#ifndef __HARUPP_OPENABLECONTENT_HPP__
#define __HARUPP_OPENABLECONTENT_HPP__

namespace pdf {

    /**
     * \class  OpenableContent
     * @brief  Represents an object that can be opened or closed.
     * @file   OpenableContent.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    struct OpenableContent {
        virtual ~OpenableContent() noexcept = 0;

        /**
         * @brief Sets the object initial open / close state.
         * @param open Whether the object should be open (`true`) or closed (`false`) initially.
        */
        virtual void setOpen(bool open) = 0;
    };
}

#endif // __HARUPP_OPENABLECONTENT_HPP__
