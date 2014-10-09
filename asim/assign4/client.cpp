// Client program for assignment 3. 

#include "Address.h"
#include "Patron.h"
#include <vector> 

using namespace std; 

int main() {
  // Patron PatronInOut;
  vector<Patron> patrons; 

  ifstream ifs("Patrons2.txt", ifstream::in); 
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

    // close the file after finish reading.
    ifs.close(); 
  } else {
    cout << "Can't open file." << endl; 
  }
  return 0;
}
