#ifndef TP_1_ALGORITMOS_INSTRUCCION_H
#define TP_1_ALGORITMOS_INSTRUCCION_H

#include <iostream>
#include <fstream>

using namespace std;


class Instruccion {
public:
    Instruccion();

    //Method
    virtual void ejecutar() = 0;

};


#endif //TP_1_ALGORITMOS_INSTRUCCION_H
