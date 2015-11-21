#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>

int main(int argc, char** argv) {
  std::vector<int> vec;
  srand(time(NULL)); 
  for(int i = 0; i < 10; i++) {
    int val = rand() % 100;
    vec.push_back(val);
  }

  std::cout << "Original data: " << std::endl; 
  std::vector<int>::iterator it = vec.begin();
  for(; it != vec.end(); ++it) {
    std::cout << *it << ' '; 
  }
  std::cout << std::endl;
  
  std::random_shuffle(vec.begin(), vec.end());

  for(it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << ' '; 
  }
  std::cout << std::endl;
}
