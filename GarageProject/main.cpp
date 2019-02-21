//
//  main.cpp
//  GarageProject
//
//  Created by Robert Cecil on 1/22/19.
//  Copyright © 2019 Robert Cecil. All rights reserved.
//

/*
    Welcome to Garage! An application where we hold cars and race them to see which one is the fastest.
 */

//#include <iostream>
#include <fstream>
#include <queue>
#include "Car.h"
//#include "ToolBox.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;

void printOptions() {
    cout <<"You can: \n  Add a new car to your garage with 'add'!\n";
    cout <<"You can: \n  Add a bunch with 'addFile!'\n";
    cout <<"  List all your current cars with 'list!\n";
    cout <<"  Clear your garage with 'clear' !\n";
    cout <<"  Request for information about your cars with 'data'";
    cout <<"  Or make your cars race with 'race'!\n";
    cout <<"  Exit the application with 'quit'!\n";
    cout <<"  Type 'v' to toggle verbosity on or off!\n";
    cout <<"  Type 'help' at any time to repeat this message\n";

}

void addCar(Garage &gar, const bool v);
void addCarsByFile(Garage &gar, const bool v);
void raceCars(Garage &gar, const bool v);
void clearCars(Garage &gar, const bool v);
void listCars(Garage &gar, const bool v);
void getData(Garage &gar, const bool v);


int main(int argc, const char * argv[]) {
    //This is entry point, no command flags right now
    //Just starting with a user prompt
    
    string input;
    bool ended = false;
    bool verbose = true;
    bool& v = verbose;
    Garage garage = Garage();
    cout <<"Hello!\n";
    cout <<"Welcome to your garage!\n";
    cout <<"what do you want to do first?\n";
    printOptions();
    
    // quasi-infinite loop to prompt for user input
    do {
        cout << "What's next?:\n";
        cin >> input;
        char inputFirstLetter = input[0];
        
        switch (inputFirstLetter)
        {
            case 'a': // code to be executed if input suggests an add;
                if (input == "add") {
                    addCar(garage,v);
                }
                break;
            case 'h': // code to be executed if input suggests a help;
                 printOptions();
                break;
            case 'q': // code to be executed if input suggests a quit;
                if (input == "quit") {
                    ended = true;
                }
                break;
            case 'c': // code to be executed if input suggests a clear;
                if (input == "clear") {
                    clearCars(garage, v);
                }
                break;
            case 'r': // code to be executed if user wants to race;
                if (input == "race") {
                    raceCars(garage, v);
                }
                break;
            default: // code to be executed if n doesn't match any cases
                cout << "Command not recognized\n";
                printOptions();
        }
        
        
        
    } while(!ended);
    
    cout <<"Goodbye!\n";
    
    return 0;
}

void addCar(Garage &gar, const bool v) {
    //Initializing constructor fields for later use
    
    char selectedType = 'e';
    carType type;
    int mpg;
    double speed;
    int year;
    string make;
    string model;
    
    
    cout << "What type of car?\n";
    cout << "   A. SUV \n B. Sedan \n C. Truck \n D. Crossover: \n E. Other: \n";
    cin >> selectedType;
    switch (selectedType) {
        case 'A':
            type = carType::SUV;
            break;
        case 'B':
            type = carType::SEDAN;
            break;
        case 'C':
            type = carType::TRUCK;
            break;
        case 'D':
            type = carType::CROSSOVER;
            break;
        default:
            type = carType::OTHER;
            break;
    }
    
    cout <<"What year, make, and model is your car? Enter year, then make, then model, with spaces in between";
    cin >> year >>  make >> model;
    cout << "What is the max speed?";
    cin >> speed;
    cout << "What is the average MPG?";
    cin >> mpg;
    cout << "Thanks! adding your car";
    
    //Construct car with these parameters
    Car* entry = new Car(make, model, type, mpg, year, speed);
    
    //Add car to garage
    gar.addCar(entry);
    
    //If verbose, print out the last car
    if (v) {
        cout << "added a new car!\n";
    }
    
    return;
}


//Read in multiple cars from one file
//TODO: set up example file and test, add final results to spec
void addCarsByFile(Garage &gar, const bool v) {
    string fileName;
    string line;
    cout <<"give your filename to input: \n";
    cin >> fileName;
    ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        cout << "can't open that file, try again later\n";
    }
    while (getline(inputFile,line) ) {
        cout << line << '\n';
    }
    inputFile.close();
    
    return;
}
//Empties out all data from the garage
void clearCars(Garage &gar, const bool v) {
    cout << "clearing out all cars!\n";
    
    return;
}

void raceCars(Garage &gar, const bool v) {
    cout<< "racing cars!";
    return;
}

void listCars(Garage &gar, const bool v) {
    return;
}
