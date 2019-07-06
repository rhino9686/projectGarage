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
#include <vector>
#include <sstream>
#include <iterator>
#include <set>

#define MANUFACTURERS_FILE "oems.json"
#define MANUFACTURERS_TEST "oemsSmall.json"


using std::string;
using std::vector;
using std::cout;
//Useful functions for input later

//Returns true if two strings are equal when not case sensitive
bool iequals(const string& a, const string& b) {
    return std::equal(a.begin(), a.end(),
                      b.begin(), b.end(),
                      [](char a, char b) {
                          return tolower(a) == tolower(b);
                      });
}

//Returns a lowercase version of a string
string lowerCase(const string& input) {
    string lowered = input;
    for (int i = 0; i < (int)input.size(); i++) {
        lowered[i] = tolower(input[i]);
    }
    return lowered;
}

//Takes out quote marks and commas from input string, returns new sanitized output string
string sanitize(const string& input) {
    
    std::set<char> mySet = {'"', ':', '[', ']', ','};
    
    string output;
    output.reserve(input.size()); // resize output string to match size of input so no reallocation
    for (size_t i = 0; i < input.size(); ++i)
        if (mySet.find(input[i]) == mySet.end()) {
            output += input[i];
        }
    
    return output;
}

//Returns a lowercase version of a character
char lowerCase(const char& input) {
    return tolower(input);
}

//Splits a giant string into its individual words
vector<string> splitString(string& inputString) {
    vector <string> stringArr;
    std::istringstream iss(inputString);
    
    for(string s; iss >> s; ) {
        stringArr.push_back(s);
    }
    
    return stringArr;
}

//Helper func
bool isKeyString(const string& input) {
    return (input[0] =='"' && input[input.size()- 1] == ':');
}


//Takes in a simple JSON file and makes a map of string (oem name) -> vector of strings (car models)
void readJSON(std::unordered_map<string, vector<string> >& myMap ) {
    
    //Set up a filestreawm
    string fileName = MANUFACTURERS_FILE;
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        cout << "can't open manufacturer file, try again later\n";
    }
    
    //give file string a character iterator for single char comparisons
    std::istreambuf_iterator<char> char_it(inputFile);
    std::istreambuf_iterator<char> eof;
    
    string nextStr;
    string key;
    char junk;
    
    //Get the opening Curly
    inputFile >> junk;
    
    // start parsing
    while (char_it != eof) {
        
        inputFile >> nextStr;
        
        if (isKeyString(nextStr)) {
            key = sanitize(nextStr);
            string dataBlock = "";
            
            while ((*char_it != ']' )) {
                dataBlock += *char_it;
                char_it++;
            }
            
            string sanitizedDataString = sanitize(dataBlock);
            vector<string> dataVec = splitString(sanitizedDataString);
            // put into Map
            if(!dataVec.empty()) {
                myMap[key] = dataVec;
            }
        }
    }
    //close file
    inputFile.close();
}




#endif /* ToolBox_h */
