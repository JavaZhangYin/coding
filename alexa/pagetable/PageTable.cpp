#include "PageTable.h"

// populate page table with give size; 
PageTable::PageTable(int size) {
  TableEntry *e = NULL;
  for(int i = 0; i < size; i++) {
    e = new TableEntry();

    e->tbl = NULL; 
    entries.push_back(e);
  }
}

void PageTable::insert(unsigned int logicAddr, unsigned int frame) {

}

Map * PageTable::lookup(unsigned int logicAddr) {

}

unsigned int PageTable::logicToPage(unsigned int laddr, unsigned int mask, unsigned int shift) {
  return (laddr & mask) >> shift; 
}
