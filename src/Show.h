#ifndef TP_1_ALGORITMOS_SHOW_H
#define TP_1_ALGORITMOS_SHOW_H

#include "Instruccion.h"
#include "TP1_AyE.h"
#include "Assign.h"
#include "CharStack.h"

class Show : public Instruccion{
public:
    Show();
    void ejecutar();
    void ejecutar(VarList*, string);
    char StringToCharArray(string);
    void set_string(string);

private:
    string contenidoString;
};

#endif //TP_1_ALGORITMOS_SHOW_H
