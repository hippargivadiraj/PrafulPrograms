#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

char getGrade(int grade); 

class GpaAnalyzer
{
  public: void Greeting()
  {
    cout << endl << "Welcome to the Gpa Analyzer" << endl;
  }
  void enterId()
  {
    char id[8]; 
    cout << "Enter student id: "; 
    if (cin >> id)
    {
        cin >> id; 
      //check for mod 2.  
    }
    else 
    {
      cout << "You have to enter only 8 digits"; 

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
         scoresArray.push_back(myNumber);
        //push inside an array
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
               << "You need to enter 'calc' to stop score entry" << endl << endl;
        }
        else
        {
          //if it is calc, then while loop will exit
          cout << endl << "EnteredValue in String is :" << entryMode << endl;
          cout << endl << "Now We will go and Calculate" << endl;
        }
        for (int i = 0; i < scoresArray.size(); i++)
       {
         cout << i << " " << 
         scoresArray[i] << " " << getGrade(scoresArray[i]) << endl; 
         sum += scoresArray[i]; 
       }
       average = sum / scoresArray.size(); 
       cout << "The average is: " << average << " "; 
       cout << getGrade(average);   
       
       
        
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
