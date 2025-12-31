#include<iostream>
using namespace std;
int sum ( int num){
   
   
    if (num ==1){
        return 1;
    }
    return  num + sum(num-1);
}
int main(){
    cout << "Sum is : "<<sum(4) << endl;
    return 0;
}