#include "Variable.h"
Variable::Variable() {}

Variable::Variable(char Name, string Type, int IntValue, Variable* Next) {
    this->Name = Name;
    this->Type = Type;
    this->IntValue = IntValue;
    this->Next = Next;
}

Variable::Variable(char Name, string Type, bool BoolValue, Variable* Next) {

    this->Name = Name;
    this->Type = Type;
    this->BoolValue = BoolValue;
    this->Next = Next;
}

int Variable::get_IntValue() { return IntValue; }
int Variable::get_BoolValue() { return BoolValue; }
char Variable::get_Name() { return Name; }
string Variable::get_Type() {return Type;}
Variable* Variable::get_Next() { return Next; }
bool Variable::esVacia() {return Next == nullptr;}

//setters
void Variable::set_IntValue(int value) { IntValue = value; }
void Variable::set_BoolValue(int value) { BoolValue = value; }
void Variable::set_Name(char name) { Name = name; }
void Variable::set_Next(Variable* Next) { this->Next = Next; }