#include<iostream>
using namespace std;
void AscendingSort (){
    int digit[10];
    for (int i=0 ;i<10;i++){
        cout <<"Enter digits"<<endl;
        cin>>digit[i];
    }

    for (int i=0 ;i<10;i++){
        for (int j=i+1;j<10;j++){
            if (digit[i]>digit[j]){
                int temp= digit[i];
                digit[i]=digit[j];
                digit[j]=temp;
            }
        }
    }
    for (int i=0 ;i<10;i++){
        cout <<digit[i]<<" ";
    }
    return ;
}
int main(){
AscendingSort();
    return 0;
}