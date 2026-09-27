#include <iostream>
using namespace std;

void moveforward()
{
    cout << "Bot is moving forward" << endl;
}
void movebackward()
{
    cout << "Bot is moving backward" << endl;
}
void moveleft()
{
    cout << "Bot is moving left" << endl;
}
void moveright()
{
    cout << "Bot is moving right" << endl;
}
    
int main()
{
    char choice;
    cout << "Enter your choice: " << endl;
    cout << "F. Move Forward" << endl;
    cout << "B. Move Backward" << endl;
    cout << "L. Move Left" << endl;
    cout << "R. Move Right" << endl;
    cout << "S. to terminate the program" << endl;
    cin >> choice;

    switch (choice)
    {
        case 'F':
            moveforward();
            main();
            break;
        case 'B':
            movebackward();
            main(); 
            break;
        case 'L':
            moveleft();
            main(); 
            break;
        case 'R':
            moveright();
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