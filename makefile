main: main.o DAL/csv_reader.o ConsoleGUI/gui.o
	g++ main.o csv_reader.o gui.o -o main

DAL/csv_reader.o: DAL/csv_reader.cpp
	g++ -c DAL/csv_reader.cpp

ConsoleGUI/gui.o: ConsoleGUI/gui.cpp
	g++ -c ConsoleGUI/gui.cpp

clean:
	rm *.o main