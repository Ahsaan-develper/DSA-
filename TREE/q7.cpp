#include<iostream>
#include<vector>
#include<queue>
using namespace std ;
class Node {
    private:
        int data ;
        Node* left ;
        Node* right;
    public:
        Node(int d){
            data= d;
            left= right= NULL;
        }
        int getData (){
            return data ;
        }
        Node* getLeft (){
            return left ;
        }
        Node* getRight (){
            return right;
        }
        void setData (int d){
            data= d;
        }
        void setLeft (Node* l){
            left= l;
        }
        void setRight (Node* r){
            right= r;
        }
};
Node* insert (Node* root , int val){
    if (root== NULL){
        return new Node(val);
    }
    if (val< root->getData()){
        root->setLeft(insert(root->getLeft(), val));
    }else{
        root->setRight(insert(root->getRight(), val));
    }
    return root;
}
Node* buildBST(vector<int>&vec){
    Node* root = NULL;
    for (int val : vec){
        root = insert(root , val);
    }
    return root;
}
bool search (Node* root, int key){
    if (root== NULL){
        return false;
    }
    if (key == root->getData()){
        return true;
    }

    if (key< root->getData()){
        return search(root->getLeft(), key);
    }else{
        return search(root->getRight(), key);
    }
   
}
int main(){
    vector<int>vec ={3,2,1,5,6,4};
    Node* root = buildBST(vec);
    bool found= search(root , 3);
     if (!found){
        cout <<"Value not found "<<endl;
     }else{
        cout <<"Value is found"<<endl;
     }
    return 0;
}