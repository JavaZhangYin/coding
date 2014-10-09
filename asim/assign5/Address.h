#ifndef _ADDRESS_H_
#define _ADDRESS_H_

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Address {
private:
  string street;
  string city;
  string state;
  int zip;
  string phone;

public:
  istream& readAddress(istream&);
  ostream& writeAddress(ostream&) const;
  ostream& writePhone(ostream&) const;
};

#endif
