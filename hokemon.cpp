//Name: Brandon Doney
//Date: 11/5/17
//Description: Plays a simple game in which you can feed creatures and watch them grow.

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>
#include <time.h>
using namespace std;

// Constraint 7 - Implement abstract base class
class Creature
{
  protected:
    int hunger;
    int boredom;
    string type;
    string name;
  public:
    //Exception classes//
    class deadOfStarvation {};
    class unresponsive {};
    class mad {};
    class frustrated {};
    class ok {};
    class happy {};
    //-----------------//

    virtual void listen() = 0;
    void play()
    {
      boredom = boredom - 4;
      if (boredom < 0)
      {
        boredom = 0;
      }
    }
    void feed()
    {
      hunger = hunger - 4;
      if (hunger < 0)
      {
        hunger = 0;
      }
    }

    void passTime()
    { hunger++; boredom++; }

    void setName(string tName)
    { name = tName; }

    void setRandoms()
    { srand (time(NULL)); hunger = rand() % 9; boredom = rand() % 9; }
};

// Constraint 1 - Implement a passtime method
// Constraint 8 - Instantiate using child classes
class Dark : public Creature
{
  public:
    virtual void listen()
    {
      cout << "Dark hokeeman hunger: " << hunger << endl;
      cout << "Dark hokeeman boredom: " << boredom << endl;
      // Constaint 5 - If hunger exceeds 10, Hokeeman dies
      if (hunger > 10)
      {
        throw deadOfStarvation();
      }
      // Constraint 6  - If boredom exceeds 20, unresponsive state
      if (boredom > 20)
      {
        throw unresponsive();
      }

      // Bonus 2 - Boredom moods
      if (boredom > 15)
      {
        throw mad();
      }
      else if (boredom >= 10 && boredom <= 14)
      {
        throw frustrated();
      }
      else if (boredom >= 5 && boredom <= 9)
      {
        throw ok();
      }
      else if (boredom >= 0 && boredom <= 4)
      {
        throw happy();
      }
    }
};

class Fighting : public Creature
{
  public:
    virtual void listen()
    {
      cout << "Fighting hokeeman hunger: " << hunger << endl;
      cout << "Fighting hokeeman boredom: " << boredom << endl;
      if (hunger > 10)
      {
        throw deadOfStarvation();
      }
      if (boredom > 20)
      {
        throw unresponsive();
      }

      if (boredom > 15)
      {
        throw mad();
      }
      else if (boredom >= 10 && boredom <= 14)
      {
        throw frustrated();
      }
      else if (boredom >= 5 && boredom <= 9)
      {
        throw ok();
      }
      else if (boredom >= 0 && boredom <= 4)
      {
        throw happy();
      }
    }
};

void displayOptions();

// Constraint 2 - Create numeric menu
void displayOptions()
{
  cout << " -----------------------------------" << endl;
  cout << "| 1 - Listen to your Hokeemon       |" << endl;
  cout << "| 2 - Play with your Hokeemon       |" << endl;
  cout << "| 3 - Feed your Hokeemon            |" << endl;
  cout << "| 4 - Quit                          |" << endl;
  cout << " -----------------------------------" << endl;
}

int main()
{
  //** Variables **/
  int userEntered = 2;
  string current;
  int timesItWasHappy = 0;
  //** End Variables **//

  // Constraint 3 - Use STL
  vector<shared_ptr<Creature>> creatures
  {
    make_shared<Dark>(),
    make_shared<Fighting>()
  };

  for (int i = 0; i < creatures.size();i++)
  {
    cout << "--------------- New creature ---------------" << endl;
    cout << "\n";

    creatures[i]->setRandoms();
    // Bonus 1 - give the critter a name
    cout << "Enter its name!" << endl;
    cin >> current;
    creatures[i]->setName(current);
    userEntered = 2;
    while (userEntered >= 1 && userEntered <= 3)
    {
      //display what hokeemon you are on
      displayOptions();
      cout << "Enter your choice." << endl;
      cin >> userEntered;
      switch (userEntered)
      {
        case 1:
          //listen to current creature
          // Bonus 4 - Use exceptions
          try
          {
            creatures[i]->passTime();
            creatures[i]->listen();
          }
          catch (Creature::mad)
          {
            cout << "Your creature is mad from boredom! Play with it or it will become unresponsive." << endl;
          }
          catch (Creature::frustrated)
          {
            cout << "Your creature is frustrated from boredom! Play with it or it will become unresponsive." << endl;
          }
          catch (Creature::ok)
          {
            cout << "Your creature is feeling ok, but keep an eye on its boredom" << endl;
          }
          catch (Creature::happy)
          {
            cout << "Your creature is happy!" << endl;
            timesItWasHappy++;
          }

          catch (Creature::deadOfStarvation)
          {
            cout << "OH NO! Your hokeemon just died of starvation!" << endl;
            cout << "\n";
            //to opt out of the loop
            userEntered = 56;
          }
          catch (Creature::unresponsive)
          {
            cout << "OH NO! Your hokeemon is now unresponsive!" << endl;
            cout << "\n";
            //to opt out of the loop
            userEntered = 56;
          }
          break;
        case 2:
          //play with the creature
          try
          {
            creatures[i]->play();
            creatures[i]->passTime();
          }
          catch (Creature::mad)
          {
            cout << "Your creature is mad from boredom! Play with it or it will become unresponsive." << endl;
          }
          catch (Creature::frustrated)
          {
            cout << "Your creature is frustrated from boredom! Play with it or it will become unresponsive." << endl;
          }
          catch (Creature::ok)
          {
            cout << "Your creature is feeling ok, but keep an eye on its boredom" << endl;
          }
          catch (Creature::happy)
          {
            cout << "Your creature is happy!" << endl;
            timesItWasHappy++;
          }

          catch (Dark::deadOfStarvation)
          {
            cout << "OH NO! Your hokeemon just died of starvation!" << endl;
            //to opt out of the loop
            userEntered = 56;
          }
          catch (Dark::unresponsive)
          {
            cout << "OH NO! Your hokeemon is now unr esponsive!" << endl;
            //to opt out of the loop
            userEntered = 56;
          }
          break;
        case 3:
          //feed the creature
          try
          {
            creatures[i]->feed();
            creatures[i]->passTime();
          }
          catch (Creature::mad)
          {
            cout << "Your creature is mad from boredom! Play with it or it will become unresponsive." << endl;
          }
          catch (Creature::frustrated)
          {
            cout << "Your creature is frustrated from boredom! Play with it or it will become unresponsive." << endl;
          }
          catch (Creature::ok)
          {
            cout << "Your creature is feeling ok, but keep an eye on its boredom" << endl;
          }
          catch (Creature::happy)
          {
            cout << "Your creature is happy!" << endl;
            timesItWasHappy++;
          }

          catch (Dark::deadOfStarvation)
          {
            cout << "OH NO! Your hokeemon just died of starvation!" << endl;
            //to opt out of the loop
            userEntered = 56;
          }
          catch (Dark::unresponsive)
          {
            cout << "OH NO! Your hokeemon is now unresponsive!" << endl;
            //to opt out of the loop
            userEntered = 56;
          }
          break;
        case 4:
          //quit
          cout << "Quitted entire program." << endl;
          return 0;
          break;
      }
    }
    cout << "Your Hokeeman was happy: " << timesItWasHappy << " times." << endl;
    timesItWasHappy = 0;
  }
  return 0;
}