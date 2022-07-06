#include "CharStack.h"
#include <iostream>

#define cout std::cout
#define cin std::cin
#define endl std::endl
#define string std::string



CharStack::CharStack() { top = nullptr;}

void CharStack::push(char Newchar) {
    Character* Newcharacter = new Character(Newchar);
    if (top==nullptr) {
        top = Newcharacter;
    }
    else {
        Newcharacter->set_next(top);
        top = Newcharacter;
    }
};

void CharStack::pop() {
    Character* aux = top;
    top = top->get_next();
    delete aux;
};

Character* CharStack::get_top() { return top; }

bool CharStack::is_empty(){
    if (top == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

void CharStack::print(Character* stack) {
    if ( stack == nullptr) { cout << "Final del stack"; return; }
    cout << stack->get_Value() << endl;
    print(stack->get_next() );
}