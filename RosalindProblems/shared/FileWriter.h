#pragma once

#include <string>
#include <fstream>
#include <memory>

class FileWriter
{
private:
    std::unique_ptr<std::ofstream> outStream_;

public:
    FileWriter(std::string filename);
    ~FileWriter();
    bool isFileOpen();
    void closeFile();
    void write(char * buffer, long long nBytes);
    void writeLine(std::string line);
};