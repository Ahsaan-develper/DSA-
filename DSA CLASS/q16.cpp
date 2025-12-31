#include<iostream>
using namespace std;
int main(){
    int n;
    cout <<"Enter number of elemnts "<<endl;
    cin>>n;
    int arr[n];
    cout <<"Enter "<<n<< " numbers here "<<endl;
    for (int i =0 ; i<n ; i++){
        cin >> arr[i];
    }
    int* ptr = arr;
    for ( int i=0 ; i<n ; i++){
        cout <<*(ptr +i)<<" ";
    } 

    return 0;
}