#ifndef TP_1_ALGORITMOS_CHARACTER_H
#define TP_1_ALGORITMOS_CHARACTER_H


#pragma once
class Character{

private:
    char Value;
    Character* next;

public:

    Character(char value);

    //getters
    char get_Value();
    Character* get_next();

    //setters
    void set_Value(char value);
    void set_next(Character* Next);

};


#endif //TP_1_ALGORITMOS_CHARACTER_H
