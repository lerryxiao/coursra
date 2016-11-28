binclude <iostream>
#include <iomanip>
using namespace std;

int main()
{

    int rect[5][5];
    int n, m;
    int temp;
    for(int i = 0; i < 5; i++)
    {
        for ( int j = 0; j < 5; j++)
        {
            cin >> rect[i][j];
        }
    }
    cin >> n >> m;
    if ( n < 0 || n >=5 || m < 0 || m >= 5)
    {
        cout << "error" << endl;
        return 0;
    }

    for ( int i = 0; i < 5; i++)
    {
        temp = rect[n][i];
        rect[n][i] = rect[m][i];
        rect[m][i] = temp;
    }

    for (int i = 0; i < 5; i++)
    {
        for ( int j = 0; j < 5; j++)
        {
            cout << setw(4) << rect[i][j];
        }
        cout << endl;
    }
    return 0;
}
