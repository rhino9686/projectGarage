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

using std::string;
using std::vector;
//useful functions for input later




bool iequals(const string& a, const string& b) {
    return std::equal(a.begin(), a.end(),
                      b.begin(), b.end(),
                      [](char a, char b) {
                          return tolower(a) == tolower(b);
                      });
}

string lowerCase(const string& input) {
    string lowered = input;
    for (int i = 0; i < (int)input.size(); i++) {
        lowered[i] = tolower(input[i]);
    }
    return lowered;
}

char lowerCase(const char& input) {
    return tolower(input);
}

void readJSON(const string& inputFile, std::unordered_map<string, vector<string>>& myMap ) {
    // TODO: implement parsing
}

vector<string> splitString(string& inputString) {
    vector<string> stringArr;
    std::istringstream iss(inputString);
    
    for(string s; iss >> s; ) {
        stringArr.push_back(s);
    }
    
    return stringArr;
}


#endif /* ToolBox_h */
