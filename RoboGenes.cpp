//Praful Hippargi

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int RandomNumberGenerator(int x)
{
    return (rand() % x);
};

class Grid
{
  public:
    int cell[10][10];

    void setAllGridCellsToZero()
    {
        for (int row = 0; row < 10; row = row + 1)
        {
            for (int column = 0; column < 10; column = column + 1)
            {
                cell[row][column] = 0;
            }
        }
    }

    void randomlyAssignBatteryTo40Cells()
    {
        for (int i = 0; i < 40; i = i + 1)
        {
            int randomX = RandomNumberGenerator(10);
            int randomY = RandomNumberGenerator(10);

            cell[randomX][randomY] = 2;
        }
    }

    int getCellValue(int x, int y)
    {

        return cell[x][y];
    }

    void cellBatteryConsumed(int x, int y)
    {
        cell[x][y] = 0;
    }
};

class Robot
{
  public:
    //Start with BatteryStrength as 5
    int batteryStrength = 5;
    //If BatteryStrength is more than Zero, isAlive is true, else it is false
    bool isAlive()
    {
        return batteryStrength > 0;
    };

    // Start with number of moves as zero
    int numberOfMoves = 0;

    //Robot sensing result
    int senseNESW[4] = {0, 0, 0, 0};

    int x = 0; // stores current X co-ordinate of robot
    int y = 0; // stores current Y co-ordinate of robot

    void placeRandomlyOnGrid()
    {
        // places X and Y co-ordinate of robot : randomly on the grid
        x = RandomNumberGenerator(10);
        y = RandomNumberGenerator(10);
    };
    // Sixteen Genes, Each with 4 slots for Genes 1 for Direction
    int gene01[5], gene02[5], gene03[5], gene04[5];
    int gene05[5], gene06[5], gene07[5], gene08[5];
    int gene09[5], gene10[5], gene11[5], gene12[5];
    int gene13[5], gene14[5], gene15[5], gene16[5];


    void assignRandomGenesAndMovements(int gene[])
    {
        // SensorStates:
        //0 - No object in Sq
        //1 - Wall
        //2 - Battery
        //3 - Dont Care if anything there
        gene[0] = RandomNumberGenerator(4);
        gene[1] = RandomNumberGenerator(4);
        gene[2] = RandomNumberGenerator(4);
        gene[3] = RandomNumberGenerator(4);
        // Robot Action: 1- Move North 2- move south 3- move east 4 move west 5-random movement
        gene[4] = RandomNumberGenerator(5) + 1;

        //    cout<< "GENE:  " << gene[0]<< gene[1]<< gene[2]<< gene[3]<< gene[4]<<endl;
        //    cout<< endl;
    };

    void setUpGenes()
    {
        assignRandomGenesAndMovements(gene01);
        assignRandomGenesAndMovements(gene02);
        assignRandomGenesAndMovements(gene03);
        assignRandomGenesAndMovements(gene04);
        assignRandomGenesAndMovements(gene05);
        assignRandomGenesAndMovements(gene06);
        assignRandomGenesAndMovements(gene07);
        assignRandomGenesAndMovements(gene08);
        assignRandomGenesAndMovements(gene09);
        assignRandomGenesAndMovements(gene10);
        assignRandomGenesAndMovements(gene11);
        assignRandomGenesAndMovements(gene12);
        assignRandomGenesAndMovements(gene13);
        assignRandomGenesAndMovements(gene14);
        assignRandomGenesAndMovements(gene15);
        assignRandomGenesAndMovements(gene16);
    };

    void setUpMixedGenePool(Robot r1, Robot r2)
    {

        copy(begin(r1.gene01), end(r1.gene01), begin(gene01));
        copy(begin(r1.gene02), end(r1.gene02), begin(gene02));
        copy(begin(r1.gene03), end(r1.gene03), begin(gene03));
        copy(begin(r1.gene04), end(r1.gene04), begin(gene04));

        copy(begin(r1.gene05), end(r1.gene05), begin(gene05));
        copy(begin(r1.gene06), end(r1.gene06), begin(gene06));
        copy(begin(r1.gene07), end(r1.gene07), begin(gene07));
        copy(begin(r1.gene08), end(r1.gene08), begin(gene08));

        copy(begin(r2.gene01), end(r2.gene01), begin(gene09));
        copy(begin(r2.gene02), end(r2.gene02), begin(gene10));
        copy(begin(r2.gene03), end(r2.gene03), begin(gene11));
        copy(begin(r2.gene04), end(r2.gene04), begin(gene12));

        copy(begin(r2.gene05), end(r2.gene05), begin(gene13));
        copy(begin(r2.gene06), end(r2.gene06), begin(gene14));
        copy(begin(r2.gene07), end(r2.gene07), begin(gene15));
        copy(begin(r2.gene08), end(r2.gene08), begin(gene16));
    };

