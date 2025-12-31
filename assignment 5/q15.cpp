// File: 15_ExpressionTreeFromPostfix.cpp
#include <iostream>
#include <stack>
#include <string>
#include<vector>
using namespace std;

struct Node {
    string val;
    Node *left, *right;
    Node(string v): val(v), left(nullptr), right(nullptr) {}
};

bool isOperator(const string& s) {
    return s=="+" || s=="-" || s=="*" || s=="/" || s=="^";
}

Node* buildFromPostfix(const vector<string>& tokens) {
    stack<Node*> st;
    for (auto &t : tokens) {
        if (!isOperator(t)) {
            st.push(new Node(t));
        } else {
            Node* right = st.top(); st.pop();
            Node* left = st.top(); st.pop();
            Node* op = new Node(t);
            op->left = left; op->right = right;
            st.push(op);
        }
    }
    return st.empty() ? nullptr : st.top();
}

void inorder(Node* r) {
    if (!r) return;
    if (isOperator(r->val)) cout << "(";
    inorder(r->left);
    cout << r->val;
    inorder(r->right);
    if (isOperator(r->val)) cout << ")";
}

int main() {
    // Example postfix: "ab+cde+**" but using tokens separated: (a b + c d e + * *)
    vector<string> postfix = {"a","b","+","c","d","e","+","*","*"};
    Node* root = buildFromPostfix(postfix);
    cout << "Inorder (infix with parentheses): ";
    inorder(root);
    cout << "\n";
    return 0;
}
