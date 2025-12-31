#include<iostream>
using namespace std;

class Solution {
    public :
        bool isAlpha (char ch){
            if ((ch>='0' && ch <='9')|| (tolower(ch)>='a' && tolower(ch)<='z')){
                return true;
            }else{
                return false;
            }
        }

        bool isPallindrome(){
            string s;
            cout <<"Enter string here!"<<endl;
            cin>>s;
            int start=0;
            int end = s.length()-1;
            while (start<end){
                if(!isAlpha(s[start])){
                    start++;continue;
                }else if (!isAlpha(s[end]))
                {
                  end--;continue;
                }else{
                    if (tolower(s[start]) != tolower(s[end])){
                        return false;
                    }
                    start++;
                    end--;
                }
                return true;
               
            }
            return true;
        }

};
int main(){
    Solution sol ;
    if (sol.isPallindrome()){
        cout <<"Yes it is pallindrome"<<endl;
    }else{
        cout <<"It is not "<<endl;
    }
    return 0;
}