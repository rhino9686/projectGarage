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
#include "Help.h"
#include "ToolBox.h"
#include <unordered_map>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;

void printOptions() {
    cout <<"You can: \n  Add a new car to your garage with 'add'.\n";
    cout <<"  Add a bunch with 'addFile'.\n";
    cout <<"  List all your current cars with 'list'.\n";
    cout <<"  Clear your garage with 'clear' \n";
    cout <<"  Request for information about your cars with 'data'.\n";
    cout <<"  Or make your cars race with 'race'\n";
    cout <<"  Exit the application with 'quit'\n";
    cout <<"  Type 'v' to toggle verbosity on or off.\n";
    cout <<"  Type 'help' at any time to repeat this message.\n";

}
void toggleVerbosity(bool& verbose);
void addCar(Garage &gar, const bool &v);
void addCarsByFile(Garage &gar, const bool &v);
void raceCars(Garage &gar, const bool &v);
void clearCars(Garage &gar, const bool &v);
void listCars(Garage &gar, const bool &v);
void getData(Garage &gar, const bool &v);

static std::unordered_map< string, vector<string> > knownMakers;




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
        //cast to lowercase so input isn't case sensitive
        input = lowerCase(input);
        char inputFirstLetter = input[0];
        
        switch (inputFirstLetter)
        {
            case 'a': // code to be executed if input suggests an add;
                if (input == "add") {
                    addCar(garage, v);
                }
                else if (input == "addfile"){
                    addCarsByFile(garage, v);
                } else {
                    goto unrecognized;
                }
                break;
            case 'c': // code to be executed if input suggests a clear;
                if (input == "clear") {
                    clearCars(garage, v);
                } else {
                    goto unrecognized;
                }
                break;
            case 'd': // code to be executed if input suggests an data;
                if (input == "data") {
                    getData(garage, v);
                } else {
                    goto unrecognized;
                }
                break;
            case 'h': // code to be executed if input suggests a help;
                if (input == "help") {
                    printOptions();
                } else {
                    goto unrecognized;
                }
                break;
            case 'q': // code to be executed if input suggests a quit;
                if (input == "quit") {
                    ended = true;
                } else {
                    goto unrecognized;
                }
                break;

            case 'r': // code to be executed if user wants to race;
                if (input == "race") {
                    raceCars(garage, v);
                } else {
                    goto unrecognized;
                }
                break;
            case 'l': // code to be executed if user wants to race;
                if (input == "list") {
                    listCars(garage, v);
                } else {
                    goto unrecognized;
                }
                break;
                
            case 'v': // code to be executed if input is 'v';
                if (input == "v") {
                    toggleVerbosity(verbose);
                }
                else {
                    goto unrecognized;
                }
                break;
            default: // code to be executed if n doesn't match any cases
            unrecognized:
                cout << "Command not recognized\n";
                printf("Type 'help' to list available commands\n");
        }
        
        
        
    } while(!ended);
    
    cout << "Goodbye!\n";
    
    return 0;
}

void toggleVerbosity(bool &verbose) {
    if(!verbose) {
        cout << "output verbosity on\n";
    }
    else {
        cout << "output verbosity off\n";
    }
    verbose = !verbose;
}


