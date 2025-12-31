#include<iostream>
using namespace std;
 int main(){
    int n, newElement;
       cout <<"Enter elements"<<endl;
        cin>>n;
        int* arr = (int*)malloc(n * sizeof(int));
        cout <<"Enter integers : ";
        for (int i =0 ; i<n; i++){
            cin >>arr[i];
        }
        cout <<"New eleemnet "<<endl;
        cin>> newElement;
        arr = (int*)realloc(arr,(n+1) * sizeof(int));
        arr[n]=newElement;
        n++;
         cout << "Array after insertion:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Free allocated memory
    free(arr);

    return 0;
 }