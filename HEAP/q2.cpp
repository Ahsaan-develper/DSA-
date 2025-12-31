#include<iostream>
using namespace std ;

class Heap {
    private:
        int arr[10] ;
        int size ;
    public:
        Heap(){
            size=0;
        }
         
        void insert (int val){
            arr[size] = val;
            int index = size;
            size ++;
            while (index >0)
            {
                int parent = (index -1) / 2 ;
                if (arr[parent] < arr[index]){
                    swap(arr[index],arr[parent]);
                    index= parent;
                }else{
                    break;
                }
            }
            
        } 

        void Printing (){
            if (size== 0){
                cout <<"No value in heap is set "<<endl;
                return ;
            }

            for ( int i=0 ; i<size ; i++){
                cout <<arr[i] << " ";
            }cout<<endl;
        }

        void deleteFromHeap (){
            if (size==0){
                cout <<"Heap is empty "<<endl;
                return;
            }

            arr[0] = arr[size-1];
            size--;
            int i=0;
            while (true)
            {
                int LeftIdx = i* 2 + 1;
                int rightIdx = i*2 + 2;
                int largest = i;
                if (LeftIdx < size && arr[LeftIdx] > arr[largest]){
                        largest =LeftIdx;
                }

                if (rightIdx < size && arr[rightIdx] > arr[largest]){
                    largest= rightIdx;
                }

                if (largest == i){
                   break;
                }
                swap(arr[i] , arr[largest]);
                i=largest;
            }
            
        }
};
int main(){
    int arr[]={30,29, 50, 55, 20, 10};
    int n =sizeof(arr)/sizeof(arr[0]);
    Heap h;
   if (n>0){
     for ( int i=0 ; i<n ; i++){
        h.insert(arr[i]);
    }
   }else{
    cout <<"Array is empty!. Please insert values first "<<endl;
   }
   cout << "Before deletion ..."<<endl;
   h.Printing();
   cout << "Before deletion ..."<<endl;
   h.deleteFromHeap();
   h.Printing();
    return 0;
}