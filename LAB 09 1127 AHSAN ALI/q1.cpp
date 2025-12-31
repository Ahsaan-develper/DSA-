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
// Insert into BST
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
// Build BST from array
// -----------------------------------
Node* buildBST(vector<int>& arr) {
    Node* root = NULL;
    for (int v : arr)
        root = Insert(root, v);

    return root;
}

// -----------------------------------
// Find Minimum Node (left-most node)
// -----------------------------------
Node* FindMinimum(Node* root) {
    if (root == NULL) return NULL;

    while (root->getLeft() != NULL)
        root = root->getLeft();

    return root;
}

// -----------------------------------
// Delete a Node from BST
// -----------------------------------
Node* DeleteNode(Node* root, int value) {
    if (root == NULL) return NULL;

    // Search the node
    if (value < root->getData()) {
        root->setLeft(DeleteNode(root->getLeft(), value));
    }
    else if (value > root->getData()) {
        root->setRight(DeleteNode(root->getRight(), value));
    }
    else {
        // Node FOUND
        // Case 1: No child
        if (root->getLeft() == NULL && root->getRight() == NULL) {
            delete root;
            return NULL;
        }
        // Case 2: One child
        else if (root->getLeft() == NULL) {
            Node* temp = root->getRight();
            delete root;
            return temp;
        }
        else if (root->getRight() == NULL) {
            Node* temp = root->getLeft();
            delete root;
            return temp;
        }
        // Case 3: Two children
        else {
            Node* minRight = FindMinimum(root->getRight());
            int minValue = minRight->getData();
            root->setRight(DeleteNode(root->getRight(), minValue));
            root->setLeft(root->getLeft()); // unchanged
            root->setRight(root->getRight());
            root->setLeft(root->getLeft());
            *(int*)((char*)root + 0) = minValue; // Replace data safely
        }
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
            if (!q.empty()) q.push(NULL);
            continue;
        }

        cout << curr->getData() << " ";

        if (curr->getLeft()) q.push(curr->getLeft());
        if (curr->getRight()) q.push(curr->getRight());
    }
}

// -----------------------------------
// MAIN (Testing)
// -----------------------------------
int main() {
    vector<int> arr = {50, 30, 70, 20, 40, 60, 80};

    Node* root = buildBST(arr);

    cout << "Original BST (Level Order):\n";
    levelOrderTraversal(root);

    Node* minNode = FindMinimum(root);
    cout << "\nMinimum value in BST = " << minNode->getData() << "\n\n";

    cout << "Deleting 20...\n";
    root = DeleteNode(root, 20);
    levelOrderTraversal(root);

    cout << "\nDeleting 30...\n";
    root = DeleteNode(root, 30);
    levelOrderTraversal(root);

    cout << "\nDeleting 50 (root)...\n";
    root = DeleteNode(root, 50);
    levelOrderTraversal(root);

    return 0;
}
