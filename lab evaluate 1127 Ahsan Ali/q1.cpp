#include<iostream>
using namespace std;

class Node {
    private:
        int data ;
        Node* left ;
        Node* right ;
    public:
        Node( int d){
            data = d;
            left = right= NULL;
        }
        int getData (){
            return data ;
        }
        void setData(int d){
            data = d;
        }
        Node* getLeft (){
            return left;
        }
        void setLeft (Node* l){
            left =l;
        }
        Node* getRight (){
            return right;
        }
        void setRight (Node* r){
            right = r;
        }
};
Node* insert (Node* root , int val){
    if ( root == NULL){
        return new Node(val);
    }
        if ( val < root->getData()){
            root->setLeft(insert(root->getLeft() , val));
        }else if ( val > root->getData()){
            root->setRight(insert(root->getRight(), val));
        }
    return root;
}
Node* buildBST (int arr[] , int n){
    if (n == 0){
        return NULL;
    }
        Node* root = NULL;
        for ( int i=0 ; i< n ; i++){
            root =insert(root , arr[i]);
        }
    return root;
}
void PreOrder (Node* root){
    if ( root == NULL){
        return;
    }else{
        cout <<root->getData() <<" ";
        PreOrder(root->getLeft());
        PreOrder(root->getRight());
    }
}
int main(){
    int arr[]={3,2,1,4,6};
    Node* root= buildBST(arr , 5);
    cout <<"The main root is : "<<root->getData();
    cout <<endl;
    PreOrder(root);
    return 0;
}