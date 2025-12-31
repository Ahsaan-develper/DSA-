#include <iostream>
using namespace std;

#define SIZE 100

class Stack {
    char arr[SIZE];
    int top;

public:
    Stack() { top = -1; }

    void push(char c) {
        if (top == SIZE - 1)
            cout << "Stack Overflow\n";
        else
            arr[++top] = c;
    }

    char pop() {
        if (top == -1)
            return '\0';
        return arr[top--];
    }

    char peek() {
        if (top == -1)
            return '\0';
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

// Function to check if a character is an opening symbol
bool isOpening(char c) {
    return (c == '(' || c == '{' || c == '[');
}

// Function to check if a character is a closing symbol
bool isClosing(char c) {
    return (c == ')' || c == '}' || c == ']');
}

// Function to check if opening and closing symbols match
bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Function to check balanced symbols
bool checkBalanced(string expr) {
    Stack s;

    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];

        if (isOpening(c)) {
            s.push(c); // push opening symbols
        } else if (isClosing(c)) {
            if (s.isEmpty()) return false; // no matching opening
            char top = s.pop();
            if (!isMatching(top, c)) return false; // mismatch
        }
    }

    return s.isEmpty(); // all symbols matched
}

// -------------------- MAIN FUNCTION --------------------
int main() {
    string expr;
    cout << "Enter an expression: ";
    cin >> expr;

    if (checkBalanced(expr))
        cout << "Expression is balanced.\n";
    else
        cout << "Expression is NOT balanced.\n";

    return 0;
}
