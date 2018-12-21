//Praful Hippargi

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

//ships and size description
const int carrier = 5;
const int battleship = 4;
const int cuiser = 3;
const int subMarine = 3;
const int destroyer = 2;

//Constants
const int waterArea = 0;
const int shipIndicator = 1;
const int hitIndicator = 2;
const int missIndicator = 3;
const int hitEarlier = 4;
const int missedEarlier = 5;
const int goingUpDown = 1;
const int goingAcross = 0;

class BattleGround
{

    //Create a grid that represents BattleGround, make private so no one sets it

  public:
    int grid[10][10];

    //first method - set grid to all water
    void setUpWaterGrid()
    {
        for (int row = 0; row < 10; row++)
        {
            for (int col = 0; col < 10; col++)
            {
                this->grid[row][col] = 0;
            };
        };
        // for (int i = 0; i < 10; i++)
        // {
        //     for (int c = 0; c < 10; c++)
        //     {

        //         cout << grid[i][c];
        //     }
        //     cout << endl;
        // }
    }

    void showValues()
    {
        for (int i = 0; i < 10; i++)
        {
            for (int c = 0; c < 10; c++)
            {

                cout << grid[i][c];
            }
            cout << endl;
        }
    }

    int getWhatIsThereAtGridRowColPosition(int x, int y)
    {
        int whatIsThereAtGrid;

        switch (grid[x][y])
        {
        case 0:
            whatIsThereAtGrid = waterArea;
            break;
        case 1:
            whatIsThereAtGrid = shipIndicator;
            break;
        case 2:
            whatIsThereAtGrid = hitIndicator;
            break;
        case 3:
            whatIsThereAtGrid = missIndicator;
            break;
        default:
            whatIsThereAtGrid = waterArea;
        }
        return whatIsThereAtGrid;
    }

    int addShipsToGrid(int shipType, int x, int y, int direction)
    {

        //make sure ship is within the board
        if (x > 10 || y > 10)
        {
            return -1;
        }
        //make sure ship size is contained in the grid
        if ((direction == goingUpDown && (y + shipType) > 10) || (direction == goingAcross && (x + shipType) > 10))
        {
            return -1;
        }

        //make sure ships are not overlapping each other
        for (int shipPosition = 0; shipPosition < shipType; shipPosition++)
        {
            if (direction == goingUpDown) //if ship positioned vertically
            {
                // this ship is hitting a grid occuppied by other ship
                if (this->grid[x][y + shipPosition] == shipIndicator)
                {
                    return -1;
                }
            }
            else
            {
                if (this->grid[x + shipPosition][y] == shipIndicator)
                {
                    return -1;
                }
            }
        }
        for (int shipPosition = 0; shipPosition < shipType; shipPosition++)
        {
            if (direction == goingUpDown) //if ship positioned vertically
            {
                // set the grid as ship occupied grid shipIndicator
                this->grid[x][y + shipPosition] = shipIndicator;
            }
            else
            {
                this->grid[x + shipPosition][y] = shipIndicator;
            }
        }
        return 0;
    }

    void takeAShot(int x, int y)
    {
        //did you hit
        if (this->grid[x][y] == shipIndicator)
        {
            // cout << "Ship Hit";
            this->grid[x][y] = hitIndicator;
            // return hitIndicator;
        };

        //if you hit water area
        if (this->grid[x][y] == waterArea)
        {
            // cout << "Water Hit";
            this->grid[x][y] = missIndicator;
            //  return missIndicator;
        };
    }

    bool gotHit()
    {
        for (int i = 0; i < 10; i++)
        {
            for (int c = 0; c < 10; c++)
            {

                if (grid[i][c] == hitIndicator)
                {
                    return true;
                    break;
                }
            }
        }
        return false;
    }
};

const int humanPlayer = 1;
const int computerPlayer = 2;

void displayBoard(BattleGround BattleGround, int playerType)
{
    char columLetters[] = "ABCDEFGHIJ";
    // Set Up the top row
    cout << "   "
         << "1 2 3 4 5 6 7 8 9 10" << endl;

    for (int row = 0; row < 10; row++)
    {
        cout << " " << columLetters[row] << "|";
        // set up columns
        for (int col = 0; col < 10; col++)
        {
            switch (BattleGround.getWhatIsThereAtGridRowColPosition(row, col))
            {
            case 0:
                cout << "~|";
                break;
            case 1:
                cout << "1|";
                break;
            case 2:
                cout << "X|";
                break;
            case 3:
                cout << "M|";
                break;
            default:
                cout << "x|";
                break;
            };
        };
        cout << endl;
    }
}

