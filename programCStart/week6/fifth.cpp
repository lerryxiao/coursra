#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    cin >> n ;
    int result[3];
    int index = 0;
    while(n > 0)
    {
        result[index] = n % 10;
        index++;
        n = n/10;
    }
    for(int i = index-1; i >=0; i--)
    {
        cout << result[i] << endl;
    }
    return 1;
}