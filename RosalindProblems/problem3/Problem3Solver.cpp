#include "Problem3Solver.h"

Problem3Solver::Problem3Solver() : ISolver("problem3/")
{
}

Problem3Solver::~Problem3Solver()
{
}

void Problem3Solver::computeComplements()
{
    complements_['A'] = 'T';
    complements_['C'] = 'G';
    complements_['G'] = 'C';
    complements_['T'] = 'A';
    computeComplementsRecursive('A', 'T' << 24, 0);
    computeComplementsRecursive('C', 'G' << 24, 0);
    computeComplementsRecursive('G', 'C' << 24, 0);
    computeComplementsRecursive('T', 'A' << 24, 0);
}

void Problem3Solver::computeComplementsRecursive(int sequence, int complement, int index)
{
    // Termination state, 4 byte sequences produced.
    if(index > 3)
    {
        complements_[sequence] = complement;
    }
    else
    {
        ++index;
        sequence = sequence << 8;
        complement = complement >> 8;
        computeComplementsRecursive(sequence | 'A', complement | ('T' << 24), index);
        computeComplementsRecursive(sequence | 'C', complement | ('G' << 24), index);
        computeComplementsRecursive(sequence | 'G', complement | ('C' << 24), index);
        computeComplementsRecursive(sequence | 'T', complement | ('A' << 24), index);
    }
}

void Problem3Solver::solveLargeProblem(char* buffer, int sequences, int size)
{
    int index = 0;
    int complementIndex = size - 4;
    for(int i = 0; i < sequences / 2; ++i)
    {
        // Swaps the positions of the values.
        int* a = reinterpret_cast<int*>(&buffer[index]);
        int* b = reinterpret_cast<int*>(&buffer[complementIndex]);
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
        char* a1 = reinterpret_cast<char*>(a);
        char* b1 = reinterpret_cast<char*>(b);

        // Transforms each value in its complement.
        *a = complements_[*a];
        *b = complements_[*b];
        index += 4;
        complementIndex -= 4;
    }

    solveSmallProblem(buffer, sequences * 2, size);
}

void Problem3Solver::solveSmallProblem(char* buffer, int index, int size)
{
    int complementIndex = size - 1 - index;

    while(complementIndex > index)
    {
        // Swaps the positions of the values.
        buffer[index] ^= buffer[complementIndex];
        buffer[complementIndex] ^= buffer[index];
        buffer[index] ^= buffer[complementIndex];

        // Transforms each value in its complement.
        buffer[index] = complements_[buffer[index]];
        buffer[complementIndex] = complements_[buffer[complementIndex]];
        ++index;
        --complementIndex;
    }

    // This solves the case of single complement, for odd lenght strings.
    // It is done outside the loop to prevent if from being checked on
    // every iteration, being only checked once in this manner.
    if(complementIndex == index)
    {
        buffer[index] = complements_[buffer[index]];
    }
}

bool Problem3Solver::solve()
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

        // Here the problem is forked into two different algorithms.
        // Small problems will be solved using a byte by byte sequential conversion,
        // while large problems (with at least 8 bytes) will be solved using a pre
        // computed complements map. 
        // The threshold for the distinction will actually be 8 bytes for the purposes 
        // of this exercise, although this method only shows performance improvements 
        // over the regular convertion above 256 bytes.
        computeComplements();
        int sequences = nBytes / 4;
        if(sequences < 2)
            solveSmallProblem(buffer.get(), 0, nBytes);
        else
            solveLargeProblem(buffer.get(), sequences, nBytes);

        // Write answer.
        writer_->write(buffer.get(), nBytes);
        writer_->closeFile();

        return true;
    }
}

std::string Problem3Solver::getName()
{
    return "Problem 3";
}