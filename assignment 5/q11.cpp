// File: 01_BinaryTreeTraversals.cpp
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v): val(v), left(nullptr), right(nullptr) {}
};

// Build a binary tree from array in level-order (complete-tree style)
Node* buildFromArray(const vector<int>& arr, int i) {
    if (i >= (int)arr.size()) return nullptr;
    Node* root = new Node(arr[i]);
    root->left = buildFromArray(arr, 2*i + 1);
    root->right = buildFromArray(arr, 2*i + 2);
    return root;
}

void inorder(Node* r) {
    if (!r) return;
    inorder(r->left);
    cout << r->val << " ";
    inorder(r->right);
}

void preorder(Node* r) {
    if (!r) return;
    cout << r->val << " ";
    preorder(r->left);
    preorder(r->right);
}

void postorder(Node* r) {
    if (!r) return;
    postorder(r->left);
    postorder(r->right);
    cout << r->val << " ";
}

int main() {
    // Example: create tree from array [1,2,3,4,5,6]
    vector<int> arr = {1,2,3,4,5,6};
    Node* root = buildFromArray(arr, 0);
    cout << "Inorder: "; inorder(root); cout << "\n";
    cout << "Preorder: "; preorder(root); cout << "\n";
    cout << "Postorder: "; postorder(root); cout << "\n";
    return 0;
}
