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
    {"sedan", carType::SEDAN}, {"truck", carType::TRUCK},
    {"crossover", carType::CROSSOVER}, {"suv", carType::SUV},
    {"other", carType::OTHER }
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
        //TODO: integrate manufacturer data as an error checking method
        if (makeIn == "" || makeIn.length() > 10 ) {
            return constructionError::Make_error;
        }
        
        //Enforcing that model must be a viable name for the manufacturer
        if (modelIn == "" || modelIn.length() > 10 ) {
            return constructionError::Model_error;
        }
        //Enforcing that year is within reasonable range, arbitrarily setting 1970-2021 for now
        if (yearIn < 1970 || yearIn > 2026) {
            return constructionError::Year_error;
        }
        //Enforcing that speed must be nonnegative and reasonable
        if (speedIn < 0 || speedIn > 150) {
            return constructionError::Speed_error;
        }
        //Enforcing that mpg is within a reasonable range
        if (mpgIn < 0 || mpgIn > 50) {
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


RaceCar::RaceCar(){
    speed = 0;
    inputtedCar = nullptr;
    symbol = 'R';
    x_coor = 0;
    y_coor = 0;
    
    
}

RaceCar::RaceCar(Car* inputCar, int row, char symbol_in) {
    speed = inputCar->getSpeed();
    inputtedCar = inputCar;
    x_coor = 0;
    y_coor = row;
    symbol = symbol_in;
}



void RaceCar::incrXCoor(double x_delta){
    x_coor += x_delta;
}

void RaceCar::incrYCoor(double y_delta){
    y_coor+= y_delta;
}


void RaceCar::move(){
    incrXCoor(0.2 * speed);
}

int RaceCar::getRoundedXCoor() {
    return static_cast<int>(x_coor);
}

int RaceCar::getRoundedYCoor() {
    return static_cast<int>(y_coor);
}

Car* RaceCar::getCar() {
    return inputtedCar;
}


const char RaceCar::getSymbol() {
    return symbol;
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

//Adds a singular car to the garage
//Does not check for validity, use the car error functions to do so
void Garage::addCar(Car* newCar) {
    cars.push_back(newCar);
    fastestQueue.push(newCar);
    efficientQueue.push(newCar);
    count++;
}

//Adds cars from a vector of cars for ease of use
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

//Gets the number of cars in the garage
const int& Garage::getCount() {
    return count;
}


//Gets the latest car added to garage
Car* Garage::getLatestCar() {
    Car* latest = cars.at(count - 1);
    return latest;
}

//Gets the fastest car in the garage
Car* Garage::getFastestCar() {
    Car* fastest = fastestQueue.top();
    return fastest;
}

//Gets the most efficient car in the garage
Car* Garage::getMostEfficientCar() {
    Car* mostEfficent = efficientQueue.top();
    return mostEfficent;
}

//Gets a list of the top <N> fastest cars in garage where N is an inputted number by user
const vector<Car*> Garage::getNFastestCars(const int N) {
    // if garage is smaller than query, use entire garage and let user know
    int numToFetch = N;
    if (N > count){
        std::cout << "garage has insufficient cars for that task, using all cars";
        numToFetch = count;
    }
    
    
    vector<Car*> candidates;
    
    // get top N fastest cars
    for (int i = 0; i < numToFetch; i++) {
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
//Prints out all cars in the garage
void Garage::listCars() {
    if (count == 0) {
        std::cout << "No cars currently in garage\n";
    }
    for (auto car: cars) {
        std::cout << *car;
    }
    
}
//Gets the average speed of all cars in garage
const double Garage::getAvgSpeed() {
    double avgSpeed = 0;
    
    for (auto car: cars) {
        avgSpeed += car->getSpeed();
    }
    avgSpeed /= count;
    
    return avgSpeed;
}

//Gets the average MPG of all cars in garage
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

//Constructor that takes in a number of racers
Racetrack::Racetrack(const int& numRacersIn, const int& raceLengthIn) {
    numRacers = numRacersIn;
    raceLength = raceLengthIn;
    
}

//Destructor that handles dynamic memory
//TODO: remove when smart pointers
Racetrack::~Racetrack() {
   for (RaceCar* racer: racers){
        delete racer;
    }
}


//Adds a vector of cars to be used as Racers in the track
//TODO: switch pointers to be smart pointers
void Racetrack::addRacers(vector <Car*> &racers_in) {
    
    int numRacersTemp = (int)racers_in.size();
    
    //for each new entry, assign it a racing profile and add it to the racers
    for (int i = 0; i < numRacersTemp; i++){
        
        Car* car_entry = racers_in[i];
        char symbol = symbols[i % (int)symbols.length()];
        RaceCar* racer = new RaceCar(car_entry, i, symbol);
        
        this->racers.push_back(racer);
    }

    //update number of racers
    numRacers = (int)racers.size();

    return;
}
// todo: make sure cars can have a tie
void Racetrack::raceCars() {
    // timeout to avoid infinite loop
    int timeOut = 10000;
    RaceCar* winningRacer = racers[1];
    
    bool ended = false;
    
    while (!ended) {
        
        //Print out the progress of the race with every iteration
        printTrack();
        std::cout << '\n';
        std::cout << '\n';
        
        for (RaceCar* racer:racers){
            racer->move();
            timeOut--;
            
            if (racer->getRoundedXCoor() > raceLength){
                ended = true;
                winningRacer = racer;
            }
        }
        
        //Condition that ends the race unconditionally after timeout ends
        if (timeOut <= 0){
            ended = true;
            std::cout << "TIMEOUT ERROR" << std::endl;
        }
    }
     
    winner = winningRacer->getCar();
    
    //  If verbose, print out the winning car
    if (1){
        std::cout << "The winning car is the " << *winner << '\n';
    }
    
    return;
}


void Racetrack::printTrack() {
    
    int fieldHeight = numRacers + 2;
    int fieldWidth = raceLength;
    std::cout << " ";
    
    for (int lon = 0; lon < fieldWidth; lon++) {
        std::cout << (lon % 10);
    }
    std::cout << "\n";
    for (int lat = 0; lat < fieldHeight; lat++) {
        std::cout << ( lat % 10);
        
        for (int lon = 0; lon < fieldWidth; lon++) {
            
            //For every spot on the grid, print out a character for the racer or just a dash instead
             char charToPrint = '-';
             for (RaceCar* player:racers){
                 
                 if (player->getRoundedXCoor() == lon && player->getRoundedYCoor() == lat){
                     charToPrint = player->getSymbol();
                 }
             }//for
             
            std::cout << charToPrint;
            
        }//for
        std:: cout << "\n";
    }//for
};

Car* Racetrack::getWinner() {
    return winner;
}
