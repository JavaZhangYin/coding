// Client program for assignment 3. 

#include "Address.h"
#include "Patron.h"
#include <vector> 

using namespace std; 

void bubbleSort(Patron ps[], int size); 

int main() {
  // Patron PatronInOut;
  vector<Patron> patrons; 

  // assignment 5. 
  // ask for the name of the data file. 
  string datafile; 
  cout << "Please enter the name of data file: ";
  cin >> datafile; 

  ifstream ifs(datafile.c_str(), ifstream::in); 
  if (ifs.is_open()) {
    Patron *patron = new Patron(); 

    // populate the patrons array by reading the data file. 
    while (patron->readPatron(ifs)) {
      patrons.push_back(*patron); 
      patron = new Patron(); 
    }
    
    // print the patrons. 
    int size = patrons.size(); 
    for(int i = 0; i < size; i++) {
      patrons[i].writePatron(cout) << endl; 
      cout << "------------------------------------------" << endl; 
    }

    cout << endl << "------------ Sorted Array of Patrons -----------" << endl << endl;  
    // close the file after finish reading.
    ifs.close(); 

    // convert vector to array for patrons. 
    Patron ps[100]; 
    copy(patrons.begin(), patrons.end(), ps); 

    // sort array of patrons.
    bubbleSort(ps, size); 

    // print the sorted patrons. 
    for(int i = 0; i < size; i++) {
      ps[i].writePatron(cout) << endl;
      cout << "------------------------------------------" << endl;
    }
    
  } else {
    cout << "Can't open file." << endl; 
  }
  return 0;
}

void bubbleSort(Patron ps[], int size) {
  for(int i = 0; i < size; i++) {

    for(int j = 0; j < size; j++) {
      Patron ptmp = ps[i]; 
      if(!ps[i].greater(ps[j])) {
	ps[i] = ps[j]; 
	ps[j] = ptmp; 
      }
    }
  }
}
