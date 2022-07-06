#ifndef TP_1_ALGORITMOS_SALTO_H
#define TP_1_ALGORITMOS_SALTO_H

#include "Instruccion.h"
#include "Lista_String_PPL.h"
#include "Instruccion.h"

class Salto{
public:
    Salto();
    Nodo* ejecutar(string instruccion, Lista_String_PPL*,Nodo* czo_lista);
    int numeroDeInstruccion(string instruccion);
};

#endif //TP_1_ALGORITMOS_SALTO_H


