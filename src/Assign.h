#ifndef TP_1_ALGORITMOS_ASSIGN_H
#define TP_1_ALGORITMOS_ASSIGN_H

#pragma once

#include <iostream>
#include "VarList.h"
#include "CharStack.h"
#include "IntStack.h"

#define cout std::cout
#define cin std::cin
#define endl std::endl
#define string std::string

using namespace std;

class Assign{

private:

    string instruction;
    VarList* list;
    CharStack* stack;
    IntStack* StackInt;

public:
    Assign();

    Assign(string, VarList*, CharStack*,IntStack*);

    void ejecutar(string instruction);

    string to_postfix(string operation, CharStack* stack);

    int HasHigherPrecedence(char op1, char op2);

    bool IsOperator(char C);

    bool IsOperand(char C);

    int IsRightAssociative(char op);

    int GetOperatorWeight(char op);

    int Calculate(string operation, CharStack* stack,VarList* list,IntStack* Stackint);

    int PerformOperation(char operation, int operand1, int operand2);

    bool IsNumericDigit(char C);

    bool IsVariable(char C);
};


#endif //TP_1_ALGORITMOS_ASSIGN_H
