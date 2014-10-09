#include <iomanip>
#include "Address.h"

istream& Address::readAddress(istream& fin) {
  getline(fin, street);
  getline(fin, city);
  fin >> state >> zip >> phone;
  return fin;
}

ostream& Address::writeAddress(ostream& fout) const {
  fout << street << endl;
  fout << city << ", " << state << " ";

  // format zip code. 
  if (zip < 100000) {
    fout << setfill('0') << setw(5) << zip; 
  } else {
    fout << zip / 100000 << "-" << zip % 10000; 
  }
  return fout;
}

ostream& Address::writePhone(ostream& fout) const {
  return fout << phone;
}
