#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to perform arithmetic operations
int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

// Function to evaluate postfix expression
int evaluatePostfix(string exp) {
    stack<int> s;

    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];

        // Ignore spaces
        if (ch == ' ')
            continue;

        // 1️⃣ If operand (digit), push to stack
        if (isdigit(ch)) {
            s.push(ch - '0');  // Convert char to int
        }
        // 2️⃣ If operator, pop two operands and apply
        else {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();

            int result = applyOperation(val1, val2, ch);
            s.push(result);
        }
    }

    // Final result on top
    return s.top();
}

int main() {
    string exp;
    cout << "Enter postfix expression (example: 23*54*+): ";
    cin >> exp;

    cout << "Result = " << evaluatePostfix(exp) << endl;
    return 0;
}
