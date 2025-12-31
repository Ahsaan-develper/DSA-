// File: 19_LevelOrderTraversal.cpp
#include <iostream>
#include <queue>
using namespace std;
struct Node { int val; Node *left,*right; Node(int v):val(v),left(nullptr),right(nullptr){} };

void levelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* cur = q.front(); q.pop();
        cout << cur->val << " ";
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
}

int main() {
    // Build small tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout << "Level-order: ";
    levelOrder(root);
    cout << "\n";
    return 0;
}
