// This program shows the donations made to the United Cause
// by the employees of CK graphics, Inc. It displays
// the donations in order from lowest to highest
// and in the original order they were received.
#include <iostream>
#include <cstdlib> // for malloc.
#include "donlist.h"
using namespace std;

int main()
{

  // dynamically allocate space for array. 
  int numFunds; 
  cout << "Enter number of funds: "; 
  cin >> numFunds; 
  double *funds = (double *)malloc(sizeof(double) * numFunds);
  for (int i = 0; i < numFunds; i++) {
    cout << "Enter fund " << i << " : "; 
    cin >> funds[i]; 
  }

  /*double funds[]={5, 100, 5, 25, 10,
		  5, 25, 5, 5, 100,
		  10, 15, 10, 5, 10 };*/
  DonationList ckGraphics(numFunds, funds);
  cout << "The donations sorted in ascending order are:" << endl;
  ckGraphics.showSorted();
  cout << "The donations in their original order are:" << endl;
  ckGraphics.show();
  return 0;
}
