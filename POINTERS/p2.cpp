#include <iostream>
using namespace std ;
int main(){
    int* ptr ;
    int* ptr1 =ptr + 2;
    cout<<"ptr address"<<&ptr<<endl;
    cout <<"PTR new address "<<ptr1<<endl;
    cout <<"ptr1 - ptr \t"<<ptr1 - ptr<<endl;
    //array
    int arr[]=  {1,2,4,5};
    int* ptr2 =arr + 1;
    int* ptr3 =ptr2 + 3;
    cout <<"ptr value on array "<<*ptr2<<endl; 

    return 0;
}