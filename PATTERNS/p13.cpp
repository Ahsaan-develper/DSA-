// #include <iostream>
// using namespace std;
//  int main(){
//     for (int i=0 ; i<4 ; i++){
//         for (int j=0 ; j<4;j++){
//             if (j==i){
//                 cout <<"*";
//             }else{
//                 cout <<".";
//             }
//         }
//         cout <<endl;
//     }
//     return 0;
//  }
#include <iostream>
using namespace std;
 int main(){
    for (int i=0 ; i<4 ; i++){
        for (int j=0 ; j<i;j++){
            cout <<".";
        }
        for (int k=0 ; k<1; k++){
            cout <<"*";
        }
        cout <<endl;
    }
    return 0;
 }