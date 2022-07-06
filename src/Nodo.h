#ifndef TP_1_ALGORITMOS_NODO_H
#define TP_1_ALGORITMOS_NODO_H

#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

class Nodo{
private:
    string lineaLeida;
    Nodo* Next;

public:
    Nodo(){lineaLeida = ""; Next = NULL;};
    Nodo(string lineaLeida);

    //Getter
    string get_ContenidoNodo(); //Devuelve el contenido del nodo
    Nodo* get_Next(); //Devuelve la cabeza del nodo
    bool get_EsVacio(); //Devuelve true si la cabeza es NULL

    //Setter
    void set_LineaNueva(string linea_leida);
    void set_Next(Nodo* Next);
};

#endif //TP_1_ALGORITMOS_NODO_H
