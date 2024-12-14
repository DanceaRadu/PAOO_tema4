#include "FileHandler.hpp"
#include <utility>
#include <stdexcept>

FileHandler::FileHandler(const std::string& name) : fileName(name) {
    file.open(fileName, std::ios::in | std::ios::out | std::ios::app);
    if (!file.is_open()) {
        throw std::ios_base::failure("Failed to open file: " + fileName);
    }
    std::cout << "File opened: " << fileName << std::endl;
}

FileHandler::~FileHandler() {
    if (file.is_open()) {
        file.close();
        std::cout << "File closed: " << fileName << std::endl;
    }
}

FileHandler::FileHandler(FileHandler&& other) noexcept : file(std::move(other.file)), fileName(std::move(other.fileName)) {
    other.fileName.clear(); // Ensure the moved-from object is left in a valid state
    std::cout << "FileHandler moved." << std::endl;
}

FileHandler& FileHandler::operator=(FileHandler&& other) noexcept {
    if (this != &other) {
        if (file.is_open()) {
            file.close();
        }

        file = std::move(other.file);
        fileName = std::move(other.fileName);
        other.fileName.clear();
        std::cout << "FileHandler move-assigned." << std::endl;
    }
    return *this;
}

void FileHandler::write(const std::string& data) {
    if (file.is_open()) {
        file << data << std::endl;
        std::cout << "Data written to file: " << data << std::endl;
    } else {
        throw std::ios_base::failure("File is not open.");
    }
}

void FileHandler::readAll() {
    if (file.is_open()) {
        file.seekg(0);
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.clear();
        file.seekg(0, std::ios::beg);
    } else {
        throw std::ios_base::failure("File is not open.");
    }
}