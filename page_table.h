//#include "level.h"


#include <iostream>
#include <math.h>
#include <cstdio>
#include <cstdint>

using namespace std;

class Page_Table{
    public:
        unsigned int levels;
        uint32_t *BitmaskArray;
        unsigned int *ShiftArray;
        unsigned int *EntryCount;
        //void PageInsert(Level* levelPtr, unsigned int logicalAddress, unsigned int Frame);
        bool PageInsert(unsigned int logicalAddress, unsigned int Frame);
        Page_Table(unsigned int levels, int *sizes);
        uint32_t logical2offset(uint32_t logicalAddress);
    private:
    

    
        //Level* rootNodePtr;
};