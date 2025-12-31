#include <iostream>
using namespace std;
int main(){
    int first,second;
    cout <<"Enter first value"<<endl;
    cin>>first;
    cout<<"Enter second value "<<endl;
    cin>>second;
    cout <<"-------------Before swapping -------"<<endl;
     cout <<" first value : "<<first<<"\t second value : "<<second<<endl;
    int temp = first;
    first = second;
    second = temp;
    cout <<"-------------After swapping -------"<<endl;
    cout <<" first value : "<<first<<"\t second value : "<<second<<endl;
    return 0;
}