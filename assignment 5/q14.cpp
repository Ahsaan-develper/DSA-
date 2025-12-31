// File: 14_BinaryTreeHeight.cpp
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val; Node *left, *right;
    Node(int v): val(v), left(nullptr), right(nullptr) {}
};

Node* buildFromArray(const vector<int>& a, int i) {
    if (i >= (int)a.size()) return nullptr;
    Node* n = new Node(a[i]);
    n->left = buildFromArray(a, 2*i+1);
    n->right = buildFromArray(a, 2*i+2);
    return n;
}

int height(Node* r) {
    if (!r) return 0;
    int hl = height(r->left);
    int hr = height(r->right);
    return 1 + max(hl, hr);
}

int main() {
    vector<int> arr = {1,2,3,4,5};
    Node* root = buildFromArray(arr, 0);
    cout << "Height: " << height(root) << "\n"; // nodes count on longest path
    return 0;
}
