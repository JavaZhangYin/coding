class NumDays {
private: 
  int hours; 

public: 
  NumDays();
  NumDays(int h);
  NumDays(double d);
  void setHours(int h); 
  void setDays(double d);
  int getHours() const;
  double getDays () const; 

  // type conversion operator. 
  operator double() const; 

  // addition (+) operator. 
  NumDays operator+(NumDays& nd);
  NumDays operator-(NumDays& nd);

  // prefix. 
  NumDays& operator++();
  NumDays& operator--();

  // postfix.
  NumDays operator++(int);
  NumDays operator--(int);
}; 
