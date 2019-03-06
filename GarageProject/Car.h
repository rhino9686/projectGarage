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
    Year_error,
    Speed_error,
    MPG_error,
    Other_error,
    none
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
    static constructionError checkError(const string &makeIn, const string &modelIn, const carType &typeIn,
                                        const int &mpgIn, const int &yearIn, const double &speedIn);
    
    //printing operator overload
    friend std::ostream& operator<<(std::ostream& os, const Car& car) {
        os << car.year << " " << car.make << " " << car.model <<  " with " << car.mpg << " MPG\n";
        
        return os;
    }
};

//Initialized static counter outside of class definition because of C++ rules for static member vars
int Car::idCounter = 1000;

/*Implemented static function outside definition as well, but as part as Car for testing purposes.
 This function should be used as a safeguard for input validation to uphold Car invariant
 */
constructionError Car::checkError(const string &makeIn, const string &modelIn, const carType &typeIn,
                                  const int &mpgIn, const int &yearIn, const double &speedIn) {
    try {
        
        //Enforcing that make must be a viable name, somehow have to filter out gibberish
        //TODO: make hashTable of known manufacturers to compare against?
        if (makeIn == ""  || makeIn.length() > 10 ) {
            return constructionError::Make_error;
        }
        //Enforcing that model must be a viable name for the manufacturer
        //TODO: make hashTable of known models for each manufacturers?
        if (modelIn == ""  || modelIn.length() > 10 ) {
            return constructionError::Model_error;
        }
        //Enforcing that year is within reasonable range, arbitrarily setting 1980-2021 for now
        if (yearIn < 1980  || yearIn > 2021) {
            return constructionError::Year_error;
        }
        //Enforcing that speed must be nonnegative and reasonable
        if (speedIn < 0  || speedIn > 120) {
            return constructionError::Speed_error;
        }
        //Enforcing that mpg is within a reasonable range
        if (mpgIn < 0  || mpgIn > 50) {
            return constructionError::MPG_error;
        }
    } catch (...) {
        //std::exception_ptr p = std::current_exception();
        //if computing any of the above fail, return a generic error
        return constructionError::Other_error;
    }

    //if everything passes, return no error
    return constructionError::none;
}



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
    
    ~Garage() {
        clear();
    }
    
    
    //Adds a car to the garage, car will be a dynamic pointer for use in multiple data structures
    void addCar(Car* newCar) {
        cars.push_back(newCar);
        fastestQueue.push(newCar);
        efficientQueue.push(newCar);
        count++;
    }
    
    //Adds a list of cars to the garage, cars will be in a vector of dynamic pointers
    void addCars(vector <Car*> &newCars) {
        for (auto &entryfromVector: newCars) {
            addCar(entryfromVector);
        }
    }
    
    //Prepares garage to take in large amount of cars from file
    void resize(const int &newEntries) {
        cars.resize(count + newEntries);
    }
    
    
    //Deletes all cars from garage, takes care of dynamic memory
    void clear() {
        
        for(Car* car: cars){
            delete car;
            //std::cout << "cleared one car\n";
            car = nullptr;
        }
        
        //clear base vector
        cars.clear();
        
        //clear speed queue
        while (!fastestQueue.empty()){
            fastestQueue.pop();
           // std::cout << "cleared one car\n";
        }
        //clear efficiency queue
        while (!efficientQueue.empty()){
            efficientQueue.pop();
            //std::cout << "cleared one car\n";
        }
        
        count = 0;
    }
    //Get the number of cars in the garage
    const int& getCount() {
        return count;
    }
    //Get the latest car added to garage
    Car* getLatestCar() {
        Car* latest = cars.at(count - 1);
        return latest;
    }
    //Get the fastest car in the garage
    Car* getFastestCar() {
        Car* fastest = fastestQueue.top();
        return fastest;
    }
    //Gets the most efficient car in the garage
    Car* getMostEfficientCar() {
        Car* mostEfficent = efficientQueue.top();
        return mostEfficent;
    }
    
    const vector<Car*> getNFastestCars(const int& N) {
        //just quit if garage is smaller than query
        if (N > count){
            std::cout << "garage has insufficient cars for that task";
        }
        
        vector<Car*> candidates;
        
        // get top N fastest cars
        for (int i = 0; i < N; i++) {
            auto fastCar = fastestQueue.top();
            candidates.push_back(fastCar);
            fastestQueue.pop();
        }
        // put them back into PQ
        for (Car* car: candidates) {
            fastestQueue.push(car);
        }
        return candidates;
    }
    
    
    void listCars() {
        if (count == 0) {
            std::cout << "No cars currently in garage\n";
        }
        for (auto car: cars) {
            std::cout << *car;
        }
    }
};


class Racetrack {
    int numRacers = 0;
    vector<Car*> racers;
    Car* winner = nullptr;
    
public:
    Racetrack(const int& numRacersIn) {
        numRacers = numRacersIn;
        
    }
    
    void addRacers() {
        
    }
    void printTrack() {
        
        int fieldHeight = 4;
        int fieldWidth = 5;
        std::cout << " ";
        
        for(int lon = 0; lon < fieldWidth; lon++) {
            std::cout << (lon % 10);
        }
        std::cout << "\n";
        for (int lat = 0; lat < fieldHeight; lat++) {
            std::cout <<(lat % 10);
            
            for (int lon = 0; lon < fieldWidth; lon++) {
                
                char charToPrint = '-';
                
                /*
                for (Car* player:racers){

                    if (player->getRoundedXCoor() == lon && player->getRoundedYCoor() == lat){
                        
                        charToPrint = player->getSymbol();
                    }
                    
                }//for
                 */
                std::cout << charToPrint;
                
            }//for

            std:: cout << "\n";
        }//for
    };
};

