#include <iostream> 

using namespace std; 

class account 
{
public: 
  long display () 
  {
    return -- weight; 
  }
  long weight; 

  void redirect (long length) {
    weight = length; 
    ++ weight; 
    cout << weight; 
    
  }
protected: 
private: 

}; 

int main() {
  account extraObject; 
  extraObject.weight = 2; 
  cout << extraObject.weight; 
}
