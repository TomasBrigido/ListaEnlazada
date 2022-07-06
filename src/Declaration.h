#ifndef TP_1_ALGORITMOS_DECLARATION_H
#define TP_1_ALGORITMOS_DECLARATION_H


#pragma once

#include <iostream>
#include "VarList.h"

#define cout std::cout
#define cin std::cin
#define endl std::endl
#define string std::string

class Declaration{

private:
    string instruction;
    VarList* list;
public:
    Declaration(string Instruction, VarList* list);
    void ejecutar();
};

#endif //TP_1_ALGORITMOS_DECLARATION_H
