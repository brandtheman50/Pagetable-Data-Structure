pagetable: pagetable.o outputMode.o byu_tracereader.o output_mode_helpers.o  level.o page_table.o
	g++ -std=c++11 -o pagetable pagetable.o outputMode.o byu_tracereader.o output_mode_helpers.o level.o page_table.o

pagetable.o: pagetable.cpp
	g++ -std=c++11 -c -o pagetable.o pagetable.cpp 

outputMode.o: outputMode.cpp
	g++ -std=c++11 -c -o outputMode.o outputMode.cpp 

byu_tracereader.o: byu_tracereader.cpp
	g++ -std=c++11 -c -o byu_tracereader.o byu_tracereader.cpp

output_mode_helpers.o: output_mode_helpers.cpp
	g++ -std=c++11 -c -o output_mode_helpers.o output_mode_helpers.cpp

level.o: level.h level.cpp
	g++ -std=c++11 -c level.cpp

page_table.o: page_table.cpp page_table.cpp
	g++ -std=c++11 -c page_table.cpp
clean:
	rm -f *.o pagetable *~
