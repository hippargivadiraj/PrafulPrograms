//Praful Hippargi
//Shopping.cpp

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <vector>

using namespace std;

int DisplayAndReciveMenuOptions();

int main()
{
    int userInput;
    //Display Menu
    userInput = DisplayAndReciveMenuOptions();

    return 0;
}

int DisplayAndReciveMenuOptions()
{
    //This Funtion display's the menu option, and validates inputs.

    cout << "Enter your choice (1, 2, 3, 4 or 5): " << endl;
    cout << "1. Add inventory" << endl;
    cout << "2. Delete inventory" << endl;
    cout << "3. Edit inventory" << endl;
    cout << "4. Display inventory" << endl;
    cout << "5. Quit Program" << endl;

    int choice;
    string input = "";
    bool isItANumber = false;

    //Get priming entry
    cout << "Enter your choice (1, 2, 3, 4 or 5): ";
    getline(cin, input);

    //Take input in stream. we dont know if Char or Int was entered
    stringstream myStream(input);
    // is it a string
    while (isItANumber == false)
    {

        cout << "You are required to enter from following choices. Try again " << endl;
        cout << "Enter your choice (1, 2, 3, 4 or 5): ";
        getline(cin, input);
        stringstream myStream(input);
        if (myStream >> choice)
        {
            if (choice < 0 || choice > 5)
            {
                cout << "You did not enter the right choice" << endl;
            }
            else
            {
                isItANumber = true;
            }
        }
    }
cout << "isItANumber :" << isItANumber << endl;
cout << "Number Being returned from Menu is :" << choice << endl;
    return choice;
}
