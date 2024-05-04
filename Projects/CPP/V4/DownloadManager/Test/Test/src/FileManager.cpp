// src/FileManager.cpp
#include "FileManager.hpp"
#include <fstream>
#include <iostream>


FileManager::FileManager(const std::string& filePath) : filePath(filePath) {}

void FileManager::writeToFile(const std::string& data) {
    std::ofstream file(filePath, std::ios::out | std::ios::app);
    if (file.is_open()) {
        file << data;
        file.close();
    }
    else {
        std::cerr << "Unable to open file: " << filePath << std::endl;
    }
}
