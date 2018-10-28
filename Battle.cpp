//Praful Hippargi

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

//ships and size description
const int carrier = 5;
const int battleship = 4;
const int cuiser = 3;
const int sunMarine = 3;
const int destroyer = 2;

//Constants
const int waterArea = 0;
const int shipIndicator = 1;
const int hitIndicator = 2;
const int missIndicator = 3;
const int hitEarlier = 4;
const int missedEarlier = 5;
const int goingUpDown = 0;
const int goingAcross = 1;

class BattleGround
{

    //Create a grid that represents BattleGround, make private so no one sets it

  private:
    int grid[10][10];
 public:
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
        for (int i = 0; i < 10; i++)
        {
            for (int c = 0; c < 10; c++)
            {

                cout << grid[i][c];
            }
            cout<<endl;
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
                cout << "~|";
                break;
            case 3:
                cout << "~|";
                break;
            default:
                cout << "~|";
                break;
            };
        };
        cout << endl;
    }
}

int main()

{
    //create Battlegrounds
    // BattleGround playerBattleGround;
    BattleGround computerBattleGround;
    computerBattleGround.setUpWaterGrid();
    // playerBattleGround.addShipsToGrid(carrier,4,4,goingUpDown);
    // displayBoard(playerBattleGround, humanPlayer);
    cout << endl
         << endl;
    computerBattleGround.addShipsToGrid(carrier, 0, 0, goingAcross);
    displayBoard(computerBattleGround, computerPlayer);
    return 0;
}