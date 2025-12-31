#include <iostream>
using namespace std;
class Solution {
    private:
        string s1 ,s2;
    public:
        bool isFreSame(int fre1[] , int fre2[]){
           for (int i=0 ; i<26 ;i++){
             if (fre1[i] != fre2[i]){
                return false;
            }
           }
            return true;
        }
        bool Permutation(){

            cout <<"Enter a string here !"<<endl;
            cin>>s1;
            cout <<"Enter part to check here !"<<endl;
            cin>>s2;
            int freq[26] ={0};
            for (int i=0 ;i<s1.length() ;i++){
                freq[s1[i] -'a']++;
            }
            int windSize = s1.length();
            for (int i=0 ;i<s2.length();i++){
               int windIdx =0 , idx=i;
               int windFre[26]={0};
               while(windIdx<windSize && idx <s1.length()){
                windFre[s2[i]-'a']++;
                windIdx++;
                idx++;
               }
               if (isFreSame(freq, windFre)){
                return true;
               }

            }
            return false;
            if (isFreSame){
                cout <<"permutaion"<<endl;
            }else{
                cout <<"Not "<<endl;
            }
        }
};
int main(){
    Solution sol;
    sol.Permutation();
    return 0;
}