// a4.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
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
    cout << endl << endl;

    cout << "Iten description: " << itemDescription 
    << endl; 

    cout << "Quantity availible is: " << QuantityAtHand 
    << endl;

    cout << "The price is: " << 2* retailCost << endl;
  }

  void addInventory(int x)
  {
    QuantityAtHand += x; 
  }

  void editInventroy(int x)
  {
    QuantityAtHand -= x; 
  }
  void deleteInventory()
  {
    QuantityAtHand = 0; 
  }


}; 

void programGreeting();
int DisplayAndReciveMenuOptions(); 
void executeUserInput(int a); 

void showInventory(); 

 



int main()
{
  //shop inventory stored here in vector array. 
  vector<Product> shopInventArray; 
  

  int userInput; 
  //Program Greeting
  programGreeting(); 

  //Display Menu
  userInput = DisplayAndReciveMenuOptions(); 
  cout << userInput; 
  executeUserInput(userInput); 

  //Act on user's choice. 

  //testing to create a product

  Product p2; 
   p2.init("Jeans", 10, 51.00, 12121966); 

  // p2.itemDescription = "Jeans pant"; 
  // p2.QuantityAtHand = 5; 
  // p2.retailCost = 51.00; 
  // p2.dateAddedToInventory = 12121961; 


  return 0; 
}

void programGreeting()
{
  //Function to display Program Greeting
   //Specification A3-Current Date. 
  cout << "Welcome to the Pig game." << endl;
  cout << "The rules are as follows: " << endl
    << "If a player roles a 1, the player losses the turn and no turn poits are added. to the player's grand total." << endl << "If a player roles a 2-6, the number rolled is added to the turn total. " << endl << "The players also have a choice to hold. " << " If a player chooses to hold, the turn total is added to the grand total. " << endl << "The first player to reach a total points of 100 wins the game.";


}

int DisplayAndReciveMenuOptions()
{
  //This Funtion display's the menu option, and validates inputs.
  int choice;
  //Specification B3--Alpha Menu.
  //Specification C3--REPLACED. 
  cout << "Enter your choice (1, 2, 3, 4 or 5): " << endl;
  cout <<  "1. Add inventory" << endl;
  cout <<  "2. Delete inventory" << endl;
  cout <<  "3. Edit inventory" << endl;
  cout << "4. Display inventory" << endl;
  cout <<  "5. Quit Program" << endl;
  cout << "Your choice is: ";
  cin >> choice; 

  ////Specification C4--BulletProof Menu. 
  while (choice < 0 || choice > 5)
  {
    cout << "You not enter the right choice" << endl;
    cout << "You are expected to choose ONLY choice 1, 2 3, 4 or 5." << endl;
    cout << "Try once again" << endl;
    cout << "Enter your choice ( 1, 2, 3, 4 or 5): ";
    cin >> choice;
  }


  return choice;

}

void executeUserInput(int a)
{
   if (a == 1)
    {
      cout << "Here you add inventory" << endl;
    }
     if (a == 2)
    {
      cout << "Here you add inventory" << endl;
    }
     if (a == 3)
    {
      cout << "Here you add inventory" << endl;
    }
     if (a == 4)
    {
      cout << "Here you add inventory" << endl;
      showInventory(); 
    }
     if (a == 5)
    {
      cout << "Here you add inventory" << endl;
    }

}


