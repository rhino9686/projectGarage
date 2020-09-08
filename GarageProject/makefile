
UNAME := $(shell uname)




CXX      = g++


ifeq ($(UNAME), Darwin)

	CXX  = clang++
endif



CXXFLAGS = -std=c++17 -stdlib=libc++ -Wall -g3


garage: main.o Car.o
	$(CXX) $(CXXFLAGS)  main.o Car.o -o garage

main.o: main.cpp ToolBox.h
	$(CXX)  $(CXXFLAGS) -c main.cpp -o main.o

Car.o: Car.cpp Car.h
	$(CXX) $(CXXFLAGS)  -c Car.cpp -o Car.o

tests: testCars.o testGarage.o
	$(CXX)  $(CXXFLAGS)   -o carTests testCars.o
	$(CXX) $(CXXFLAGS)   -o garageTests testGarage.o

testCars.o: testCars.cpp Car.h
	$(CXX)  $(CXXFLAGS)  -c testCars.o testCars.cpp

testGarage.o: testGarage.cpp Car.h 
	$(CXX)  $(CXXFLAGS)  -c testGarage.o testGarage.cpp 

clean:
	rm -f garage carTests garageTests *.o
	
