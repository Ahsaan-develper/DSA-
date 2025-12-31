#include<iostream>
#include<vector>
using namespace std;
void pairSum(){
    vector<int>vec;
    int arr[5]={1,2,3,5,2};
    int target ;
    cout <<"Enter target here !"<<endl;
    cin>>target;
    for (int i=0;i<5;i++){
        for (int j=i+1;j<5;j++){
            if (arr[i]+ arr[j]==target){
                vec.push_back(arr[i]);
                vec.push_back(arr[j]);
            }
        }
    }
   if (vec.empty()){
    cout <<"Not found"<<endl;
   }else{
    for (int val : vec){
        cout <<val <<" ";
    }
   }
    

}
int main(){
   pairSum();

    return 0;
}