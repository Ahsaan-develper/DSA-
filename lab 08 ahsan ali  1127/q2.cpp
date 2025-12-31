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




int main()
{
   

    return 0;
}
