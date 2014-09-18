#include <iostream>
using namespace std; 

class InstanceCounter {
public: 
  static int counter;	// class variable, unique for the class. 

  InstanceCounter() { var = 0; counter++; }
  void setVar(int v) { var = v; }
  int getVar() const { return var; }
  ~InstanceCounter() { counter--; }

private: 
  int var; // object variable, unique for each object. 
}; 

int InstanceCounter::counter = 0; 

int main() {
  const int SIZE = 10; 
  InstanceCounter * cnter[SIZE]; 
  // create objects dynamically. 
  for(int i = 0; i < SIZE; i++) {
    cnter[i] = new InstanceCounter(); 
    cnter[i]->setVar(i);
    cout << "Number of instances: " << InstanceCounter::counter << endl;
  }

  // delete the objects dynamically. 
  for(int i = 0; i < SIZE; i++) {
    if(NULL != cnter[i]) delete cnter[i]; 
    cout << "Number of instances: " << InstanceCounter::counter << endl;
  }
}
