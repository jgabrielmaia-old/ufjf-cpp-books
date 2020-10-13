main: main.o csv_reader.o gui.o random_reader.o
	g++ main.o csv_reader.o gui.o random_reader.o -o main

csv_reader.o: DAL/csv_reader.cpp
	g++ -c DAL/csv_reader.cpp

gui.o: ConsoleGUI/gui.cpp
	g++ -c ConsoleGUI/gui.cpp

random_reader.o: DAL/random_reader.cpp
	g++ -c DAL/random_reader.cpp

clean:
	rm *.o main