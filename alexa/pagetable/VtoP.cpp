#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream>

int main(int argc, char **argv) {
  
  char *input = NULL; 

  // number of bits for each level.
  int ll[10]; 
  int llidx = 0; 

  // process first n memory references.
  int n = -1;

  // output to specified file. 
  char *output = NULL;	

  // show logical to physical translation. 0 for non show. 1 for show. 
  int show = 0; 

  // parse options. 
  int i ; 
  for(i = 1; i < argc; i++) {
    
    std::cout << argv[i] << std::endl; 
    
    if(strcmp(argv[i], "-n") == 0) {
      n = atoi(argv[++i]);
    } else if(strcmp(argv[i], "-p") == 0) {
      strcpy(output, argv[++i]);
    } else if (strcmp(argv[i], "-t") == 0) {
      show = 1; 
    } else break; 

  }
  std::cout << i << std::endl;

  std::ofstream ofs; 

  // output file. 
  if (NULL != output) {
    ofs.open(output, std::ofstream::out|std::ofstream::app); 

    if (!ofs.is_open()) {
      std::cerr << "Error opening output file." << std::endl; 
      exit(-1);
    }
  }

  strcpy(input, argv[i++]);
  
  std::cout << "Input file is:" << input << std::endl; 

  for (int j = i; j < argc; j++) {
    ll[llidx++] = atoi(argv[j]); 
    std::cout << "Level " << llidx << " has " 
	      << ll[llidx-1] << " bits..." << std::endl;
  }

  //////////////////////
  // do translation.
  //////////////////////
  
  if (NULL == input) {
    perror("Please specify the input file. "); 
    exit(-1); 
  }

  std::ifstream ifs(input);
  // FILE *ifp = fopen(input);
  if (ifs.is_open()) {
    std::cout << "Input file opened ..." << std::endl; 
  } else {
    std::cerr << "Error opening input file..." << std::endl; 
    exit(-1);
  }

  // create page table. 
  //PageTable *pt = new PageTable();
  
  std::string line; 
  // process all lines in the file.
  int cnt = 0;
  return 0; 
  while (getline(ifs, line)) {
    // line is the data.

    std::string::size_type sz; 
    int logic = atoi(line.c_str());
    // int logic = std::stoi(line, &sz);

    //pt->insert(logic); 
    cnt++; 
    
    //unsigned int frame = pt->lookup(logic);
    //if (ofs.is_open()) {
    //	ofs << logic << " -> " << frame << std::endl; 
    //}

    // process n lines of input. 
    if (n > 0 && cnt >= n) break; 
      
  }
  
  if (ifs.is_open()) ifs.close();
  if (ofs.is_open()) ofs.close(); 

  return 0; 
}
