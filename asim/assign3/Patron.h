#ifndef _PATRON_H_
#define _PATRON_H_

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Patron {
private:
  int id;
  string lastName;
  string firstName;
  Address PatronAddress;
  void writeSpace(ostream& fout, int needed, int printed ) const; 
public:
  istream& readPatron(istream&);
  ostream& writePatron(ostream&) const;
};


#endif
