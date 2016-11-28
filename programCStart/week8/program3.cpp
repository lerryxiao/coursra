#include <iostream>
using namespace std;

int main()
{
    double n, k;
    double ok = false;
    double money = 0.0, house = 200;
    while(cin >> n >> k)
    {
        house = 200;
        ok = false;
        for( int i =1; i <= 20; i++)
        {
            money = n * i;
            if ( money >= house)
            {
                ok = true;
                cout << i  << endl;
                break;
            }
            house = k / 100 * house  + house;
        }
        if (!ok)
        {
            cout << "Impossible" << endl;
        }
    }
}