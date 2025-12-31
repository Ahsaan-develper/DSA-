// File: 18_AVL_Deletion.cpp
#include <iostream>
using namespace std;

struct Node {
    int val; Node *left, *right; int height;
    Node(int v): val(v), left(nullptr), right(nullptr), height(1) {}
};

int height(Node* n) { return n ? n->height : 0; }
int getBalance(Node* n) { return n ? height(n->left)-height(n->right) : 0; }

Node* rightRotate(Node* y) {
    Node* x = y->left; Node* T2 = x->right;
    x->right = y; y->left = T2;
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    return x;
}
Node* leftRotate(Node* x) {
    Node* y = x->right; Node* T2 = y->left;
    y->left = x; x->right = T2;
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}

Node* minValueNode(Node* node) {
    Node* cur = node;
    while (cur->left) cur = cur->left;
    return cur;
}

Node* insert(Node* node, int key) {
    if (!node) return new Node(key);
    if (key < node->val) node->left = insert(node->left, key);
    else if (key > node->val) node->right = insert(node->right, key);
    else return node;
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && key < node->left->val) return rightRotate(node);
    if (balance < -1 && key > node->right->val) return leftRotate(node);
    if (balance > 1 && key > node->left->val) { node->left = leftRotate(node->left); return rightRotate(node); }
    if (balance < -1 && key < node->right->val) { node->right = rightRotate(node->right); return leftRotate(node); }
    return node;
}

Node* removeNode(Node* root, int key) {
    if (!root) return root;
    if (key < root->val) root->left = removeNode(root->left, key);
    else if (key > root->val) root->right = removeNode(root->right, key);
    else {
        // node with one or no child
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp) { // no child
                temp = root;
                root = nullptr;
            } else { // one child
                *root = *temp;
            }
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->val = temp->val;
            root->right = removeNode(root->right, temp->val);
        }
    }
    if (!root) return root;
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);
    // balance cases
    if (balance > 1 && getBalance(root->left) >= 0) return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0) { root->left = leftRotate(root->left); return rightRotate(root); }
    if (balance < -1 && getBalance(root->right) <= 0) return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0) { root->right = rightRotate(root->right); return leftRotate(root); }
    return root;
}

void preorder(Node* r) { if (!r) return; cout << r->val << " "; preorder(r->left); preorder(r->right); }

int main() {
    Node* root = nullptr;
    int vals[] = {9,5,10,0,6,11,-1,1,2};
    for (int v: vals) root = insert(root, v);
    cout << "Preorder before deletion: "; preorder(root); cout << "\n";
    root = removeNode(root, 10);
    cout << "Preorder after deleting 10: "; preorder(root); cout << "\n";
    return 0;
}
