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


#include <iostream>
#include "Car.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

void printOptions() {
    
    cout <<"You can: \n  Add a new car to your garage!\n";
    cout <<"  List all your current cars with 'list!\n";
    cout <<"  Clear your garage with 'clear' !\n";
    cout <<"  Or make your cars race with 'race'!\n";
     cout <<"  Exit the application with 'quit'!\n";
    cout <<"  Type 'help' at any time to repeat this message\n";
    
    return;
}

void addCar();
void raceCars();
void clearCars();


int main(int argc, const char * argv[]) {
    //This is entry point, no command flags right now
    //Just starting with a user prompt
    
    string input;
    bool ended;
    Garage garage = Garage();
    
    
    cout <<"Hello!\n";
    cout <<"Welcome to your garage!\n";
    cout <<"what do you want to do first?\n";
    printOptions();
    
    ended = false;
    
    // quasi-infinite loop to prompt for user input
    do {
        cout << "What's next?:\n";
        cin >> input;
        char inputFirstLetter = input[0];
        
        switch (inputFirstLetter)
        {
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
                    clearCars();
                }
                break;
            case 'r': // code to be executed if user wants to race;
                if (input == "race") {
                    raceCars();
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

void addCar(Garage &gar) {
    //Initializing constructor fields for later use
    char selectedType = 'e';
    carType type;
    int mpg;
    double speed;
    int year;
    string make;
    string model;
    
    cout << "adding a new car!\n";
    if (0) {
        return;
    }
    
    cout << "What type of car?\n";
    cout << "   A. SUV \n B. Sedan \n C. Truck \n D. Crossover:";
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
    Car entry = Car(make, model, type, year, speed);
    //Add car to garage
    gar.addCar(entry);
    
    return;
}

void clearCars() {
    cout << "clearing out all cars!\n";
    
    return;
}

void raceCars() {
    cout<< "racing cars!";
    return;
}
