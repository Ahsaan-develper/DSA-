#include<iostream>
using namespace std;
class MaxHeap {
    private:
        int arr[10];
        int size;
    public:
        MaxHeap(){
            size=0;
        }
        void insert ( int val , int n){
          arr[size]= val;
          int index = size;
          size++;
            while (index > 0)
            {
                int parent = (index-1 )/2;
                if ( arr[parent]< arr[index]){
                    swap(arr[parent], arr[index]);
                    index= parent;
                }else{
                    break;
                }
            }
            
        }
        void Print ( ){
            if ( size ==-1){
             return ;
            }
            for ( int i=0 ; i< size ; i++){
                cout << arr[i]<<" "; 
            }cout <<endl;
        }
};
int main(){
    MaxHeap h;

    int arr[] ={1,2,3,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    if ( n> 0){
        for ( int i=0 ; i<n ; i++){
            h.insert(arr[i], n);
        }
    }
    h.Print();
    return 0;
}