    //Robot senses surrounding and updates results to senseNSEW[4]
    void sesnseSurrounding(Grid grid)
    {
        if (y <= 8)
        {
            senseNESW[0] = grid.cell[x][y + 1];
        }
        else
        {
            senseNESW[0] = 1;
        }
        if (x <= 8)
        {
            senseNESW[1] = grid.cell[x + 1][y];
        }
        else
        {
            senseNESW[1] = 1;
        }
        if (y >= 1)
        {
            senseNESW[2] = grid.cell[x][y - 1];
        }
        else
        {
            senseNESW[2] = 1;
        }
        if (x >= 1)
        {
            senseNESW[3] = grid.cell[x - 1][y];
        }
        else
        {
            senseNESW[3] = 1;
        }

        //cout << "sensed surrounding : " << senseNESW[0] << senseNESW[1] << senseNESW[2] << senseNESW[3] << endl;
    };

    void makeMove(int asPerGeneInstruction, Grid &grid)
    {
        if (asPerGeneInstruction == 5)
        {
            //generate random direction from 1 to 4
            asPerGeneInstruction = RandomNumberGenerator(4) + 1;
        }

        if (asPerGeneInstruction == 1)
        {
            //Move North
            if (y < 9)
            {
                y = y + 1;
            }
            if (grid.cell[x][y] == 2)
            {
                batteryStrength = batteryStrength + 5;
            }
            //Battery is Consumed
            grid.cell[x][y] = 0;

            batteryStrength = batteryStrength - 1;
            // cout << "N" << grid.cell[x][y] << endl;
        };
        if (asPerGeneInstruction == 2)
        {
            //Move East
            if (x < 9)
            {
                x = x + 1;
            }
            if (grid.cell[x][y] == 2)
            {
                batteryStrength = batteryStrength + 5;
            }
            //Battery is Consumed
            grid.cell[x][y] = 0;
            batteryStrength = batteryStrength - 1;
            // cout << "E" << grid.cell[x][y] << endl;
        };
        if (asPerGeneInstruction == 3)
        {
            //Move South
            if (y > 0)
            {
                y = y - 1;
            }
            if (grid.cell[x][y] == 2)
            {
                batteryStrength = batteryStrength + 5;
            }
            //Battery is Consumed
            grid.cell[x][y] = 0;
            batteryStrength = batteryStrength - 1;
            //cout << "S" << grid.cell[x][y] << endl;
        };
        if (asPerGeneInstruction == 4)
        {
            //Move West
            if (x > 0)
            {
                x = x - 1;
            }
            if (grid.cell[x][y] == 2)
            {
                batteryStrength = batteryStrength + 5;
            }
            //Battery is Consumed
            grid.cell[x][y] = 0;
            batteryStrength = batteryStrength - 1;
            // cout << "W" << grid.cell[x][y] << endl;
        };
    }

