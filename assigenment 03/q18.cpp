#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if opening and closing brackets match
bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Function to check if parentheses are balanced
bool isBalanced(string expr) {
    stack<char> s;

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        // If it's an opening bracket, push to stack
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }

        // If it's a closing bracket
        else if (ch == ')' || ch == '}' || ch == ']') {
            // If stack empty → no matching opening
            if (s.empty())
                return false;

            // Check if top matches
            if (!isMatchingPair(s.top(), ch))
                return false;

            s.pop(); // Pop matched pair
        }
    }

    // If stack is empty → all matched
    return s.empty();
}

// Main Function
int main() {
    string expr;
    cout << "Enter an expression (e.g., {[()]}): ";
    cin >> expr;

    if (isBalanced(expr))
        cout << "The expression is Balanced " << endl;
    else
        cout << "The expression is NOT Balanced " << endl;

    return 0;
}
