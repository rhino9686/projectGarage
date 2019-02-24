
garage: garage.o
   g++ -o garage garage.o



garage.o: main.cpp Car.h ToolBox.h Help.h
   g++ -c Car.h ToolBox.h Help.h main.cpp
   

test: testCars.o testGarage.o
  
   

clean:
   rm -f garage garage.o