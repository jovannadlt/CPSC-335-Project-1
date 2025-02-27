#include "bestStartingCity.h"

int bestStartingCity(const std::vector<int> &city_distances, const std::vector<int> &fuel, int mpg)
{

    int n = city_distances.size(); // Get the total number of cities
    int totalSurplus = 0;          // Tracks net for all cities
    int currentSurplus = 0;        // Tracks net since last reset
    int startCity = 0;             // initialize the starting city as city 0

    for (int i = 0; i < n; i++)
    {
        // Net = fuel gained at city i minus distance to next city
        int net = fuel[i] * mpg - city_distances[i];

        // Edge-case handling: 
        // Tells you if the journey is even possible. 
        // If surplus is negative, then no mater where you start, you'll run out of fuel before reaching the original city.
        
        totalSurplus += net;

        // This keeps track of the surplus fuel for the current candidate starting city.
        currentSurplus += net;

        // If surplus goes negative, none of the cities in [startCity..i] can be valid
        if (currentSurplus < 0)
        {
            startCity = i + 1;  // Move start candidate to the next city
            currentSurplus = 0; // Reset
        }
    }

    // If total is nonnegative, startCity is the unique valid index; otherwise, no solution
    if (totalSurplus >= 0)
    {
        return startCity;
    }
    else
    {
        std::cout << "No valid starting city.";
        return 0;
    }
}
