#include <cmath>
#include <iostream>
#include <string>

#include "../custom/stack.hpp"
#include "infix_postfix.hpp"

using namespace custom;
using std::string;

class infix_to_postfix {
  private:
    int opPrec(char c) {
        switch (c) {
            case '^':
                return 4;
            case '/':
            case '*':
                return 3;
            case '%':
                return 2;
            case '+':
            case '-':
                return 1;
            default:
                return 0;
        }
    }

    bool isOp(char c) {
        if (c == '/' || c == '*' || c == '+' || c == '-' || c == '%' || c == '^') {
            return true;
        }
        return false;
    }

  public:
    void infixToPostfix(string exp) {
        linked_list_stack<char> stack;

        std::cout << "Postfix expression: ";
        for (int i = 0; i < exp.length(); i++) {
            if (exp[i] == '(') {
                stack.push('(');
            } else if (exp[i] == ')') {
                while (stack.top() != '(') {
                    std::cout << stack.top();
                    stack.pop();
                }
                stack.pop();
            } else if (!isOp(exp[i])) {
                std::cout << exp[i];
            } else {
                while (!stack.empty() && opPrec(stack.top()) >= opPrec(exp[i])) {
                    std::cout << stack.top();
                    stack.pop();
                }
                stack.push(exp[i]);
            }
        }
        while (!stack.empty()) {
            std::cout << stack.top();
            stack.pop();
        }
        std::cout << std::endl;
    }
};

void infix_to_postfix_driver() {
    std::cout << "Enter infix expression: ";
    infix_to_postfix itop;
    string s;
    std::getline(std::cin >> std::ws, s);
    itop.infixToPostfix(s);
}

class infix_to_prefix {
  private:
    int opPrec(char c) {
        switch (c) {
            case '^':
                return 4;
            case '/':
            case '*':
                return 3;
            case '%':
                return 2;
            case '+':
            case '-':
                return 1;
            default:
                return 0;
        }
    }

    bool isOp(char c) {
        if (c == '/' || c == '*' || c == '+' || c == '-' || c == '%' || c == '^') {
            return true;
        }
        return false;
    }

  public:
    void infixToPrefix(string exp) {
        linked_list_stack<char> stack;

        string new_exp = "";
        for (int i = exp.length() - 1; i >= 0; i--) {
            if (exp[i] == ')') {
                stack.push(')');
            } else if (exp[i] == '(') {
                while (stack.top() != ')') {
                    new_exp += stack.top();
                    stack.pop();
                }
                stack.pop();
            } else if (!isOp(exp[i])) {
                new_exp += exp[i];
            } else {
                while (!stack.empty() && opPrec(stack.top()) >= opPrec(exp[i])) {
                    new_exp += stack.top();
                    stack.pop();
                }
                stack.push(exp[i]);
            }
        }
        while (!stack.empty()) {
            new_exp += stack.top();
            stack.pop();
        }

        std::cout << "Prefix expression: ";
        for (int i = new_exp.length() - 1; i >= 0; i--) {
            std::cout << new_exp[i];
        }
        std::cout << std::endl;
    }
};

void infix_to_prefix_driver() {
    std::cout << "Enter infix expression: ";
    infix_to_prefix itop;
    string s;
    std::getline(std::cin >> std::ws, s);
    itop.infixToPrefix(s);
}

class postfix_evaluation {
  private:
    bool isOp(char c) {
        return (c == '/' || c == '*' || c == '+' || c == '-' || c == '^' || c == '%');
    }

    int operate(int b, char op, int a) {
        switch (op) {
            case '^':
                return (int) std::pow(a, b);
            case '/':
                return a / b;
            case '*':
                return a * b;
            case '%':
                return a % b;
            case '+':
                return a + b;
            case '-':
                return a - b;
            default:
                return 0;
        }
    }

  public:
    void evalPostfix(string exp) {
        linked_list_stack<int> stack;

        for (int i = 0; i < exp.length(); i++) {
            if (!isOp(exp[i])) {
                stack.push(int (exp[i]) - 48);
            } else {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();

                stack.push(operate(a, exp[i], b));
            }
        }
        std::cout << stack.top() << std::endl;
    }
};

void postfix_evaluation_driver() {
    std::cout << "Enter postfix expression: ";
    postfix_evaluation pe;
    string s;
    std::getline(std::cin >> std::ws, s);
    pe.evalPostfix(s);
}

class prefix_evaluation {
  private:
    bool isOp(char c) {
        return (c == '/' || c == '*' || c == '+' || c == '-' || c == '^' || c == '%');
    }

    int operate(int b, char op, int a) {
        switch (op) {
            case '^':
                return (int) std::pow(a, b);
            case '/':
                return a / b;
            case '*':
                return a * b;
            case '%':
                return a % b;
            case '+':
                return a + b;
            case '-':
                return a - b;
            default:
                return 0;
        }
    }

  public:
    void evalPrefix(string exp) {
        linked_list_stack<int> stack;

        for (int i = exp.length() - 1; i >= 0; i--) {
            if (!isOp(exp[i])) {
                stack.push(int(exp[i]) - 48);
            } else {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();

                stack.push(operate(a, exp[i], b));
            }
        }
        std::cout << stack.top() << std::endl;
    }
};

void prefix_evaluation_driver() {
    std::cout << "Enter prefix expression: ";
    prefix_evaluation pe;
    string s;
    std::getline(std::cin >> std::ws, s);
    pe.evalPrefix(s);
}
