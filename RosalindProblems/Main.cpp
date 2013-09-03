#include "shared\ISolver.h"
#include "problem1\Problem1Solver.h"
#include "problem2\Problem2Solver.h"
#include "problem3\Problem3Solver.h"
#include "problem4\Problem4Solver.h"
#include "problem5\Problem5Solver.h"

#include <vector>
#include <memory>
#include <cstdlib>

int main()
{
    // Build and fill solver vector.
    std::vector<std::unique_ptr<ISolver>> solvers;
    solvers.push_back(std::unique_ptr<ISolver>(new Problem1Solver()));
    solvers.push_back(std::unique_ptr<ISolver>(new Problem2Solver()));
    solvers.push_back(std::unique_ptr<ISolver>(new Problem3Solver()));
    solvers.push_back(std::unique_ptr<ISolver>(new Problem4Solver()));
    solvers.push_back(std::unique_ptr<ISolver>(new Problem5Solver()));

    // Iterate through all the problems and solve them.
    for(std::vector<std::unique_ptr<ISolver>>::iterator it = solvers.begin(); it != solvers.end(); ++it)
    {
        std::string result = (*it)->solve() ? "EXECUTED" : "FAILED";
        printf("%-10s%20s\n", (*it)->getName().c_str(), result.c_str());
    }
    getchar();
}