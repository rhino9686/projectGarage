//
//  ToolBox.h
//  GarageProject
//
//  Created by Robert Cecil on 2/7/19.
//  Copyright © 2019 Robert Cecil. All rights reserved.
//

#ifndef ToolBox_h
#define ToolBox_h


#endif /* ToolBox_h */

#include <iostream>
#include <fstream>
#include <algorithm>

using std::string;
//useful
bool iequals(const string& a, const string& b)
{
    return std::equal(a.begin(), a.end(),
                      b.begin(), b.end(),
                      [](char a, char b) {
                          return tolower(a) == tolower(b);
                      });
}
