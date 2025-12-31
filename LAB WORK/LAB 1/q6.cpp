#include<iostream>
using namespace std;
int GetUpperLimit(){
    int limit;
    cout <<"Enter upper limit here that not exceed 1000"<<endl;
    cin>>limit;
    return limit;
   
}
void SumOfEven(int limit){
     if (limit>1000){
        cout<<"Your limit exceed to 1000 so Please enter limit upto 1000"<<endl;
        return ;
    }
   
    int sum =0;
for (int i=1 ; i<=limit;i++){
    if (i % 2 ==0){
        sum +=i;
    }
}
cout <<"Sum of even Num : \t"<<sum<<endl;

    return ;
}
int main(){
    int limit =GetUpperLimit();
    SumOfEven(limit);
    return 0;
}