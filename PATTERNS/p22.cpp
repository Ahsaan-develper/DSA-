#include<iostream>
using namespace std;
int main(){
   for (int i=0 ; i<4 ; i++){
    for (int j=0 ; j<4-i-1;j++){
        cout <<" ";
    }
    cout <<"*";
  if (i !=0){
     for (int j=0; j<2*i-1;j++){
   cout <<" ";
   }
cout <<"*";
  }
    cout <<endl;
   }
   for (int i = 4- 2; i >= 0; i--) {
        // outer spaces
        for (int j = 0; j < 4 - i - 1; j++) {
            cout << " ";
        }
        cout << "*";

        // inner spaces
        if (i > 0) {
            for (int j = 0; j < 2 * i - 1; j++) {
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}