//
//  testToolBox.cpp
//  GarageProject
//
//  Created by Robert Cecil on 6/15/19.
//  Copyright © 2019 Robert Cecil. All rights reserved.
//

#include <stdio.h>
#include "ToolBox.h"


int main() {
    
    std::unordered_map< string, vector<string> > knownMakers;
    
    readJSON(knownMakers);
    auto data = knownMakers["tesla"];
    
    for (auto datum: data){
        cout << datum << std::endl;
    }

}
