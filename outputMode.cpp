#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <iomanip>
#include <stdbool.h>
#include "outputMode.h"

using namespace std;

void report_bitmask(int levels, uint32_t *masks) {
    uint32_t bitmask;
    int offCounter = 0;
    cout << "Bitmasks\n";
    cout << setfill('0') << uppercase;
    for (int i=0; i < levels; i++) {
        if (masks[i] == 4){
            bitmask = 0xF;
            bitmask = bitmask<<28 - offCounter;
            }  
        else if (masks[i] == 8){
            bitmask = 0xFF;
            bitmask = bitmask<<24 - offCounter;
        }
        else if (masks[i] == 12){
            bitmask = 0xFFF;
            bitmask = bitmask<<20 - offCounter;
        }
        else if (masks[i] == 16){
            bitmask = 0xFFFF;
            bitmask = bitmask<<16 - offCounter;
        }
        else if (masks[i] == 20){
            bitmask = 0xFFFFF;
            bitmask = bitmask<<12 - offCounter;
        }
        else if (masks[i] == 24){
            bitmask = 0xFFFFF;
            bitmask = bitmask<<8 - offCounter;
        }
        else if (masks[i] == 28){
            bitmask = 0xFFFFF;
            bitmask = bitmask<<4 - offCounter;
        }
        offCounter = offCounter + 4;
        cout << "level " << i << " mask " <<  hex << setw(8) << bitmask << "\n";
    }
}