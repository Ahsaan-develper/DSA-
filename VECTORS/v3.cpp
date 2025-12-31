#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>vec;
    int val;
    for (int i=0 ;i<5 ; i++){
        cout <<"Enter value here !" <<endl;
        cin>>val;
        vec.push_back(val);
    }
    for (int i=0 ;i<2;i++){
        vec.pop_back();
    }
for (int val : vec){
    cout <<val <<" ";
}
    return 0;
}