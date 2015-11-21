#include <string>
#include <sstream>
#include <vector>
#include <iostream>

void split(const std::string &s, char delim, std::vector<std::string> &elems) {
  std::stringstream ss(s);
  std::string item;
  while (std::getline(ss, item, delim)) {
    elems.push_back(item); 
  }
}

int main(int argc, char **argv) {
  std::string s("abcded:dddd:223f:lsfjslf:lsjfl::::");
  std::vector<std::string> words;

  split(s, ':', words);
  for(std::vector<std::string>::iterator it = words.begin(); it != words.end(); it++) {
    std::cout << *it << std::endl; 
  }
}
