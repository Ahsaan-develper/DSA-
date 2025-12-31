#include<iostream>
#include<vector>
using namespace std;
void PrintAllSub(vector<int>& vec , vector<int> &ans , int i){
    if (i == vec.size()){
        for (int val : ans){
            cout <<val<<" ";
        }
        cout <<endl;
    }else{
        // inlcude 

        ans.push_back(vec[i]);
        PrintAllSub(vec , ans , i+1);
        // exlude 

        ans.pop_back();
        PrintAllSub(vec , ans , i+1);

    }
}
int main(){
    vector<int>vec={1,2,3};
    vector<int>ans;
    PrintAllSub(vec , ans , 0);
    return 0;
}