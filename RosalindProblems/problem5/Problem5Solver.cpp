#include "Problem5Solver.h"

Problem5Solver::Problem5Solver() : ISolver("problem5/")
{
}

Problem5Solver::~Problem5Solver()
{
}

bool Problem5Solver::solve()
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
        char * token = strtok(buffer.get(), "\n");
        std::string last = "";
        double total;
        std::map<std::string, double> results;
        while(token != NULL)
        {
            // Start of a new set of values.
            if(token[0] == '>')
            {
                if(last != "")
                {
                    results[last] /= total;
                }
                last = std::string(token);
                results[last] = 0;
                total = 0;
            }
            else
            {
                while(token[0] != '\0')
                {
                    if(token[0] == 'C' || token[0] == 'G')
                    {
                        ++results[last];
                        ++total;
                    }
                    else if(token[0] == 'A' || token[0] == 'T')
                    {
                        ++total;
                    }
                    ++token;
                }
            }
            token = strtok(NULL, "\n");
        }
        results[last] /= total;

        
        for(std::map<std::string, double>::iterator it = results.begin(); it != results.end(); ++it)
        {
            if(results[last] < results[it->first])
            {
                last = it->first;
            }
        }

        // Write answer.
        std::stringstream sstream;
        sstream << last << std::endl << results[last] * 100.0;
        writer_->writeLine(sstream.str());
        writer_->closeFile();

        return true;
    }
}

std::string Problem5Solver::getName()
{
    return "Problem 5";
}