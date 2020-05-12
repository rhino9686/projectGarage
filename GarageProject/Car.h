//
//  Car.h
//  GarageProject
//
//  Created by Robert Cecil on 1/22/19.
//  Copyright © 2019 Robert Cecil. All rights reserved.
//

#ifndef Car_h
#define Car_h


#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <unordered_map>

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
    Car();
    
    /*Constructor from input fields, user entered. TODO: make sure input upholds variant, but error. Sanitize at user input level to be forgiving */
    Car(const string &makeIn, const string &modelIn, const carType &typeIn,
        const int &mpgIn, const int &yearIn, const double &speedIn);
    //Copy Constructor
    Car(Car const &other);
    //Assignment operator. Main difference is that this doesn't create a unique ID.
    Car& operator=(const Car &other);
    
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
    
    static void clearCarVec(vector<Car*> carVec);
    
    static std::unordered_map<string, carType> types;
    static std::unordered_map<string, vector<string>> manufacturerData;
    
    //printing operator overload
    friend std::ostream& operator<<(std::ostream& os, const Car& car) {
        os << car.year << " " << car.make << " " << car.model <<  " with " << car.mpg << " MPG\n";
        
        return os;
    }
};


class RaceCar {
    
    int speed;
    Car* inputtedCar;
    
    double x_coor;
    double y_coor;
    char symbol;
    
 public:
    //Constructor
    RaceCar();
    RaceCar(Car* inputCar, int row, char symbol_in);
    int getRoundedXCoor();
    int getRoundedYCoor();
    
    void incrXCoor(double x_delta);
    void incrYCoor(double y_delta);
    void move();
    
    Car* getCar();
    const char getSymbol();

};


//Comparator classes for priority queues

class CarSpeedLess{
    
public:
    bool operator()(Car* car1, Car* car2);
};

class CarMPGLess{
    
public:
    bool operator()(Car* car1, Car* car2);
};


//Class to represent a garage, the main database to hold all cars
class Garage {
    int count;
    vector<Car*> cars;
    priority_queue<Car*, vector<Car*>, CarSpeedLess> fastestQueue;
    priority_queue<Car*, vector<Car*>, CarMPGLess> efficientQueue;
    
public:
    //Constructor
    Garage();
    
    //Destructor: I put the garage object in charge of memory for cars, so destructor deletes dynamic pointers
    ~Garage();
    
    
    //Adds a car to the garage, car will be a dynamic pointer for use in multiple data structures
    void addCar(Car* newCar);
    
    //Adds a list of cars to the garage, cars will be in a vector of dynamic pointers
    void addCars(vector <Car*> &newCars);
    
    //Prepares garage to take in large amount of cars from file
    void resize(const int &newEntries);
    
    //Deletes all cars from garage, takes care of dynamic memory
    void clear();
    
    //Get the number of cars in the garage
    const int& getCount();
    
    //Get the latest car added to garage
    Car* getLatestCar();
    
    //Get the fastest car in the garage
    Car* getFastestCar();
    
    //Gets the most efficient car in the garage
    Car* getMostEfficientCar();
    
    //Gets the top N fastest cars where N < number of cars
    const vector<Car*> getNFastestCars(const int N);
    
    //Lists all the cars in garage, by order that they were put in
    void listCars();
    
    //Get the average speed of all cars in garage
    const double getAvgSpeed();
    
    //Get the average MPG of all cars in garage
    const double getAvgMpg();
    
};


class Racetrack {
    int numRacers = 0;
    int raceLength = 0;
    vector<RaceCar*> racers;
    string symbols = "!@#$%^&*~=+";
    Car* winner = nullptr;
    
public:
    //Constructor
    Racetrack(const int& numRacersIn, const int& raceLengthIn);
    
    //Destructor
    ~Racetrack();
    
    //Add Cars from an external source
    void addRacers(vector <Car*> &racers_in);
    
    //Simulate a race to see who is the winner
    void raceCars();
    
    //Return the Winner of the race, nullptr if there hasn't been a race yet
    Car* getWinner();
    
    //Utility function to print the racetrack with each iteration of the
    void printTrack();
};

#endif /* Car_h */
