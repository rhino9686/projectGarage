//
//  Car.h
//  GarageProject
//
//  Created by Robert Cecil on 1/22/19.
//  Copyright © 2019 Robert Cecil. All rights reserved.
//

#ifndef Car_h
#define Car_h

#endif /* Car_h */

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using std::string;
using std::vector;

//Class to distinct between vehicle form factors
enum class carType {
    SEDAN,
    TRUCK,
    SUV,
};


//Class to represent a car and perform operations like racing
class Car {
private:
    string make;
    string model;
    int year;
    double speed;
    int uniqID;
    int mpg;
    static int idCounter;
    
public:
    Car() {
        make = "";
        model = "";
        year = 3;
        speed = -1;;
        uniqID = -1;
        mpg = 30;
    }
    Car(string makeIn, string modelIn, int yearIn, double speedIn) {
        make = makeIn;
        model = modelIn;
        year = yearIn;
        speed = speedIn;
        uniqID = idCounter++;
    }
    Car(Car const &other) {
        make = other.make;
        model = other.model;
        year = other.year;
        uniqID = other.uniqID;
        uniqID++;
    }
    
    string getMake();
    string getModel();
    int getYear();
    int getSpeed();
};

//Initialize static counter here
int Car::idCounter = 1000;

//Class to represent a garage, the main database to hold all cars
class Garage {
    int count;
    vector<Car> cars;
    
public:
    //Constructors
    Garage() {
        count = 0;
    }
    //Add a car to the garage
    void addCar(Car newCar) {
        cars.push_back(newCar);
        count++;
    }
    //Delete all cars from garage
    void clear() {
        cars.clear();
        count = 0;
    }
    //Get the number of cars in the garage
    int getCount() {
        return count;
    }
    //Get the latest car added to garage
    Car getLatestCar() {
        Car latest = cars.at(count - 1);
        return latest;
    }
    //Get the fastest car in the garage
    Car getFastestCar() {
        Car temp = Car();
        Car* fastest = &temp;
        
        for (Car car: cars) {
            
            if ( car.getSpeed() > fastest->getSpeed() ) {
                fastest = &car;
            }
        }
        return *fastest;
    }
    
};

class Racetrack {
    int numCars = 0;
    Car* winner = nullptr;
    
public:
    Racetrack() {
        
    }
};
