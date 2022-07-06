#include "IntStack.h"

IntStack::IntStack() { top = nullptr; }

void IntStack::push(int Newint) {
    Integer* Newinteger = new Integer(Newint);
    if (top == nullptr) {
        top = Newinteger;
    }
    else {
        Newinteger->set_next(top);
        top = Newinteger;
    }
};

void IntStack::pop() {
    Integer* aux = top;
    top = top->get_next();
    delete aux;
};

Integer* IntStack::get_top() { return top; }

bool IntStack::is_empty() {
    if (top == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

void IntStack::print(Integer* stack) {
    if (stack == nullptr) { cout << "Final del stack" << endl; return; }
    cout << stack->get_Value() << endl;
    print(stack->get_next());
}