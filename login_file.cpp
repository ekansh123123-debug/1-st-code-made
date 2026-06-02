#include <iostream>
#include <string>
#include <fstream>
using namespace std;
bool email_cheak(const string &mail){
    bool condition1 = false, condition2 = false;
    size_t i = 0 ;
    while(i < mail.length())
    {
        if (mail[i] == '@')
        {
            condition1 = true;
            break;
        }
        i++;
    }
    while (i < mail.length())
    {
        if (mail[i] == '.')
        {
            condition2 = true;
            break;
        }
        i++;
    }
    return (condition1 & condition2) && mail.length() > 5;
}
bool correct_username(const string &username){
    fstream file;
    string temp_username, temp_email_adress, temp_password;
    file.open("loginid.txt", ios ::in);
    if (!file.is_open()){
        return true;
    }
    while (getline(file, temp_username, '*') && getline(file, temp_email_adress, '*') && getline(file, temp_password, '\n')){
        if (username == temp_username){
            file.close();
            return false;
        }
    }
    file.close();
    return username.length() > 4;
}
class Account
{
private:
    string password, username, email_adress, temp_username, temp_email_adress, temp_password;
    fstream file;

public:
    void login_function()
    {
        while (true)
        {
            cout << "Enter username : ";
            getline(cin, username);
            cout << "Enter email adress : ";
            getline(cin, email_adress);
            cout << "Enter password : ";
            getline(cin, password);
            file.open("loginid.txt", ios ::in);
            if (!file.is_open())
            {
                cout << "Could not open the file" << endl;
                return;
            }
            while (getline(file, temp_username, '*') && getline(file, temp_email_adress, '*') && getline(file, temp_password, '\n'))
            {
                if (temp_username != username)
                    continue;
                else if (temp_email_adress != email_adress || temp_password != password)
                    break;
                else
                {
                    cout << "Correct credentials" << endl;
                    cout << "loging in ..." << endl;
                    file.close();
                    // fuction of login
                    return;
                }
            }
            cout << "Incorrect credentials" << endl;
            cout << "Try again" << endl;
            file.close();
        }
    }
    void registe_function()
    {
        while (true)
        {
            cout << "Enter username : ";
            getline(cin, temp_username);
            if (!correct_username(username))
            {
                cout << "This name is already taken or incorrect length" << endl;
                cout << "Please try another username " << endl;
                continue;
            }

            cout << "Enter email adress : ";
            getline(cin, temp_email_adress);
            if (!email_cheak(temp_email_adress))
            {
                cout << "Incorrect email format " << endl;
                cout << "Try again " << endl;
                continue;
            }

            cout << "Enter password : ";
            getline(cin, temp_password);
            if (temp_password.length() < 6)
            {
                cout << "Try a longer password" << endl;
                continue;
            }
            break;
        }

        file.open("loginid.txt", ios ::out | ios::app);
        file << temp_username << "*" << temp_email_adress << "*" << temp_password << endl;

        file.close();

        if (file.is_open())
        {
            cout << "Failed to register " << endl;
            cout << "Try again later ..." << endl;
            return;
        }

        cout << "Registration Sucessfull";
    }
    void forgot_password()
    {
        cout << "Enter username : ";
        getline(cin, username);
        cout << "Enter email adress : ";
        getline(cin, email_adress);
        file.open("loginid.txt", ios ::in);
        while (getline(file, temp_username, '*') &&
               getline(file, temp_email_adress, '*') &&
               getline(file, temp_password, '\n'))
        {
            if (username == temp_username)
            {
                if (temp_email_adress == email_adress)
                {
                    cout << "Password is : " << temp_password;
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
                getline(file, temp_username, '*');
                getline(file, temp_email_adress, '*');
                getline(file, temp_password, '\n');
            }
        }
        file.close();
    }
} obj;
int main()
{
    Account a1;
    while(true)
        {
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
                obj.login_function();
                return 0;
            case 2:
                cin.ignore();
                obj.registe_function();
                break;
            case 3:
                cin.ignore();
                obj.forgot_password();
                break;
            case 4:
                return 0;
                break;

            default:
                cout << "invalid input \nTry again" << endl;

                break;
            }
        }
    return 0;
}