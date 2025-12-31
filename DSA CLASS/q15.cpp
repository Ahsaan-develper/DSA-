#include<iostream>
using namespace std;
int main(){
    int n ;
    cout <<"Enter number of elements "<<endl;
    cin>> n;
    int* arr=(int*) malloc(n* sizeof(int));
    if (arr==NULL){
        cout <<"Failed to allocate memory "<<endl;
        return 1;
    }
    cout << "Enter "<<n << " numbers "<<endl;
    for (int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
    cout <<"Numbers are : ";
    for (int i=0 ; i<n ; i++){
        cout <<arr[i]<<" ";
    }
    free(arr);
    return 0;
}