void addCar(Garage &gar, const bool &v) {
    //Initializing constructor fields for later use
    
    char selectedType = 'e';
    carType type;
    int mpg;
    double speed;
    int year;
    string make;
    string model;
    
    do {
        cout << "What type of car?\n";
        cout << "   A. SUV \n B. Sedan \n C. Truck \n D. Crossover: \n E. Other: \n";
        cin >> selectedType;
        //cast character to lower case so that it's not case sensitive
        selectedType = tolower(selectedType);
        switch (selectedType) {
            case 'a':
                type = carType::SUV;
                break;
            case 'b':
                type = carType::SEDAN;
                break;
            case 'c':
                type = carType::TRUCK;
                break;
            case 'd':
                type = carType::CROSSOVER;
                break;
            default:
                type = carType::OTHER;
                break;
        }
    
        cout << "What year, make, and model is your car? Enter year, make, then model, with spaces in between: \n";
        cin >> year >> make >> model;
        cout << "What is the max speed?\n";
        cin >> speed;
        cout << "What is the average MPG?\n";
        cin >> mpg;
        cout << "Thanks! processing...\n";
    
        constructionError error = Car::checkError(make, model, type, mpg, year, speed);
        
        if (error == constructionError::none) {
            //Construct car with these parameters
            Car* entry = new Car(make, model, type, mpg, year, speed);
            //Add car to garage
            gar.addCar(entry);
            //If verbose, print out the last car
            if (v) {
                cout << "Added car succesfully!\n";
            }
            return;
        }
        else {
            //print out the correct error based on the returned error type
            std::vector<string> Errortypes = { "make", "model", "year", "speed", "mpg", "unkown" };
            int index = static_cast<int>(error);
            
            //clear the cin buffer if user typed in extra words or newlines
            char temp[20];
            cin.getline(temp, 20);
            if (cin.fail()) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            
            string tryAgain;
            
            cout << "ERROR: You inputted an invalid " << Errortypes[index] << " for this car. Try again? \n"
            " Y or N  \n";
           
            cin >> tryAgain;
            
            tryAgain = lowerCase(tryAgain);
            
            if (tryAgain == "n" || tryAgain == "no" ) {
                return;
            }

        }
    } while(true);
    
}


// Reads in multiple cars from one file
//TODO: set up example file and test, add final results to spec
void addCarsByFile(Garage &gar, const bool &v) {
    string fileName;
    string line;
    cout << "give your filename to input: \n";
    cin >> fileName;
    ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        cout << "can't open that file, try again later\n";
    }
    
    
    string typeStr;
    carType type;
    int year;
    string make;
    string model;
    int speed;
    int mpg;
    
    
    while (getline(inputFile,line) ) {
        vector<string> carData;
        // cout << line << '\n';
        
        carData = splitString(' ', line);
        for (auto car:carData)
            cout << car << " ";
        cout << endl;
        
        // extract info from split string
        typeStr = carData[0];
        type = Car::types[typeStr];
        
        year = std::stoi(carData[1]);
        make = carData[2];
        model = carData[3];
        speed = std::stoi(carData[4]);
        mpg = std::stoi(carData[5]);
        
        
        constructionError error = Car::checkError(make, model, type, mpg, year, speed);
        
        
    }
    
    
    
    
    inputFile.close();
    
    return;
}


//Empties out all data from the garage
void clearCars(Garage &gar, const bool &v) {
    int count = gar.getCount();
    if (count == 0) {
        cout << "already empty\n";
        return;
    }
    gar.clear();
    
    if (v) {
        cout << "cleared out " << count << " cars\n";
    } else {
        cout << "clearing out all cars!\n";
    }
    return;
}

//TODO: implement
void raceCars(Garage &gar, const bool &v) {
    cout << "racing cars!\n";
    Racetrack r = Racetrack(2);
    
    
    r.printTrack();
    
    return;
}

//lists all cars in the garage currently
void listCars(Garage &gar, const bool &v) {
    cout << "listing all cars:\n";
    
    if (v) {
        gar.listCars();
    }
    else {
        cout << "Total cars: " << gar.getCount() << " \n";
    }

    return;
}

//TODO: test garage functions in testGarage to make sure this will work properly
void getData(Garage &gar, const bool &v) {
    cout << "here's your data\n";
    
    auto latest = gar.getLatestCar();
    auto fastest = gar.getFastestCar();
    auto efficient = gar.getMostEfficientCar();
    
    cout << "Most recent car: \n" << *latest;
    cout << "Fastest car: \n" << *fastest;
    cout << "most efficient car: \n" << *efficient;
    
    return;
    
}

