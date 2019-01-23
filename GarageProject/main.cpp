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

void addCar() {
    cout << "adding a new car!\n";
    
    return;
}

void raceCars() {
    cout<< "racing cars!";
    return;
}
