#include "Address.h"
#include "Patron.h"

istream& Patron::readPatron(istream& fin) {
  fin >> id >> lastName >> firstName;
  // while(fin && fin.get() != '\n' ) ;
  fin.ignore(255,'\n'); 
  PatronAddress.readAddress(fin);
  return fin;
}

ostream& Patron::writePatron(ostream& fout) const {
  // TODO Add formatting to the output. 
  fout << id << endl << lastName << ", " << firstName; 
  writeSpace(fout, 30, lastName.size() + firstName.size() + 2); 
  PatronAddress.writePhone(fout) << endl;
  PatronAddress.writeAddress(fout);
  return fout;
}

void Patron::writeSpace(ostream& fout, int needed, int printed ) const {
  int toprint = needed - printed; 
  if (toprint <= 0) return; 
  for ( int i = 0; i < toprint; i++) {
    fout << " "; 
  }
}
