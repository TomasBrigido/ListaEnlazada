#include "Character.h"

Character::Character(char Value) { this->Value = Value; next = nullptr;}

//getters
char Character::get_Value() { return Value; }


Character* Character::get_next() { return next; }

//setters
void Character::set_Value(char Value) { this->Value = Value; }
void Character::set_next(Character* next) { this->next = next; }