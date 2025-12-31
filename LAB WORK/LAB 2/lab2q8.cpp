#include<iostream>
#include<cstring>
using namespace std;
void revString (char* ptr ){
    int size = strlen(ptr);
    int start =0,end= size-1;
    while (start < end){
        char temp= ptr[start];
        ptr[start]=ptr[end];
        ptr[end]=temp;
        start++;
        end--;
    }
    return ;
   
    

}
int main(){
    char s[20]= "somestring";
    cout <<"----Before Reversing----"<<endl;
    cout <<s<<endl;
    revString(s);
    cout <<"----After Reversing----"<<endl;
    cout<<s<<endl;


    return 0;
}