#include <iostream>
#include <cctype>
using namespace std;

class Node {
public:
    char data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() { top = NULL; }

    bool isEmpty() {
        return (top == NULL);
    }

    void push(char val) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (!isEmpty()) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    char peek() {
        if (!isEmpty())
            return top->data;
        else
            return '\0';
    }

    int precedence(char c) {
        if (c == '^')
            return 3;
        else if (c == '*' || c == '/')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return 0;
    }

    bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
    }

    string infixToPostfix(string infix) {
        string postfix = "";
        for (char c : infix) {
            if (isalnum(c)) {
                postfix += c;
            }
            else if (c == '(') {
                push(c);
            }
            else if (c == ')') {
                while (!isEmpty() && peek() != '(') {
                    postfix += peek();
                    pop();
                }
                pop();
            }
            else if (isOperator(c)) {
                while (!isEmpty() && precedence(peek()) >= precedence(c)) {
                    postfix += peek();
                    pop();
                }
                push(c);
            }
        }

        while (!isEmpty()) {
            postfix += peek();
            pop();
        }

        return postfix;
    }
};

// ------------------- MAIN FUNCTION -------------------
int main() {
    Stack st;
    string infix;

    cout << "Enter infix expression (e.g., A+B*C): ";
    cin >> infix;

    string postfix = st.infixToPostfix(infix);

    cout << "Postfix Expression: " << postfix << endl;
    return 0;
}
