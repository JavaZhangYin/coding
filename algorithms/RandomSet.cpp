// get a set of random numbers.
#include <cstdlib>
#include <iostream>
#include <set>

int main(int argc, char ** argv) {
  int cnt = 10;
  std::set<int> s;
  srand(time(NULL));
  
  while(s.size() < cnt) {
    s.insert(rand() % 1000); 
  }

  std::set<int>::iterator it = s.begin();
  while(it != s.end()) {
    std::cout << *it << ' '; 
    it++; 
  }
  std::cout << std::endl;
}
