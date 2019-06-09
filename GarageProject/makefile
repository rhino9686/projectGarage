
garage: garage.o
	g++ -o garage garage.o

garage.o: main.cpp Car.h Car.cpp ToolBox.h Help.h
	g++ -c garage.o Car.cpp main.cpp

tests: testCars.o testGarage.o
	g++ -o carTests testCars.o
	g++ -o garageTests testGarage.o

testCars.o: testCars.cpp Car.h
	g++ -c testCars.o testCars.cpp

testGarage.o: testGarage.cpp Car.h 
	g++ -c testGarage.o testGarage.cpp 

clean:
	rm -f garage carTests garageTests *.o
