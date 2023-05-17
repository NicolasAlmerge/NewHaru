#ifndef __HARUPP_OUTLINE_HPP__
#define __HARUPP_OUTLINE_HPP__
#include "ContentStream.hpp"
#include "PdfObject.hpp"

namespace pdf {
    class Destination;

    /**
     * \class  Outline
     * @brief  Represents an outline.
     * @file   Outline.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class Outline: public ContentStream {
        explicit Outline(const HPDF_Outline outline);
        friend class PdfDocument;

    public:

        /**
         * @brief Sets the outline initial open / close state.
         * @param open Whether the outline should be open (`true`) or closed (`false`) initially.
        */
        void setOpen(bool opened);

        /**
         * @brief Sets the destination of the outline.
         * @param destination The destination to use.
        */
        void setDestination(const Destination& destination);
    };
}

#endif // __HARUPP_OUTLINE_HPP__
