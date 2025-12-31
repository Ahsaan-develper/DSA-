#include<iostream>
#include<vector>
#include<queue>
using namespace std ;
class Node {
    private:
        int data ;
        Node* left ;
        Node* right ;
    public:
        Node( int data){
            this->data= data;
            left= right= NULL;
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
        void setData (int data){
            this->data= data ;
        }
        void setLeft (Node* l){
            left= l;
        }
        void setRight (Node* r){
            right= r;
        }

};
Node* insert (Node* root , int val){
    if (root == NULL){
        return new Node(val);
    }
    if (val < root->getData()){
        root->setLeft(insert(root->getLeft() , val));
    }else{
        root->setRight(insert(root->getRight() , val));
    }
    return root;
}
Node* buildBST (vector<int> &vec ){
    Node* root = NULL;

    for (int val : vec){
       root= insert(root , val);
    }
    return root;
}   

void inOrder (Node* root ){
    if (root== NULL){
        return ;
    }
    inOrder(root->getLeft());
    cout <<root->getData()<<" ";
    inOrder(root->getRight());

}
int main(){
    vector<int> vec = {3,2,1,5,6,4};
    Node* root = buildBST(vec);
    inOrder(root);
    cout<< endl;
    return 0;
}