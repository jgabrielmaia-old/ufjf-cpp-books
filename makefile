main: main.o csv_reader.o gui.o random_reader.o benchmark.o
	g++ main.o csv_reader.o gui.o random_reader.o benchmark.o -o main

csv_reader.o: DAL/csv_reader.cpp
	g++ -c DAL/csv_reader.cpp

gui.o: GUI/gui.cpp
	g++ -c GUI/gui.cpp

random_reader.o: DAL/random_reader.cpp
	g++ -c DAL/random_reader.cpp

benchmark.o: Benchmark/benchmark.cpp
	g++ -c Benchmark/benchmark.cpp

clean:
	rm *.o main