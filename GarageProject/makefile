
CXX      = g++

CXXFLAGS = -std=c++17 -Wall -g3


garage: main.o Car.o
	$(CXX) main.o Car.o -o garage

main.o: main.cpp ToolBox.h
	$(CXX) -c main.cpp -o main.o

Car.o: Car.cpp Car.h
	$(CXX) -c Car.cpp -o Car.o

tests: testCars.o testGarage.o
	$(CXX) -o carTests testCars.o
	$(CXX) -o garageTests testGarage.o

testCars.o: testCars.cpp Car.h
	$(CXX) -c testCars.o testCars.cpp

testGarage.o: testGarage.cpp Car.h 
	$(CXX) -c testGarage.o testGarage.cpp 

clean:
	rm -f garage carTests garageTests *.o
