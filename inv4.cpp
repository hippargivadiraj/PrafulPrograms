//Praful Hippargi
//Shopping.cpp

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <vector>

using namespace std;

class Product
{
    //class variables
  public:
    string itemDescription;
    int QuantityAtHand;
    double retailCost;
    int dateAddedToInventory;

    //member funtions
    Product(string b, int c, double f, int v)
    {
        itemDescription = b;
        QuantityAtHand = c;
        retailCost = f;
        dateAddedToInventory = v;
    }

    void displayProduct()
    {
        cout << endl
             << endl;

        cout << "Item description_______: " << itemDescription
             << endl;

        cout << "Quantity availible is__: " << QuantityAtHand
             << endl;

        cout << "The price is __________: " << 2 * retailCost << endl
             << endl;
    }

    void addInventory(int x)
    {
        QuantityAtHand += x;
    }

    void editInventroy(int x)
    {
        QuantityAtHand += x;
    }
    void deleteInventory()
    {
        QuantityAtHand = 0;
    }
};

void programGreeting();
int DisplayAndReciveMenuOptions();
Product createProduct();
string getProductDescriptionFromUser();

int main()
{
    //shop inventory stored here in vector array.
    vector<Product> shopInventArray;

    int userInput;
    //Program Greeting
    programGreeting();

    //Display Menu
    userInput = DisplayAndReciveMenuOptions();

    //Act on user's choice.

    while (userInput < 5)
    {
        if (userInput == 1)
        {
            cout << endl
                 << "Please enter details to Create and Add New Product and Inventory" << endl;

            //here you create product and update into array
            shopInventArray.push_back(createProduct());
            //go and get next thing user wants to do
            userInput = DisplayAndReciveMenuOptions();
        }
        if (userInput == 2)
        {
            cout << "Delete inventory of a Product" << endl;
            string a = getProductDescriptionFromUser();

            //First set productWasFound to false
            bool productWasFound = false;
            //show inventory for that product
            for (int i = 0; i < shopInventArray.size(); i++)
            {

                cout << endl;
                if (shopInventArray[i].itemDescription == a)
                {
                    productWasFound = true;
                    cout << "Product Inventory for product " << a << " was : " << shopInventArray[i].QuantityAtHand << endl;
                    shopInventArray[i].deleteInventory();
                    cout << "Product Inventory for product " << a << " is deleted and is : " << shopInventArray[i].QuantityAtHand << endl;
                }
            }

            if (productWasFound == false)
            {
                cout << "No Product with description " << a << " was found in inventory" << endl;
                cout << "Here is a list of products in invetory. Please enter exact product " <<  endl;

                 for (int i = 0; i < shopInventArray.size(); i++){
                    cout << "Product " << i+1  << " : "<< shopInventArray[i].itemDescription <<endl;
                 }
                
            }

            userInput = DisplayAndReciveMenuOptions();
        }

        if (userInput == 3)
        {
            cout << "Edit inventory of a Product" << endl;
            string a = getProductDescriptionFromUser();

            //First set productWasFound to false
            bool productWasFound = false;
            //show inventory for that product
            for (int i = 0; i < shopInventArray.size(); i++)
            {

                cout << endl;
                if (shopInventArray[i].itemDescription == a)
                {
                    productWasFound = true;
                    cout << "Product Inventory for product: " << a << " is : " << shopInventArray[i].QuantityAtHand << endl;
                    int numberToBeAdjusted;
                    cout << "Please enter a quantity. Exhisting inventory will be updated  : ";
                    cin >> numberToBeAdjusted;
                    shopInventArray[i].editInventroy(numberToBeAdjusted);
                    cout << "Product Inventory for product: " << a << " is updated and is now set to : " << shopInventArray[i].QuantityAtHand << endl;
                }
            }

            if (productWasFound == false)
            {
                cout << "No Product with description " << a << " was found in inventory" << endl;
            }

            userInput = DisplayAndReciveMenuOptions();
        }
        if (userInput == 4)
        {
            cout << "Display inventory of a Product" << endl;
            string a = getProductDescriptionFromUser();

            //First set productWasFound to false
            bool productWasFound = false;
            //show inventory for that product
            for (int i = 0; i < shopInventArray.size(); i++)
            {

                cout << endl;
                if (shopInventArray[i].itemDescription == a)
                {
                    productWasFound = true;
                    cout << "Product Inventory for product: " << a << " is : " << shopInventArray[i].QuantityAtHand << endl;
                }
            }

            if (productWasFound == false)
            {
                cout << "No Product with description " << a << " was found in inventory" << endl;
            }

            //go and get next thing user wants to do
            userInput = DisplayAndReciveMenuOptions();
        }
        if (userInput == 5)
        {
            cout << "Quit Program" << endl;
            break;
        }
    }
    return 0;
}

void programGreeting()
{
    //Function to display Program Greeting
    //Specification A3-Current Date.
    cout << "Welcome to the Inventory Management System." << endl;
    cout << "The rules are as follows: " << endl
         << "If a player roles a 1, the player losses the turn and no turn poits are added. to the player's grand total." << endl
         << "If a player roles a 2-6, the number rolled is added to the turn total. " << endl
         << "The players also have a choice to hold. "
         << " If a player chooses to hold, the turn total is added to the grand total. " << endl
         << "The first player to reach a total points of 100 wins the game.";
}

int DisplayAndReciveMenuOptions()
{
    //This Funtion display's the menu option, and validates inputs.

    cout << "1. Add inventory" << endl;
    cout << "2. Delete inventory" << endl;
    cout << "3. Edit inventory" << endl;
    cout << "4. Display inventory" << endl;
    cout << "5. Quit Program" << endl;

    int choice;
    string input = "";
    bool isItANumber = false;

    do
    {

        //cout << "You are required to enter from following choices" << endl;
        cout << "Enter your choice (1, 2, 3, 4 or 5): ";
        getline(cin, input);
        stringstream myStream(input);
        if (myStream >> choice)
        {
            if (choice < 0 || choice > 5)
            {
                // cout << "You did not enter the right choice" << endl;
            }
            else
            {
                isItANumber = true;
            }
        }
    }while (isItANumber == false);

    return choice;
}

Product createProduct()
{
    // define variables to take in input

    string b;
    int c;
    double f;
    int v;

    // request input from user

    cout << "Enter Product Name[Max 22 Characters]: ";
    cin >> b;
    while ( b.length() > 22 )
    {
    cout << "Please enter a product name with less than 22 characters"<<endl;
    cout << "Enter Product Name[Max 22 Characters]: ";
    cin >> b;  
    }

    cout << "Enter Quantity availible[ Example: 45]: ";
    cin >> c;

    cout << "Enter price: [Example $50.55] : ";
    cin >> f;

    cout << "Date entered:[Example 01/01/2018] ";
    cin >> v;
    cout << endl;

    //create a product
    Product p(b, c, f, v);

    //Return Product
    return p;
}

string getProductDescriptionFromUser()
{
    string a;
    cout << "Enter product description: ";
    cin >> a;
    cout << endl
         << " You Entered Product Description as  : " << a << endl;
    return a;
}
