// File: 12_BST_Insert_Search.cpp
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
    // duplicate keys ignored
    return root;
}

bool search(Node* root, int key) {
    if (!root) return false;
    if (root->val == key) return true;
    if (key < root->val) return search(root->left, key);
    else return search(root->right, key);
}

int main() {
    Node* root = nullptr;
    int keys[] = {50, 30, 70, 20, 40, 60, 80};
    for (int k : keys) root = insert(root, k);
    cout << "Search 60: " << (search(root, 60) ? "Found" : "Not found") << "\n";
    cout << "Search 25: " << (search(root, 25) ? "Found" : "Not found") << "\n";
    return 0;
}
