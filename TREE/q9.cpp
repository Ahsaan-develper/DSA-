#include<iostream>
#include<queue>
using namespace std ;
class Node {
    private:
        int data ;
        Node* left ;
        Node* right ;
    public:
        Node(int d){
            data = d;
            left = right= NULL;
        }
        int getData (){
            return data ;
        }
        void setData (int d){
            data =d ;
        }
        Node* getLeft (){
            return left;
        }
        void setLeft (Node* l){
            left = l;
        }
        Node* getRight (){
            return right;
        }
        void setRight (Node* r){
            right= r;
        }
};

Node* insert (Node* root , int val){
    if ( root== NULL){
        return new Node(val);
    }
    if (val< root->getData()){
        root->setLeft(insert(root->getLeft() , val));
    }else {
        root->setRight(insert(root->getRight() , val));
    }
    return root;
}
Node* buildBST (int arr[] , int size ){
    if (size==0){
        return NULL;
    }
    Node* root = NULL;
    for (int i =0 ; i<size; i++){
        root= insert(root , arr[i]);
    }
    return root;

}
void inOrder (Node* root){
    if (root==NULL){
        return ;
    }else{
        inOrder(root->getLeft() );
        cout <<root->getData()<<" ";
        inOrder(root->getRight());
    }
}

void PreOrder (Node* root){
    if ( root == NULL){
        return ;
    }else{
        cout <<root->getData()<<" ";
        PreOrder(root->getLeft());
        PreOrder(root->getRight());
    }   
}
void PostOrder ( Node* root){
    if ( root==NULL){
        return ;
    }else{
        PostOrder(root->getLeft());
        PostOrder(root->getRight());
        cout <<root ->getData()<<" ";
    }
}
Node* LevelOrder (Node* root){
    queue<Node*> q ;
    q.push(root);
    q.push(NULL);
    while (q.size() > 0)
    {
        Node* curr = q.front();
        q.pop();
        if ( curr== NULL){
            if (!q.empty()){
                cout<<endl;
                q.push(NULL);
                continue;
            }else{
                break;
            }
        } 
        cout <<curr->getData() <<" ";
        if (curr ->getLeft() != NULL){
            q.push(curr->getLeft());
        }
        if (curr ->getRight() != NULL){
            q.push(curr->getRight());
        }
    }
    
}
bool isFind (Node* root , int val){
    if (root == NULL){
        return false;
    }
    if ( val == root->getData()){
        cout << "The val is : "<<root->getData()<<endl;
        return true;
    }
    if ( val < root->getData()){
        return isFind(root->getLeft(), val);
    }else{
         return isFind(root->getRight(), val);
    }
    return false;
}
void MinVal (Node* root){
    if ( root== NULL){
        return ;
    }
    if ( root->getLeft() == NULL){
        cout <<"The min val : "<<root->getData();
    }
        if  (root->getLeft() != NULL){
             MinVal(root->getLeft());
            
        }
    
}

Node* orderSuccessor (Node* root){
  while (root != NULL && root->getLeft() != NULL)
  {
    root= root->getLeft();
  }
  return root;
}
Node* deleteNode (Node* root , int val){
    if ( root== NULL){ 
        return NULL;
    }
    if (val < root->getData()){
        root->setLeft(deleteNode(root->getLeft(), val));
    }else if (val > root->getData()){
         root->setRight(deleteNode(root->getRight(), val));
    }else{
        if ( root->getLeft()== NULL){
            Node* temp = root->getRight();
            delete root;
            return temp;
        }else if (root->getRight() == NULL){
            Node* temp = root->getLeft();
            delete root;
            return temp;
        }else{
            Node* is = orderSuccessor(root->getRight());
            root->setData(is->getData());
            root->setRight(deleteNode(root->getLeft(), is->getData()));
        }
    }
    return root;
}
int main(){
    int arr[]={3,2,1,4,6,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* root= buildBST(arr , n);
    // inOrder(root);
    // PreOrder(root);
    // PostOrder(root);
    // LevelOrder(root);
    // bool found=  isFind(root , 10 );
    // if ( !found){
    //     cout <<"The value is not found"<<endl;
    // }
    // MinVal(root);
    deleteNode(root , 2);
    LevelOrder(root);
    return 0;
}