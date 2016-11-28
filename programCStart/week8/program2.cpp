#include <iostream>
using namespace std;

int main()
{
    int count ;
    cin >> count;
    double OPEN = 27.0, CLOSE = 23.0;
    double WALK_S = 1.2, BIKE_S = 3.0;
    double walk_c = 0.0, bike_c = 0.0;

    double length[count];
    for ( int i = 0; i < count; i++) {
        cin >> length[i];
    }
    for ( int i = 0; i < count; i++){

        walk_c = length[i] / WALK_S;

        bike_c = OPEN + CLOSE + length[i] / BIKE_S;

        if ( walk_c < bike_c )
        {
            cout << "Walk" << endl;
        }
        else if ( bike_c < walk_c )
        {
            cout << "Bike" << endl;
        }
        else
        {
            cout << "All" << endl;
        }
    }
}