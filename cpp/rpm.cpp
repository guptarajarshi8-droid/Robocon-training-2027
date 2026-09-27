#include <iostream>
using namespace std;
int main() {
    int n;
    cout<<"Enter number of trial:";
    cin >> n;
    int rpm[n];

    for(int i=0;i<n;i++)
    {
        cout << "Enter marks of trial "<<(i+1)<<":";
        cin >> rpm[i];
        
    }    
    return 0;
}