// File: 16_InfixToPostfix_TreeMethod.cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    string val; Node *left, *right;
    Node(string v): val(v), left(nullptr), right(nullptr) {}
};

int prec(const string& op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/") return 2;
    if (op == "^") return 3;
    return 0;
}

bool isOperator(const string& s) {
    return s=="+"||s=="-"||s=="*"||s=="/"||s=="^";
}

// apply top operator to top two operand nodes, build subtree
void applyOp(stack<string>& ops, stack<Node*>& vals) {
    string op = ops.top(); ops.pop();
    Node* right = vals.top(); vals.pop();
    Node* left = vals.top(); vals.pop();
    Node* n = new Node(op);
    n->left = left; n->right = right;
    vals.push(n);
}

vector<string> tokenize(const string& s) {
    vector<string> tokens;
    for (size_t i=0;i<s.size();) {
        if (isspace(s[i])) { ++i; continue; }
        if (isdigit(s[i]) || isalpha(s[i])) {
            string t;
            while (i<s.size() && (isalnum(s[i]) )) { t.push_back(s[i]); ++i; }
            tokens.push_back(t);
        } else {
            tokens.push_back(string(1,s[i]));
            ++i;
        }
    }
    return tokens;
}

void postorder(Node* r) {
    if (!r) return;
    postorder(r->left);
    postorder(r->right);
    cout << r->val << " ";
}

Node* buildTreeFromInfix(const string& expr) {
    auto tokens = tokenize(expr);
    stack<string> ops;
    stack<Node*> vals;
    for (auto &tok : tokens) {
        if (isalnum(tok[0])) {
            vals.push(new Node(tok));
        } else if (tok == "(") {
            ops.push(tok);
        } else if (tok == ")") {
            while (!ops.empty() && ops.top() != "(") applyOp(ops, vals);
            if (!ops.empty()) ops.pop(); // pop "("
        } else if (isOperator(tok)) {
            while (!ops.empty() && ops.top()!="(" &&
                   ( (prec(ops.top()) > prec(tok)) || (prec(ops.top())==prec(tok) && tok != "^") )
                   ) {
                applyOp(ops, vals);
            }
            ops.push(tok);
        }
    }
    while (!ops.empty()) applyOp(ops, vals);
    return vals.empty() ? nullptr : vals.top();
}

int main() {
    string infix = "a+b*(c-d)";
    Node* root = buildTreeFromInfix(infix);
    cout << "Postfix (from tree): ";
    postorder(root);
    cout << "\n";
    return 0;
}
