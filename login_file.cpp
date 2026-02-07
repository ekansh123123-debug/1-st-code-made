#include<bits/stdc++.h>
using namespace std;
class Account{
private:
    string password , username , email_adress , fusername , femail_adress , fpassword;
    fstream file;
public:
    void log(){
        cout << "Enter username : " ;
        getline(cin , fusername);
        cout << "Enter email adress : " ;
        getline(cin , femail_adress);
        cout << "Enter password : " ;
        getline(cin , fpassword);
        file.open("loginid.txt",ios :: in);
        getline(file , username , '*');
        getline(file , email_adress , '*');
        getline(file , password , '\n');
        while(!file.eof()){
            if(fusername == username){
                if(femail_adress == email_adress){
                    if(fpassword == password){
                        cout << "Login Suscessful";
                        break;
                    }
                    else{
                        cout << "Wrong Password";
                        break;
                    }
                }
                else{
                    cout << "Email Id does not match with Username" ;
                    break;
                }
            }
            getline(file , username , '*');
            getline(file , email_adress , '*');
            getline(file , password , '\n');
        }
        file.close();
    }
    void registe(){
        cout << "Enter username : " ;
        getline(cin,fusername);
        cout << "Enter email adress : " ;
        getline(cin,femail_adress);
        cout << "Enter password : " ;
        getline(cin,fpassword);
        file.open("loginid.txt",ios :: out |ios::app);
        file << fusername << "*" << femail_adress << "*" << fpassword << endl;
        file.close();
        cout << "Registration Sucessfull"; 
    }
    void forgt_passerd(){
        cout << "Enter username : " ;
        getline(cin , username);
        cout << "Enter email adress : " ;
        getline(cin , email_adress);
        file.open("loginid.txt", ios :: in);
        getline(file , fusername , '*');
        getline(file , femail_adress , '*');
        getline(file, fpassword , '\n');
        while(!file.eof()){
            if(username == fusername){
                if(femail_adress == email_adress){
                    cout << "Password is : " << fpassword;
                    break;
                }
                else{
                    cout << "Could not find ..." ;
                    break;
                }
            }
            else{
                getline(file , fusername , '*');
                getline(file , femail_adress , '*');
                getline(file,fpassword,'\n');
            }
        }
        file.close();
    }
}obj;
int main(){
    Account a1;
    cout << "Select" << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. Forgot Password" << endl;
    cout << "4. Exit" << endl ;
    int cas;
    cin >> cas;
    switch (cas)
    {
        case 1:
            cin.ignore();
            obj.log();
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
        cout << "invalid input" ;
        break;
    }
    return 0;
}