#include <iostream>
using namespace std;

class TreeNode {
private:
    int data;
    TreeNode* left;
    TreeNode* right;

public:
    TreeNode() {
        data = 0;
        left = right = NULL;
    }

    TreeNode(int d) {
        data = d;
        left = right = NULL;
    }

    int GetData() {
        return data;
    }

    void SetData(int d) {
        data = d;
    }

    TreeNode* GetLeft() {
        return left;
    }

    void SetLeft(TreeNode* l) {
        left = l;
    }

    TreeNode* GetRight() {
        return right;
    }

    void SetRight(TreeNode* r) {
        right = r;
    }

    bool isLeaf() {
        return left == NULL && right == NULL;
    }
};


void InsertNode(TreeNode* root, int value)
{
    if (value < root->GetData())
    {
        // Go left
        if (root->GetLeft() == NULL)
            root->SetLeft(new TreeNode(value));
        else
            InsertNode(root->GetLeft(), value);
    }
    else
    {
        // Go right
        if (root->GetRight() == NULL)
            root->SetRight(new TreeNode(value));
        else
            InsertNode(root->GetRight(), value);
    }
}



void PreOrder(TreeNode* node)
{
    if (node == NULL)
        return;

    cout << node->GetData() << " ";
    PreOrder(node->GetLeft());
    PreOrder(node->GetRight());
}


void InOrder(TreeNode* node)
{
    if (node == NULL)
        return;

    InOrder(node->GetLeft());
    cout << node->GetData() << " ";
    InOrder(node->GetRight());
}



void PostOrder(TreeNode* node)
{
    if (node == NULL)
        return;

    PostOrder(node->GetLeft());
    PostOrder(node->GetRight());
    cout << node->GetData() << " ";
}

void  minNodeValue (TreeNode* root){
     TreeNode* min = root;
        if (root ==  NULL){
            return ;
        }
        int val = min->GetData();
        if (val > root->GetData()){
            min->SetData(root->GetData());
        }
        minNodeValue(root->GetLeft());
         minNodeValue(root->GetRight());
}
// void Delete (TreeNode* root){
    
// }

int main()
{
    TreeNode* root = new TreeNode(50);
    
    // Insert nodes into BST
    InsertNode(root, 30);
    InsertNode(root, 70);
    InsertNode(root, 20);
    InsertNode(root, 40);
    InsertNode(root, 60);
    InsertNode(root, 80);

    cout << "PreOrder: ";
    PreOrder(root);
 minNodeValue(root);


    return 0;
}
