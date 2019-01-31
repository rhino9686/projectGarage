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
    CROSSOVER,
    OTHER
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
    carType type;
    
public:
    Car() {
        make = "PLACEHOLDER_MAKE";
        model = "PLACEHOLDER_MODEL";
        year = 3;
        speed = -1;;
        uniqID = -1;
        mpg = 0;
    }
    Car(string makeIn, string modelIn, carType typeIn, int yearIn, double speedIn) {
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
    
    //Getters
    string getMake() { return make; }
    string getModel() { return model; }
    int getYear() { return year; }
    double getSpeed() { return speed; }
    int getMPG() { return mpg; }
    carType getType() { return type; }
    
    
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
    
    Car getMostEfficientCar() {
        Car temp = Car();
        Car* cleanest = &temp;
        
        for (Car car: cars) {
            
            if ( car.getMPG() > cleanest->getMPG() ) {
                cleanest = &car;
            }
        }
        return *cleanest;
    }
    
};

class Racetrack {
    int numCars = 0;
    Car* winner = nullptr;
    
public:
    Racetrack() {
        
    }
};
