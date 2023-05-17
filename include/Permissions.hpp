#ifndef __HARUPP_PERMISSIONS_HPP__
#define __HARUPP_PERMISSIONS_HPP__
#include "PdfObject.hpp"

namespace pdf {

    /**
     * \class   Permissions
     * @brief   Represents a set of permissions for a pdf document.
     * @details The read permission is always included.
     * @file    Permissions.hpp
     * @author  Nicolas Almerge
     * @date    2023-05-16
    */
    class Permissions final: public PdfObject {
        unsigned int value = 0UL;
        explicit Permissions(unsigned int v);
        friend class PdfDocument;

    public:

        /**
         * @brief   Creates a new read-only Permissions.
         * @details This is equivalent to `Permissions(false, false, false, false)` and Permissions::READ_ONLY.
        */
        Permissions() noexcept;

        /**
         * @brief Creates new Permissions with the given values.
         * @param canPrint Whether the user can print the document.
         * @param canEditContent Whether the user can edit the content of the document.
         * @param canCopy Whether the user can copy the document.
         * @param canEditAnnotations Whether the user can edit annotations.
        */
        Permissions(bool canPrint, bool canEditContent, bool canCopy, bool canEditAnnotations) noexcept;

        /**
         * @brief  Creates new Permissions by combining two permission sets.
         * @note   Overlapping permissions are allowed. Hence, Permissions::ALL + Permissions::PRINT is equal to Permissions::ALL.
         * @param  other Permissions to use for concatenation.
         * @return Concatenated Permissions.
        */
        Permissions operator +(const Permissions& other) const noexcept;

        /**
         * @brief   Creates new Permissions by taking the difference of two permission sets.
         * @details The read permissions will always be included in the result.
         * @note    This also works if subtracting permissions only included in `other`. Hence, Permissions::EDIT_CONTENT - Permissions::ALL works and is equal to Permissions::READ_ONLY.
         * @param   other Permissions to use for difference.
         * @return  Difference of Permissions.
        */
        Permissions operator -(const Permissions& other) const noexcept;

        /**
         * @brief   Checks whether two Permissions are equal.
         * @return `true` if the Permissions are equal, `false` otherwise.
        */
        bool operator ==(const Permissions& other) const noexcept;

        /**
         * @brief   Checks whether two Permissions are not equal.
         * @details This is equivalent to `!operator==(other)`.
         * @return `true` if the Permissions are not equal, `false` otherwise.
        */
        bool operator !=(const Permissions& other) const noexcept;

        /**
         * @brief Checks whether the Permissions only contain the read permission.
         * @return `true` if only the read permission is included, `false` otherwise.
        */
        bool isEmpty() const noexcept override;

        /// Read-only permissions.
        const static Permissions READ_ONLY;
        /// Read and print permissions.
        const static Permissions PRINT;
        /// Read and edit content permissions.
        const static Permissions EDIT_CONTENT;
        /// Read and copy permissions.
        const static Permissions COPY;
        /// Read and edit annotations permissions.
        const static Permissions EDIT_ANNOTATIONS;
        /// Read, edit content and edit annotations permissions.
        const static Permissions EDIT_ALL;
        /// All permissions.
        const static Permissions ALL;
    };
}

#endif // __HARUPP_PERMISSIONS_HPP__
