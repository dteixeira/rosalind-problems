#include "Problem2Solver.h"

Problem2Solver::Problem2Solver() : ISolver("problem2/")
{
}

Problem2Solver::~Problem2Solver()
{
}

bool Problem2Solver::solve()
{
    if(!reader_->isFileOpen() || !writer_->isFileOpen())
        return false;
    else
    {
        // Read input data.
        int nBytes = static_cast<int>(reader_->getFileSize());
        std::unique_ptr<char[]> buffer(new char[nBytes * sizeof(char)]);
        reader_->read(buffer.get(), nBytes);
        reader_->closeFile();

        for(int i = 0; i < nBytes; ++i)
        {
            if(buffer[i] == 'T' || buffer[i] == 't')
                buffer[i] = 'U';
        }

        // Write answer.
        writer_->write(buffer.get(), nBytes);
        writer_->closeFile();

        return true;
    }
}

std::string Problem2Solver::getName()
{
    return "Problem 2";
}