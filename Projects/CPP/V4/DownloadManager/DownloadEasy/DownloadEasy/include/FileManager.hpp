// include/FileManager.hpp
#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <string>

class FileManager {
public:
    FileManager(const std::string& filePath);
    void writeToFile(const std::string& data);

private:
    std::string filePath;
};

#endif // FILEMANAGER_HPP
