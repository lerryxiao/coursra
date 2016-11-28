#include <iostream>
using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < n - 1; i++)
    {
        for ( int j = n -1; j > 0; j--)
        {
            if( arr[i] + arr[j] == k)
            {
                cout << "yes" << endl;
                return 0;
            }
        }
    }
    cout << "no" << endl;
    return 0;
}