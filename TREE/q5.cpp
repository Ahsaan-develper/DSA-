#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node  {
    private:
        int data ;
        Node* left ;
        Node* right ;
    public:
        Node(int data ){
            this->data= data ;
            left = right= NULL;
        }
        int getData (){
            return data ;
        }
        Node*getLeft (){
            return left ;
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
        void setRight(Node* r){
            right = r;
        }

};
static int idx = -1;
Node* BinaryTree (vector<int> &vec ){
    idx++;
    if (vec[idx] == -1){
        return NULL;
    }
    Node* root = new Node(vec[idx]);
    root->setLeft(BinaryTree(vec));
    root->setRight(BinaryTree(vec));
    return root;
}

void levelOrderTraversal(Node* root){
    queue <Node*> q;
    q.push(root);
    q.push(NULL);
    while (q.size() > 0)
    {
        Node* curr= q.front();
        q.pop();
       
        if (curr == NULL){
            if (!q.empty() ){
                cout<<endl;
                q.push(NULL);
                continue;
            }else{
                break;
            }
        }
        cout <<curr->getData()<< " ";
        if (curr->getLeft() != NULL){
            q.push(curr->getLeft());
        }
        if (curr ->getRight() != NULL){
            q.push(curr->getRight());
        }
    }
    cout <<endl;
}
int main(){
    vector<int>vec ={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root= BinaryTree(vec);
    levelOrderTraversal(root);
    return 0;
}