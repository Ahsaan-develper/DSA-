#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>vec;
    int val ;
    for (int i=0 ; i<5 ;i++){
         cout <<"Enter value :"<<endl;
    cin>>val;
    vec.push_back(val);
    }
    cout<<"Size is :" <<vec.size()<<endl;
    for (int val : vec){
        cout <<val <<" ";
    }
    return 0;
}