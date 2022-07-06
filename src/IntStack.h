#ifndef TP_1_ALGORITMOS_INTSTACK_H
#define TP_1_ALGORITMOS_INTSTACK_H


#pragma once

#include <iostream>
#include "Integer.h"

#define cout std::cout
#define cin std::cin
#define endl std::endl
#define string std::string

class IntStack{
private:
    Integer* top;

public:
    IntStack();
    void push(int Newint);
    void pop();
    Integer* get_top();
    bool is_empty();
    void print(Integer* stack);
};


#endif //TP_1_ALGORITMOS_INTSTACK_H
