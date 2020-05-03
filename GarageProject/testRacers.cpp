//
//  testRacers.cpp
//  GarageProject
//
//  Created by Robert Cecil on 5/3/20.
//  Copyright © 2020 Robert Cecil. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <cassert>
#include "Car.h"


int main() {
    
  // new garage
    Garage Gar = Garage();
    
    string make = "Fastest";
    string model = "Car";
    carType type = carType::SEDAN;
    int year = 2010;
    int speed = 20;
    int mpg = 32;
    
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
    speed = 5;
    mpg = 32;
    
    Car* med = new Car(make, model, type, mpg, year, speed);
    Gar.addCar(med);
    
    
    auto track = Racetrack(3);
    
    
    
    
    return 0;
}
