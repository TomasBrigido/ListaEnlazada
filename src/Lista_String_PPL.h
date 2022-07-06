#ifndef TP_1_ALGORITMOS_LISTA_STRING_PPL_H
#define TP_1_ALGORITMOS_LISTA_STRING_PPL_H
#include "Nodo.h"

class Lista_String_PPL {
public:
    Lista_String_PPL();

    //Getters
    void add_string(string);
    Nodo* get_ValorPosicionNodo(string);
    string get_content(string); //Retorna el contenido si es que esta en la lista
    Nodo* get_head(); //devuelve la cabeza
    bool get_EstaVacia(); //Devuelve True si es Vacia
    string get_Contenido(); //Devuelve el dato del Nodo
    void set_head(Nodo*); //Setea la cabeza del nodo
    int size(); //Devuelve la cantidad que tiene la lista
    Lista_String_PPL* resto(); //Devuelve un resto de la lista

private:
    Nodo* head;
};


#endif //TP_1_ALGORITMOS_LISTA_STRING_PPL_H
