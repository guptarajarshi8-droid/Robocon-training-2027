#include <iostream>
using namespace std;

class robot
{
    private:
    int speed;

    public:
    void setSpeed(int s)
    {
        if(s >= 0)
        {
            speed = s;
        }
        else
        {
            cout << "Invalid speed. Please enter a value greater than 0" << endl;
        }
    }
   int getSpeed()
   {
    return speed;
   }
};
   int main()
{
    robot r;
    char choice;
    int sp;
    cout << "Enter your choice: " << endl;
    cout << "F. Move Forward" << endl;
    cout << "B. Move Backward" << endl;
    cout << "L. Move Left" << endl;
    cout << "R. Move Right" << endl;
    cout << "S. to terminate the program" << endl;
    cin >> choice;

    cout <<"Enter speed";
    cin >> sp;
    r.setSpeed(sp);

    switch (choice)
    {
        case 'F':
            cout << "Bot is moving front with speed "<< sp << endl;
            main();
            break;
        case 'B':
            cout << "Bot is moving back with speed "<< sp << endl;
            main(); 
            break;
        case 'L':
            cout << "Bot is moving left with speed "<< sp << endl;
            main(); 
            break;
        case 'R':
            cout << "Bot is moving right with speed "<< sp << endl;
            main(); 
            break;
        case 'S':
            cout << "Program terminated." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
    return 0;
}