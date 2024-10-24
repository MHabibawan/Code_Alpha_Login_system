#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void registration()
{
    string username, password;
    cout << " Enter the username \n";
    cin >> username;
    cout << " Enter the password \n ";
    cin >> password;
    // saving user credentials
    ofstream userfile;
    userfile.open(username + ".txt");
    if (userfile.is_open())
    {
        userfile << username << endl;
        userfile << password << endl;
        userfile.close();
        cout << " Registration Sucessfull \n";
    }
    else
    {
        cout << " Error creating a user file \n";
    }
}
bool Login()
{
    string username, password, fileUsername, filepassword;
    cout << " Enter username \n";
    cin >> username;
    cout << " Enter pasword \n";
    cin >> password;
    ifstream userFile(username + ".txt");
    if (userFile.is_open())
    {
        getline(userFile, fileUsername);
        getline(userFile, filepassword);
        userFile.close();

        if (fileUsername == username && filepassword == password)
        {
            cout << "Login successful!   " << endl;
            return true;
        }
        else
        {
            cout << "Invalid username or password!" << endl;
            return false;
        }
    }
    else
    {
        cout << "User does not exist!" << endl;
        return false;
    }
}

int main()
{
    int choice;

    while (true)
    {
        cout << "\n *** USER LOGIN & REGISTRATION SYSTEM *** \n";
        cout << "1. Register \n";
        cout << "2. Login \n";
        cout << "3. Exit Application \n";
        cout << "Enter your choice \n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            registration();
            break;
        case 2:
            Login();
            break;
        case 3:
            cout << " Exiting the application \n";
            return 0;
        default:
            cout << " Invalid Choice \n";
            break;
        }
    }
}