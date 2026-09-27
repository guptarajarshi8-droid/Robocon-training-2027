// Q1. Write a C++ program for an autonomous line-following robot with 8 IR sensors arranged from left to right.

// Each sensor gives:
// 0 → White surface
// 1 → Black line

// Example sensor input:
// 0 0 1 1 1 0 0 0

// Requirements:
// 1. Store the 8 sensor readings in an array.
// 2. Take all 8 sensor readings as input from the user.
// 3. Calculate the position of the detected line using the sensor indices.
// 4. If the line is detected more toward the left, print "Turn Left".
// 5. If the line is detected more toward the right, print "Turn Right".
// 6. If the line is centered, print "Move Forward".
// 7. If no sensor detects the line, print "Line Lost".
// 8. Create separate functions for:
//    - Reading the sensor values
//    - Calculating the line position
//    - Deciding the robot's movement
// 9. Do not use a separate if-else condition for every possible sensor combination.

// Example:

// Input:
// 0 0 1 1 1 0 0 0

// Output:
// Line Position: Center
// Action: Move Forward
#include <iostream>
using namespace std;    

int sensorReadings[8];

void readSensorValues() 
{
    cout << "Enter the sensor readings (0 or 1) for all 8 sensors: ";
    for (int i = 0; i < 8; i++) 
    {
        cin >> sensorReadings[i];
    }
}

int calculateLinePosition()
 {
    int sum = 0;
    int count = 0;
    for (int i = 0; i < 8; i++) 
    {
        if (sensorReadings[i] == 1) 
        {
            sum =sum + i;
            count++;
        }
    }
    if (count == 0) {
        return -1; // lost the line
    }
    return (sum / count); // Return the average position
}

void decideMovement(int linePosition) 
{
    if (linePosition == -1)
     {
        cout << "Line Lost" << endl;
    } 
    else if (linePosition < 3)
     {
        cout << "Line position: Left" << endl;
        cout << "Action: Turn Left" << endl;
    } 
    else if (linePosition > 4) 
    {
        cout << "Line position: Right" << endl;
        cout << "Action: Turn Right" << endl;
    } 
    else 
    {
        cout << "Line position: Center" << endl;
        cout << "Action: Move Forward" << endl;
    }
}

int main() 
{
    readSensorValues();
    int linePosition = calculateLinePosition();
    decideMovement(linePosition);
    return 0;
}