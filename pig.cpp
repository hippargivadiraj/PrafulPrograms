#include <iostream> 
#include <string> 
#include <cstdlib> 
#include <ctime>
using namespace std; 

string restartGame(); 
int RandomNumberGenerator (); 
void programGreeting(); 
int PlayerStartGenerator (); 
int DisplayAndReciveMenuOptions();
int updateNumOfGamesPlayed(int gamesplayed); 


int main ()
{
  programGreeting(); 
  cout << endl << endl;

  int numOfGamesPlayed = 1; 
  int playerId1 = 1; 
  int playerId2 = 2; 
  int currentPlayer; 
  int turnTot = 0; 
  string gameStatus = "Game Started";



//Specification C2--Student Name
  cout << "Enter player 1's first and last name:" <<endl;
  string player1Fname; 
  string player1Lname; 
  cin >> player1Fname; 
  cin >>player1Lname; 
  cout << endl; 
  
//Specification C2--Student Name. 
  cout << "Enter player 2's first and last name:" <<endl;
  string player2Fname; 
  string player2Lname; 
  cin >> player2Fname; 
  cin >>player2Lname; 


  //Turn total varibales 
  int turnTot1 = 0; 
  int turnTot2 = 0; 


  //Grand total varibales
  int grandTot1 = 0; 
  int grandTot2 = 0; 
  


  //Start the game
  currentPlayer = PlayerStartGenerator (); 

  int playerChoice; 
 playerChoice = DisplayAndReciveMenuOptions(); 

 do  
 {  

  while (playerChoice == 1 )
  {
   int randomNum; 
   turnTot = 0;
   cout << "You chose to roll." << endl;
   randomNum = RandomNumberGenerator(); 
   while (randomNum != 1)
   {
    turnTot = turnTot + randomNum;
    playerChoice = DisplayAndReciveMenuOptions();  
    if (playerChoice == 2) { break; }

    randomNum = RandomNumberGenerator(); 
   }
    if (randomNum == 1) 
    {
      turnTot = 0; 
  
      cout << "Player Switched";
      turnTot = 0; 
      playerChoice = 2;

    }
    // Tracking Each Turn Total
    cout << endl<< "TURN TOTAL of: " << "Player: "<< currentPlayer << " is :"<< turnTot << endl; 
 }




 while (playerChoice == 2) 
 {
   cout << " You chose to hold." << endl;
   
   if (currentPlayer == playerId1) 
      {
        //Specification B1--Track Each turn. 
        grandTot1 = grandTot1 + turnTot; 
        cout << "GRAND TOTAL of: " << turnTot
        << endl;
        
        cout << player1Fname 
        << " " << player1Lname << " is at "<< grandTot1 << " grand total points " << endl;
        
        // Switch the player
        currentPlayer = playerId2;
        cout <<endl<< "PLAYER SWITCHED"<<endl<<endl;
        turnTot = 0; 
        cout << "New Player is : " << player2Fname 
        << " " << player2Lname <<endl<<endl;
        if (grandTot1 >= 100 )
        {
          cout << "Game Over Player 1 Won : " <<grandTot1 << endl;
             gameStatus = "GameOver";
             playerChoice = 3;

        }else 
        {
           playerChoice = DisplayAndReciveMenuOptions(); 
    
        }
        
      }
      else 
      {
        //Specification B1--Track Each turn.  
        grandTot2 = grandTot2 + turnTot;
       cout << "GRAND TOTAL of: " << turnTot 
       << endl; 

       cout << player2Fname << " " << player2Lname 
       << " is at " <<  grandTot2 
       << " grand total points" 
       << endl;
       // Switch the player
       currentPlayer = playerId1;
       cout << endl<< "PLAYER SWITCHED"<<endl<<endl;
        cout << "New Player is : " << player1Fname 
        << " " << player1Lname << endl;
                if (grandTot2 >= 100 )
                {
            cout << "Game Over Player 2 Won" << grandTot2 << endl;
             gameStatus = "GameOver";
             playerChoice = 3;
             

        }else 
        {
           playerChoice = DisplayAndReciveMenuOptions(); 
  
        }
     
      } 
  }

  if (playerChoice == 3)
  {
    cout << "You chose to resgin." << endl; 
   //Specification A1-Main Event Loop. 

   //gameStatus = restartGame();
   //Specification A2--Group Stats. 
   numOfGamesPlayed = numOfGamesPlayed + 1; 
   cout << "You are going into game number: " << numOfGamesPlayed
   << endl; 
   turnTot1 = 0; 
   turnTot2 = 0; 
   grandTot1 = 0; 
   grandTot2 = 0; 
   currentPlayer = PlayerStartGenerator (); 
   playerChoice = DisplayAndReciveMenuOptions();
  }


  if (playerChoice == 4)
  {
    cout << "You chose to quit." << endl;
   gameStatus = "GameOver";
   cout << "The game is over." << endl;
   turnTot1 = 0; 
   turnTot2 = 0; 
   grandTot1 = 0; 
   grandTot2 = 0; 
  }

  } while (gameStatus != "GameOver");

  cout << "Total number of games played is: " << numOfGamesPlayed; 
}

//Specification B2--Randomize start. 
int PlayerStartGenerator ()
{
  //Generates which player goes first. 
  int generatedNum; 
  srand (time (0)); 
  generatedNum =  (rand () % 2 + 1); 

  return generatedNum; 
}

//Specification A1--Main event loop. 
string restartGame()
{
  // Function to ask if user wants to restart new game
  string gamestarted = "Game started"; 
  string gameOver = "GameOver";  
  
  cout << "The current game is over." << endl; 
  cout << "Do you want to restart the game?" 
  << endl << "enter Y to restart" << " and  enter N to end." << endl;

  string restartGame; 
  cin >> restartGame; 
  if (restartGame == "Y" || restartGame == "y" ) 
  {
    cout << "Game has restarted again. " << restartGame << endl; 
    return gamestarted; 
   
  }
  else 
  {
    cout << "Game has ended. "; 
    cout << "game ended. " << restartGame; 
    return gameOver; 
    
  }

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

void programGreeting()
{
  //Function to display Program Greeting
   //Specification A3-Current Date. 
  cout << "Today's date is: ";
  time_t t = time(0);   // get time now
  char* dt = ctime(&t); 
  cout << dt; 

  cout << "Welcome to the Pig game." << endl; 
  cout << "The rules are as follows: " << endl 
  << "If a player roles a 1, the player losses the turn and no turn poits are added. to the player's grand total." << endl << "If a player roles a 2-6, the number rolled is added to the turn total. " << endl << "The players also have a choice to hold. " << " If a player chooses to hold, the turn total is added to the grand total. " << endl << "The first player to reach a total points of 100 wins the game."; 


}
 
int RandomNumberGenerator ()
{
  // Function to output a Random Number
  int generatedNum; 
  //Specification C1--Time Seed
  srand (time (0)); 
  generatedNum =  (rand () % 6 + 1); 

  cout << "The roll came out to be this number: " << generatedNum << endl;
  return generatedNum; 
}