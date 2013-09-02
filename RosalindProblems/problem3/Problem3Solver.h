#pragma once

#include <string>
#include <memory>
#include <cstdlib>
#include <map>

#include "..\shared\ISolver.h"

class Problem3Solver : public ISolver
{
private:
    std::map<int, int> complements_;
    void computeComplements();
    void computeComplementsRecursive(int sequence, int complement, int index);
    void solveLargeProblem(char* buffer, int sequences, int size);
    void solveSmallProblem(char* buffer, int index, int size);

public:
    Problem3Solver();
    ~Problem3Solver();
    bool solve();
    std::string getName();
};