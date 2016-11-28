#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float count[4][4] = {0.0,0.0};
    int user,c;
    char t;
    float m;

    for(int i = 0; i < 3; i++)
    {
        cin >> user >> c;// input user and count
        for(int j = 0; j < c; j++)
        {
            cin >> t;
            cin >> m;
            switch (t)
            {
            case 'A':
                count[user-1][0] = m + count[user-1][0];
                break;
            case 'B':
                count[user-1][1] = m + count[user-1][1];
                break;
            case 'C':
                count[user-1][2] = m + count[user-1][2];
                break;
            default:
                break;
            }
        }
    }

    // count user
    for(int i =0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            count[i][3] = count[i][3] + count[i][j];
        }
    }

    //count type
    for(int i =0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            count[3][i] = count[3][i] + count[j][i];
        }
    }

    cout << fixed << setprecision(2);
    //output user
    for(int i =0 ; i < 3; i++)
    {
        cout << ( i + 1 ) << " " << count[i][3] << endl;
    }

    //output type
    for(int i =0 ; i < 3; i++)
    {
        cout << char(('A' + i)) << " " <<  count[3][i] << endl;
    }

    return 0;
}