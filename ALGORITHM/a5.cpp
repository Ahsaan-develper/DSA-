#include<iostream>
#include<vector>
using namespace std;
void PairSum(){
    int arr[]={1,2,7,8,10,80};
    vector<int>vec;
    int target;
    cout <<"Enter target here !"<<endl;
    cin>>target;
    int st=0,end = 5,sum=0;
    while (st<end)
    {
        sum = arr[st] +arr[end];
        if (sum ==target){
        vec.push_back(arr[st]);
        vec.push_back(arr[end]);
        st++;
        end--;
        }else if (sum <target){
            st++;
        }else if (sum > target){
            end--;
        }
    }
    
   if (vec.empty()){
    cout <<"Target not found here!"<<endl;
   }else{
    for (int val : vec){
        cout <<val<<" ";
    }
   }
}
int main(){
    PairSum();
    return 0;
}