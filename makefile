main: main.o csv_reader.o gui.o random_reader.o benchmark.o quicksort.o insertionsort.o output_writer.o input_reader.o mapping.o hash.o parsing.o
	g++ -g main.o csv_reader.o gui.o random_reader.o benchmark.o quicksort.o insertionsort.o output_writer.o input_reader.o mapping.o hash.o parsing.o -o main

hash.o: Hash/hash.cpp
	g++ -c -g Hash/hash.cpp

parsing.o: DAL/parsing.cpp
	g++ -c -g DAL/parsing.cpp

mapping.o: DAL/mapping.cpp
	g++ -c -g DAL/mapping.cpp

csv_reader.o: DAL/csv_reader.cpp
	g++ -c -g DAL/csv_reader.cpp

gui.o: GUI/gui.cpp
	g++ -c -g GUI/gui.cpp

random_reader.o: DAL/random_reader.cpp
	g++ -c -g DAL/random_reader.cpp

benchmark.o: Benchmark/benchmark.cpp
	g++ -c -g Benchmark/benchmark.cpp

quicksort.o: Sorters/quicksort.cpp
	g++ -c -g Sorters/quicksort.cpp

insertionsort.o: Sorters/insertionsort.cpp
	g++ -c -g Sorters/insertionsort.cpp

output_writer.o: DAL/output_writer.cpp
	g++ -c -g DAL/output_writer.cpp

input_reader.o: DAL/input_reader.cpp
	g++ -c -g DAL/input_reader.cpp

clean:
	rm *.o main