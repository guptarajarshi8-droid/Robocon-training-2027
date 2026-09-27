// Create a C++ class called Robot to control a robot.

// The robot has the following properties:
// - Speed
// - Battery

// Requirements:
// 1. Make the data members private.
// 2. Create the following member functions:
//    - setSpeed()
//    - setBattery()
//    - moveForward()
//    - moveBackward()
//    - turnLeft()
//    - turnRight()
//    - displayStatus()
// 3. Speed should only accept values between 0 and 100.
// 4. Battery should only accept values between 0 and 100.
// 5. The robot should not move if the battery is 0%.
// 6. Each movement should reduce the battery by 5%.
// 7. Create a Robot object in main().
// 8. Take the speed and battery values as input from the user.
// 9. Execute a sequence of movement commands.
// 10. Display the final speed and battery level.

// Example:

// Input:
// Speed: 80
// Battery: 100

// Commands:
// Forward
// Left
// Forward
// Right

// Output:
// Robot Speed: 80
// Battery: 80%
#include <iostream>
using namespace std;

class Robot
{
private:
    int speed = 0;
    int battery = 0;

    void useBattery()
    {
        if (battery == 0) 
        { 
            cout << "Robot cannot move: battery is empty." << endl; 
            exit(0);
        }
        if (battery > 0)
        {
            battery = (battery >= 5) ? battery - 5 : 0;
        }
    }

public:
    void setSpeed(int s)
    {
        if (s >= 0 && s <= 100)
            speed = s;
        else
            cout << "Invalid speed. Please enter a value between 0 and 100" << endl;
    }

    void setBattery(int b)
    {
        if (b >= 0 && b <= 100)
            battery = b;
        else
            cout << "Invalid battery level. Please enter a value between 0 and 100" << endl;
    }

    void moveForward()
    {
        useBattery();
        cout << "Robot moved forward." << endl;
    }

    void moveBackward()
    {
        useBattery();
        cout << "Robot moved backward." << endl;
    }

    void turnLeft()
    {
        useBattery();
        cout << "Robot turned left." << endl;
    }

    void turnRight()
    {
        useBattery();
        cout << "Robot turned right." << endl;
    }
    void displayStatus()
    {
        cout << "Robot Speed: " << speed << endl;
        cout << "Battery: " << battery << "%" << endl;
    }

};
     
int main()
{
    Robot r;
    int speed, battery;
    char choice;

    cout << "Enter speed (0-100): ";
    cin >> speed;
    r.setSpeed(speed);

    cout << "Enter battery level (0-100): ";
    cin >> battery;
    r.setBattery(battery);

    cout << "Enter commands (F/B/L/R), or S to stop:" << endl;
    cin >> choice;
    while (choice != 'S' && choice != 's')
    {
        switch (choice)
        {
        case 'F': case 'f': r.moveForward(); break;
        case 'B': case 'b': r.moveBackward(); break;
        case 'L': case 'l': r.turnLeft(); break;
        case 'R': case 'r': r.turnRight(); break;
        default: cout << "Invalid choice!" << endl;
        }
        cin >> choice;
    }
    r.displayStatus();
    return 0;
}