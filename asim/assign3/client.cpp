// Client program for assignment 3. 

#include "Address.h"
#include "Patron.h"

using namespace std; 

int main() {
  Patron PatronInOut;

  ifstream ifs("Patrons.txt", ifstream::in); 
  if (ifs.is_open()) {

    while (PatronInOut.readPatron(ifs))
      PatronInOut.writePatron(cout) << endl;
 
    // close the file after finish reading.
    ifs.close(); 
  } else {
    cout << "Can't open file." << endl; 
  }
  return 0;
}
