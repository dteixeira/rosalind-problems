#pragma once

#include <string>
#include <memory>
#include <cstdlib>
#include <sstream>
#include <array>

#include "..\shared\ISolver.h"

class Problem4Solver : public ISolver
{
private:
    std::unique_ptr<long long[]> monthPairs_;

public:
    Problem4Solver();
    ~Problem4Solver();
    bool solve();
    std::string getName();
    long long fibonacciSolveRecursive(int nMonths, int& nPairs);
};