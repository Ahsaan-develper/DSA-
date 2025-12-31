#include<iostream>
using namespace std;

class TreeNode{
private:
    int data;
    TreeNode* left;
    TreeNode* right;

public:
    TreeNode(){
        data = 0;
        left = right = NULL;
    }
    TreeNode(int d){
        data = d;
        left = right = NULL;
    }

    int GetData(){
        return data;
    }
    void SetData(int d){
        data = d;
    }

    TreeNode* GetLeft(){
        return left;
    }
    void SetLeft(TreeNode* l){
        left = l;
    }

    TreeNode* GetRight(){
        return right;
    }
    void SetRight(TreeNode* r){
        right = r;
    }

    bool isLeaf(){
        return left == NULL && right == NULL;
    }

    void Insert(int value){
        if(value < data){
          
            if(left == NULL){
                left = new TreeNode(value);
            }
            else{
                left->Insert(value);
            }
        }
        else{
           
            if(right == NULL){
                right = new TreeNode(value);
            }
            else{
                right->Insert(value);
            }
        }
    }
};


int main(){

    TreeNode* root = new TreeNode(50);

    root->Insert(30);
    root->Insert(70);
    root->Insert(20);
    root->Insert(40);
    root->Insert(60);
    root->Insert(80);

    cout << "Root: " << root->GetData();

    return 0;
}
