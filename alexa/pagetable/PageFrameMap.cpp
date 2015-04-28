#include "PageFrameMap.hpp"

PageFrameMap::PageFrameMap() {    
    frame = 0x00000000;
}

int PageFrameMap::getFrame() const {
    return frame;
}

int PageFrameMap::setFrame(int f) {
    frame = f; 
    current = f; 
}

int PageFrameMap::next() {
    return ++current;
}

int PageFrameMap::current = 0x00000000; 
