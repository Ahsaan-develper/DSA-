// #include <iostream>
// using namespace std;
//  int main(){
//     int arr[]= {1,2,3,4,5,6};
//     int target=6;
//     bool found=false;
//     for (int i=0 ; i<6; i++){
//         if (arr[i]==target){
//             found = true;
//         }else{
//            found =false;
//         }
//     }
//     if (found){
//         cout <<target <<"Found";
//     }else{
//         cout <<"Not found";
//     }
//     return 0;
//  }

#include <iostream>
using namespace std;
 int main(){
    int arr[]= {1,2,3,4,5,6};
    int target=5;
    for (int i=0 ; i<6; i++){
        if (arr[i]==target){
          cout <<"Found"<<endl;
          break;
        }else{
            cout <<"not found";  
        }
    }
    
   
    return 0;
 }