#include "PageTable.h"

// populate page table with give size; 
PageTable::PageTable(int size) {

    if (size > 0) entries = (TableEntry *)malloc(4*size);
}

void PageTable::insert(unsigned int logicAddr, 
                       unsigned int frame) {

}

Map * PageTable::lookup(unsigned int logicAddr) {

}

unsigned int PageTable::logicToPage(unsigned int laddr, 
                                    unsigned int mask, 
                                    unsigned int shift) {
    return (laddr & mask) >> shift; 
}
