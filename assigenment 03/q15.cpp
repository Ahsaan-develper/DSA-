#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        // Ignore spaces
        if (ch == ' ') continue;

        // 1️⃣ If operand → add to postfix
        if (isalnum(ch)) {
            postfix += ch;
        }

        // 2️⃣ If '(' → push to stack
        else if (ch == '(') {
            s.push(ch);
        }

        // 3️⃣ If ')' → pop until '('
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // remove '('
        }

        // 4️⃣ If operator → handle precedence
        else {
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    // 5️⃣ Pop all remaining operators
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

// Main function
int main() {
    string infix;
    cout << "Enter infix expression (example: A+B*C): ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
