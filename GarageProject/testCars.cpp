//
//  testCars.cpp
//  GarageProject
//
//  Created by Robert Cecil on 1/30/19.
//  Copyright © 2019 Robert Cecil. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <cassert>
#include "Car.h"


using namespace std;

class CarTester {
    
    vector<Car*> Cars;
    Car primaryCar;
    
    //paramaters
    string make;
    string model;
    int year;
    double speed;
    int mpg;
    carType type;
    
public:
    CarTester() {
        
    }
    
    void carTestValidParams1();
    void carTestValidParams2();
    void carTestuniqID();
    void carTestPrintCar();
    void carTestInvalidParams1();
    
};


int main() {
    CarTester carTests = CarTester();
    carTests.carTestValidParams1();
    carTests.carTestValidParams2();
    carTests.carTestuniqID();
    carTests.carTestPrintCar();
    
    return 0;
}

void CarTester::carTestValidParams1() {
    make = "Toyota";
    model = "Camry";
    type = carType::SEDAN;
    year = 2004;
    speed = 105;
    mpg = 29;
    
    Car myCar = Car(make, model, type, mpg, year, speed);
    
    assert(myCar.getMake() == make);
    assert(myCar.getModel() == model);
    assert(myCar.getMPG() == mpg);
    assert(myCar.getSpeed() == speed);
    assert(myCar.getYear() == year);
    printf("Car with valid params, Test 1: all fine!\n" );
}

void CarTester::carTestValidParams2() {
    make = "Honda";
    model = "Civic";
    type = carType::SEDAN;
    year = 2010;
    speed = 23;
    mpg = 32;
    
    Car myCar = Car(make, model, type, mpg, year, speed);
    
    assert(myCar.getMake() == make);
    assert(myCar.getModel() == model);
    assert(myCar.getMPG() == mpg);
    assert(myCar.getSpeed() == speed);
    assert(myCar.getYear() == year);
    printf("Car with valid params, Test 2: all fine!\n" );
}


void CarTester::carTestuniqID() {
    
    make = "Chevrolet";
    model = "Camaro";
    type = carType::SEDAN;
    year = 2014;
    speed = 27;
    mpg = 25;
    
    Car* uniqCar1 = new Car(make, model, type, mpg, year, speed);
    Car* uniqCar2 = new Car(make, model, type, mpg, year, speed);
    Car* uniqCar3 = new Car(make, model, type, mpg, year, speed);
    Car copiedCar1 = *uniqCar1;
    Car* copiedCar2 = new Car(*uniqCar2);
    Car* copiedCar3 = new Car(*uniqCar3);
    
    Cars.push_back(uniqCar1);
    Cars.push_back(uniqCar2);
    Cars.push_back(uniqCar3);
    Cars.push_back(&copiedCar1);
    Cars.push_back(copiedCar2);
    Cars.push_back(copiedCar3);
    
    for (Car* car: Cars) {
        printf("%d \n",car->getID());
    }
    
    assert(copiedCar3->getID() - uniqCar1->getID() == 5);
    printf("Car uniq IDs are incremementing properly.\n" );
}

void CarTester::carTestPrintCar() {
    
    make = "Honda";
    model = "Civic";
    type = carType::SEDAN;
    year = 2010;
    speed = 23;
    mpg = 32;
    
    Car myCar = Car(make, model, type, mpg, year, speed);
    
    ostringstream os;
    os << myCar;
    string testStr = os.str();
    assert(testStr == "2010 Honda Civic with 32 MPG\n");
    printf("Cars are printing properly.\n" );
}

