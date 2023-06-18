# NewHaru

PDF Creation C++ Library, made by [Nicolas Almerge](https://github.com/NicolasAlmerge).

It is based on the C library [LibHaru](https://github.com/libharu/libharu), but provides an easier, cleaner and simpler syntax with object oriented patterns, exception handling and flexibility.

## Usage

```cpp
#include "include/NewHaru.hpp"
#include "iostream"

int main() {
    pdf::Document document;

    // Print 'true' or 'false' instead of '1' and '0' for boolean types
    std::cout << std::boolalpha;

    try {
        // Open the document
        document.open();

        // Get font 'Helvetica'
        pdf::Font font = document.getFont("Helvetica");

        // Add a page at the end of the document
        pdf::Page page = document.addPage();

        // Set the pdf creation date to December 10th, 2002 at 12:15:30 PM
        document.setAttribute(
            pdf::enums::DateTimeAttribute::CREATION_DATE,
            {2000, 12, 10, 12, 15, 30}
        );

        // Set font and size
        page.setFontAndSize(font, 12);

        // Write text at specified positions
        page.writeText("This is a test\n", {50, 50});
        page.writeText("This is a second test\n", {150, 50});

        // Create a new text annotation and set the icon to a help icon
        pdf::TextAnnotation annotation = page.createTextAnnotation(
            "Hi there!", {200, 200, 200, 200}
        );
        annotation.setIcon(pdf::enums::AnnotationIcon::HELP);

        // Save to file
        document.saveToFile("output.pdf");
    } catch (const pdf::excepts::Exception& e) {
        // Print the exception name and description in case one occurred
        std::cout << e.getFullDescription() << std::endl;
    }

    return 0;
}
```
