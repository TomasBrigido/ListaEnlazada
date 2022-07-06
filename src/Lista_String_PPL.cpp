#include "Lista_String_PPL.h"
Lista_String_PPL::Lista_String_PPL() {head = new Nodo();};

void Lista_String_PPL::add_string(string linea) {
    Nodo* NuevoNodo = new Nodo(linea);

    if(head == nullptr){
        head = NuevoNodo;
    } else{
        NuevoNodo->set_Next(head);
        head = NuevoNodo;
    }
}

string Lista_String_PPL::get_content(string palab) {
    Nodo* actual = new Nodo(palab);
    Nodo *aux1 = head;

    while (aux1 != nullptr){
        if(actual->get_ContenidoNodo() == palab){
            return palab;
        }
        actual = actual->get_Next();
    }
}

Nodo* Lista_String_PPL::get_head() {return head;}

bool Lista_String_PPL::get_EstaVacia() {return head->get_EsVacio();}

string Lista_String_PPL::get_Contenido() {
    if(get_EstaVacia()){
        cout << "Error, cabeza de lista VACIA" << endl;
        return NULL;
    } else{
        return head->get_ContenidoNodo();
    }
}

void Lista_String_PPL::set_head(Nodo *head) { this->head = head;}

Lista_String_PPL* Lista_String_PPL::resto() {
    Lista_String_PPL *l = new Lista_String_PPL();//crea una lista con la direccion get_next y lo retornamos como el resto de la lista
    l->set_head(head->get_Next());
    return l;
}

int Lista_String_PPL::size() {
    if(this->get_EstaVacia()){
        return 0;
    }else {
        int aux = this->resto()->size();
        return aux + 1;
    }
}

