#pragma once

#include <string>
#include <memory>
#include <cstdlib>

#include "..\shared\ISolver.h"

class Problem1Solver : public ISolver
{
public:
    Problem1Solver();
    ~Problem1Solver();
    bool solve();
    std::string getName();
};