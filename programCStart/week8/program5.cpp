#include <iostream>
using namespace std;

int main()
{
    int n;
    int sum = 0, temp = 0;
    cin >> n;
    for(int i =10; i <= n; i++)
    {
        sum = 0;
        temp  = i;
        while(temp != 0)
        {
            sum += temp % 10;
            temp = temp / 10;
        }
        if ( i % sum == 0)
        {
            cout << i << endl;
        }
    }
    return 0;
}