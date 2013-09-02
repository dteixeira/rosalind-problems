#include "Problem1Solver.h"

Problem1Solver::Problem1Solver() : ISolver("problem1/")
{
}

Problem1Solver::~Problem1Solver()
{
}

bool Problem1Solver::solve()
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

        // Compute the solution.
        std::unique_ptr<int[]> counters(new int[256]);
        std::fill(counters.get(), counters.get() + 256, 0);
        for(int i = 0; i < nBytes; ++i)
        {
            counters[buffer[i]]++;
        }

        // Write answer.
        std::unique_ptr<char[]> result(new char[32]);
        sprintf(result.get(), "%d %d %d %d\0", 
                counters['A'] + counters['a'],
                counters['C'] + counters['c'],
                counters['G'] + counters['g'],
                counters['T'] + counters['t']);
        writer_->write(result.get(), strlen(result.get()));
        writer_->closeFile();

        return true;
    }
}

std::string Problem1Solver::getName()
{
    return "Problem 1";
}