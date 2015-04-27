#ifndef _TABLE_TABLE_H_
#define _TABLE_TABLE_H_

#include "PageFrameMap.hpp" 

using namespace std;

class PageTable {
 public:
  PageTable(int size); 
  void insert(unsigned int logicAddr, unsigned int frame); 
  void lookup(unsigned int logicAddr); 
  unsigned int logicToPage(unsigned int laddr, 
			   unsigned int mask, 
			   unsigned int shift); 

  /**
   * Get the number of entries in the table. 
   * @param none. 
   * @return size of table. 
   */
  int getTableSize() const { return size; }

  /**
   * Return the table entry with given integer index. 
   * @param idx The index of entry in the table. 
   * @return Pointer of table entry of the given index. 
   */
  TableEntry *getEntry(int idx);

  /**
   * Set the entry into the index. 
   * @param te Pointer to the table entry. 
   * @param idx Index in the table to insert the table entry into. 
   * @return true when success and false on failure. 
   */
  bool setEntry(TableEntry *te, int idx);

  /**
   * Check if the given index has been set or not. 
   * @param idx The table entry index to check.
   * @return true if the table entry has been set, otherwise false.
   */
  bool isEntrySet(int idx); 

 private:
  int size; 
  TableEntry **entries; 
};

// A page table entry class. 
class TableEntry {
 public: 
  TableEntry(); 
  TableEntry(bool isLeaf);

  /**
   * If this entry is a leaf or not. 
   * A leaf entry will point to a map object. A non-leaf will point to
   * a page table object. 
   * @param none. 
   * @return true if this is leaf node otherwise false.
   */
  bool leaf() const { return isLeaf; }
  
  /**
   * This entry will point to the given page table. 
   * @param ptbl The page table pointer this entry will point to. 
   * @return void. 
   */
  void setTable(PageTable *ptbl); 

  /** 
   * THIS leaf entry will point to a page frame map object. 
   * @param pfm The page frame map. 
   * @return void. 
   */
  void setFrameMap(PageFrameMap *pfm); 

 private: 
  bool isLeaf;
  PageTable *tbl; 
  PageFrameMap *frame; // mapping to frame. 
};

#endif
