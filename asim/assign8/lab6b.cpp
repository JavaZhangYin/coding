#include <iostream>
using namespace std;
class MyDouble
{ 
  double value;
public:
  MyDouble( double inVal = 0 ) { value = inVal; }
  MyDouble operator++( int );
  operator double() const { return value; }
  MyDouble operator+( const MyDouble& ) const;
  MyDouble& operator++() { value = value + 1; return *this; }
  //ostream& operator<<( ostream& ) const;
  MyDouble( const MyDouble& );
  MyDouble operator-(const MyDouble& x);
};

MyDouble MyDouble::operator-(const MyDouble& x )
{
  return MyDouble(value - (double)x);
}

MyDouble MyDouble::operator++( int )
{
  MyDouble temp( *this );
  value = value + 1;
  return temp;
}
MyDouble MyDouble::operator+( const MyDouble& a ) const
{
  return MyDouble(value + a.value);
}
//ostream& MyDouble::operator<<( ostream& fout ) const
//{
//  return fout << value;
//}
MyDouble::MyDouble( const MyDouble& b )
{
  value = b.value;
  //  return *this;
}
ostream& operator<<( ostream& fout, const MyDouble& outVal )
{
  return fout << (double)outVal;
}
int main()
{
  MyDouble x = 7.0,
    y = 4;
  cout << "Original values: " << x << " " << y << endl;
  cout << "Anna: " << x - y << endl;
  cout << "Allen: " << x++ << endl;
  cout << "Current values: " << x << " " << y << endl;
  cout << "George: " << x + y << endl;
  cout << "Peggy: " << ++x << endl;
  cout << "Current values: " << x << " " << y << endl;
  x = y ;
  cout << "Susan: " << y << endl;
  cout << "Current values: " << x << " " << y << endl;
}
