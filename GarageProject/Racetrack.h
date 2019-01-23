//
//  Racetrack.h
//  GarageProject
//
//  Created by Robert Cecil on 1/23/19.
//  Copyright © 2019 Robert Cecil. All rights reserved.
//

#ifndef Racetrack_h
#define Racetrack_h


#endif /* Racetrack_h */

#include "Car.h"

class Racetrack {
    int numCars;
    Car winner;
    
public:
    Racetrack() {
        numCars = 2;
        winner = Car();
    }
    
};
