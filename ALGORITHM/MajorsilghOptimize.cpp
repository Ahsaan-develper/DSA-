#include<iostream>
#include <algorithm>

using namespace std;
int main(){
    int arr[]={1,2,3,3,3,3,3,4,1};
    int size = sizeof(arr)/ sizeof(arr[0]);
    sort(arr , arr + size );
    bool found = false;
    int freq =1, ans = arr[0];
   for (int i =1 ; i<size ; i++){
    if (arr[i] == arr[i-1]){
        freq++;
    }else{
        freq=1;
        ans=arr[i];
    }
    if (freq > size /2){
        found = true;
        break;
    }
   }
   if(found ){
    cout <<" Major alement is "<<ans<<endl;
   }else{
    cout <<"major not found"<<endl;
   }
    return 0;
}