#include <iostream>
using namespace std;
class MyDouble
{ 
  double value;
public:
  MyDouble( double inVal = 0 ) { value = inVal; }
  MyDouble allen( int );
  double fred() const { return value; }
  MyDouble george( const MyDouble& ) const;
  MyDouble& peggy() { value = value + 1; return *this; }
  ostream& ralph( ostream& ) const;
  MyDouble susan( const MyDouble& );
};
MyDouble anna( const MyDouble& x, const MyDouble& y )
{
  return MyDouble(x.fred() - y.fred());
}
MyDouble MyDouble::allen( int )
{
  MyDouble temp( *this );
  value = value + 1;
  return temp;
}
MyDouble MyDouble::george( const MyDouble& a ) const
{
  return MyDouble(value + a.value);
}
ostream& MyDouble::ralph( ostream& fout ) const
{
  return fout << value;
}
MyDouble MyDouble::susan( const MyDouble& b )
{
  value = b.value;
  return *this;
}
ostream& operator<<( ostream& fout, const MyDouble& outVal )
{
  return outVal.ralph( fout );
}
int main()
{
  MyDouble x = 7.0,
    y = 4;
  cout << "Original values: " << x << " " << y << endl;
  cout << "Anna: " << anna( x, y ) << endl;
  cout << "Allen: " << x.allen(0) << endl;
  cout << "Current values: " << x << " " << y << endl;
  cout << "George: " << x.george(y) << endl;
  cout << "Peggy: " << x.peggy() << endl;
  cout << "Current values: " << x << " " << y << endl;
  cout << "Susan: " << x.susan(y) << endl;
  cout << "Current values: " << x << " " << y << endl;
}
