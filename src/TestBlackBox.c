/*#include <stdio.h>
#include "finder.h"
#include "mapping.h"

void test_shipment_weight() {

    printf("\nTEST FUNCTION WEIGHT\n");
    // Test Case 1: Valid weight within range
    int weight = 1500;
    printf("Test1: Expected: 1, Actual: %d\n", isWeight(weight));

    // Test Case 2: Weight equal to zero (invalid)
    weight = 0;
    printf("Test2: Expected: 0, Actual: %d\n", isWeight(weight));

    // Test Case 3: Negative weight (invalid)
    weight = -500;
    printf("Test3: Expected: 0, Actual: %d\n", isWeight(weight));

    // Test Case 4: Weight above maximum limit (invalid)
    weight = 3000;
    printf("Test4: Expected: 0, Actual: %d\n", isWeight(weight));

    // Test Case 5: Weight equal to maximum limit (valid)
    weight = 2500;
    printf("Test5: Expected: 1, Actual: %d\n", isWeight(weight));
    
}


void test_isSize() {

    printf("\nTEST FUNCTION SIZE\n");
    // Test Case 1: Valid size (1)
    double size = 1;
    printf("Test1: Expected: 1, Actual: %d\n", isSize(size));

    // Test Case 2: Invalid size (0)
    size = 0;
    printf("Test2: Expected: 0, Actual: %d\n", isSize(size));

    // Test Case 3: Invalid size (4)
    size = 4;
    printf("Test3: Expected: 0, Actual: %d\n", isSize(size));

    // Test Case 4: Invalid size (-1)
    size = -1;
    printf("Test4: Expected: 0, Actual: %d\n", isSize(size));
}




void test_convertChar() {
    printf("\nTEST FUNCTION CONVERT CHAR\n");

    // Test Case 1: Valid character 'a'
    char c = 'a';
    printf("Test1: Expected: 0, Actual: %d\n", convertChar(c));

    // Test Case 2: Valid character 'A' (uppercase)
    c = 'A';
    printf("Test2: Expected: 0, Actual: %d\n", convertChar(c));

    // Test Case 3: Invalid character 'z'
    c = 'z';
    printf("Test3: Expected: -1, Actual: %d\n", convertChar(c));

    // Test Case 4: Invalid character '1'
    c = '1';
    printf("Test4: Expected: -1, Actual: %d\n", convertChar(c));

    // Test Case 5: Invalid character '@'
    c = '@';
    printf("Test5: Expected: -1, Actual: %d\n", convertChar(c));
}



void test_distance() {
    printf("\nTEST FUNCTION DISTANCE\n");

    // Test Case 1: Distance between (0, 0) and (3, 4)
    struct Point p1 = { 0, 0 };
    struct Point p2 = { 3, 4 };
    double result = distance(&p1, &p2);
    printf("Test1: Expected: 5.00, Actual: %.2f\n", result);

    // Test Case 2: Distance between (1, 1) and (4, 5)
    p1 = (struct Point){ 1, 1 };
    p2 = (struct Point){ 4, 5 };
    result = distance(&p1, &p2);
    printf("Test2: Expected: 5.00, Actual: %.2f\n", result);

    // Test Case 3: Distance between (-1, -1) and (-4, -5)
    p1 = (struct Point){ -1, -1 };
    p2 = (struct Point){ -4, -5 };
    result = distance(&p1, &p2);
    printf("Test3: Expected: 5.00, Actual: %.2f\n", result);

    // Test Case 4: Distance between (0, 0) and (0, 0)
    p1 = (struct Point){ 0, 0 };
    p2 = (struct Point){ 0, 0 };
    result = distance(&p1, &p2);
    printf("Test4: Expected: 0.00, Actual: %.2f\n", result);

    // Test Case 5: Distance between (3, 5) and (0, 0)
    p1 = (struct Point){ 3, 5 };
    p2 = (struct Point){ 0, 0 };
    result = distance(&p1, &p2);
    printf("Test5: Expected: 5.83, Actual: %.2f\n", result);
}




void test_findBetterCapacityTruck() {
    printf("\nTEST FUNCTION FIND BETTER CAPACITY TRUCK\n");

    // Test Case 1: Truck1 has better capacity
    struct Truck truck1 = { 2000.0, 1000.0 };
    struct Truck truck2 = { 3000.0, 2000.0 };
    int result = findBetterCapacityTruck(&truck1, &truck2);
    printf("Test1: Expected: 0, Actual: %d\n", result);

    // Test Case 2: Both trucks have the same capacity
    truck1 = (struct Truck){ 2000.0, 1000.0 };
    truck2 = (struct Truck){ 2000.0, 1000.0 };
    result = findBetterCapacityTruck(&truck1, &truck2);
    printf("Test2: Expected: 0, Actual: %d\n", result);

    // Test Case 3: One truck is empty and the other is full
    truck1 = (struct Truck){ 0.0, 0.0 };
    truck2 = (struct Truck){ MAX_WEIGHT_CAPACITY, MAX_VOLUME_CAPACITY };
    result = findBetterCapacityTruck(&truck1, &truck2);
    printf("Test3: Expected: 0, Actual: %d\n", result);
}




// Function prototypes
void test_shipment_weight();
void test_isSize();
void test_convertChar();
void test_distance();
void test_findBetterCapacityTruck();

int main() {
    // Run all test functions
    test_shipment_weight();
    test_isSize();
    test_convertChar();
    test_distance();
    test_findBetterCapacityTruck();
    return 0;
}*/
