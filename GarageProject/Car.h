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
#include <queue>
#include <cstdlib>

#define INVALID_ID -23

using std::string;
using std::vector;
using std::priority_queue;

//Class to distinguish between vehicle form factors
enum class carType {
    SEDAN,
    TRUCK,
    SUV,
    CROSSOVER,
    OTHER
};

//Class for runtime errors on car input
enum class constructionError {
    Make_error,
    Model_error,
    year_error,
    speed_error,
    mpg_error,
    other_error
};


//Class to represent a car and perform operations like racing
class Car {
private:
    //Initial member variables, may expand later to get better simulation for racing
    string make;
    string model;
    int year;
    double speed;
    int uniqID;
    int mpg;
    static int idCounter;
    carType type;
    
public:
    //Default constructor, may revise with better default values
    Car() {
        make = "PLACEHOLDER_MAKE";
        model = "PLACEHOLDER_MODEL";
        year = 2000;
        speed = 27;;
        mpg = 0;
        uniqID = INVALID_ID;
    }
    /*Constructor from input fields, user entered. TODO: make sure input upholds variant, but error. Sanitize at user input level to be forgiving */
    Car(const string &makeIn, const string &modelIn, const carType &typeIn,
        const int &mpgIn, const int &yearIn, const double &speedIn) {
        make = makeIn;
        model = modelIn;
        type = typeIn;
        mpg = mpgIn;
        year = yearIn;
        speed = speedIn;
        uniqID = idCounter++;
    }
    //Copy Constructor
    Car(Car const &other) {
        make = other.make;
        model = other.model;
        type = other.type;
        mpg = other.mpg;
        year = other.year;
        speed = other.speed;
        uniqID = idCounter++;
    }
    //Assignment operator. Main difference is that this doesn't create a unique ID.
    Car& operator=(const Car &other) {
        if (this == &other) {
            return *this;
        }
        make = other.make;
        model = other.model;
        year = other.year;
        speed = other.speed;
        mpg = other.mpg;
        uniqID = other.uniqID;
        return *this;
    }
    
    
    //Getters
    const string getMake() { return make; }
    const string getModel() { return model; }
    const int getYear() { return year; }
    double getSpeed() { return speed; }
    const int getMPG() { return mpg; }
    const carType getType() { return type; }
    const int getID() { return uniqID; }
    
    //printing operator overload
    friend std::ostream& operator<<(std::ostream& os, const Car& car) {
        os << car.year << " " << car.make << " " << car.model <<  " with " << car.mpg << " MPG\n";
        
        return os;
    }
};

//Initialize static counter here
int Car::idCounter = 1000;

//Comparator classes for priority queues

class CarSpeedLess{
    
public:
    bool operator()(Car* car1, Car* car2){
        if (car1->getSpeed() < car2->getSpeed()) {
            return true;
            
        }
        
        if (car1->getSpeed() == car2->getSpeed()) {
            if (car1->getMPG() > car2->getMPG())  {
                return true;
            }
        }
        return false;
    }
};

class CarMPGLess{
    
public:
    bool operator()(Car* car1, Car* car2) {
        if (car1->getMPG() < car2->getMPG()) {
            return true;
        }
        
        if (car1->getMPG() == car2->getMPG()) {
            if (car1->getYear() > car2->getYear()) {
                return true;
            }
        }
        return false;
    }
};


//Class to represent a garage, the main database to hold all cars
class Garage {
    int count;
    vector<Car*> cars;
    priority_queue<Car*, vector<Car*>, CarSpeedLess> fastestQueue;
    priority_queue<Car*, vector<Car*>, CarMPGLess> efficientQueue;
    
public:
    //Constructor
    Garage() {
        count = 0;
    }
    
    //Adds a car to the garage, car will be a dynamic pointer for use in multiple data structures
    void addCar(Car* newCar) {
        cars.push_back(newCar);
        fastestQueue.push(newCar);
        efficientQueue.push(newCar);
        count++;
    }
    
    //Prepares garage to take in large amount of cars from file
    void resize(const int &newEntries) {
        cars.resize(count + newEntries);
    }
    
    
    //Deletes all cars from garage, takes care of dynamic memory
    void clear() {
        
        for(Car* car: cars){
            delete car;
            car = nullptr;
        }
        
        //clear base vector
        cars.clear();
        
        //clear speed queue
        while (!fastestQueue.empty()){
            fastestQueue.pop();
        }
        //clear efficiency queue
        while (!efficientQueue.empty()){
            efficientQueue.pop();
        }
        
        
        count = 0;
    }
    //Get the number of cars in the garage
    const int& getCount() {
        return count;
    }
    //Get the latest car added to garage
    const Car* getLatestCar() {
        Car* latest = cars.at(count - 1);
        return latest;
    }
    //Get the fastest car in the garage
    const Car* getFastestCar() {
        Car* fastest = fastestQueue.top();
        return fastest;
    }
    //Gets the most efficient car in the garage
    const Car* getMostEfficientCar() {
        Car* mostEfficent = efficientQueue.top();
        return mostEfficent;
    }
};


class Racetrack {
    int numCars = 0;
    Car* winner = nullptr;
    
public:
    Racetrack() {
        
    }
};

