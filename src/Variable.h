#ifndef TP_1_ALGORITMOS_VARIABLE_H
#define TP_1_ALGORITMOS_VARIABLE_H

#include <iostream>

#define cout std::cout
#define cin std::cin
#define endl std::endl
#define string std::string

using namespace std;

class Variable{
private:
    int IntValue;
    bool BoolValue;
    char Name;
    string Type;
    Variable* Next;

public:
    Variable();
    Variable(char Name, string Type, int IntValue, Variable* Next);
    Variable(char Name, string Type, bool BoolValue, Variable* Next);

    //getters
    int get_IntValue();
    int get_BoolValue();
    char get_Name();
    string get_Type();
    Variable* get_Next();
    bool esVacia();

    //setters
    void set_IntValue(int value);
    void set_BoolValue(int value);
    void set_Name(char name);
    void set_Next(Variable* Next);
};


#endif //TP_1_ALGORITMOS_VARIABLE_H
