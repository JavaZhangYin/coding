#ifndef _PAGE_FRAME_MAP_H_
#define _PAGE_FRAME_MAP_H_

using namespace std; 

// map virtual page to a frame page. 
// this class will maintain a static 
// variable so that we know what's the 
// currently mapped frame. 

class PageFrameMap {
  
public: 
    PageFrameMap(); 
    int getFrame() const; 
    int setFrame(int f); 
    int next(); // get the next frame for mapping. 

    /**
     * Return the physical address with given offset. 
     * @param offset the address offset relative to the page.
     * @return the physical address. 
     */
    int getPhysicalAddress(int offset); 

private: 
    static int current; // currently mapped page. 
    int frame;	      // frame address.
  
}; 

#endif
