#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>               
#include <string.h>                         
#include "mapping.h"             
#include "finder.h"              
#include "math.h"                

struct Truck* findBestTruckShipment(struct Truck* trucks, const int weight, const double size, const char destination[]) {
    struct Truck* truck_choice = NULL;

    if (isValidShipment(weight, size) && isValidDestination(destination)) {
        struct Point dest = conversion(destination);  // Convert destination name to Point
        struct Shipment shipment = { weight, size, dest };  // Create shipment struct
        int* truckIndxs = getCapacity(trucks, MAX_NUMBER_OF_TRUCKS, shipment);  // Get valid trucks

        double shortestDistance = INFINITY;

        for (int i = 0; i < MAX_NUMBER_OF_TRUCKS; i++) {
            if (truckIndxs[i] == 1) {
                struct Route* truckRoute = getRoute(trucks[i].truckSymbol);  // Get route for the truck
                double distance = getDistanceToDestination(truckRoute, dest);  // Calculate distance to destination

                if (distance < shortestDistance ||
                    (distance == shortestDistance && findBetterCapacityTruck(truck_choice, &trucks[i]))) {
                    shortestDistance = distance;
                    truck_choice = &trucks[i];  // Select the truck with the shortest distance or better capacity
                }
            }
        }

        if (truck_choice != NULL) {
            struct Route* selectedRoute = getRoute(truck_choice->truckSymbol);  // Get route for the selected truck
            double initialDistance = getDistanceToDestination(selectedRoute, dest);

            if (initialDistance > 1) {
                shipment.divertedRoute = handleDiversion(selectedRoute, dest);  // Handle diversion if needed
                if (shipment.divertedRoute.numPoints >= MAX_ROUTE) {
                    truck_choice = NULL;  // If diversion route is too long, reset the selected truck
                }
            }

            if (truck_choice != NULL) {
                truck_choice->actualWeight += shipment.weight;  // Update truck's weight
                truck_choice->actualVolume += shipment.size;  // Update truck's volume
                if (truck_choice->numberOfshipments < 200) {
                    truck_choice->shipments[truck_choice->numberOfshipments++] = shipment;  // Add shipment to the truck
                }
            }
        }
    }

    return truck_choice;
}

// Function to validate the user input for the shipment's weight, size, and destination name
void validInput(const int weight, const double size, const char destination[], struct Truck* trucks) {
    int validInput = 1;

    if (validInput && !isWeight(weight)) {
        validInput = 0;
        printf("Invalid weight (must be 1-2500 Kg.)\n");
    }

    if (validInput && !isSize(size)) {
        validInput = 0;
        printf("Invalid size\n");
    }

    if (validInput && !isValidDestination(destination)) {
        validInput = 0;
        printf("Invalid destination\n");
    }

    if (validInput) {
        struct Truck* deliveryTruck = findBestTruckShipment(trucks, weight, size, destination);

        if (deliveryTruck != NULL) {
            printf("Ship on ");
            switch (deliveryTruck->truckSymbol) {
            case BLUE:
                printf("BLUE LINE, ");
                break;
            case GREEN:
                printf("GREEN LINE, ");
                break;
            case YELLOW:
                printf("YELLOW LINE, ");
                break;
            }

            int shipmentIdx = deliveryTruck->numberOfshipments - 1;
            struct Shipment shipment = deliveryTruck->shipments[shipmentIdx];
            if (shipment.divertedRoute.numPoints == 0) {
                printf("no diversion\n");
            }
            else {
                printf("divert: ");

                for (int i = 0; i < shipment.divertedRoute.numPoints - 1; i++) {
                    char* destination = convertDestination(shipment.divertedRoute.points[i]);
                    printf("%d%c, ", destination[0], destination[1]);
                }
                printf("%s\n", destination);
            }
        }
        else {
            printf("No truck Available\n");
        }
    }
}

// Function to convert a string representation of a destination to a Point structure
struct Point conversion(const char arr[]) {
    struct Point dest = { -1, -1 };
    int value;
    char character;

    // Use sscanf to parse the input string
    if (sscanf(arr, "%d%c", &value, &character) == 2) {
        // Validate and assign the Point values
        if (value > 0 && value <= 25 && character >= 'A' && character <= 'Y') {
            dest.row = value - 1;               // Assign row value
            dest.col = character - 'A';         // Assign column value by converting character
        }
    }

    return dest;  // Return the converted Point
}


// Function to convert a Point structure to a string representation of the destination name
char* convertDestination(const struct Point pt) {
    static char destination[3] = { 0 };

    if (pt.row >= 0 && pt.row < 25 && pt.col >= 0 && pt.col < 25) {
        snprintf(destination, sizeof(destination), "%d%c", pt.row + 1, 'A' + pt.col);
    }

    return destination;
}

