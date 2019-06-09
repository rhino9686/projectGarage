//
//  ToolBox.h
//  GarageProject
//
//  Created by Robert Cecil on 2/7/19.
//  Copyright © 2019 Robert Cecil. All rights reserved.
//

#ifndef ToolBox_h
#define ToolBox_h
#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include <unordered_map>

#define MANUFACTURERS_FILE "oems.json"
#define MANUFACTURERS_TEST "oemsSmall.json"


using std::string;
using std::vector;
//useful functions for input later

// Returns true if two strings are equal when not case sensitive
bool iequals(const string& a, const string& b) {
    return std::equal(a.begin(), a.end(),
                      b.begin(), b.end(),
                      [](char a, char b) {
                          return tolower(a) == tolower(b);
                      });
}

// Returns a lowercase version of a string
string lowerCase(const string& input) {
    string lowered = input;
    for (int i = 0; i < (int)input.size(); i++) {
        lowered[i] = tolower(input[i]);
    }
    return lowered;
}

//Returns a lowercase version of a character
char lowerCase(const char& input) {
    return tolower(input);
}

//Takes in a simple JSON file and makes a map of string (oem name) -> vector of strings (car models)
void readJSON(const string& inputFile, std::unordered_map<string, vector<string>>& myMap ) {
    string fileName = MANUFACTURERS_FILE;
    ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        cout << "can't open manufacturer file, try again later\n";
    }
    // start parsing
    
    
    
    //close file
    inputFile.close();
}


//Splits a giant string into its individual words
vector<string> splitString(string& inputString) {
    vector<string> stringArr;
    std::istringstream iss(inputString);
    
    for(string s; iss >> s; ) {
        stringArr.push_back(s);
    }
    
    return stringArr;
}


#endif /* ToolBox_h */
