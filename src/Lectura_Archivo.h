#ifndef TP_1_ALGORITMOS_LECTURA_ARCHIVO_H
#define TP_1_ALGORITMOS_LECTURA_ARCHIVO_H

#include "Instruccion.h"
#include "VarList.h"
#include "Lista_String_PPL.h"

#include "string.h"
#include <iostream>
#include <fstream>
using namespace std;

class Lectura_Archivo : public Instruccion {
public:
    Lista_String_PPL *lista_de_variables = new Lista_String_PPL();
    Lectura_Archivo();
    void ejecutar();
    void almacenar_contenido_archivo();
//  Variable lectura_variables(string instruccion);
    char StringToCharArray(string);

private:
    string linea;
    VarList lista_texto;
};


#endif //TP_1_ALGORITMOS_LECTURA_ARCHIVO_H
