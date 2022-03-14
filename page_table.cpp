#include "page_table.h"

Page_Table::Page_Table(unsigned int levels, int* sizes){
    unsigned int offset = 32;
    Page_Table::levels = levels;
    BitmaskArray = new uint32_t[levels];
    ShiftArray = new unsigned int[levels];
    EntryCount = new unsigned int[levels];
    //rootNodePtr = nullptr;

    for(int i=0; i<levels; ++i){
        offset -= sizes[i];
        ShiftArray[i] = offset;
        EntryCount[i] = pow(2, sizes[i]);
    }
    unsigned int shiftBits = offset;
    for(int i=levels-1; i>=0; --i){
        int bits = sizes[i];
        unsigned int bitmask = (unsigned int) (1 << bits) -1;
        BitmaskArray[i] = bitmask << shiftBits;
        shiftBits += sizes[i];

    }
}

uint32_t Page_Table::logical2offset(uint32_t logical2offset){
    uint32_t sub;
    uint32_t offset = logical2offset;
    for(int i=0; i<levels; ++i){
        sub = logical2offset & BitmaskArray[i];
        offset -= sub;
    }
    return offset;
}