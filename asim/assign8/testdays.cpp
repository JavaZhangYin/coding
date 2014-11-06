#include <iostream>
using namespace std;
#include "numdays.h"
int main()
{
  NumDays Employee1(20),
    Employee2(15);
  cout << "Employee 1" << endl;
  cout << "hours: " << Employee1.getHours() << endl;
  cout << " days: " << Employee1.getDays() << endl;
  cout << "Employee 2" << endl;
  cout << "hours: " << Employee2.getHours() << endl;
  cout << " days: " << Employee2.getDays() << endl;
  cout << "Employee 1 plus Employee 2" << endl;
  cout << "hours: " << (Employee1 + Employee2).getHours() << endl;
  cout << " days: " << (Employee1 + Employee2).getDays() << endl;
  cout << "Employee 1 minus Employee 2" << endl;
  cout << "hours: " << (Employee1 - Employee2).getHours() << endl;
  cout << " days: " << (Employee1 - Employee2).getDays() << endl;
  cout << "Employee1++: " << Employee1++.getHours() << endl;
  cout << "Employee1: " << Employee1.getHours() << endl;
  cout << "++Employee1: " << (++Employee1).getHours() << endl;
  cout << "Employee1: " << Employee1.getHours() << endl;
  cout << "Employee2--: " << Employee2--.getHours() << endl;
  cout << "Employee2: " << Employee2.getHours() << endl;
  cout << "(--Employee2)--: " << (--Employee2)--.getHours() << endl;
  cout << "Employee2: " << Employee2.getHours() << endl;
  cout << " days: " << Employee2.getDays() << endl;
  Employee1 = 215; // calls the int constructor
  cout << "Employee1 = 215;" << endl;
  cout << "Employee 1: " << Employee1.getHours() << endl;
  cout << " days: " << Employee1.getDays() << endl;
  Employee2 = 2.5; // calls the double constructor
  cout << "Employee2 = 2.5;" << endl;
  cout << "Employee 2: " << Employee2.getHours() << endl;
  cout << " days: " << Employee2.getDays() << endl;
  double x;
  x = Employee1;
  cout << "converted Employee1 " << x << endl;
  cout << "converted Employee2 " << (double)Employee2 << endl;
}
/******************* Expected Output ******************************
Employee 1
hours: 20
 days: 2.5
Employee 2
hours: 15
 days: 1.875
Employee 1 plus Employee 2
hours: 35
 days: 4.375
Employee 1 minus Employee 2
hours: 5
 days: 0.625
Employee1++: 20
Employee1: 21
++Employee1: 22
Employee1: 22
Employee2--: 15
Employee2: 14
(--Employee2)--: 13
Employee2: 12
 days: 1.5
Employee1 = 215;
Employee 1: 215
 days: 26.875
Employee2 = 2.5;
Employee 2: 20
 days: 2.5
converted Employee1 26.875
converted Employee2 2.5
******************************************************************/
