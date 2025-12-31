#include <iostream>
using namespace std ;
class Heap {
    private : 
        int arr[10];
        int size ;
    public :
        Heap(){
            size=0;
        }
        void maxHeap (int val , int n){
            arr[size] = val;
            int index = size;
            size++;
            while (index > 0)
            {
                int parent = (index -1 )/ 2;
                if (arr[parent] < arr[index] ){
                    swap(arr[index] , arr[parent]);
                    index= parent;
                }else {
                    break;
                }
            }
            
        }
        void minHeap (int val , int n){
            arr[size] = val;
            int index = size;
            size++;
            while (index > 0)
            {
                int parent = (index -1 )/ 2;
                if (arr[parent] > arr[index]){
                    swap(arr[index] , arr[parent]);
                    index= parent;
                }else {
                    break;
                }
            }
            
        }

        void DeleteMax (){
            if (size == 0){
                cout <<"The heap is empty "<<endl;
                cout <<endl;
                return;
            }
              arr[0] =arr[size -1 ];
                size --;
                int i=0 ;
                
            while (true)
            {
                int leftIndex = i* 2 + 1;
                int rightIndex = i * 2 + 2;
                int largest = i;
                if ( leftIndex < size && arr[leftIndex] > arr[largest]){
                    largest = leftIndex;
                }
                if(rightIndex < size && arr[rightIndex] > arr[largest]){
                    largest = rightIndex;
                }
                if (largest == i){
                    break;
                }
                swap(arr[i] , arr[largest]);
                i =largest;
            }
            
        }
        void DeleteMin (){
            if ( size == 0){
                return ;
            }
            arr[0] = arr [size-1 ];
            size --;
            int i =0;
            while (true)
            {
                int leftIndex = i* 2 + 1;
                int rigthIndex = i*2 + 2;
                int min = i;
                if (leftIndex <   size && arr[leftIndex] < arr[min]){
                        min = leftIndex;
                }
                if ( rigthIndex <  size  && arr[rigthIndex] < arr[min]){
                    min = rigthIndex;
                             
                }
                if (i == min){
                    break;
                }
                swap(arr[i] , arr[min]);
                i = min;
            }
            

        }
        void getLargestNumber (){
            if (size ==0 ){
                return ;
            }
            int largest = arr[0];
                for ( int i=0 ; i< size ; i++){
                    if (arr[i] > arr[largest]){
                        largest = arr[i];
                    }
                
        }
        cout <<"Largest : "<<largest <<endl;
    }
        void Print (){
            if (size == -1){
                cout <<"Arr : is empty "<<endl;
                return ;
            }
            for ( int i=0 ; i<size ; i++){
                cout <<arr[i] << " ";
            }cout <<endl;
        }

};  
int main(){
    Heap h;
    int arr[]= {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i=0 ; i<n; i++){
        // h.maxHeap(arr[i], n);
        h.minHeap(arr[i] , n);
    }
    h.Print();
    // h.DeleteMax();
    h.DeleteMin();
    h.Print();
    h.getLargestNumber();
    return 0;
}