void fireAtEnemyGrid(int x, int y, BattleGround &bGround)
{
    bGround.takeAShot(x, y);
}

int RandomNumberGenerator(int x)
{
    // Function to output a Random Number
    int generatedNum;
    //Specification C1--Time Seed
    srand(time(0));
    generatedNum = (rand() % x);
    return generatedNum;
}

int DisplayAndReciveMenuOptions()
{
    //This Funtion display's the menu option, and validates inputs.
    int choice;
    cout << "Do You want to Continue ( 1:To Continue, 2:To End game) " << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    while (choice < 1 || choice > 2)
    {
        cout << "You are expected to choose ONLY choice 1 and 2 " << endl;
        cout << "Try once again" << endl;
        cin >> choice;
    }
    return choice;
}

int main()

{
    //create Battlegrounds
    BattleGround playerBattleGround;
    playerBattleGround.setUpWaterGrid();
    playerBattleGround.addShipsToGrid(carrier, 4, 4, goingUpDown);
    playerBattleGround.addShipsToGrid(destroyer, 1, 5, goingUpDown);
    playerBattleGround.addShipsToGrid(subMarine, 7, 2, goingAcross);
    cout << "My BattleGround Status at the Begnning" << endl;
    displayBoard(playerBattleGround, humanPlayer);
    cout << endl
         << endl;
    BattleGround computerBattleGround;
    computerBattleGround.setUpWaterGrid();
    computerBattleGround.addShipsToGrid(carrier, 0, 0, goingAcross);
    computerBattleGround.addShipsToGrid(destroyer, 5, 1, goingUpDown);
    computerBattleGround.addShipsToGrid(subMarine, 2, 4, goingAcross);
    cout << "Computer BattleGround Status at the Begnning" << endl;
    displayBoard(computerBattleGround, computerPlayer);

    bool gameOver = false;

    while (gameOver == false)
    {

        //let player Choose Row and Column to hit
        int playerChoiceForRow, playerChoiceForColumn;
        cout << "Please enter row you want to target( Number Between 1 to 10): ";
        cin >> playerChoiceForRow;
        playerChoiceForRow = playerChoiceForRow - 1;
        cout << "Please enter column you want to target( Number Between 1 to 10): ";
        cin >> playerChoiceForColumn;
        playerChoiceForColumn = playerChoiceForColumn - 1;

        // use the player's choice to hit the computer BattleGround
        fireAtEnemyGrid(playerChoiceForRow, playerChoiceForColumn, computerBattleGround);

        //let computer randomly Choose Row and Column to hit
        int computerChoiceForRow, computerChoiceForColumn;
        computerChoiceForRow = RandomNumberGenerator(100) / 10 - 1;
        computerChoiceForColumn = RandomNumberGenerator(10) - 1;
        // use the player's choice to hit the computer BattleGround

        fireAtEnemyGrid(computerChoiceForRow, computerChoiceForColumn, playerBattleGround);

        cout << endl
             << endl;

        //Allow player to continue or quit the game
        bool didSomeoneGotHit = false;
        //check if someone got hit

        bool playerGotHit = playerBattleGround.gotHit();
        
        bool computerGotHit = computerBattleGround.gotHit();
        
        if (playerGotHit == true && computerGotHit == true)
        {
            cout << "GAME OVER. You and Computer both got hit. You are Even" << endl;
            gameOver = true;
        }
        if (playerGotHit == true && computerGotHit == false)
        {
            cout << "GAME OVER. You got hit. Computer Wins" << endl;
            gameOver = true;
        }
        if (playerGotHit == false && computerGotHit == true)
        {
            cout << "GAME OVER. Computer got hit. You Win" << endl;
            gameOver = true;
        }

        // Now display Status after the play
        cout << "Computer Played : "
             << "Row: " << computerChoiceForRow + 1 << "  and Column: " << computerChoiceForColumn + 1 << endl;

        cout << "My BattleGround Status at the End of Play" << endl;
        displayBoard(playerBattleGround, computerPlayer);

        cout << endl;

        cout << "You Played : "
             << "Row: " << playerChoiceForRow + 1 << "  and Column: " << playerChoiceForColumn + 1 << endl;
        cout << "Computer BattleGround Status at the End of Play" << endl;
        displayBoard(computerBattleGround, humanPlayer);

        //Allow player to continue or quit the game if the game is not over yet
        if (gameOver == false)
        {
            int playerChoiceToContinueGame = DisplayAndReciveMenuOptions();
            if (playerChoiceToContinueGame == 2)
            {
                cout << "GAME ENDED. YOU CHOSE TO DISCONTINUE THE GAME" << endl;
                ;
                gameOver = true;
            }
        }
    }

    return 0;
}
