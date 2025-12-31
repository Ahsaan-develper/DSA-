#include<iostream>
#include<vector>
using namespace std;
class Node {
    private:
        int data ;
        Node* left ;
        Node* right;
    public:
        Node(int d){
            data = d;
            left= right= NULL;
        }
        int getData (){
            return data;
        }
        void setData (int d){
            data = d;
        }
        Node* getLeft (){
            return left;
        }
        void setLeft (Node* l){
            left= l;
        }
        Node* getRight (){
            return right;
        }
        void setRight(Node* r){
            right = r;
        }
};  
static int idx= -1;
Node* Buildtree (vector<int>preOrder){
        idx++;
        if (preOrder[idx]==-1){
            return NULL;
        }
        Node* root = new Node (preOrder[idx]);
        root->setLeft(Buildtree(preOrder));
        root->setRight(Buildtree(preOrder));
        return root;
}
int main(){
    vector<int>preOrder={1,2,-1,-1,3,4,-1,-1,5,-1,-1} ;
    Node* root =Buildtree (preOrder);
    cout <<root->getData()<<endl;
    cout <<root->getLeft()->getData()<<endl;
    return 0;
}