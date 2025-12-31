#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>vec={1,2,3,4,5};
    int ans=0;
    for(int val : vec){
       if (val %2==0){
        ans += val;
       }
      
    }
     cout <<ans;
    return 0;
}