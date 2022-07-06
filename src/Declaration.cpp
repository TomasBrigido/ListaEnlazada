#include "Declaration.h"

Declaration::Declaration(string instruction, VarList* list) {
    this->instruction = instruction;
    this->list = list;
}

void Declaration::ejecutar() {
    if (instruction.at(0) == 'I') {
        list->add_variable(instruction.at(instruction.length() - 1), "INT",0);  // crea nueva Variable y la agrega a la lista
    }
    else {
        list->add_variable(instruction.at(instruction.length() - 1), "BOOL", false);
    }

}