#include "numdays.h" 

NumDays::NumDays() {
  hours = 0; 
}
NumDays::NumDays(int h) {
  hours = h; 
}
NumDays::NumDays(double d) {
  hours = (int)(d * 8); 
}
void NumDays::setHours(int h) {
  hours = h; 
}
void NumDays::setDays(double d) {
  hours = (int)(d * 8); 
} 

int NumDays::getHours() const {
  return hours; 
}
double NumDays::getDays () const {
  return (double)hours / 8.0; 
}

// type conversion operator. 
NumDays::operator double() const {
  return (double)hours / 8.0; 
}

// addition (+) operator. 
NumDays NumDays::operator+(NumDays& nd) {
  NumDays d;
  d.setHours(hours + nd.getHours()); 
  return d; 
}

NumDays NumDays::operator-(NumDays& nd) {
  NumDays d; 
  d.setHours(hours - nd.getHours()); 
  return d; 
}

// prefix. 
NumDays& NumDays::operator++() { hours++; return *this; }
NumDays& NumDays::operator--() { hours--; return *this; } 

// postfix.
NumDays NumDays::operator++(int) { 
  NumDays tmp = *this;  
  hours++; 
  return tmp; 
}
NumDays NumDays::operator--(int) {
  NumDays tmp = *this;
  hours--;
  return tmp;
}
