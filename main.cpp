#include <iomanip>
#include "bestStartingCity.h"

int main()
{

    // Example from the project prompt
    // Note: This algorithim will return the FIRST valid starting city it encounters.
    // It cannot account for multiple valid starting cities.
    std::vector<int> city_distances = {5, 25, 15, 10, 15};
    std::vector<int> fuel           = {1, 2, 1, 0, 3};
    int mpg = 10;

    bestStartingCity(city_distances, fuel, mpg);
    
    return 0;

}