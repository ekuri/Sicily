#include <iostream>
#include <stdio.h>

#define PI 3.1415927
#define INCHES_PER_FOOT 12
#define FEET_PER_MILE 5280
#define SECONDS_PER_MINUTE 60
#define MINUTES_PER_HOUR 60

using namespace std;

int main()
{
    int testCaseCount = 0;
    while (true) {
        testCaseCount++;

        float diameter;
        int revolution;
        float timeInSeconds;

        cin >> diameter >> revolution >> timeInSeconds;

        if (revolution <= 0 || timeInSeconds <= 0) {
            break;
        }

        float perimeterOfWheel = diameter * PI;
        float distanceInMiles = perimeterOfWheel * revolution / INCHES_PER_FOOT / FEET_PER_MILE;
        float timeInHours = timeInSeconds / SECONDS_PER_MINUTE / MINUTES_PER_HOUR;
        float speed = distanceInMiles / timeInHours;

        printf("Trip #%d: %.2f %.2f\n", testCaseCount, distanceInMiles, speed);
    }
    return 0;
}

