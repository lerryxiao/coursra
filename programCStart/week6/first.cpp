#include <iostream>
using namespace std;

int main()
{
    int n =0, x =0 , y =0;
    cin >> n >> x >> y;
    int hasEat = y / x;
    if (y % x != 0)
    {
        hasEat += 1;
    }
    int left = n - hasEat;
    if (left < 0 )
    {
        left = 0;
    }
    cout << left << endl;
    return 0;
}