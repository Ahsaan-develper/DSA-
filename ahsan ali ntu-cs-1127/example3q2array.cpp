#include <iostream>
#include <cmath>     // for pow()
using namespace std;

#define SIZE 100

class Stack {
    int top;
    float arr[SIZE];

public:
    Stack() { top = -1; }

    void push(float value) {
        if (top == SIZE - 1)
            cout << "Stack Overflow\n";
        else
            arr[++top] = value;
    }

    float pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    bool isEmpty() { return top == -1; }
};

float evaluatePostfix(string exp) {
    Stack s;

    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        // If character is a digit
        if (isdigit(ch)) {
            s.push(ch - '0'); // convert char to int
        }
        else {
            // Pop two operands
            float val2 = s.pop();
            float val1 = s.pop();

            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                case '^': s.push(pow(val1, val2)); break;
                default: cout << "Invalid operator: " << ch << endl;
            }
        }
    }

    return s.pop();
}

int main() {
    string postfix;
    cout << "Enter a postfix expression (e.g., 53+82-*): ";
    cin >> postfix;

    float result = evaluatePostfix(postfix);
    cout << "Result = " << result << endl;

    return 0;
}