int isValidDestination(const char destination[]) 
{
    struct Point dest = conversion(destination);  // Convert the destination name to Point
    return dest.row >= 0 && dest.col >= 0;        
}

int convertChar(char c) 
{
    return (c >= 'A' && c <= 'Y') ? c - 'A' : -1;  // Use ternary operator to return index or -1
}

// Function to check which trucks can handle the shipment based on their current capacity
int* getCapacity(struct Truck trucks[], int numTruck, struct Shipment shipment) {
    static int idxs[3];                // Static array to store valid truck indices
    memset(idxs, 0, sizeof(idxs));     // Initialize array to 0

    for (int i = 0; i < numTruck; i++) {
        if (trucks[i].actualWeight + shipment.weight <= MAX_WEIGHT_CAPACITY &&
            trucks[i].actualVolume + shipment.size <= MAX_VOLUME_CAPACITY) {
            idxs[i] = 1;               // Mark truck as valid if it can handle the shipment
        }
    }
    return idxs;                       // Return the array of valid truck indices
}

// Function to calculate the distance from the route to the destination
double getDistanceToDestination(struct Route* route, struct Point dest) {
    int closestPointIdx = getClosestPoint(route, dest);  // Get the index of the closest point on the route
    return distance(&route->points[closestPointIdx], &dest);  // Calculate and return the distance to the destination
}

// Function to retrieve the route based on the truck symbol
struct Route* getRoute(char symbol)
{
    struct Route truckRoute;
    switch (symbol)
    {
    case BLUE:
        truckRoute = getBlueRoute();   
        break;
    case GREEN:
        truckRoute = getGreenRoute();  
        break;
    case YELLOW:
        truckRoute = getYellowRoute(); 
    }
    return &truckRoute;
}

int findBetterCapacityTruck(const struct Truck* truck1, const struct Truck* truck2) 
{
    double truck1WeightCapacity = (MAX_WEIGHT_CAPACITY - truck1->actualWeight) / MAX_WEIGHT_CAPACITY;
    double truck1VolumeCapacity = (MAX_VOLUME_CAPACITY - truck1->actualVolume) / MAX_VOLUME_CAPACITY;
    double truck1Capacity = (truck1WeightCapacity + truck1VolumeCapacity) * 50.0;

    double truck2WeightCapacity = (MAX_WEIGHT_CAPACITY - truck2->actualWeight) / MAX_WEIGHT_CAPACITY;
    double truck2VolumeCapacity = (MAX_VOLUME_CAPACITY - truck2->actualVolume) / MAX_VOLUME_CAPACITY;
    double truck2Capacity = (truck2WeightCapacity + truck2VolumeCapacity) * 50.0; for truck2

    return truck2Capacity > truck1Capacity;
}

// Function to handle the diversion of a truck to avoid obstacles, calculating a new route
struct Route handleDiversion(const struct Route* selectedRoute, struct Point dest) {
    struct Map map = populateMap();
    struct Map routeMap = addRoute(&map, selectedRoute);

    double shortestDistance = INFINITY;
    struct Route bestDiversion = { 0 };

    // Iterate over all points in the selected route
    for (int i = 0; i < selectedRoute->numPoints; i++) {
        struct Point currentPoint = selectedRoute->points[i];
        struct Route diversion = shortestPath(&routeMap, currentPoint, dest);  // Calculate the shortest path for diversion

        // Check if this diversion route is shorter than the current shortest distance
        double distanceToDestination = distance(&currentPoint, &dest);
        if (distanceToDestination < shortestDistance) {
            shortestDistance = distanceToDestination;
            bestDiversion = diversion;
        }
    }

    addPtToRoute(&bestDiversion, dest);  // Add the destination point to the best diversion route
    return bestDiversion;
}

// Function to check if the destination is reached
int destinationFinished(const struct Point p1, const struct Point p2) {
    double positionDistance = distance(&p1, &p2);  // Calculate the distance between points p1 and p2
    return positionDistance == 1;                  // Return 1 if the distance is 1, otherwise return 0
}

// Function to check if the weight is within the valid range
int isWeight(int weight) {
    return (weight > 0 && weight <= MAX_WEIGHT_CAPACITY);
}

// Function to check if the size is a valid value
int isSize(double size) {
    return (size == 3 || size == 5 || size == 1);
}

// Function to validate the weight and size of the shipment
int isValidShipment(int weight, double size) {
    return (isWeight(weight) && isSize(size));
}
