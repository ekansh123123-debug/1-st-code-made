#include <iostream>
#include <string>
#include <fstream>
bool email_cheak(const std::string &mail){
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
bool correct_username(const std::string &username){
    std::fstream file;
    std::string temp_username, temp_email_adress, temp_password;
    file.open("loginid.txt", std:: ios ::in);
    if (file.is_open()){
    while (getline(file, temp_username, '*') && getline(file, temp_email_adress, '*') && getline(file, temp_password, '\n')){
        if (username == temp_username){
            file.close();
            return false;
        }
    }
    file.close();
    }
    return username.length() > 4;
}
class Account
{
private:
    std::string password, username, email_adress;
    std::string temp_username, temp_email_adress, temp_password;
    std::fstream file;

public:
    void login_function()
    {
        while (true)
        {
            std::cout << "Enter username : ";
            getline(std::cin, username);
            std::cout << "Enter email adress : ";
            getline(std::cin, email_adress);
            std::cout << "Enter password : ";
            getline(std::cin, password);
            file.open("loginid.txt", std::ios ::in);
            if (!file.is_open())
            {
                std::cout << "Could not open the file" <<std:: endl;
                std::cout << "Try to register" << std::endl;
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
                    std::cout << "Correct credentials" <<std:: endl;
                    std::cout << "loging in ..." << std::endl;
                    file.close();
                    // fuction of login
                    return;
                }
            }
            std::cout << "Incorrect credentials" <<std:: endl;
            std::cout << "Try again" << std::endl;
            file.close();
        }
    }
    void registe_function()
    {
        while (true)
        {
            std::cout << "Enter username : ";
            getline(std::cin, temp_username);
            if (!correct_username(temp_username))
            {
                std::cout << "This name is already taken or incorrect length" << std::endl;
                std::cout << "Please try another username " << std::endl;
                continue;
            }

            std::cout << "Enter email adress : ";
            getline(std::cin, temp_email_adress);
            if (!email_cheak(temp_email_adress))
            {
                std::cout << "Incorrect email format " << std::endl;
                std::cout << "Try again \n" << std::endl;
                continue;
            }

            std::cout << "Enter password : ";
            getline(std::cin, temp_password);
            if (temp_password.length() < 6)
            {
                std::cout << "Try a longer password" << std::endl;
                continue;
            }
            break;
        }

        file.open("loginid.txt", std::ios ::out | std::ios::app);
        file << temp_username << "*" << temp_email_adress << "*" << temp_password << std::endl;

        file.close();

        if (file.is_open())
        {
            std::cout << "Failed to register " <<std:: endl;
            std::cout << "Try again later ..." << std::endl;
            return;
        }

        std::cout << "Registration Sucessfull";
    }
    void forgot_password()
    {

        std::cout << "Enter username : ";
        getline(std::cin, username);

        std::cout << "Enter email adress : ";
        getline(std::cin, email_adress);

        file.open("loginid.txt", std::ios ::in);
        if(!file.is_open()){
            std::cout << "Errer in opening the file " << std::endl;
            std::cout << "Try to register" << std::endl;
            return;
        }

        while (getline(file, temp_username, '*') && getline(file, temp_email_adress, '*') && getline(file, temp_password, '\n')) {
            if (username == temp_username)
            {
                if (temp_email_adress == email_adress){
                    std::cout << "Password is : " << temp_password << std::endl;
                    file.close();
                    return;
                }
                else{
                    std::cout << "username does not match email adress ..." <<std:: endl;
                    std::cout << "Pleas try again or register " << std::endl;
                    file.close();
                    return;
                }
            }
        }
        std::cout << "Could not find username\nTry again or register " << std::endl;
        file.close();
    }
} obj;
int main()
{
    Account a1;
    while(true)
        {
            std::cout << "Select" << std::endl;
            std::cout << "1. Login" << std::endl;
            std::cout << "2. Register" << std::endl;
            std::cout << "3. Forgot Password" << std::endl;
            std::cout << "4. Exit" << std::endl;
            int cas;
            std::cin >> cas;
            switch (cas)
            {
            case 1:
                std::cin.ignore();
                obj.login_function();
                return 0;
            case 2:
                std::cin.ignore();
                obj.registe_function();
                break;
            case 3:
                std::cin.ignore();
                obj.forgot_password();
                break;
            case 4:
                return 0;
                break;
            default:
                std::cout << "invalid input \nTry again" << std::endl;
                break;
            }
        }
    return 0;
}