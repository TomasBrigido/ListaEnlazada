#include "VarList.h"

VarList::VarList() { head = new Variable('%',"",0,NULL); }

Variable* VarList::get_head() { return head; }

void VarList::add_variable(char Name, string Type, int IntValue) { // agrega correctamente
    Variable* NewVariable = new Variable(Name, Type, IntValue, nullptr);
    if (head == nullptr) {
        head = NewVariable;
    }
    else {
        NewVariable->set_Next(head);
        head = NewVariable;
    }
}
void VarList::add_variable(char Name, string Type, bool BoolValue) {
    Variable* NewVariable = new Variable(Name, Type, BoolValue, NULL);
    if (head == NULL) {
        head = NewVariable;
    }
    else {
        NewVariable->set_Next(head);
        head = NewVariable;
    }
}

void VarList::print(Variable* HeadOfList) {
    if (HeadOfList == NULL) { cout << "Final de la lista" << endl; return; }
    cout << "Nombre: " << HeadOfList->get_Name() << endl;
    cout << "Tipo: " << HeadOfList->get_Type() << endl;
    cout << "Valor entero: "<<HeadOfList->get_IntValue() << endl;
    cout << "Valor booleano: "<<HeadOfList->get_BoolValue() << endl;
    print(HeadOfList->get_Next());
}

void VarList::set_IntVariable(char name,int NewValue) {
    Variable* aux = head;
    do {
        if (aux->get_Name() == name) {

            aux->set_IntValue(NewValue);
        }
        aux = aux->get_Next();
    } while (aux != nullptr);
}

int VarList::get_IntVariable(char character) {
    Variable* aux = head;
    while (aux->get_Next() != nullptr) {

        if (aux->get_Name() == character) {

            return aux->get_IntValue();
        }
        aux = aux->get_Next();
    }
}

bool VarList::get_BoolVariable(char character) {
    Variable* aux = head;
    while (aux->get_Next() != nullptr) {

        if (aux->get_Name() == character) {

            return aux->get_BoolValue();
        }
        aux = aux->get_Next();
    }
}

void VarList::set_BoolVariable(char name, bool NewValue) {
    Variable* aux = head;
    do {
        if (aux->get_Name() == name) {

            aux->set_BoolValue(NewValue);
        }
        aux = aux->get_Next();                            // seguir acá
    } while (aux != nullptr);

}

bool VarList::estaVacia() {
    return head->esVacia();
}

void VarList::set_head_var(Variable *head) {
    this->head = head;
}

VarList* VarList::resto_VarList(){
    VarList *l = new VarList();
    l->set_head_var(head->get_Next());
    return l;
}