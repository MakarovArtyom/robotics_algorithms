//
//  sense.h
//  robot_localisation
//
//  Created by Artem Makarov on 18/02/2020.
//  Copyright © 2020 Artem Makarov. All rights reserved.
//
// same as #pragma once
#ifndef sense_h
#define sense_h

#include <vector>
#include <string>

std::vector<double> sense(std::vector<double> p, std::string Z, std::vector<std::string> world, double pHit, double pMiss);
#endif /* sense_h */

