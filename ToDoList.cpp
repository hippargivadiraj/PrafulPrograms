// To Do List app - Praful Hippargi
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <vector>
#include <iomanip>
using namespace std;

//create a class of TODO that has Number and Description and Status
class ToDo
{
  public:
    //class variables
    string description;
    time_t t = time(0); // get time now
    string status = "Open";

};


int main()
{

    string input = "";
    string operatorEntered = "ToDoEntry";
    vector<ToDo> taskList;
    while (operatorEntered != "^")
    {

        // Priming Entry
        cout << " Please enter Task Action" << endl;
        cout << " --------------------------------------------------------" << endl;
        cout << " + task-description : To add new Task Example: + Go To Work " << endl;
        cout << " ? To list tasks entered Example: ? " << endl;
        cout << " - Number  To set task to DELETED Example: - 3 " << endl;
        cout << " ^  To EXIT from the Program " << endl;
        cout << " --------------------------------------------------------" << endl;
        cout<<endl;

        getline(cin, input);

        // Push input into operatorEntered
        operatorEntered = input[0];

        if (operatorEntered == "+")
        {
            if (input.length() < 2)
            {
                cout << "You did not enter any description" << endl;
                cout << "Please enter Task (+ description example: + Go To Work) " << endl;
            }
            else
            { //create new ToDo
                ToDo task;
                //Add task description
                task.description = input.substr(2, input.length());
                //Add to array
                taskList.push_back(task);

                cout << "New Task Entered" << endl<<endl;
            }
        }
        else if (operatorEntered == "-")
        {
             if (taskList.size() == 0)
            {
                cout << "NO Tasks have been entered. Your task List is empty. There is Nothing to delete" << endl;
            } else 
            {
            int indexToBeUpdated;

            // Take input and put in a Stream.At this point we dont know if input is a number or a string.
            stringstream myStream(input.substr(2, input.length()));
            if (myStream >> indexToBeUpdated)
            {
                if (taskList.size() >= indexToBeUpdated)
                {
                    //set task to Delete status in array but dont delete
                    taskList[indexToBeUpdated - 1].status = "DELETED";
                    cout << "Task " << indexToBeUpdated<< " set to DELETED" << endl<<endl;
                }
                else
                {
                    cout << "You entered a task number which is not available" << endl;
                    cout << "Please enter Task Number between 1 to  " << taskList.size() << endl;
                }
            }

            }
           

        }
        else if (operatorEntered == "?")
        {
            if (taskList.size() == 0)
            {
                cout << "NO Tasks have been entered. Your task List is empty" << endl;
            }
            else
            {
                cout << "Here are the tasks you have entered and their status" << endl<< endl;
                //    List evrything inside array
                for (int i = 0; i < taskList.size(); i++)
                {
                    char* dt = ctime(&taskList[i].t);
                    cout << i + 1 << " " << left << setw(30) << taskList[i].description << " " << taskList[i].status << " " << dt <<endl;
                }
            }

            cout << endl<< endl;
        } 
    }
}
