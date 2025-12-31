#include<iostream>
using namespace std;
int main(){
    int n , newElement ;
    cout <<"Enter number of elements "<<endl;
    cin>>n;
    int* arr = (int*) malloc(n * sizeof(int));
    cout <<"Enter "<<n <<" numbers here "<<endl;
    for (int i=0; i<n ; i++){
        cin>>arr[i];
    }
    cout <<"Enter new element to place it at last "<<endl;
    cin>>newElement;
    arr= (int*)realloc(arr,(n+1)  * sizeof(int));
    arr[n]=newElement;
    n++;
    cout <<"Numbers are :";
    for (int i=0 ; i<n ; i++){
        cout <<arr[i]<< " ";
    }
    free(arr);
    return 0;
}