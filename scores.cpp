#include <iostream> 
#include <string>
using namespace std; 

int scores(int grades, string final); 


class GpaAnalyzer
{
  public:
  void Greeting()
  {
    cout << endl << "Welcome to the Gpa Analyzer" 
    << endl; 
  }
  void EnterId()
  {
    char id[8]; 
    cout << "Enter Student Id:"; 
    cin >> id; 
  }


}; 


int main()
{
  int display; 
  string end; 
  GpaAnalyzer gpaclass; 
  gpaclass.Greeting(); 
  gpaclass.EnterId(); 
  cout << scores(display, end); 


}

int scores(int grades, string final)
{
  final = ""; 
  do
  {
     if (grades > 90 || grades <= 100)
  {
    cout << "Enter score:";
    cin >> grades; 
    getline(cin, final); 
  }
  if (grades > 80 || grades <= 89)
  {
    cout << "Enter score:";
    cin >> grades; 
    getline(cin, final); 
  }
  if (grades > 70 || grades <= 79)
  {
    cout << "Enter score:";
    cin >> grades; 
    getline(cin, final); 
  }
  if (grades > 60 || grades <= 69)
  {
    cout << "Enter score:";
    cin >> grades; 
    getline(cin, final); 
  }
  if (grades > 0 || grades <= 59)
  {
    cout << "Enter score:";
    cin >> grades; 
    getline(cin, final); 
  }

  }while (final == "calc"); 
   
  return grades; 
}