#include "Assign.h"
#include <iostream>

Assign::Assign() {}

Assign::Assign(string instruct,VarList* list,CharStack* stack,IntStack* StackInt) {
    instruction = instruct;
    this->list = list;
    this->stack = stack;
    this->StackInt = StackInt;
}

string Assign::to_postfix(string operation, CharStack* stack) {

    string postfix = ""; // Initialize postfix as empty string.
    for (int i = 0; i < operation.length(); i++) {

        // Scanning each character from left.If character is a delimitter, move on.
        if (operation[i] == ',') continue;

        else if (operation[i] == ' ') { postfix += operation[i]; }

            // If character is operator, pop two elements from stack, perform operation and push the result back.
        else if (IsOperator(operation[i]))
        {
            while (!stack->is_empty() && stack->get_top()->get_Value() != '(' && HasHigherPrecedence(stack->get_top()->get_Value(), operation[i]))
            {
                postfix += stack->get_top()->get_Value();
                stack->pop();
            }
            stack->push(operation[i]);
        }
            // Else if character is an operand
        else if (IsOperand(operation[i]))
        {
            postfix += operation[i];
        }

        else if (operation[i] == '(')
        {
            stack->push(operation[i]);
        }

        else if (operation[i] == ')')
        {
            while (!stack->is_empty() && stack->get_top()->get_Value() != '(') {
                postfix += stack->get_top()->get_Value();
                stack->pop();
            }
            stack->pop();
        }
    }

    while (!stack->is_empty()) {
        postfix += stack->get_top()->get_Value();
        stack->pop();
    }
    return postfix;
}

int Assign::HasHigherPrecedence(char op1, char op2) {

    int op1Weight = GetOperatorWeight(op1);
    int op2Weight = GetOperatorWeight(op2);

    // If operators have equal precedence, return true if they are left associative.
    // return false, if right associative.
    // if operator is left-associative, left one should be given priority.
    if (op1Weight == op2Weight)
    {
        return true;
    }
    return op1Weight > op2Weight ? true : false;
}

// Function to verify whether a character is operator symbol or not.
bool Assign::IsOperator(char C) {
    if (C == '+' || C == '-' || C == '*' || C == '/'||C=='>'||C=='<') {
        return true;
    }
    return false;
}

// Function to verify whether a character is alphanumeric character (letter or numeric digit) or not.
bool Assign::IsOperand(char C) {
    if (C >= '0' && C <= '9') { return true; }
    if (C >= 'a' && C <= 'z') { return true; }
    if (C >= 'A' && C <= 'Z') { return true; }
    return false;
}

bool Assign::IsVariable(char C) {
    if (C >= 'a' && C <= 'z') { return true; }
    return false;
}

int Assign::GetOperatorWeight(char op) {
    int weight = -1;
    switch (op)
    {
        case '+':
        case '-':
            weight = 1;
        case '*':
        case '/':
            weight = 2;
    }
    return weight;
}

void Assign::ejecutar(string instruction) {

    string operation;

    for (int i = instruction.find("=") + 1; i < instruction.length(); i++) { // getting the operation that needs
        // to be evaluated from string
        operation += instruction[i];
    }
    // remember to replace instruction with operation once it works
    string PostfixOp=to_postfix(operation,stack);

    //cout<<PostfixOp<<endl;

    if (operation.find('<')!=string::npos || operation.find('>')!= string::npos) {
        bool result = Calculate(PostfixOp, stack, list, StackInt);
        list->set_BoolVariable(instruction[0], result);
    }
    else {
        int result = Calculate(PostfixOp, stack, list, StackInt);
        list->set_IntVariable(instruction[0], result);
    }
}

int Assign::Calculate(string operation, CharStack* stack,VarList* list,IntStack* Stackint) {
    for (int i = 0; i < operation.length(); i++) {

        if (operation[i] == ' ' || operation[i] == ',') { continue; }

        else if (IsOperator(operation[i])) {

            int operand2 = Stackint->get_top()->get_Value(); Stackint->pop();
            int operand1 = Stackint->get_top()->get_Value(); Stackint->pop();

            int result = PerformOperation(operation[i], operand1, operand2);

            Stackint->push(result);
        }
        else if (islower(operation[i])) {
            Variable *aux = new Variable();
            aux = list->get_head();
            while (!list->estaVacia()){
                if(list->get_head()->get_Name() == operation[i] && list->get_head()->get_Type() == "INT"){
                    Stackint->push(list->get_IntVariable(operation[i]));
                }else if(list->get_head()->get_Name() == operation[i] && list->get_head()->get_Type() == "BOOL"){
                    Stackint->push(list->get_BoolVariable(operation[i]));
                }
                list = list->resto_VarList();
            }
            list->set_head_var(aux);
        }
        else if (IsNumericDigit(operation[i])) {
            int operand = 0;
            while (i < operation.length() && IsNumericDigit(operation[i])) {
                operand = (operand * 10) + (operation[i] - '0');
                i++;
            }
            i--;

            Stackint->push(operand);
        }
    }
    return Stackint->get_top()->get_Value();
}


int Assign::PerformOperation(char operation, int operand1, int operand2){
    if (operation == '+') { return operand1 + operand2; }
    else if (operation == '-') { return operand1 - operand2; }
    else if (operation == '*') { return operand1 * operand2; }
    else if (operation == '/') { return operand1 / operand2; }
    else if (operation == '<') { return operand1 < operand2; }
    else if (operation == '>') { return operand1 > operand2; }

    else cout << "Error \n";
    return -1;
}

bool Assign::IsNumericDigit(char C){
    if (C >= '0' && C <= '9') return true;
    return false;
}