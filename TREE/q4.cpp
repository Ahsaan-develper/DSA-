#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node {
    private:
        int data ;
        Node* left ;
        Node* right ;
    public:
        Node(int data){
            this->data= data;
            left = NULL;
            right=  NULL;
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
            data= d;
        }
        void setLeft (Node* l){
            left = l;
        }
        void setRight (Node* r){
            right= r;
        }
};
static int idx = -1;
Node* binaryTree ( vector<int> &preOrder ){
   idx ++;
   if (preOrder[idx]== -1 ){
    return NULL;
   }
    Node* root = new Node(preOrder[idx]);
    root->setLeft(binaryTree(preOrder ));
    root->setRight( binaryTree(preOrder));
    return root;
}
// level order traversal 
void levelOrder (Node* root ){
    queue<Node*> q;
    q.push(root);
    while (q.size()> 0)
    {
        Node* curr = q.front();
        q.pop();
        cout<<curr->getData()<< " ";
        if (curr->getLeft() != NULL){
            q.push(curr->getLeft());
        }
        if (curr->getRight() != NULL){
            q.push(curr->getRight());
        }

    }
}
int main(){
    vector<int>preOrder={1,2,-1,-1,3,4,-1,-1,5,-1,-1} ;
   
    Node* root = binaryTree (preOrder )  ;
    // cout <<root->getLeft()->getData();
    levelOrder(root);
    return 0;
}