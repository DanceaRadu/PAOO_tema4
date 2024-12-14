#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP

#include <fstream>
#include <string>
#include <iostream>
#include <utility>

class FileHandler {
private:
    std::fstream file;
    std::string fileName;

public:
    explicit FileHandler(const std::string& name);
    ~FileHandler();

    FileHandler(const FileHandler&) = delete;
    FileHandler& operator=(const FileHandler&) = delete;

    FileHandler(FileHandler&& other) noexcept;
    FileHandler& operator=(FileHandler&& other) noexcept;

    void write(const std::string& data);
    void readAll();
};

#endif
