#ifndef TP_1_ALGORITMOS_TP1_AYE_H
#define TP_1_ALGORITMOS_TP1_AYE_H
#include "Lectura_Archivo.h"
#include "Declaration.h"
#include "Salto.h"
#include "Show.h"
#include "Assign.h"
#include "CharStack.h"
#include "IntStack.h"
#include "Lista_String_PPL.h"
#include "Condicional.h"

class TP1_AyE : public Instruccion{
private:
public:
    TP1_AyE();
    void ejecutar();
    int identificar_instruccion(string);
    VarList *lista_variables = new VarList();
    Lista_String_PPL* lista_alverre(Lista_String_PPL*);

private:

};


#endif //TP_1_ALGORITMOS_TP1_AYE_H