    int matchSensorInformationToGeneAndGetMoveDirection( int sense[])
    {
    
    bool matchFound = false;
    int movement = 5;
    while (matchFound == false)
    {
        //mtach Gene01

        cout << "SENSE : "<< sense[0] << sense[1] << sense[2] << sense[3] <<endl;
        cout <<"GENE : "<<gene01[0]<<gene01[1]<<gene01[2]<<gene01[3]<<gene01[4]<<endl;

        if ( (sense[0] == gene01[0] || gene01[0] == 3) && (sense[1] == gene01[1] || gene01[1] == 3 ) && (sense[2] == gene01[2] || gene01[2] == 3) && (sense[3] == gene01[3] || gene01[3] == 3) ){
          movement = gene01[4];
          matchFound = true;  
        }
        if ( (sense[0] == gene01[0] || gene01[0] == 3) && (sense[1] == gene01[1] || gene01[1] == 3 ) && (sense[2] == gene01[2] || gene01[2] == 3) && (sense[3] == gene01[3] || gene01[3] == 3) ){
          movement = gene01[4];
          matchFound = true;  
        }
        if ( (sense[0] == gene02[0] || gene02[0] == 3) && (sense[1] == gene02[1] || gene02[1] == 3 ) && (sense[2] == gene02[2] || gene02[2] == 3) && (sense[3] == gene02[3] || gene02[3] == 3) ){
          movement = gene02[4];
          matchFound = true;  
        }
        if ( (sense[0] == gene03[0] || gene03[0] == 3) && (sense[1] == gene03[1] || gene03[1] == 3 ) && (sense[2] == gene03[2] || gene03[2] == 3) && (sense[3] == gene03[3] || gene03[3] == 3) ){
          movement = gene03[4];
          matchFound = true;  
        }
        if ( (sense[0] == gene04[0] || gene04[0] == 3) && (sense[1] == gene04[1] || gene04[1] == 3 ) && (sense[2] == gene04[2] || gene04[2] == 3) && (sense[3] == gene04[3] || gene04[3] == 3) ){
          movement = gene04[4];
          matchFound = true;  
        }
        if ( (sense[0] == gene05[0] || gene05[0] == 3) && (sense[1] == gene05[1] || gene05[1] == 3 ) && (sense[2] == gene05[2] || gene05[2] == 3) && (sense[3] == gene05[3] || gene05[3] == 3) ){
          movement = gene05[4];
          matchFound = true;  
        }
        if ( (sense[0] == gene06[0] || gene06[0] == 3) && (sense[1] == gene06[1] || gene06[1] == 3 ) && (sense[2] == gene06[2] || gene06[2] == 3) && (sense[3] == gene06[3] || gene06[3] == 3) ){
          movement = gene06[4];
          matchFound = true;  
        }
        if ( (sense[0] == gene07[0] || gene07[0] == 3) && (sense[1] == gene07[1] || gene07[1] == 3 ) && (sense[2] == gene07[2] || gene07[2] == 3) && (sense[3] == gene07[3] || gene07[3] == 3) ){
          movement = gene07[4];
          matchFound = true;  
        }
        if ( (sense[0] == gene08[0] || gene08[0] == 3) && (sense[1] == gene08[1] || gene08[1] == 3 ) && (sense[2] == gene08[2] || gene08[2] == 3) && (sense[3] == gene08[3] || gene08[3] == 3) ){
          movement = gene08[4];
          matchFound = true;  
        }
        if ( (sense[0] == gene09[0] || gene09[0] == 3) && (sense[1] == gene09[1] || gene09[1] == 3 ) && (sense[2] == gene09[2] || gene09[2] == 3) && (sense[3] == gene09[3] || gene09[3] == 3) ){
          movement = gene09[4];
          matchFound = true;  
        }
        if ( (sense[0] == gene10[0] || gene10[0] == 3) && (sense[1] == gene10[1] || gene10[1] == 3 ) && (sense[2] == gene10[2] || gene10[2] == 3) && (sense[3] == gene10[3] || gene10[3] == 3) ){
          movement = gene10[4];
          matchFound = true;  
        }
        if ( (sense[0] == gene11[0] || gene11[0] == 3) && (sense[1] == gene11[1] || gene11[1] == 3 ) && (sense[2] == gene11[2] || gene11[2] == 3) && (sense[3] == gene11[3] || gene11[3] == 3) ){
          movement = gene11[4];
          matchFound = true;  
        }
        if ( (sense[0] == gene12[0] || gene12[0] == 3) && (sense[1] == gene12[1] || gene12[1] == 3 ) && (sense[2] == gene12[2] || gene12[2] == 3) && (sense[3] == gene12[3] || gene12[3] == 3) ){
          movement = gene12[4];
          matchFound = true;  
        }
        if ( (sense[0] == gene13[0] || gene13[0] == 3) && (sense[1] == gene13[1] || gene13[1] == 3 ) && (sense[2] == gene13[2] || gene13[2] == 3) && (sense[3] == gene13[3] || gene13[3] == 3) ){
          movement = gene13[4];
          matchFound = true;  
        }
        if ( (sense[0] == gene14[0] || gene14[0] == 3) && (sense[1] == gene14[1] || gene14[1] == 3 ) && (sense[2] == gene14[2] || gene14[2] == 3) && (sense[3] == gene14[3] || gene14[3] == 3) ){
          movement = gene14[4];
          matchFound = true;  
        }
        if ( (sense[0] == gene15[0] || gene15[0] == 3) && (sense[1] == gene15[1] || gene15[1] == 3 ) && (sense[2] == gene15[2] || gene15[2] == 3) && (sense[3] == gene15[3] || gene15[3] == 3) ){
          movement = gene15[4];
          matchFound = true;  
        }
        if (matchFound == false){

        movement = gene16[4];
        cout<<"GENE 16 MOVE"<<gene16[4]<<endl;
        matchFound = true;

        }

        

    }
        cout<<"MOVEMENT RETURNED : "<<movement<<endl;
        return movement ;
    }

         
};

