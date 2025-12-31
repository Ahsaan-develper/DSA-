#include <iostream>
using namespace std;
class Node {
    public:
        int pageId;
        string PageTitle ;
        Node*  next;
};
class Stack {
    private :
        Node* top;
    public:
        Stack(){
            top=NULL;
        }
        bool isEmpty (){
            return (top==NULL);
        }
        void push (int id , string title ){
            Node* newNode = new Node;
            newNode ->pageId=id;
            newNode->PageTitle= title;
            newNode ->next= top;
            top = newNode;
                }
        
        void pop(){
            if (isEmpty()){
                return;
            }else{      
          Node* temp = top;
            top = top->next;
            delete temp; 
            }      
        }
        void display (){
            Node* temp = top;
                while (temp != NULL)
                {
                    cout<<"Id :" <<temp->pageId <<" title " <<temp->PageTitle;
                    temp = temp->next;
                    
                }        
            cout <<endl;
        }
};
int main(){
    Stack s;
    cout <<"Original stack" <<endl;
    s.push(1,"habib");
    s.push(2,"ali");
    s.push(3,"ahsan");
    s.display();
    cout <<"After pop "<<endl;
    s.pop();
    s.display();
    return 0;
}