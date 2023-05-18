#ifndef __HARUPP_PDFOBJECT_HPP__
#define __HARUPP_PDFOBJECT_HPP__

/// Represents the Haru++ namespace.
namespace pdf {

    /**
     * \class  PdfObject
     * @brief  Represents a pdf object.
     * @file   PdfObject.hpp
     * @author Nicolas Almerge
     * @date   2023-05-16
    */
    class PdfObject {
    public:
        virtual ~PdfObject() noexcept = 0;

        /**
         * @brief  Checks whether an object is empty.
         * @return `true` if object is empty, `false` otherwise.
        */
        virtual bool isEmpty() const noexcept = 0;

        /**
         * @brief   Checks whether an object is not empty.
         * @details This is equivalent to: `!isEmpty()`.
         * @return `true` if object is not empty, `false` otherwise.
        */
        virtual operator bool() const noexcept final;
    };
}

#endif // __HARUPP_PDFOBJECT_HPP__
