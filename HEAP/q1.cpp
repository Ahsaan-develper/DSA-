#include<iostream>
using namespace std ;
class Heap {
    private:
        int arr[100];
        int size ;
    public:
        Heap(){
            arr[0] = -1;
            size= 0;
        }

    void insert(int val){
        size += 1;
        int idx = size;
        arr[idx]=  val;
        while (idx > 1)
        {
            int parent = idx / 2;

            if (arr[parent] < arr[idx]){
                swap(arr[parent] , arr[idx]);
                idx= parent;
            }else{
                return ;
            }
        }
        
    }
    void deleteFromHeap (){
        // check if heap is empty or not
        if (size== 0){
            cout<<"Heap is empty here "<<endl;
            return;
        }
        
        // swap the first and  the last node here

        swap(arr[1] , arr[size]);

        // delete the last element here

        size--;

        //take root node to its corect position

        int i = 1;

        while (i <= size)
        {
            int leftIdx = 2*i;
            int rightIdx = 2*i + 1;
            int largest = i;
           if ( leftIdx <= size && arr[leftIdx]  > arr[largest]){
            largest= leftIdx;
           } 
           if (rightIdx <= size && arr[rightIdx] > arr[largest]){
            largest = rightIdx;
           }
           if (largest == i ){
            return;


           }

           swap (arr[i] , arr[largest]);
           i=largest;
        }
    }
    void print (){
        for (int i=1 ; i<=size ;i++){
            cout <<arr[i] << " ";
        }cout <<endl;
    }
};
int main(){
    Heap h;
    h.insert(33);
    h.insert(10);
    h.insert(50);
    h.insert(20);

    // Before deletion of node
    cout << "Before deletion..."<<endl;
    h.print();

    // after deletion of node 
    h.deleteFromHeap();
     cout << "Before deletion..."<<endl;
    h.print();
    return 0;
}