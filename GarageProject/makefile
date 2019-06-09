
garage: main.o Car.o
	g++ main.o Car.o -o garage

main.o: main.cpp ToolBox.h
	g++ -c main.cpp -o main.o

Car.o: Car.cpp Car.h
	g++ -c Car.cpp -o Car.o

tests: testCars.o testGarage.o
	g++ -o carTests testCars.o
	g++ -o garageTests testGarage.o

testCars.o: testCars.cpp Car.h
	g++ -c testCars.o testCars.cpp

testGarage.o: testGarage.cpp Car.h 
	g++ -c testGarage.o testGarage.cpp 

clean:
	rm -f garage carTests garageTests *.o
