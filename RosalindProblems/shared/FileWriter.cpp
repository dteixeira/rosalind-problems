#include "FileWriter.h"

FileWriter::FileWriter(std::string filename)
{
    try
    {
        outStream_ = std::unique_ptr<std::ofstream>(new std::ofstream(filename, std::ios::out | std::ios::trunc));
    }
    catch(std::exception&) {}
}

FileWriter::~FileWriter(void)
{
    if(outStream_->is_open())
        outStream_->close();
}

bool FileWriter::isFileOpen()
{
    return outStream_->is_open();
}

void FileWriter::closeFile()
{
    if(outStream_->is_open())
        outStream_->close();
}

void FileWriter::write(char * buffer, long long nBytes)
{
    if(outStream_->is_open())
        outStream_->write(buffer, nBytes);
}

void FileWriter::writeLine(std::string line)
{
    if(outStream_->is_open())
        *outStream_ << line << std::fflush;
}