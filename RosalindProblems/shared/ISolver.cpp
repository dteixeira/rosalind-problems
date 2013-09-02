#include "ISolver.h"

ISolver::ISolver(std::string folder)
{
    reader_ = std::unique_ptr<FileReader>(new FileReader(folder + "input.txt"));
    writer_ = std::unique_ptr<FileWriter>(new FileWriter(folder + "output.txt"));
}

ISolver::~ISolver() 
{
}