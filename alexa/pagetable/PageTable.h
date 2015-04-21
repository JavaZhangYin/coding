#ifndef _TABLE_TABLE_H_
#define _TABLE_TABLE_H_

using namespace std;

// the page table. 
class PageTable {
 public:
  PageTable(int size); 
  // insert into page table.
  void insert(unsigned int logicAddr, unsigned int frame); 

  // lookup logic address in page table. 
  void lookup(unsigned int logicAddr); 

  // translate a logic address to page with given mask and shift. 
  unsigned int logicToPage(unsigned int laddr, unsigned int mask, unsigned int shift); 

 private:
  int size; 
  vector<TableEntry *> entries; 
};

// A page table entry class. 
class TableEntry {
 public: 
  TableEntry(); 
  TableEntry(bool isLeaf);

 private: 
  bool isLeaf;
  PageTable *tbl; 
  Map *map; // mapping to frame. 
};

// the mapping of virtual page to a frame. 
class Map {
 public: 
  Map(); 

 private: 
  int frame; 
};

#endif
