#include<iostream>
#include<vector>
using namespace std;
 int main(){
    vector<int>vec ={1,4,1,3,3};
    int ans =0;
    for (int val : vec){
        ans = ans ^val;
    }
cout <<ans;
    return 0;
 }