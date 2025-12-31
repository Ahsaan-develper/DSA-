#include<iostream>
using namespace std;
int main(){
   int arr []={1,2,3,4,5};
   int sum =0, maxSum=arr[0];
   for (int i=0 ; i< 5 ; i++){
        sum += arr[i];
        if (sum> maxSum){
            maxSum= sum ;
        }else if ( sum == maxSum){
            maxSum = sum;
        }
        if ( sum < 0){
            sum = 0;
        }
   }
   cout << " Max sub array is "<<maxSum<<endl;
}