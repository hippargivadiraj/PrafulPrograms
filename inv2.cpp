// a4.cpp : This file contains the 'main' function. Program execution begins and ends there.



#include <iostream>

using namespace std; 

void programGreeting();
int DisplayAndReciveMenuOptions(); 

int main()
{
	int userInput; 
	//Program Greeting
	programGreeting(); 

	//Display Menu
	userInput = DisplayAndReciveMenuOptions(); 
	cout << userInput; 

	//Act on user's choice. 


	
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
	cout << "Enter your choice ( 1, 2, or 3) " << endl;
	cout << "1 " << "1. Roll" << endl;
	cout << "2 " << "2. Hold" << endl;
	cout << "3 " << "3. Resgin" << endl;
	cout << "4. " << "4. Quit" << endl;
	cout << "Your choice is: ";
    cin >> choice;
	////Specification C4--BulletProof Menu. 
	while (choice < 0 || choice > 4)
	{
		cout << "You are expected to choose ONLY choice 1, 2 or 3 or 4." << endl;
		cout << "Try once again" << endl;
		cout << "Enter your choice ( 1, 2, 3, or 4): ";
		cin >> choice;
	}


	return choice;

}