#include <iostream>
using namespace std;

int main()
{
    int count = 0;
    int max = 0;
    int score = 0;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cin >> score;
        if (score > max)
        {
            max = score;
        }
    }
    cout << max << endl;
    return 1;
}