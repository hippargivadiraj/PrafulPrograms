#include <iostream>

using namespace std;


int main(){

int myArray[25] = {10, 20, 30, 40, 50, 60, 70, 87 ,90, 100, 10, 20, 30, 50, 60, 70, 80 ,90, 120 } ;
int total = 0;
int average = 0;
for ( int i = 0; i< 25; ++i ) {
 total += myArray[i];
 cout <<endl << "The ArrayValues   is : "<< myArray[i] <<endl<<endl;
}
average = total/25;
cout <<endl << "The ARRAY LENGTH   is : "<< sizeof(myArray) / sizeof(int) <<endl<<endl;
cout <<endl << "The TOTAL   is : "<< total <<endl<<endl;
cout <<endl << "The AVERAGE is : "<< average <<endl<<endl;

return 0;


}
