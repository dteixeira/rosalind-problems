#pragma once

#include <string>
#include <memory>

#include "FileReader.h"
#include "FileWriter.h"

class ISolver
{
protected:
    std::unique_ptr<FileReader> reader_;
    std::unique_ptr<FileWriter> writer_;
    ISolver(std::string folder);

public:
    virtual ~ISolver();
    virtual bool solve() = 0;
    virtual std::string getName() = 0;
};