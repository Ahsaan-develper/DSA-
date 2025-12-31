#include<iostream>
using namespace std;
class Node {
    private:
        int data ;
        Node* next;
    public:
        Node(int d){
            data =d;
            next = NULL;
        }
        int GetData (){
            return data;
        }
        Node* GetNext (){
            return next;
        }
        void SetData (int val){
            data = val;
        }
        void SetNext (Node* ptr){
            next = ptr ;
        }
};
class List {
    private:
        Node* head ;
        Node* tail;
    public:
        List(){
        tail=head= NULL;
         }
        void insertItemDesireIndex(int val , int pos){  
    if (pos < 0) {
        cout << "Wrong position " << endl;
        return;
    }

    Node* newNode = new Node(val);

    // Case 1: empty list
    if (head == NULL) {
        head = tail = newNode;
        return;
    }

    // Case 2: insert at head
    if (pos == 0) {
        newNode->SetNext(head);
        head = newNode;
        return;
    }

    // Case 3: insert at given pos
    Node* temp = head;
    int count = 0;
    while (temp != NULL && count < pos - 1) {
        temp = temp->GetNext();
        count++;
    }

    if (temp == NULL) {
        cout << "Position out of range" << endl;
        delete newNode;
        return;
    }

    newNode->SetNext(temp->GetNext());
    temp->SetNext(newNode);

    if (newNode->GetNext() == NULL) { // if inserted at end
        tail = newNode;
    }
}

        void print(){
            Node* temp =head;
            while (temp != NULL)
            {
                cout <<temp->GetData()<<" ";
                temp=temp->GetNext();
            }
            cout <<endl;
            
        }
        void findingMin(){
            if (head==NULL){
                cout <<"List is empty "<<endl;
                return;
            }else{
                Node* temp =head;
                int min = temp->GetData();
                while (temp != NULL)
                {
                    if (temp->GetData() <min){
                        min=temp->GetData();
                    }
                    temp = temp->GetNext();
                }
                cout <<"Min value : "<<min<<endl;
                
            }
        }
        void Max (){
            if (head == NULL){
                cout <<"List is empty "<<endl;
                return;
            }else{
                Node* temp = head;
                int max = temp->GetData();
                while (temp != NULL)
                {
                    if (temp->GetData()>max){
                        max = temp->GetData();
                    }
                    temp = temp->GetNext();
                }
                cout <<" Max value : "<<max<<endl;
            }
        }
        bool searching (int val){
            if (head== NULL){
                cout <<"List is empty"<<endl;
                return false;
            }else{
                Node* temp = head;
                bool found = false;
                while (temp != NULL)
                {
                    if (temp->GetData()==val){
                       found = true;
                    }
                    temp= temp->GetNext();
                }
                if (found ){
                     cout <<val<<" found in list"<<endl;
                     return true;
                }else{
                    cout <<val <<" Value not found in list"<<endl;
                    return false;
                }
                
            }
        }
        void swap (int val1 , int val2){
            if (head==NULL){
                cout <<"List is empty "<<endl;
                return;
            }else{
                Node* v1 = NULL;
                Node* v2= NULL;
                Node* temp = head;

             while (temp != NULL) {
            if (temp->GetData() == val1) v1 = temp;
            if (temp->GetData() == val2) v2 = temp;
            temp = temp->GetNext();
             }
             if (v1 && v2 ){
                int temp = v1->GetData();
                    v1->SetData(v2->GetData());
                    v2->SetData(temp);
             }else{
                cout <<"One or both value not found "<<endl;
                return;
             }

               
                
            }
        }
   void sort() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        Node* val = temp->GetNext();  // reset val for each temp
        while (val != NULL) {
            if (temp->GetData() > val->GetData()) {
                // Swap data
                int t = temp->GetData();
                temp->SetData(val->GetData());
                val->SetData(t);
            }
            val = val->GetNext();
        }
        temp = temp->GetNext();
    }
}
void insertSort(int val){
    Node* newNode = new Node(val);
    if (head ==NULL){
        head=tail=newNode;
    }else{
        if (val < head->GetData()){
            newNode->SetNext(head);
            head= newNode;
            return;
        }
        Node* temp= head;
        while (temp->GetNext()!=NULL && temp->GetNext()->GetData()<val)
        {
            temp= temp ->GetNext();
        }
        newNode->SetNext(temp->GetNext());
        temp ->SetNext(newNode);
        if (newNode->GetNext()==NULL){
            tail= newNode;
        }

        

    }
}

};
int main(){
    List li;
    li.insertItemDesireIndex(1,0);
    li.insertItemDesireIndex(2,1);
    li.insertItemDesireIndex(3,0);
    li.findingMin();
    li.Max();
    li.searching(2);
    cout <<"---Before swap---"<<endl;
    li.print();
    li.swap(1,2);
    cout <<"---After swap---"<<endl;
    li.print();
    li.sort();
    cout <<"---After sort---"<<endl;
    li.print();
    li.insertSort(6);
    cout <<"---Insert data in sort manner---"<<endl;
    li.print();

    return 0;
}