//
//  sense.cpp
//  robot_localisation
//
//  Created by Artem Makarov on 18/02/2020.
//  Copyright © 2020 Artem Makarov. All rights reserved.
//


#include "sense.h"

#include <iostream>
#include <vector>

std::vector<double> sense(std::vector<double> p, std::string Z, std::vector<std::string> world,
                     double pHit, double pMiss) {
    /*
     * Updates probability based on a sensor reading.
     */
    
    std::vector<double> q (p.size());
    bool hit;
    double s = 0; // sum of the q vector's elements
    
    // Calculate new probabilities
    for (int i = 0; i < p.size(); i++) {
        hit = (Z == world[i]);
        q[i] = p[i] * (hit * pHit + (1-hit) * pMiss);
        s += q[i];
    }
    
    // Divide probabilities by the total sum
    for (int i = 0; i < q.size(); i++) {
        q[i] = q[i] / s;
    }
    
    return q;
}


