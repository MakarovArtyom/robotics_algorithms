//
//  move.cpp
//  robot_localisation
//
//  Created by Artem Makarov on 18/02/2020.
//  Copyright © 2020 Artem Makarov. All rights reserved.
//

#include "move.hpp"
#include <vector>
using namespace std;


vector<double> move(vector<double> p, int U, double pExact,
                    double pOvershoot, double pUndershoot) {
    /*
     * Updates probability based on movement.
     */
    
    vector<double> q (p.size());
    double s = 0; // holds probability values calculated below
    
    // Calculate new probabilities
    for (int i = 0; i < p.size(); i++) {
        // The modulo operator behaves a bit different in C++ with negatives
        // If we took it as -1 % p.size(), we'd get zero instead of four
        // -1 + p.size() will give us what we would get from -1 % p.size in Python
        if (i-U < 0) {
            s = pExact * p[(i-U) + p.size()];
        }
        else {
            s = pExact * p[(i-U) % p.size()];
        }
        if (i-U-1 < 0) {
            s = s + pOvershoot * p[(i-U-1) + p.size()];
        }
        else {
            s = s + pOvershoot * p[(i-U-1) % p.size()];
        }
        if (i-U+1 < 0) {
            s = s + pUndershoot * p[(i-U+1) + p.size()];
        }
        else {
            s = s + pUndershoot * p[(i-U+1) % p.size()];
        }
        
        q[i] = s;
    }
    
    return q;
}
