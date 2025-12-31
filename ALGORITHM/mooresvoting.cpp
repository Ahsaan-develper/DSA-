#include<iostream>
using namespace std;
int main(){
    int arr[]= {1,2,3,3,4};
    int freq=0, ans =0;
    for (int i=0 ; i< 5 ; i++){
        if (freq==0){
            ans = arr[i];
        }
        if (ans == arr[i]){
            freq++;
        }else{
            freq--;
        }
    }
    cout <<" Majrity element is "<<ans<<endl;
}