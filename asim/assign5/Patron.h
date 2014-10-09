#ifndef _PATRON_H_
#define _PATRON_H_

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class Patron {
private:
  int id;
  string lastName;
  string firstName;
  int nums[11]; 
  int cnt; 
  Address PatronAddress;
  void writeSpace(ostream& fout, int needed, int printed ) const; 
public:
  Patron(); 
  bool greater(const Patron&) const; 
  istream& readPatron(istream&);
  ostream& writePatron(ostream&) const;
};


#endif
