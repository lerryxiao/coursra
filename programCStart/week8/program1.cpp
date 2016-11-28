#include <iostream>
using namespace std;

int main()
{
    int sum = 0;
    int n, a;
    cin >> n;

    for ( int i = 0; i < 5; i++)
    {
        cin >> a;
        if ( a < n ){
            sum += a;
        }
    }
    cout << sum << endl;
    return 0;
}