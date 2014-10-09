#include "Address.h"
#include "Patron.h"
#include <cstdlib> // for function atoi.

// added constructor to initialize cnt. 
Patron::Patron() {
  cnt = 0; 
}

istream& Patron::readPatron(istream& fin) {
  fin >> id >> lastName >> firstName;
  fin.ignore(255,'\n'); 
  PatronAddress.readAddress(fin);

  // read the list of numbers. 
  fin.ignore(255,'\n');
  string s; 
  getline(fin, s); 

  istringstream ss(s); 
  while(!ss.eof()) {
    string x; 
    getline(ss, x, ' '); 

    // convert to integer. 
    nums[cnt++] = atoi(x.c_str()); 
  }
  // fin.ignore(255,'\n');
  return fin;
}

ostream& Patron::writePatron(ostream& fout) const {
  fout << id << endl << lastName << ", " << firstName; 
  writeSpace(fout, 30, lastName.size() + firstName.size() + 2); 
  PatronAddress.writePhone(fout) << endl;
  PatronAddress.writeAddress(fout) << endl;
  // write the list of numbers. 
  for(int i = 0; i < cnt; i++) {
    fout << nums[i] << " "; 
  }

  return fout;
}

void Patron::writeSpace(ostream& fout, int needed, int printed ) const {
  int toprint = needed - printed; 
  if (toprint <= 0) return; 
  for ( int i = 0; i < toprint; i++) {
    fout << " "; 
  }
}
