#pragma once

#include <string>
#include <fstream>
#include <memory>

class FileReader
{
private:
    std::unique_ptr<std::ifstream> inStream_;
    long long fileSize_;

public:
    FileReader(std::string filename);
    ~FileReader();
    bool isFileOpen();
    bool isEof();
    long long getFileSize();
    void closeFile();
    void rewindFile();
    long long read(char * buffer, long long nBytes);
};