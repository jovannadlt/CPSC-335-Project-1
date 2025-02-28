#ifndef BESTSTARTINGCITY_H
#define BESTSTARTINGCITY_H

#include <iostream>
#include <vector>
#include <stdexcept>

// Takes in city_distances, fuel, and mpg and returns the index of 
// the city that allows you to complete a full circle, visting every 
// city and ending up back at the start.

int bestStartingCity(const std::vector<int> &city_distances, const std::vector<int> &fuel, int mpg);

#endif