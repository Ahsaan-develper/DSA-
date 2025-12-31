#include<iostream>
using namespace std;
int main(){
     int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int* arr =  (int*) malloc(n * sizeof(int));
    if (arr== NULL){
        cout <<"Memory allocation is failed "<<endl;
        return 0;
    }
    cout <<"Enter integers ";
    for (int i=0 ; i<n ; i++){
        cin >> arr[i];
    }
    for ( int i=0 ; i<n ; i++){
        cout <<arr[i]<<" ";
    }
    cout <<endl;
    free(arr);
    return 0;
}