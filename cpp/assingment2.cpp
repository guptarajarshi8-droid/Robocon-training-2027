/*Assignment 2 — Digit Frequency

Write a C++ program that takes a number and finds how many times each digit (0–9) appears.

Requirements:

Use an array of size 10 to store the digit counts.
Extract each digit and update its count.
Use a loop to check all digits.
Use if to print only the digits that appear.
Don't print digits with a count of 0.
Handle the input 0 separately.*/

#include <iostream>
using namespace std;
int main() 
{
    long long number;
    int digitCounts[10] = {0}; // Initialize all elements to 0

    cout << "Enter a number: ";
    cin >> number;

    // Handle the special case of 0
    if (number == 0)
     {
        digitCounts[0] =1 ;
    } 
    else 
       { 
        while (number > 0) 
        {
            int digit = number % 10;
            digitCounts[digit]++;
            number= number / 10;
        }
    }

    // Print the frequency of each digit that appears
    for (int i = 0; i < 10; i++) 
    {
       if (digitCounts[i] > 0) 
        {
            cout << "Digit " << i << " appears " << digitCounts[i] << " times." << endl;
        }
    }


    return 0;
}