#include <iostream>
#include <fstream> 
#include <cstdlib> 
#include <ctime> 

int main(int argc, char** argv) {
  srand(time(NULL)); 
  for(int i = 0; i < 100; i++) {
    int from, to; 
    from = (int)rand() % 100; 
    to = (int)rand() % 100; 
    std::cout << from << "," << to << std::endl;
  }
}
