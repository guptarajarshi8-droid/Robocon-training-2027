/*Assignment 1 — Sensor Data Analysis

A robot takes 10 distance readings using an ultrasonic sensor. Write a C++ program to analyze the readings.

Requirements:

Take 10 readings and store them in an array.
Find the maximum and minimum readings using if.
Calculate the average.
Count readings below 20 cm and above 100 cm.
Use loops to process the array.
Do not use built-in functions for maximum/minimum.
*/
#include <iostream>
using namespace std;

int main() 
{
    int SIZE = 10;
    double readings[SIZE];
    double sum = 0;
    int countBelow20 = 0;
    int countAbove100 = 0;

    // Take 10 readings
    cout << "Enter 10 distance readings (in cm): ";
    for (int i = 0; i < SIZE; i++) 
    {
        cin >> readings[i];
        sum += readings[i];
    }

    // Find maximum and minimum
    double maxReading = readings[0];
    double minReading = readings[0];
    for (int i = 1; i < SIZE; i++) {
        if (readings[i] > maxReading)
         {
            maxReading = readings[i];
        }
        if (readings[i] < minReading) 
        {
            minReading = readings[i];
        }
    }

    // Calculate average
    double average = sum / SIZE;

    // Count readings below 20 cm and above 100 cm
    for (int i = 0; i < SIZE; i++) {
        if (readings[i] < 20) 
        {
            countBelow20++;
        }
        if (readings[i] > 100)
         {
            countAbove100++;
        }
    }

    // Display results
    cout << "Maximum reading: " << maxReading << " cm" << endl;
    cout << "Minimum reading: " << minReading << " cm" << endl;
    cout << "Average reading: " << average << " cm" << endl;
    cout << "Readings below 20 cm: " << countBelow20 << endl;
    cout << "Readings above 100 cm: " << countAbove100 << endl;

    return 0;
}