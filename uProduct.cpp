#include <iostream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

class Product
{
    //class variables
  public:
    string itemDescription;
    int QuantityAtHand;
    double retailCost;
    int dateAddedToInventory;

    //member funtions
    Product(string b, int c, double f, int v)
    {
        itemDescription = b;
        QuantityAtHand = c;
        retailCost = f;
        dateAddedToInventory = v;
    }

    void displayProduct()
    {
        cout << endl
             << endl;

        cout << "Iten description: " << itemDescription
             << endl;

        cout << "Quantity availible is: " << QuantityAtHand
             << endl;

        cout << "The price is: " << 2 * retailCost << endl;
    }

    void addInventory(int x)
    {
        QuantityAtHand += x;
    }

    void editInventroy(int x)
    {
        QuantityAtHand -= x;
    }
    void deleteInventory()
    {
        QuantityAtHand = 0;
    }
};

int main()
{
    Product p1( "abc", 5, 20.22, 1998);
    p1.addInventory(6);
    p1.displayProduct();

    return 0;
}