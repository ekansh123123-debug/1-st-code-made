#include <iostream>
#include <string>
#include <fstream>
using namespace std;
bool email_cheak(string mail){
    bool condition1 = false, condition2 = false ;
    size_t i;
    for (i = 0 ; i < mail.length() ; i++){
        if(mail[i] == '@'){
            condition1 = true;
            break;
        }
    }
    for(;i < mail.length() ; i++){
        if(mail[i] == '.'){
            condition2 = true;
            break;
        }
    }
    return (condition1 & condition2) && mail.length() > 5; 
}
class Account
{
private:
    string password, username, email_adress, fusername, femail_adress, fpassword;
    fstream file;

public:
    void login_()
    {
        bool log = true;
        while (log)
        {
            cout << "Enter username : ";
            getline(cin, username);
            cout << "Enter email adress : ";
            getline(cin, email_adress);
            cout << "Enter password : ";
            getline(cin, password);
            file.open("loginid.txt", ios ::in);
            if(!file.is_open()) {
                cout << "Could not open the file" << endl;
                return;
            }
            while (getline(file, fusername, '*') && getline(file, femail_adress, '*') && getline(file, fpassword, '\n'))
            {
                if (fusername != username)
                    continue;
                else if (femail_adress != email_adress || fpassword != password)
                    break;
                else {
                    cout << "Correct credentials" << endl;
                    log = false;
                    break;
                }
            }
            cout << "Incorrect credentials" << endl;
            cout << "Try again" << endl;
            file.close();
            }
        cout << "loging in ..." << endl;
        file.close();
        // fuction of login
    }
    void registe()
    {
        while(true)
        {
            cout << "Enter username : ";
            getline(cin, fusername);
            if(fusername.length() < 6) {
                cout << "Try a longer username" << endl;
                continue;
            }

            cout << "Enter email adress : ";
            getline(cin, femail_adress) ;
            if(!email_cheak(femail_adress)){
                cout << "Incorrect email format " << endl;
                cout << "Try again " << endl;
                continue;
            }

            cout << "Enter password : ";
            getline(cin, fpassword);
            if (fpassword.length() < 6)
            {
                cout << "Try a longer password" << endl;
                continue;
            }
            break;
        }


        file.open("loginid.txt", ios ::out | ios::app);
        file << fusername << "*" << femail_adress << "*" << fpassword << endl;

        file.close();
        if(file.is_open()){
            cout << "Failed to register " << endl;
            cout << "Try again later ..." << endl;
            return;
        }
        cout << "Registration Sucessfull";
    }
    void forgt_passerd()
    {
        cout << "Enter username : ";
        getline(cin, username);
        cout << "Enter email adress : ";
        getline(cin, email_adress);
        file.open("loginid.txt", ios ::in);
        while(getline(file, fusername, '*') &&
            getline(file, femail_adress, '*') &&
            getline(file, fpassword, '\n'))
        {
            if (username == fusername)
            {
                if (femail_adress == email_adress)
                {
                    cout << "Password is : " << fpassword;
                    break;
                }
                else
                {
                    cout << "Could not find ...";
                    break;
                }
            }
            else
            {
                getline(file, fusername, '*');
                getline(file, femail_adress, '*');
                getline(file, fpassword, '\n');
            }
        }
        file.close();
    }
} obj;
int main()
{
    Account a1;
    cout << "Select" << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. Forgot Password" << endl;
    cout << "4. Exit" << endl;
    int cas;
    cin >> cas;
    switch (cas)
    {
    case 1:
        cin.ignore();
        obj.login_();
        break;
    case 2:
        cin.ignore();
        obj.registe();
        break;
    case 3:
        cin.ignore();
        obj.forgt_passerd();
        break;
    case 4:
        return 0;
        break;

    default:
        cout << "invalid input";
        break;
    }
    return 0;
}