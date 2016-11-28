#include <iostream>
using namespace std;

int main()
{
    int n;
    int data[100][100];
    int count = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for ( int j = 0; j < n; j++)
        {
            cin >> data[i][j];
        }
    }

    for (int i =1; i < n - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            if(data[i-1][j] - data[i][j] >= 50)
            {
                count++;
            }
            else if(data[i][j-1] - data[i][j] >= 50)
            {
                count++;
            }
            else if (data[i][j+1] - data[i][j] >= 50)
            {
                count++;
            }
            else if (data[i+1][j] - data[i][j] >= 50)
            {
                count++;
            }
        }
        
}