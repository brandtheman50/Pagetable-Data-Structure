
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <getopt.h>
#include <iomanip>
#include <stdbool.h>
#include <unistd.h>
#include "output_mode_helpers.h"
#include "byutr.h"
#include "page_table.h"
 

#define OOPS 5

using namespace std;


string mode;

const int BITS = 15;
int currentCount = 0;
int memoryCount = 0;
int arguments = 1;
int i;



bool isBitmask = false;
bool isLogical2physical = false;
bool isPage2frame = false;
bool isOffset = false;
bool isSummary = false;
bool nFlag = false;

void flag(int argc, char **argv) {
    int opt;
    while ((opt = getopt(argc, argv, "n:o:")) != -1) {
        switch (opt) {
            /* Sets corresponding boolean to true if the argument is valid */
            case 'n': 
                /* if '-n' is inputted, nFlag is set to true */
                memoryCount = atoi(optarg);
                
                nFlag = true;
                arguments = arguments + 2;
                break;
            case 'o': 
                /* if the selected mode is inputted, the 
                corresponding boolean will be set to true */
                mode = string(optarg);             // mode will be the 3rd input in argv
                if (mode == "bitmasks"){
                    isBitmask = true;
                }
                else if (mode == "logical2physical"){
                    isLogical2physical = true;           
                }
                else if (mode == "page2frame"){
                    isPage2frame = true;
                }
                else if (mode == "offset"){
                    isOffset = true;
                }
                else if (mode == "summary"){
                    isSummary = true;
                }
                else {
                    isSummary = true;
                } 
                arguments = arguments + 2;
                break;
            default:
                break;
        }
    } 
    
}

void runCode(int argc, char **argv){
    FILE* file;
    file = fopen(argv[arguments], "r");
    ++arguments;
    if(file == NULL){
        cout<<"Cannot open file"<<endl;
        return;
    }
    unsigned int levels = argc - arguments;
    int levelsizes[levels];
    int counter = 0;
    for(arguments ; arguments<argc; ++arguments){
        levelsizes[counter] = atoi(argv[arguments]);
        ++counter;
    }
    Page_Table pagetable(levels, levelsizes);
    if(isBitmask){
        report_bitmasks(levels, pagetable.BitmaskArray);
        return;
    }
    p2AddrTr trace_item;  /* Structure with trace information */
    bool done = false;
    int loop = 0;
    while (! done) {
    // Grabe the next address
    if(done || loop == memoryCount){
            break;
        }
        int bytesread = NextAddress(file, &trace_item);
    // Check if we actually got something
        if(isOffset)
            report_logical2offset(trace_item.addr, pagetable.logical2offset(trace_item.addr));
        done = bytesread == 0;
        
        ++loop;
  }
}

/*
    main function had 2 functions to run
    first one helps the code to select if 
    the input contains the selected flag
    then the second function process the 
    rest of the code
*/
int main(int argc, char **argv) {
    
    flag(argc, argv);                           // sets the boolean 
    runCode(argc, argv);                        // runs the rest of the code

   return 0;
}
    
   
   
