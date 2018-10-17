#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class BattleGround
{

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
    const int goingUpDown = 1;
    const int goingAcross = 0;

    //Create a grid that represents BattleGround, make private so no one sets it

  private:
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




int main()
{
    return 0;

}