#include "FileHandler.hpp"
#include <iostream>

int main() {
    try {
        FileHandler fh1("test.txt");
        fh1.write("Hello, World!");
        fh1.write("PAOO - Item 13 and 14");

        std::cout << "File content:" << std::endl;
        fh1.readAll();

        // Demonstrate move semantics
        FileHandler fh2 = std::move(fh1);
        fh2.write("This is after moving fh1 to fh2.");
        std::cout << "File content after move:" << std::endl;
        fh2.readAll();

    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    return 0;
}