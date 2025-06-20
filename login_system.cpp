
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void login();
void registration();
void forget();

int main()
{
    int c;
    do {
        cout << "\n                MENU                     \n";
        cout << " press 1 to LOGIN\n";
        cout << " press 2 to REGISTRATION\n";
        cout << " press 3 if you forget your PASSWORD\n";
        cout << " press 4 to EXIT\n";
        cout << "\nPlease enter your choice: ";
        cin >> c;
        cout << endl;

        switch (c)
        {
        case 1:
            login();
            break;
        case 2:
            registration();
            break;
        case 3:
            forget();
            break;
        case 4:
            cout << "\t\t\tThank you!\n\n";
            break;
        default:
            cout << "\tPlease select from the options given above\n";
        }

    } while (c != 4);
    return 0;
}

void login()
{
    int count = 0;
    string userid, password, id, pass;
    cout << "Please enter the username & password\n";
    cout << "\tUSERNAME: ";
    cin >> userid;
    cout << "\tPASSWORD: ";
    cin >> password;

    ifstream input("records.txt");
    while (input >> id >> pass)
    {
        if (id == userid && pass == password)
        {
            count = 1;
            break;
        }
    }
    input.close();

    if (count == 1)
        cout << userid << ", your LOGIN was successful!\n";
    else
        cout << "\nLOGIN ERROR\nPlease check your username and password\n";
}

void registration()
{
    string ruserid, rpassword;
    cout << "\tEnter the username: ";
    cin >> ruserid;
    cout << "\tEnter the password: ";
    cin >> rpassword;

    ofstream f1("records.txt", ios::app);
    f1 << ruserid << ' ' << rpassword << endl;
    f1.close();

    cout << "\n\tRegistration successful!\n";
}

void forget()
{
    int option;
    cout << "\tForgot your password? No worries\n";
    cout << "Press 1 to search your ID by username\n";
    cout << "Press 2 to go back to the main menu\n";
    cout << "\t\tEnter your choice: ";
    cin >> option;

    switch (option)
    {
    case 1:
    {
        int count = 0;
        string suserid, sid, spass;
        cout << "\n\tEnter the username you remember: ";
        cin >> suserid;

        ifstream f2("records.txt");
        while (f2 >> sid >> spass)
        {
            if (sid == suserid)
            {
                count = 1;
                break;
            }
        }
        f2.close();

        if (count == 1)
        {
            cout << "\n\nYour account is found!\n";
            cout << "Your password is: " << spass << endl;
        }
        else
            cout << "\n\tSorry! Your account was not found!\n";

        break;
    }
    case 2:
        break;
    default:
        cout << "\tWrong choice! Please try again\n";
        break;
    }
}
