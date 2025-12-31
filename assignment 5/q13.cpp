// File: 13_BST_MinMax.cpp
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v): val(v), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->val) root->left = insert(root->left, key);
    else if (key > root->val) root->right = insert(root->right, key);
    return root;
}

int findMin(Node* root) {
    if (!root) throw runtime_error("Empty tree");
    Node* cur = root;
    while (cur->left) cur = cur->left;
    return cur->val;
}

int findMax(Node* root) {
    if (!root) throw runtime_error("Empty tree");
    Node* cur = root;
    while (cur->right) cur = cur->right;
    return cur->val;
}

int main() {
    Node* root = nullptr;
    int keys[] = {15, 10, 20, 8, 12, 17, 25};
    for (int k : keys) root = insert(root, k);
    cout << "Min: " << findMin(root) << "\n";
    cout << "Max: " << findMax(root) << "\n";
    return 0;
}
