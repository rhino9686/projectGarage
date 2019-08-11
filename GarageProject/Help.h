//
//  Help.h
//  GarageProject
//
//  Created by Robert Cecil on 1/30/19.
//  Copyright © 2019 Robert Cecil. All rights reserved.
//

#ifndef Help_h
#define Help_h
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using std::string;
using std::cout;


void printHelpMessage() {
    string helpString =
     "Usage rules for the garage program: \n"
     
     "Commands: \n"
    " 'Add': adds a singular car to your garage \n"
    " 'Clear': clears all cars from the garage \n"
    " 'List': lists all cars currently in your garage\n"
    " 'data': displays useful information about the cars as a whole \n "
    " 'race': simulates a race of your cars and tell you the winner\n "
    " 'quit': exits the program \n "
     
    " VERBOSITY: \n "
    " 'v' will toggle verbosity of the program, which controls how much output\n "
     " you want when you enter other commands. \n "
     
    " MULTIPLE CAR INPUT: \n "
     "'Addfile' will allow you to submit a textfile with car data to input multiple cars at once. \n"
     " it should be a plaintext document, .txt or equivalent. \n"
    " file input format should be split into lines of parameters, with each line formatted as such: \n "
     "           [Car Make] [Model] [Type] [Year] [Speed] <end of line> \n"
    " all separated by spaces. Data should be valid, or the program will exit with an error. \n" ;
    
    cout << helpString << std::endl;
    return;
}

#endif /* Help_h */
