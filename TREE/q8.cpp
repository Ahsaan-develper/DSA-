#include<iostream>
using namespace std;
// This is main node 
class Node{
    private:
        int data ;
        Node* left ;
        Node* right ;

    public:
        //this is main consructor here
        Node (int data  ){
            this->data= data ;
            left= right= NULL;
        }

        // get data function here
        int getData  (){
            return data;
        }

        // set data function here
        void setData(int data){
            this->data= data;
        }

        // getleft function here
        Node* getLeft (){
            return left;
        }

        //set left function here
        void setLeft (Node* left){
            this->left= left;
        }

        // gte right function here
        Node* getRight (){
            return right;
        }
        
        //set rigth function here 
        void setRight (Node* right){
            this->right= right;
        }
};

// Insert function is present here
Node* Insert (Node* root , int val){
    if (root== NULL){
        return new Node(val);
    }
    if ( val < root->getData()){
        root->setLeft(Insert(root->getLeft() , val));
    }else{
        root->setRight(Insert(root->getRight(), val));
    }
    return root;
}

// build bst tree function is here 
Node* BuildBST (int arr[] , int n){
    if (n== 0){
        return NULL;
    }
    Node* root = NULL;
    for (int i=0 ;i<n ; i++){
        root= Insert(root , arr[i]);
    }
    return root;
}


// find min value function is here 
bool findValue (Node* root , int val){
    if (root== NULL){
        return false;
    }
    if (val == root->getData()){
        cout <<"The "<<val<<" is found "<<endl;
        return true;
    }
    if (val < root->getData()){
        return findValue(root->getLeft() , val);
    }else{
        return findValue(root->getRight() , val);
    }

}

// get inorder successor
Node* inOrderSuccessor (Node* root){
    while (root != NULL && root->getLeft() != NULL)
    {
       root = root->getLeft();
    }
    return root;
    
}

// delete node function is here
Node* deleteNode (Node* root , int val){
    if (root== NULL){
        return NULL;
    }

    if (val < root->getData()){
        root->setLeft(deleteNode(root->getLeft() , val));
    }else if (val > root->getData()){
        root->setRight(deleteNode(root->getRight() , val));
    }else{
        // value equal to node 

        if (root->getLeft()== NULL){
            Node* temp= root->getRight();
            delete root;
            return temp;
        }else if (root->getRight()== NULL){
               Node* temp= root->getLeft();
            delete root;
            return temp;
        }else{
            // this is use to delete root have 2 child 
            Node* is = inOrderSuccessor(root->getRight());
            root->setData(is->getData ());
            root->setRight(deleteNode(root->getRight() , is->getData()));
        }
    }
    return root;

}



// find min vvalue function is here
void findMin(Node* root){
    if ( root == NULL){
        return ;
    }
    if ( root->getLeft()==NULL){
        cout <<"The min value in  BST is : "<<root->getData()<<endl;
        return ;
    }
    if (root->getLeft()){
        findMin(root->getLeft());
    }
}

// find max value  function is  here
void FindMax(Node* root){
    if ( root== NULL){
        return;
    }
    if  ( root->getRight()== NULL){
        cout <<"The max Value is : "<<root->getData()<<endl;
        return;
    }
    if ( root->getRight()){
        FindMax(root->getRight());
    }
}

// InOrder traversal


void inOrder (Node* root ){
    if ( root== NULL){
        return ;
    }else{
        inOrder(root->getLeft());
        cout <<root ->getData()<< " ";
        inOrder(root->getRight());
    }
}
int main(){
    // the main array is here
    int arr[]= {4,3,2,1,5,6,7,8};

    //array size calculate here 
    int n = sizeof(arr) /sizeof(arr[0]);
    
    //bst tree call here 
    Node* root = BuildBST(arr , n);

    //Find value function call here
    bool found=findValue(root , 10 );
    if (!found){
        cout <<"Value is not found here !"<<endl;
    }

    // The delete function call here 
    deleteNode(root, 1);

    // The find min function call here 
    findMin(root);

    // The find max function call here 
    FindMax(root);
    

    cout <<"Before Deletion --------"<<endl;

    // in order function is calling ...
    inOrder(root);

    // delete function calling ....
    deleteNode(root, 5);
    cout <<"After Deletion ---------"<<endl;

    // inorder function is calling ...
    inOrder(root);

    return 0;
}