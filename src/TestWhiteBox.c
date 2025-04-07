/*#include <stdio.h>
#include "finder.h"
#include "mapping.h"
*/


/***********************************************************************/
/*The purpose of this source code is to create whiteBox test cases to ensure that all the utilities of the implemented functions are working properly*/
/**********************************************************************/




// Test functions prototypes

/*void test_distance();
void test_shortestPath();
void test_getClosestPoint();
void test_getCapacity();


int main() {
    // Run all test functions
    test_shortestPath();
    test_getClosestPoint();
    test_getCapacity();
    return 0;
}

void test_distance() {
    printf("DISTANCE TEST\n");
    struct Point p1, p2;

    // Test Case 1
    p1 = (struct Point){ 0, 0 };
    p2 = (struct Point){ 1, 1 };
    printf("Test1: Expected: 1.414, Actual: %.3f\n", distance(&p1, &p2));

    // Test Case 2
    p1 = (struct Point){ 1, 1 };
    p2 = (struct Point){ 2, 2 };
    printf("Test2: Expected: 1.414, Actual: %.3f\n", distance(&p1, &p2));

    // Test Case 3
    p1 = (struct Point){ 2, 2 };
    p2 = (struct Point){ 3, 3 };
    printf("Test3: Expected: 1.414, Actual: %.3f\n", distance(&p1, &p2));

    // Test Case 4
    p1 = (struct Point){ 3, 3 };
    p2 = (struct Point){ 4, 4 };
    printf("Test4: Expected: 1.414, Actual: %.3f\n", distance(&p1, &p2));
}

void test_shortestPath() {
    printf("SHORTEST PATH TEST\n");
    struct Map map = { .squares = {{ '.', '.', '.' }, { '.', '.', '.' }, { '.', '.', '.' }, { '.', '.', '.' }} };
    struct Point start, dest;
    struct Route path;

    // Test Case 1
    start = (struct Point){ 0, 0 };
    dest = (struct Point){ 1, 1 };
    path = shortestPath(&map, start, dest);
    printf("Test1: Expected: Path found, Actual: %s\n", path.numPoints > 0 ? "Path found" : "No path");

    // Test Case 2
    start = (struct Point){ 1, 1 };
    dest = (struct Point){ 2, 2 };
    path = shortestPath(&map, start, dest);
    printf("Test2: Expected: Path found, Actual: %s\n", path.numPoints > 0 ? "Path found" : "No path");

    // Test Case 3
    start = (struct Point){ 2, 2 };
    dest = (struct Point){ 3, 3 };
    path = shortestPath(&map, start, dest);
    printf("Test3: Expected: Path found, Actual: %s\n", path.numPoints > 0 ? "Path found" : "No path");

    // Test Case 4
    start = (struct Point){ 3, 3 };
    dest = (struct Point){ 4, 4 };
    path = shortestPath(&map, start, dest);
    printf("Test4: Expected: Path found, Actual: %s\n", path.numPoints > 0 ? "Path found" : "No path");
}

void test_getClosestPoint() {
    printf("CLOSEST POINT TEST\n");
    struct Route route = { { {1, 1}, {2, 2}, {3, 3}, {4, 4} }, 4, 'R' };
    struct Point pt;

    // Test Case 1
    pt = (struct Point){ 1, 1 };
    printf("Test1: Expected: 0, Actual: %d\n", getClosestPoint(&route, pt));

    // Test Case 2
    pt = (struct Point){ 2, 2 };
    printf("Test2: Expected: 1, Actual: %d\n", getClosestPoint(&route, pt));

    // Test Case 3
    pt = (struct Point){ 3, 3 };
    printf("Test3: Expected: 2, Actual: %d\n", getClosestPoint(&route, pt));

    // Test Case 4
    pt = (struct Point){ 4, 4 };
    printf("Test4: Expected: 3, Actual: %d\n", getClosestPoint(&route, pt));
}




// Test function for getCapacity
void test_getCapacity() {
    printf("GET CAPACITY TEST\n");

    // Test Setup
    struct Truck trucks[3] = {
        {.actualWeight = 2000.0, .actualVolume = 20.0 },
        {.actualWeight = 1000.0, .actualVolume = 26.0 },
        {.actualWeight = 1500.0, .actualVolume = 10.0 }
    };
    struct Shipment shipment;
    int* result;

    // Test Case 1: 2 trucks can handle the shipment
    shipment = (struct Shipment){ .weight = 1000.0, .size = 5.0 };
    result = getCapacity(trucks, 3, shipment);
    printf("Test1: Expected: 0 1 1, Actual: %d %d %d\n", result[0], result[1], result[2]);

    // Test Case 2: No truck can handle the shipment (overweight)
    shipment = (struct Shipment){ .weight = 9000.0, .size = 5.0 };
    result = getCapacity(trucks, 3, shipment);
    printf("Test2: Expected: 0 0 0, Actual: %d %d %d\n", result[0], result[1], result[2]);

    // Test Case 3: No truck can handle the shipment (over volume)
    shipment = (struct Shipment){ .weight = 1000.0, .size = 36.0 };
    result = getCapacity(trucks, 3, shipment);
    printf("Test3: Expected: 0 0 0, Actual: %d %d %d\n", result[0], result[1], result[2]);

    // Test Case 4: Only one truck can handle the shipment
    shipment = (struct Shipment){ .weight = 1000.0, .size = 20.0 };
    result = getCapacity(trucks, 3, shipment);
    printf("Test4: Expected: 0 0 1, Actual: %d %d %d\n", result[0], result[1], result[2]);

    // Test Case 5: No trucks available
    result = getCapacity(trucks, 0, shipment);
    printf("Test5: Expected: 0 0 0, Actual: %d %d %d\n", result[0], result[1], result[2]);
}*/
