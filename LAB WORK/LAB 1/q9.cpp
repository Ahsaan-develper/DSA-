#include<iostream>
using namespace std;
int main(){
    char ch ='c';
    int guess=1;
    bool correct=false;
    do {
        char g;
        cout <<"Guess character between a to z"<<endl;
        cin>>g;
        if (g==ch){
            cout <<"You gess write character"<<endl;
            if (guess ==1){
                cout <<"You get score : 10000";
                return 0;
            }else if(guess ==2){
                cout <<"You get score : 8000";
                return 0;
            }else if(guess ==3){
                cout <<"You get score : 6000";
                return 0;
            }else if(guess ==4){
                cout <<"You get score : 4000";
                return 0;
            }else if(guess ==5){
                cout <<"You get score : 2000";
                return 0;
            }
            correct = true;
            
        }
        guess++;


    }while(guess <=5);
    if (!correct){
        cout <<"You waste all your tries"<<endl;
    }
    return 0;
}