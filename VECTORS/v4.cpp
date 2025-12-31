#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>vec ={1,2,3,4,5};
   cout << vec.front()<<endl;
   cout << vec.back()<<endl;
   cout << vec.at(4)<<endl;

    return 0;
}