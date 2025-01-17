#ifndef OPERATOR_H
#define OPERATOR_H

#include <string>
#include "simulator.h"

using Signature = std::string;

class Operator {
    
public:
    Operator() {}
    
    virtual void performance_measuring(Simulator* simu, int rounds) = 0;

protected:
    Operator* baseOp;
    Operator* prevOp;
    Signature signature;
};

// <======================================================>
// MatMul op

class MatMul : public Operator {
public:
    MatMul() {}
    MatMul(OpConfig config): config(config) {}
    
    virtual void performance_measuring(Simulator* simu, int rounds);

private:
    OpConfig config;
};

#endif
