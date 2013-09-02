#include "Problem4Solver.h"

Problem4Solver::Problem4Solver() : ISolver("problem4/")
{
}

Problem4Solver::~Problem4Solver()
{
}

bool Problem4Solver::solve()
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
        std::stringstream sstream(std::string(buffer.get(), nBytes));
        int nMonths = 0;
        int nPairs = 0;
        sstream >> nMonths >> nPairs;

        // Compute the solution.
        monthPairs_ = std::unique_ptr<long long[]>(new long long[nMonths + 1]);
        std::fill(monthPairs_.get(), monthPairs_.get() + nMonths + 1, 0);
        monthPairs_[1] = 1;
        monthPairs_[2] = 1;
        long long result = fibonacciSolveRecursive(nMonths, nPairs);

        // Write answer.
        std::array<char, 128> toWrite;
        sprintf(toWrite.data(), "%lld", result);
        writer_->write(toWrite.data(), strlen(toWrite.data()));
        writer_->closeFile();

        return true;
    }
}

long long Problem4Solver::fibonacciSolveRecursive(int nMonths, int& nPairs)
{
    if(!monthPairs_[nMonths])
    {
        if(!monthPairs_[nMonths - 1])
            monthPairs_[nMonths - 1] = fibonacciSolveRecursive(nMonths - 1, nPairs);
        if(!monthPairs_[nMonths - 2])
            monthPairs_[nMonths - 2] = fibonacciSolveRecursive(nMonths - 2, nPairs);
        monthPairs_[nMonths] = monthPairs_[nMonths - 1] + monthPairs_[nMonths - 2] * nPairs;
    }
    return monthPairs_[nMonths];
}

std::string Problem4Solver::getName()
{
    return "Problem 4";
}