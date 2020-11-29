main: main.o csv_reader.o gui.o random_reader.o benchmark.o quicksort.o insertionsort.o output_writer.o input_reader.o mapping.o hash.o parsing.o
	g++ -g -std=c++11 main.o csv_reader.o gui.o random_reader.o benchmark.o quicksort.o insertionsort.o output_writer.o input_reader.o mapping.o hash.o parsing.o -o main

hash.o: Hash/hash.cpp
	g++ -c -g -std=c++11 Hash/hash.cpp

parsing.o: DAL/parsing.cpp
	g++ -c -g -std=c++11 DAL/parsing.cpp

mapping.o: DAL/mapping.cpp
	g++ -c -g -std=c++11 DAL/mapping.cpp

csv_reader.o: DAL/csv_reader.cpp
	g++ -c -g -std=c++11 DAL/csv_reader.cpp

gui.o: GUI/gui.cpp
	g++ -c -g -std=c++11 GUI/gui.cpp

random_reader.o: DAL/random_reader.cpp
	g++ -c -g -std=c++11 DAL/random_reader.cpp

benchmark.o: Benchmark/benchmark.cpp
	g++ -c -g -std=c++11 Benchmark/benchmark.cpp

quicksort.o: Sorters/quicksort.cpp
	g++ -c -g -std=c++11 Sorters/quicksort.cpp

insertionsort.o: Sorters/insertionsort.cpp
	g++ -c -g -std=c++11 Sorters/insertionsort.cpp

output_writer.o: DAL/output_writer.cpp
	g++ -c -g -std=c++11 DAL/output_writer.cpp

input_reader.o: DAL/input_reader.cpp
	g++ -c -g -std=c++11 DAL/input_reader.cpp

clean:
	rm *.o main