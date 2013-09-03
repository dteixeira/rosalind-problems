#pragma once

#include <string>
#include <memory>
#include <cstdlib>
#include <sstream>
#include <array>
#include <map>
#include <iostream>

#include "..\shared\ISolver.h"

class Problem5Solver : public ISolver
{
private:
    std::unique_ptr<long long[]> monthPairs_;

public:
    Problem5Solver();
    ~Problem5Solver();
    bool solve();
    std::string getName();
};