#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

char getGrade(int grade);

class GpaAnalyzer
{
  public:
    void Greeting()
    {
        cout << endl
             << "Welcome to the GPA Analyzer" << endl;
    }
    void enterId()

    {
        bool correctIdEntered = false;
        while (correctIdEntered != true)
        {

            string input = "";
            int id;
            cout << "Enter student id: ";
            getline(cin, input);
            //Take input in stream. wedont know if Char or Int was entered
            stringstream myStream(input);
            //if it is a number check rules
            if (myStream >> id)
            {
                //check entered number is 8 digits
                int numberOfDigits = 0;
                int numberToBeChecked = id;

                while (numberToBeChecked)
                {
                    numberToBeChecked /= 10;
                    numberOfDigits++;
                }
                if (numberOfDigits != 8)
                {
                    cout << "You Entry is not Valid. Please Enter Number that is 8 Digits, which starts with 127  or 379 or 833 and is even" << endl;
                }
                else
                { //if number of digits is 8, then
                    //check if it is even number
                    if (id % 2 != 0)
                    {
                        cout << "You Entry is not Valid. Please Enter Number that is 8 Digits, which starts with 127  or 379 or 833 and is even" << endl;
                    }
                    else
                    {
                        //check if it starts with 329 or 127 or 833
                        int startingDigits = 0;
                        startingDigits = id / 100000;
                        cout << endl;
                        if (startingDigits == 379 || startingDigits == 127 || startingDigits == 833)
                        {
                            correctIdEntered = true;
                        }
                        else
                        {
                            cout << "You Entry is not Valid. Please Enter Number that is 8 Digits, which starts with 127  or 379 or 833 and is even" << endl;
                        }
                    }
                }
            }
            else //If it is not a number, show Error message
            {
                cout << "You Entry is not Valid. Please Enter Number that is 8 Digits, which starts with 127  or 379 or 833 and is even" << endl;
            }
        }
    }
    void enterScores(vector<int> scoresArray)
    {
        int sum = 0;
        int average = 0;
        string input = "";

        // How to get a number.
        int myNumber = 0;
        string entryMode = "ScoreEntry";

        while (entryMode != "calc")
        {
            // Priming Entry
            cout << "Please enter your score: ";
            getline(cin, input);

            // Take input and put in a Stream.At this point we dont know if input is a number or a string.
            stringstream myStream(input);

            //if it is a number, update array
            if (myStream >> myNumber)
            {
                if (myNumber < 0 || myNumber > 100)
                {
                    cout << endl
                         << "Please enter score value between 0 1nd 100" << endl;
                }
                else
                {
                    scoresArray.push_back(myNumber);
                    //push inside an array
                }
            }
            else //If it is not a number, it must be string
            {
                // Push input into entryMode
                entryMode = input;
                // if entry mode is NOT calc
                if (entryMode != "calc")
                {
                    // Tell User what he entered. Tell that he needs to enter calc to end
                    cout << endl
                         << "EnteredValue in String is :" << entryMode << endl;
                    cout << endl
                         << "You need to enter 'calc' to stop score entry" << endl
                         << endl;
                }
                else
                {
                    //if it is calc, then while loop will exit

                    cout << endl
                         << "#"
                         << "     "
                         << "Score"
                         << "  "
                         << "Grade" << endl;

                    for (int i = 0; i < scoresArray.size(); i++)
                    {
                        cout << i << "     " << scoresArray[i] << "     " << getGrade(scoresArray[i]) << endl;
                        sum += scoresArray[i];
                    }
                    average = sum / scoresArray.size();

                    cout << endl
                         << endl
                         << "The Student GPA is: " << endl;
                    cout << average << "  " << getGrade(average) << endl
                         << endl
                         << endl;
                }
            }
        }
    }
};

int main()
{
    vector<int> scoresArray2;
    GpaAnalyzer gpaclass;
    gpaclass.Greeting();
    gpaclass.enterId();
    gpaclass.enterScores(scoresArray2);

    return 0;
}

char getGrade(int grade)
{
    char letterGrade;

    if (grade >= 90 && grade <= 100)
    {
        letterGrade = 'A';
    }
    if (grade >= 80 && grade <= 89)
    {
        letterGrade = 'B';
    }
    if (grade >= 70 && grade <= 79)
    {
        letterGrade = 'C';
    }
    if (grade >= 60 && grade <= 69)
    {
        letterGrade = 'D';
    }
    if (grade >= 0 && grade <= 59)
    {
        letterGrade = 'F';
    }
    return letterGrade;
}