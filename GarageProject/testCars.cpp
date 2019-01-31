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
    
    vector<Car> Cars;
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
    void carTest2();
    void carTest3();
    void carTest4();
    void carTest5();
    
};


int main() {
    
    
    
    return 0;
}

void CarTester::carTestValidParams1() {
    make = "Toyota";
    model = "Camry";
    type = carType::SEDAN;
    year = 2004;
    speed = 105;
    mpg = 29;
    
    Car myCar = Car(make, model, type, year, speed);
    
    assert(myCar.getMake() == make);
    assert(myCar.getModel() == model);
    assert(myCar.getMPG() == mpg);
    assert(myCar.getSpeed() == speed);
    assert(myCar.getYear() == year);
    
}

