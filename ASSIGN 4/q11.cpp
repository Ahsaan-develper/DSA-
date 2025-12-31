    #include <iostream>
    using namespace std;
    #define size 5
    class Queue {
        private:
            int front , rear ;
            int items[size];
        public:
            Queue(){
                front = -1 ;
                rear= -1;
            }
            void enqueue(int val){
                if (rear==size -1 ){
                    cout <<"Queue is full"<<endl;
                    return;
                }else
                {
                    if (front== -1){
                        front++;
                    }
                        rear++;
                        items[rear]= val;
                        cout <<"Val added is "<<val<<endl;    
                    
                }
                
            }
            void dequeue(){
                if (front == -1 ){
                    cout <<"Queue is empty "<<endl;
                    return;
                }else
                {
                    cout <<"items pop "<<items[front]<<endl;
                    front++;
                    if (front> rear){
                        front = rear = -1;
                    }
                }
                
            }
            void display (){
                if (front == -1 ){
                    cout  <<"queue  is empty "<<endl;
                    return;
                }else{
                    for (int i=front ; i<= rear ;i++){
                            cout <<"items "<<items[i] << " ";
                    }
                    cout <<endl;

                }
            }
    };  
    int main(){
        Queue q;
        q.enqueue(1);    
        q.enqueue(2);    
        q.enqueue(3);    
        q.display();
        q.dequeue();
        q.display();
        return 0;
    }