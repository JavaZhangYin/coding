/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream>
#include <iomanip> // for setfill and setw.
#include "PageTable.hpp"

int main(int argc, char **argv) {
  
    char input[100];
  // number of bits for each level.
  int ll[10]; 
  int llidx = 0; 
  for(int i = 0; i < 10; i++) ll[i] = 0; 

  // process first n memory references.
  int n = -1;

  // output to specified file. 
  char output[100];	

  // show logical to physical translation. 0 for non show. 1 for show. 
  int show = 0; 

  // for(int m = 0; m < argc; m++) {
  //     std::cout << "Argument: [" << m << "] = " << argv[m] << std::endl; 
  // }

  // parse options. 
  int i ; 
  for(i = 1; i < argc; i++) {
    
    std::cout << argv[i] << std::endl; 
    
    if(strcmp(argv[i], "-n") == 0) {

      n = atoi(argv[++i]);
      std::cout << "n = " << n << std::endl; 

    } else if(strcmp(argv[i], "-p") == 0) {

      strcpy(output, argv[++i]);
      std::cout << "output file is: " << output << std::endl; 

    } else if (strcmp(argv[i], "-t") == 0) {

        show = 1; 
        std::cout << "Showing the mapping steps...." << std::endl; 

    } else break; 

  }
  // std::cout << i << std::endl;

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

  // create level 0 page table. 
  PageTable *pt = new PageTable(ll[0]);
  
  std::string line; 
  // process all lines in the file.
  int cnt = 0;

  while (getline(ifs, line)) {
    // line is the data.

    std::string::size_type sz; 
    long logic = (int)strtol(line.c_str(), NULL, 16);
    std::cout << "Handling address: " << line 
              << " --> " << std::setfill('0') << std::setw(8) 
              << std::hex << logic << std::endl; 

    // int logic = std::stoi(line, &sz);
    std::cout << "Creating mapping......" << std::endl;
    // page indices.
    for(int i = 0; i < llidx; i++) {
        std::cout << "level " << i << " is " << ll[i] << " bits." << std::endl; 
    }
    

    //pt->insert(logic); 
    cnt++; 

    // TODO, insert entry into the tree and then return the mapped 
    // physical address. 
    
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
