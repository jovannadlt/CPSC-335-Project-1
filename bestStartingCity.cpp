#include "bestStartingCity.h"


// Note that this alogrithim uses an "implicit wrap-around"
// Since we are keeping track of the final total surplus, we know if the trip is possible at all.


int bestStartingCity(const std::vector<int> &city_distances, const std::vector<int> &fuel, int mpg)
{

    int n = city_distances.size(); // Get the total number of cities
    int totalSurplus = 0;          // Tracks net fuel for all cities
    int currentSurplus = 0;        // Tracks net fuel since last reset
    int startCity = 0;             // initialize the starting city as city 0

    // Start the journey
    for (int i = 0; i < n; i++)
    {
        // Net = fuel gained at city i minus distance to next city
        int net = fuel[i] * mpg - city_distances[i];

        // Edge-case handling:
        // Tells you if the journey is even possible.
        // If surplus is negative, then no mater where you start, you'll run out of fuel before reaching the original city.
        // This also eliminates the need to do a "wrap-around" by keeping track of all previous surplus fuel [i . . . n]

        totalSurplus += net;

        // This keeps track of the surplus fuel for the current candidate starting city.
        currentSurplus += net;

        // If surplus goes negative, this isn't a valid starting city, move on to the next and reset.
        if (currentSurplus < 0)
        {
            startCity = i + 1;  // Move start candidate to the next city
            currentSurplus = 0; // Reset
        }

        // Continue until you run out of fuel, or traverse all the cities. 
    }

    // If total is nonnegative, startCity is the unique valid index; otherwise, no solution
    if (totalSurplus >= 0)
    {
        std::cout << "The preferred starting city is city " << startCity << ".\n";

        return 0;
    } else {

        std::cout << "No valid starting city." << "\n";

        return 0;
    }
}
