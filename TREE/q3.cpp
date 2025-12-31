#include<iostream>
#include<vector>
using namespace std ;
class Node {
    private:
        int data ;
        Node* left;
        Node* right;
    public:
        Node(int d){
            data = d;
            left = right= NULL;
        }
        int getData (){
            return data ;
        }
        Node* getLeft (){
            return left;
        }
        Node* getRight (){
            return right;
        }
        void setData (int d){
            data = d;
        }
        void setLeft (Node* l){
            left = l;
        }
        void setRight (Node* r){
            right= r;
        }
};
static int idx = -1;
Node* buildTree (vector<int>& preOrder){
       idx++;
    if (preOrder[idx]== -1){
        return NULL;
    }
 
    Node* root= new Node(preOrder[idx]);
    root ->setLeft(buildTree(preOrder));
    root ->setRight(buildTree(preOrder));
    return root;
}

void PreOrderView (Node* root){
        if (root== NULL){
            return;
        }
        cout <<root->getData()<<" ";
       PreOrderView(root->getLeft());
       PreOrderView(root->getRight());
}
void inOrder (Node* root ){
    if (root== NULL){
        return;
    }
    inOrder(root->getLeft());
    cout <<root->getData()<< " ";
    inOrder(root->getRight());
}
void PostOrder (Node* root){
    if (root == NULL){
        return;
    }
    PostOrder(root->getLeft());
    PostOrder(root->getRight());
    cout <<root ->getData()<<" ";
}
int main (){
    vector<int>preOrder ={1 ,2, -1, -1, 3, 4, -1, -1, 5, -1 ,-1};
     Node* root = buildTree(preOrder);
    PreOrderView(root);
    cout <<endl;
    inOrder(root);
    cout <<endl;
    PostOrder(root);
    return 0;
}