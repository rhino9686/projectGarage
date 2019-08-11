//
//  Car.cpp
//  GarageProject
//
//  Created by Robert Cecil on 3/20/19.
//  Copyright © 2019 Robert Cecil. All rights reserved.
//

#include "Car.h"

///////////////
//Car Functions
///////////////

Car::Car() {
    make = "PLACEHOLDER_MAKE";
    model = "PLACEHOLDER_MODEL";
    year = 2000;
    speed = 27;;
    mpg = 0;
    uniqID = INVALID_ID;
}
 

Car::Car(const string &makeIn, const string &modelIn, const carType &typeIn,
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
 Car::Car(Car const &other) {
     make = other.make;
     model = other.model;
     type = other.type;
     mpg = other.mpg;
     year = other.year;
     speed = other.speed;
     uniqID = idCounter++;
 }

//Assignment operator. Main difference is that this doesn't create a unique ID.
Car& Car::operator=(const Car &other) {
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


//Initialized static counter outside of class definition because of C++ rules for static member vars
int Car::idCounter = 1000;


//Initialized a static map for mapping strings to car types since types don't convert implicitly
std::unordered_map<string, carType> Car::types = {
    {"sedan",carType::SEDAN}, {"truck",carType::TRUCK},
    {"crossover",carType::CROSSOVER}, {"suv",carType::SUV},
    {"other",carType::OTHER }
};


// Static function to clear a vector of dynamic car pointers
void Car::clearCarVec(vector<Car*> carVec) {
    for (auto car: carVec) {
        delete car;
    }
}


/*Implemented static function as well, but as part as Car for testing purposes.
 This function should be used as a safeguard for input validation to uphold Car invariant */

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
        //Enforcing that year is within reasonable range, arbitrarily setting 1970-2021 for now
        if (yearIn < 1970  || yearIn > 2021) {
            return constructionError::Year_error;
        }
        //Enforcing that speed must be nonnegative and reasonable
        if (speedIn < 0  || speedIn > 150) {
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


//Garage Priority Queue Comparators

bool CarSpeedLess::operator()(Car* car1, Car* car2){
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


bool CarMPGLess::operator()(Car* car1, Car* car2) {
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

///////////////////////
//Garage functions
///////////////////////

Garage::Garage() {
    count = 0;
    }

Garage::~Garage() {
    clear();
}


void Garage::addCar(Car* newCar) {
    cars.push_back(newCar);
    fastestQueue.push(newCar);
    efficientQueue.push(newCar);
    count++;
}

void Garage::addCars(vector <Car*> &newCars) {
    for (auto &entryfromVector: newCars) {
        addCar(entryfromVector);
    }
}

//Prepares garage to take in large amount of cars from file
void Garage::resize(const int &newEntries) {
    cars.resize(count + newEntries);
    }

//Deletes all cars from garage, takes care of dynamic memory
void Garage::clear() {
    
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
const int& Garage::getCount() {
    return count;
}


//Get the latest car added to garage
Car* Garage::getLatestCar() {
    Car* latest = cars.at(count - 1);
    return latest;
}

//Get the fastest car in the garage
Car* Garage::getFastestCar() {
    Car* fastest = fastestQueue.top();
    return fastest;
}

//Gets the most efficient car in the garage
Car* Garage::getMostEfficientCar() {
    Car* mostEfficent = efficientQueue.top();
    return mostEfficent;
}

const vector<Car*> Garage::getNFastestCars(const int& N) {
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

void Garage::listCars() {
    if (count == 0) {
        std::cout << "No cars currently in garage\n";
    }
    for (auto car: cars) {
        std::cout << *car;
    }
    
}

const double Garage::getAvgSpeed() {
    double avgSpeed = 0;
    
    for (auto car: cars) {
        avgSpeed += car->getSpeed();
    }
    avgSpeed /= count;
    
    return avgSpeed;
}

//Get the average MPG of all cars in garage
const double Garage::getAvgMpg() {
    double avgMPG = 0;
    
    for (auto car: cars) {
        avgMPG += car->getMPG();
    }
    avgMPG /= count;
    
    return avgMPG;
    
}


/////////////////////
//RaceTrack functions
/////////////////////

Racetrack::Racetrack(const int& numRacersIn) {
    numRacers = numRacersIn;
    
}

void Racetrack::addRacers() {
    return;
}


void Racetrack::printTrack() {
    
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
