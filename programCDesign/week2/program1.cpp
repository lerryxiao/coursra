#include <iostream>
using namespace std;

int main()
{
    int n;
    int data[100];
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> data[i];
    }

    for(int i = 0; i < n; i++){
        if (i == data[i])
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << "N" << endl;
    return 0;
}