void displayGridAndRobot(Grid grid, Robot robot)
{

    grid.cell[robot.x][robot.y] = 8;
    for (int i = 10; i > 0; i--)
    {
        for (int c = 0; c < 10; c++)
        {

            if (grid.cell[c][i] == 8)
            {
                cout << "🁢";
            }
            else
            {
                cout << " ";
            } // grid.cell[c][i];
        }
        cout << endl;
    }
    cout << "--------------------" << endl;
};

void sortRobotsOnNumberOfMoves(Robot robotArray[])
{
    for (int i = 0; i <= 200; i++)
    {
        Robot temp;
        temp.numberOfMoves;

        if (robotArray[i].numberOfMoves < robotArray[i + 1].numberOfMoves)
        {
            temp = robotArray[i];
            robotArray[i] = robotArray[i + 1];
            robotArray[i + 1] = temp;
        }
    }
}

int main()
{
    //Specification C1--Time Seed
    srand(time(0));

    Grid g;
    g.setAllGridCellsToZero();
    g.randomlyAssignBatteryTo40Cells();

    Robot r;
    r.placeRandomlyOnGrid();
    cout << "Initial Robot Coordinates: "
         << "  x: " << r.x << "  y:  " << r.y << endl;

    //initialize all parameters
    r.numberOfMoves = 0;
    r.setUpGenes();
    // r.sesnseSurrounding(g);
    r.batteryStrength = 5;
    

    //displayGridAndRobot(g, r);

    while (r.isAlive())
    {
        displayGridAndRobot(g, r);
       
        r.sesnseSurrounding(g);
        r.makeMove(r.matchSensorInformationToGeneAndGetMoveDirection(r.senseNESW), g);
        r.numberOfMoves = r.numberOfMoves + 1;
        
        //cout << "X: " << r.x << " Y: " << r.y << " Grid: " << g.cell[r.x][r.y] << " Battery: " << r.batteryStrength << endl;
    }

    cout << " TOTAL Number Of Moves: " << r.numberOfMoves << endl;
    r.numberOfMoves = 0;
    r.batteryStrength = 5;

    // Initialize 200 robots

    //Start Generation 0- and repaet this to 10 Generations

    //Get the 200 robots

    // For each of 200 robots Do the following

    //initialize the grid

    //Layout a 10 By 10 Grid and initialize with all zeros in Cells

    // Make 40 Percent of these cells have a Battery - ie value 5

    //Randomly place a Robot in one of the squares on grid

    //Make robot sense the surrounding

    //Make Robot compare its gene with surrounding input - get Moving instruction

    // Move robot as per instruction - Add the move to MoveTotal

    //Check if it alive or dead

    // if alive - loop through

    //if dead - exit loop

    // Go on to Next Robot till you complete 200 robots

    //When all 200 robots finished running

    //Sort robots on MoveTotal Highest to Lowest

    //Display avaerage Moves (strength for the Generarion)

    // Delete lower 100 robots (50%)

    //Make anather 100 robots and add to existing 100

    //Take these 200 robots - Repeat the process by randomly placing robots

    // Finish all Generations

    return 0;
}