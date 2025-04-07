#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mapping.h"
#include "finder.h"


int main(void)
{

    struct Map baseMap = populateMap();
    int weight;
    double size;
    char destination[4];
    char ch = 'x';

    //Initialization of  all the Truck
    struct Truck trucks[3] = { {BLUE, 0,0, NULL,0},{GREEN, 0,0, NULL,0}, {YELLOW, 0,0, NULL,0} };


    printf("=================\n");
    printf("Seneca Deliveries\n");
    printf("=================\n\n");

    while (1)
    {
        printf("Enter shipment weight, box size and destination (0 0 x to stop): ");
        int result = scanf("%d %lf %s", &weight, &size, &destination);
        int exit = weight == 0 && size == 0 && destination[0] == ch && destination[1] == '\0';

        if (result != 3)
        {
            printf("Invalid input\n");

            while (getchar() != '\n');
        }
        else if (exit)
        {
            break;
        }
        else
        {
            validInput(weight, size, destination, trucks);
        }
    }

    printf("Thanks for shipping with Seneca!");
    return 0;

}
