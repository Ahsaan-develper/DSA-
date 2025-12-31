#include <iostream>
using namespace std;
class Solution{
    public :
        void RemovePart(){
            string s, part;
            cout <<"Enter string here :"<<endl;
            cin>>s;
            cout <<"Enter string part here :"<<endl;
            cin>>part;
            bool flag=false;
            while (s.length()>0 && s.find(part)<s.length()){
                s.erase(s.find(part),part.length());
                flag = true;
            }

            if (!flag){
                cout <<"Part not found here \t"<<s<<endl;
            }
        }

} ;
int main(){
    Solution sol;
    sol.RemovePart();
    return 0;
}