// #include <iostream>
// using namespace std;
// int main(){
   
//     int arr[]={1,2,12,4,5};
//  int largest= arr[0];
//  int bytes = sizeof(arr);
//  int elemnt = sizeof(arr[0]);
//  int len = bytes / elemnt;
//  for (int i=0 ; i<len ; i++){
//     if (arr[i]>largest){
//         largest = arr[i];
//     }
//  }
//  cout <<"Largest number is :"<<largest<<endl;
//     return 0;
// }
#include <iostream>
using namespace std;
int main(){
   
    int arr[]={1,2,12,20,5};
 int largest;
 int bytes = sizeof(arr);
 int elemnt = sizeof(arr[0]);
 int len = bytes / elemnt;
 for (int i=0 ; i<len ; i++){
   for (int j=0 ;j<len ; j++){
    if (arr[i]<arr[j]){
        largest = arr[j];
    }
    // else{
    //     largest= arr[j];
    // }
   }
 }
 cout <<"Largest number is :"<<largest<<endl;
    return 0;
}