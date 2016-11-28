#include <iostream>
using namespace std;


int main()
{
    float pi = 3.14159;
    int h = 0, r = 0;

    cin >> h >> r;
    float all  = pi * r * r * h / 1000;
    int count = 20 / all + 1  ;
    cout << count << endl;
    return 1;
}