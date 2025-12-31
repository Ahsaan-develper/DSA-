#include <iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>vec(3,8);
    cout<<vec[0]<<" ";
    cout<<vec[1]<<" ";
    cout<<vec[2]<<" "<<endl;
    vector<int>vec2 ={1,2,3,4,5,6,7,8};
    for(int val : vec2){
        cout <<val <<" ";
    }
    return 0;
}