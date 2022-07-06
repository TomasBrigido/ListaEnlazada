#include "Nodo.h"
Nodo::Nodo(string lineaLeida) {
    this->lineaLeida = lineaLeida;
    Next = NULL;
}

string Nodo::get_ContenidoNodo() {return lineaLeida;}

Nodo* Nodo::get_Next() {return Next;}

void Nodo::set_LineaNueva(string lineaLeida) { this->lineaLeida = lineaLeida;}

void Nodo::set_Next(Nodo *Next) {this->Next = Next;}

bool Nodo::get_EsVacio() {return Next == nullptr;} //TODO: CAMBIE EL NULL POR UN NULLPTR
