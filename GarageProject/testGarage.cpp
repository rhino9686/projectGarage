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

    
    return 0;
}
