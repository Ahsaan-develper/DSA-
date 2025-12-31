#include<iostream>
using namespace std;
void majority(){
    int arr[]={1,2,3,1,1};
    bool found = false;
    int num ;
    for(int i=0 ;i<5;i++){
        int freq =0;
        
        for (int j=0 ; j<5 ; j++){
            if (arr[i]== arr[j]){
                freq++;
            }
        }
        if (freq > 5 / 2){  
            num = arr[i];
            found = true;
        }
    }
    if (! found ){
        cout <<" major element not found"<<endl;
    }else{
         cout <<" Majority element is "<<num<<endl;
    }
}
int main(){
majority();
    return 0;
}