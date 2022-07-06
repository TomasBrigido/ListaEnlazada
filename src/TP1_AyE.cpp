#include "TP1_AyE.h"
TP1_AyE::TP1_AyE() {ejecutar();}

int TP1_AyE::identificar_instruccion(string instruccion) {
    int posInit = 0;
    int posFound = 0;
    string splitted;

    while(posFound >= 0){
        posFound = instruccion.find(" ", posInit);
        splitted = instruccion.substr(posInit, posFound - posInit);
        break;
    }

    if(splitted == "INT" || splitted == "BOOL"){return 1;}
    if(splitted == "IF"){return 2;}
    if(splitted == "SHOW"){return 3;}
    if(splitted == "JUMP"){return 4;}

    int valorASCII = splitted.at(0);
    if(valorASCII >= 97 && valorASCII <= 122 ){
        return 5;
    }
    return 6;
}

void TP1_AyE::ejecutar() {
    Lectura_Archivo l1;
    Show observar;
    CharStack cSta;
    IntStack iSta;
    Salto s;
    Condicional cond;
    //TP1_AyE tp;
    bool banderaJump = true;
    Nodo* czo_lista;

    l1.lista_de_variables = lista_alverre(l1.lista_de_variables);

    czo_lista = l1.lista_de_variables->get_head();

    while (!l1.lista_de_variables->get_EstaVacia()) {
        string instruccion = l1.lista_de_variables->get_Contenido();
        int tipo_instruccion = identificar_instruccion(instruccion);


        switch (tipo_instruccion) {
            case 1: {
                Declaration d(instruccion, lista_variables);
                d.ejecutar();
                cout << "\nSe ejecuto una instruccion de declaracion";//Instruccion de declaracion
                break;
            }
            case 2:
                cond.ejecutar_condicional(instruccion,lista_variables);
                cout << "\nSe ejecuto una instruccion de condicion";//Instruccion de condicion
                break;
            case 3:
               // observar.set_string(instruccion);
                observar.ejecutar(lista_variables, instruccion);
                cout << "\nSe ejecuto instruccion de show";//instruccion de show
                break;
            case 4: {
                Nodo *nuevo_comienzo = s.ejecutar(instruccion, l1.lista_de_variables, czo_lista);
                if (nuevo_comienzo != nullptr) {
                    l1.lista_de_variables->set_head(nuevo_comienzo);
                    banderaJump = false;
                }
                cout << "\nSe ejecuto instruccion de jump";//instruccion de jump
                break;
            }
            case 5: {
                Assign asigno(instruccion, lista_variables, &cSta, &iSta);
                asigno.ejecutar(instruccion);
                cout << "\nSe ejecuto instruccion de asignacion";//Instruccion de asigancion
                break;
            }
            case 6:
                cout << "\nNo se reconoce la instruccion";
                break;

        }

        if(banderaJump){
            l1.lista_de_variables = l1.lista_de_variables->resto();
        }
        banderaJump = true;
    }
}

Lista_String_PPL* TP1_AyE::lista_alverre(Lista_String_PPL* lista) {
    Lista_String_PPL* lista_aux = new Lista_String_PPL();

    while (!lista->get_EstaVacia()){
        lista_aux->add_string(lista->get_head()->get_ContenidoNodo());
        lista = lista->resto();
    }
    return lista_aux;
}
