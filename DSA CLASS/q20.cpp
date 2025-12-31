#include<iostream>
using namespace std;
int main(){
    int arr[8]={1,2,3,4,5,6,7,8};
    int s = 8;
    cout <<"All elements : ";
    for (int i=0 ; i<s ; i++){
        cout <<arr[i]<< " ";
    }
    cout <<endl;
    // delete 1st element
    for (int i=0 ; i<s-1; i++){
        arr[i]= arr[i+1];
    }
    s--;
    cout <<"Delete first : ";
    for (int i=0 ; i<s ; i++){
        cout <<arr[i]<< " ";
    }
    cout <<endl;
    int pos ;
    cout <<"Enter pos here from 0 to "<<s-1<<endl;
    cin>>pos;
    for (int i=pos ; i<s-1; i++){
        arr[i]= arr[i+1];
    }
    s--;
    cout <<"Delete at position  : ";
    for (int i=0 ; i<s ; i++){
        cout <<arr[i]<< " ";
    }
    cout <<endl;
    s--;
    cout <<"Delete at end  : ";
    for (int i=0 ; i<s ; i++){
        cout <<arr[i]<< " ";
    }
    return 0;
}