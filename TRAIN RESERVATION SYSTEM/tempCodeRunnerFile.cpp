#include <iostream>
using namespace std ;
// ============================= Show Stations  Class============================== 
class ShowStaions {

    private :

    public:

    // Constructor 
        ShowStaions(){

        }
// --------------------------------Show Station Function------------------------------      
        void showStations (){

        }
};


// ============================= Admin Registration Class============================== 
class AdminRegistration {
    private:
    
    public:

        AdminRegistration(){

        }
// --------------------------------Admin SignUp Function----------------------------

        void signUp (){

        }
// --------------------------------Admin Login Function----------------------------
        void login (){

        }

// --------------------------------Admin Registration Panel Function-----------------------
        void registrationPanel (){
            string choice ;
            int num ;
            cout <<"\t 1. Admin Sign Up "<<endl;
            cout <<"\t 2. Admin Login "<<endl;
            cout <<"\t 3. Exit the Admin Authentication "<<endl;
            cout <<"Please select an option ";
            num = atoi(choice.c_str());

                switch (num)
                {
                case 1 :
                    signUp();
                    break;
                case 2 :
                    login() ;
                    break;
                case 3 :
                    cout <<"Good bye!!! From Admin Authentication Panel"<<endl;
                    break;
                default:
                    cout <<"Invalid option Pleaase select again !"<<endl;
                    break;
                }while(num !=3);
        }
};


class Admin {
    private :

    public:
        Admin(){

        }
        // --------------------------------Admin BookSeat Function-------------------------

        void bookSeat (){

        }
// --------------------------------Admin ViewSeat Function-------------------------
        void viewSeat (){
            
        }
// --------------------------------Admin CancelSeat Function-----------------------
        void cancelSeat (){

        }
// --------------------------------Admin UpdateSeat Function-----------------------
        void updateSeat (){

        }
// --------------------------------Admin Panel Function-----------------------
        void adminPanel(){

        }

// --------------------------------Admin Panel Function-----------------------
        void Panel (){
            string choice ;
            int num ;
            cout <<"\t 1. Admin Book Seats "<<endl;
            cout <<"\t 2. Admin View Seats "<<endl;
            cout <<"\t 3. Admin Cancel Seats "<<endl;
            cout <<"\t 4. Admin Update Seats "<<endl;
            cout <<"\t 5. Exit Admin Panel "<<endl;
            cout <<"Please select an option ";
            num = atoi(choice.c_str());

                switch (num)
                {
                case 1 :
                    bookSeat();
                    break;
                case 2 :
                    viewSeat();
                    break;
                case 3 :
                    cancelSeat();
                    break;
                case 4 :
                    updateSeat();
                    break;
                case 5 :
                    cout <<"Good bye !!! From admin Panel"<<endl;
                    break;
                default:
                    cout <<"Invalid option Pleaase select again !"<<endl;
                    break;
                }while(num !=5);
        }
};

// ============================= Show List Class================================
class ShowList {
    private:

    public:
    // Constructor 
        ShowList(){

        }
// --------------------------------Show  List Function-----------------------
        void showList (){

        }
};
// --------------------------------Main Function-----------------------
int main(){
    string choice ;
    int num ;
        do {
        cout << "\n--- TRAIN RESERVATION SYSTEM ---\n";
        cout << "1. View Train Stations \n";
        cout << "2. Admin \n";
        cout << "3. View List\n";
        cout << "4. Exit the system \n";
        cout << "Please select an option  ";
        num = atoi(choice.c_str());
        cin >> num;   
            
            switch (num )
            {
            case 1 :
                ShowStaions station ;
                station.showStations();
            case 2:
                AdminRegistration register ;
                    register.mainFunction();
            case 4 :
                cout <<"Good bye!!! The system is exit !"<<endl;
                break;
            
            default:
                cout <<"Invalid number so enter correct number"<<endl;
                break;
            }
        }while(num != 4);
    return 0;
}