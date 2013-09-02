#include "FileReader.h"

FileReader::FileReader(std::string filename)
{
    try
    {
        inStream_ = std::unique_ptr<std::ifstream>(new std::ifstream(filename));

        // Throw exception if file couldn't be open.
        if(!inStream_->is_open())
            throw std::exception();

        // Calculate file size.
        inStream_->seekg(0, inStream_->end);
        fileSize_ = inStream_->tellg();
        inStream_->seekg(0);
    }
    catch(std::exception&)
    {
        fileSize_ = 0;
    }
}

FileReader::~FileReader(void)
{
    if(inStream_->is_open())
        inStream_->close();
}

bool FileReader::isFileOpen()
{
    return inStream_->is_open();
}

bool FileReader::isEof()
{
    return inStream_->eof();
}

long long FileReader::getFileSize()
{
    return fileSize_;
}

void FileReader::closeFile()
{
    if(inStream_->is_open())
        inStream_->close();
}

void FileReader::rewindFile()
{
    if(inStream_->is_open())
        inStream_->seekg(0);
}

long long FileReader::read(char * buffer, long long nBytes)
{
    if(inStream_->is_open() && !inStream_->eof())
    {
        inStream_->read(buffer, nBytes);
        return inStream_->gcount();
    }
    else
        return 0;
}