#include<iostream>
#include<vector>
using namespace std;
    void getPermutaion( vector<int> vec , int idx ,   vector<vector<int>> &ans ){
        if (idx==vec.size()){
            ans.push_back({vec});
            return;
        }else{
            for (int i= idx ; i<vec.size(); i++){
            swap(vec[idx], vec[i]);
            getPermutaion(vec , idx+1 , ans);
            swap(vec[idx], vec[i]);
        }
        }
    }
int main(){
    vector<int> vec = {1,2,3};
    vector<vector<int>>ans;
    int idx = 0;
        getPermutaion(vec , idx , ans);
    return 0;
}