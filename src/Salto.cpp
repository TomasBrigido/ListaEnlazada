#include "Salto.h"

Salto::Salto() {}

Nodo* Salto::ejecutar(string instruccion, Lista_String_PPL *l,Nodo* czo_lista) {
    int cantidad = numeroDeInstruccion(instruccion);
    Nodo *aux = l->get_head();

    l->set_head(czo_lista);

    if(cantidad > 0 && cantidad <= l->size()) {
        Nodo* czo_nuevo;

        for (int i = 0; i < cantidad; i++) {
            czo_nuevo = l->get_head();
            l = l->resto();
        }
        return czo_nuevo;
    }
    l->set_head(aux);
    cout<< "\nNumero de instruccion invalida";
    return nullptr;
}
int Salto::numeroDeInstruccion(string instruccion){

    int posInit = 0;
    int posFound = 0;
    int splitted;

    while(posFound >= 0){
        posFound = instruccion.find(" ", posInit);
        posInit = posFound + 1;
        posFound = instruccion.find(" ", posInit);
        splitted = stoi(instruccion.substr(posInit,posFound-posInit));

        break;
    }
    return splitted;
}