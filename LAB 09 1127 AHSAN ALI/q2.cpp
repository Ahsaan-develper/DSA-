#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
private:
    int data;
    Node* left;
    Node* right;

public:
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
    int getData() {
        return data;
    }
    Node* getLeft() {
        return left;
    }
    Node* getRight() {
        return right;
    }
    void setLeft(Node* l) {
        left = l;
    }
    void setRight(Node* r) {
        right = r;
    }
};

// -----------------------------------
// Insert into Binary Search Tree
// -----------------------------------
Node* Insert(Node* root, int value) {
    if (root == NULL)
        return new Node(value);

    if (value < root->getData())
        root->setLeft(Insert(root->getLeft(), value));
    else
        root->setRight(Insert(root->getRight(), value));

    return root;
}

// -----------------------------------
// Build BST from an array
// -----------------------------------
Node* buildBST(vector<int>& arr) {
    Node* root = NULL;
    for (int v : arr) {
        root = Insert(root, v);
    }
    return root;
}

// -----------------------------------
// Level Order Traversal
// -----------------------------------
void levelOrderTraversal(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr == NULL) {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
            continue;
        }

        cout << curr->getData() << " ";

        if (curr->getLeft())
            q.push(curr->getLeft());
        if (curr->getRight())
            q.push(curr->getRight());
    }
}

// -----------------------------------
// Find Minimum in BST 
// (Left-most node always holds minimum)
// -----------------------------------
Node* FindMinimum(Node* root) {
    if (root == NULL) return NULL;

    while (root->getLeft() != NULL) {
        root = root->getLeft();
    }
    return root;   // left-most node
}

// -----------------------------------
// MAIN
// -----------------------------------
int main() {
    vector<int> arr = {50, 30, 70, 20, 40, 60, 80};

    Node* root = buildBST(arr);

    cout << "Level Order Traversal of BST:\n";
    levelOrderTraversal(root);

    Node* minNode = FindMinimum(root);

    if (minNode != NULL)
        cout << "\nMinimum value in BST = " << minNode->getData() << endl;

    return 0;
}
