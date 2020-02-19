//
//  move.h
//  robot_localisation
//
//  Created by Artem Makarov on 18/02/2020.
//  Copyright © 2020 Artem Makarov. All rights reserved.
//

#ifndef move_h
#define move_h

#include <vector>

std::vector<double> move(std::vector<double> p, int U, double pExact, double pOvershoot, double pUndershoot);

#endif /* move_h */

