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





int main()
{
   

    return 0;
}
