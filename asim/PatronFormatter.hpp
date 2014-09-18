//********************************************************************
//
//  File:           assign3.hpp
//  
//  Student:        Asim
//
//  Assignment:     assignment 2
//
//  Course Number:  COSC 1560-03
//
//  due:            September 11, 2014
//
//  input: library patron records (from the keyboard) 
//         consisting of four lines each:
//     id lastName firstName
//     street address
//     city
//     state zipcode phonenumber
//
//      street address and city may contain spaces,
//      other items may not. id and zipcode are integers.
//          
//  output: Formatted patron record entries
//
//********************************************************************
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Address
{
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
