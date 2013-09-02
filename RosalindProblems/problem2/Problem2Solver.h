#pragma once

#include <string>
#include <memory>
#include <cstdlib>

#include "..\shared\ISolver.h"

class Problem2Solver : public ISolver
{
public:
    Problem2Solver();
    ~Problem2Solver();
    bool solve();
    std::string getName();
};