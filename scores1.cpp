#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class GpaAnalyzer
{
  public: void Greeting()
  {
    cout << endl << "Welcome to the Gpa Analyzer" << endl;
  }
  void EnterId()
  {
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
      }
    }
  }
};
  
int main()
{
GpaAnalyzer gpaclass; 
  gpaclass.Greeting(); 
  gpaclass.EnterId(); 
return 0;

}
