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

using std::string;
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

#endif /* ToolBox_h */
