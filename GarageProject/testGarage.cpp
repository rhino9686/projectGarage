//
//  testGarage.cpp
//  GarageProject
//
//  Created by Robert Cecil on 2/19/19.
//  Copyright © 2019 Robert Cecil. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <cassert>
#include "Car.h"

using namespace std;

class GarageTester {
    
    Car primaryCar;
    Garage Gar;
    
    //paramaters for making cars
    string make;
    string model;
    int year;
    double speed;
    int mpg;
    carType type;
    
public:
    GarageTester() {
        Gar = Garage();
    }

    void garageAddCars();
    void garageFetchCars();
    void garageGetFastestCar();
    void garageGetEfficientCar();
    void garageGetSlowestCar();
    void garageGetAvgSpeed();
    void garageGetAvgMPH();
    void garageGetAvgYear();
    void carTest5();
    
};


int main() {
    GarageTester garTests = GarageTester();
    garTests.garageAddCars();
    garTests.garageGetFastestCar();

    
    return 0;
}

void GarageTester::garageAddCars() {
    make = "Honda";
    model = "Civic";
    type = carType::SEDAN;
    year = 2010;
    speed = 23;
    mpg = 32;
    
    Car* carOne = new Car(make, model, type, mpg, year, speed);
    
    make = "Toyota";
    model = "Camry";
    type = carType::SEDAN;
    year = 2004;
    speed = 105;
    mpg = 29;
    
    Car* carTwo = new Car(make, model, type, mpg, year, speed);
    
    make = "Chevrolet";
    model = "Camaro";
    type = carType::SEDAN;
    year = 2007;
    speed = 79;
    mpg = 35;
    
    Car* carThree = new Car(make, model, type, mpg, year, speed);
    
    Gar.addCar(carOne);
    Gar.addCar(carTwo);
    Gar.addCar(carThree);
    
    cout << Gar.getCount() << endl;
    Gar.clear();
    
    cout << Gar.getCount() << endl;
    
}

void GarageTester::garageGetFastestCar() {
    make = "Fastest";
    model = "Car";
    type = carType::SEDAN;
    year = 2010;
    speed = 200;
    mpg = 32;
    
    Car* fast = new Car(make, model, type, mpg, year, speed);
    Gar.addCar(fast);
    
    make = "Slowest";
    model = "Car";
    type = carType::SEDAN;
    year = 2010;
    speed = 1;
    mpg = 32;
    
    Car* slow = new Car(make, model, type, mpg, year, speed);
    Gar.addCar(slow);
    
    make = "Medium";
    model = "Car";
    type = carType::SEDAN;
    year = 2010;
    speed = 50;
    mpg = 32;
    
    Car* med = new Car(make, model, type, mpg, year, speed);
    Gar.addCar(med);
    
    Car* result = Gar.getFastestCar();
    assert(result->getSpeed() == 200);
    
    printf("Garage returns fastest car properly.\n");
    
}
