#include<iostream>
using namespace std ;
class MaxHeap {
    private:
        int arr[10];
        int size;
    public:
        MaxHeap(){
            size= 0;
        }

        void insert (int val, int n){
                arr[size]= val;
                int index = size;
                size++;
                while (index > 0)
                {
                    int parent = (index-1 )/ 2;
                    if (arr[parent] < arr[index]){
                        swap(arr[index] , arr[parent]);
                        index= parent;
                    }else{
                        break;
                    }
                }
        }

        void Print ( ){
            if (size== 0){
                cout <<"No value in heap"<<endl;
                return ;
            }
            for ( int i=0 ; i <size ; i++){
                cout << arr[i] << " ";
            }cout <<endl;
        }
        void deleteNode (){
            if ( size == 0){
                return ;
            }
            arr[0] = arr[size -1 ];
            size--;
            int i=0 ;
             while (true)
             {
                int leftIndex = i* 2 + 1;
                int rightIndex = i*2 + 2;
                int largest = i;
                if ( leftIndex < size && arr[leftIndex]> arr[largest]){
                    largest= leftIndex;
                }
                if ( rightIndex < size && arr[rightIndex] > arr[largest]){
                    largest = rightIndex;
                }
                if (largest ==i ){
                    break;
                }
                swap(arr[i], arr[largest]);
                i = largest;

             }
             
        }
};
int main(){ 
    MaxHeap h;
   
    int arr[]={50,12,34,67,8};
    int n = sizeof(arr)/ sizeof(arr[0]);
    if ( n> 0){
        for (int i=0 ; i<n ; i++){
        h.insert(arr[i], n);
    }
    }
    h.Print();
    h.deleteNode();
    h.Print();
    return 0;
}