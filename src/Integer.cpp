#include "Integer.h"

Integer::Integer(int Value) { this->Value = Value; }

//getters
int Integer::get_Value() { return Value; }

Integer* Integer::get_next() { return next; }

//setters
void Integer::set_Value(char Value) { this->Value = Value; }
void Integer::set_next(Integer* next) { this->next = next; }