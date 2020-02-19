//
//  main.cpp
//  robot_localisation
//
//  Created by Artem Makarov on 18/02/2020.
//  Copyright © 2020 Artem Makarov. All rights reserved.
//

#include "sense.h"
#include "move.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;


void print_probability(vector<double> p);

int main() {
    // Declare & define all vectors and probability variables
    vector<double> p (5, 0.2);
    vector<string> world;
    vector<string> measurements;
    vector<int> motions (2, 1);
    double pHit = 0.6;
    double pMiss = 0.2;
    double pExact = 0.8;
    double pOvershoot = 0.1;
    double pUndershoot = 0.1;
    
    // Fill in our world and measurements vectors
    world.push_back("green");
    world.push_back("red");
    world.push_back("red");
    world.push_back("green");
    world.push_back("green");
    
    measurements.push_back("red");
    measurements.push_back("green");
    
    // Iterate through our measurements
    for (int k = 0; k < measurements.size(); k++) {
        p = sense(p, measurements[k], world, pHit, pMiss);
        p = move(p, motions[k], pExact, pOvershoot, pUndershoot);
    }
    
    // Print out the probability vector
    print_probability(p);
    
    return 0;
}

void print_probability(vector<double> p) {
    // Iterates through the vector to print it out
    for (int i = 0; i < p.size(); i++) {
        cout << p[i] << " ";
    }
    cout << endl;
}

