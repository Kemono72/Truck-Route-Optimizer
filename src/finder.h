#ifndef FINDER_H
#define FINDER_H
#define MAX_NUMBER_OF_TRUCKS 3
#define MAX_WEIGHT_CAPACITY 2500	// maximum weight capacity of a truck in kilograms
#define MAX_VOLUME_CAPACITY 100		// maximum volume capacity of a truck in cubic meters
#include "mapping.h"


/**
 * The Shipment struct represents the details of a package to be delivered.
 *
 * - weight: The mass of the package in kilograms.
 * - size: The volume of the shipment in cubic meters.
 * - destination: The target location where the shipment is to be delivered.
 * - truck: A pointer to the Truck struct that will transport this shipment. It will be null if no truck is assigned.
 * - divertedRoute: An array of Point structs representing an alternate route for the shipment if a diversion is necessary. This will be null if there is no diversion.
 */

struct Shipment
{
	int weight;
	double size;
	struct Point destination;
	//struct Point* divertedRoute;
	struct Route divertedRoute;
};

/**
 * The Truck struct stores information about a delivery truck.
 *
 * - truckSymbol: A unique identifier for the truck (Y for Yellow, B for Blue, G for Green).
 * - currentWeight: The total weight of all shipments currently loaded on the truck, measured in kilograms.
 * - currentVolume: The total volume of all shipments currently loaded on the truck, measured in cubic meters.
 * - shipments: An array of Shipment structs representing the list of shipments that the truck is assigned to deliver.
 * - numberOfshipments: The total number of shipments that are currently loaded on the truck.
 */

struct Truck
{
	char truckSymbol;
	int actualWeight;
	double actualVolume;
	struct Shipment shipments[200];	// allocate some memory
	int numberOfshipments;
};

/**
* This function will validate a shipment weight before place to a truck
* weight - weight of the shipment in kg
* returns 1 if shipment is valid otherwise 0
*/
int isWeight(int weight);

/**
* This function will validate a shipment size before place to a truck
* size - size of the shipment in cubic meter
* returns 1 if shipment is valid otherwise 0
*/
int isSize(double size);

/**
* This function will validate a shipment before place to a truck
* returns 1 if shipment is valid otherwise 0
*/
int isValidShipment(int weight, double size);

/**
* This function will validate if destination is correct
*/

struct Point conversion(const char destName[]);

/**
* This function will convert a point to readable destination name
* pt - point
*/

char* convertDestination(const struct Point pt);

/**
* This function check if destination name is valid or not
*
* returns 1 if destination name is valid
*/

int isValidDestination(const char destinationName[]);

/**
* This function is to verify if the truck reach destination.
* Reached at destination will be consider when the truck is just
* beside the building.
* returns 1 if true, otherwise 0
**/

int destinationFinished(const struct Point p1, const struct Point p2);

/**
* This function will returns an array of correspondence truck index with value 1
*
* trucks[] - list of trucks that will be checked if has capacity
* numberOfTrucks - size of the trucks array
* pkg - shipment info of type Package that requires to ship
*
* returns an int array of correspondence truck index with value 1 if has capacity, 0 otherwise
*/

int* getCapacity(struct Truck trucks[], int numTruck, struct Shipment pkg);

/**
* This function calculate distance from a route to destination
*
* routeToFollow - The route to from where the distance will be calcualted
* dest - destination Point
*
* returns eucladian distance
*/
double getDistanceToDestination(struct Route* routeToFollow, struct Point dest);

/***
* Return a route(BLUE, GREEN, YELLOW) based on symbol
*/
struct Route* getRoute(char symbol);

/**
* Find which truck has better capacity
*
* return 1 if truck2 has better capacity
*/
int findBetterCapacityTruck(const struct Truck* truck1, const struct Truck* truck2);


/**
* Return the route the truck will follow to deliver the package
*/
struct Route handleDiversion(struct Route* markedRoute, struct Point dest);

/**
* Return the delivery truck that will deliver the package, Also
* update the capacity of the truck
*/
struct Truck* findBestTruckShipment(struct Truck* trucks, const int weight, const double size, const char destinationName[]);


/**
* Helper function to convert a character to correspondent index
*/
int convertChar(char c);

/**
* Function to validate the input of the weight size and destination
* Return : None
*/

void validInput(const int weight, const double size, const char destinationName[], struct Truck* trucks);
#endif