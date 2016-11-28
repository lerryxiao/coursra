#include <iostream>
using namespace std;

int main()
{
    int a;
    int result[3];
    int count = 0;
    while(cin >> a)
    {
        if(a % 3 == 0)
        {
            result[count++] = 3;
        }
        if(a % 5 == 0)
        {
            result[count++] = 5;
        }
        if(a % 7 == 0)
        {
            result[count++] = 7;
        }

        switch (count) {
        case 0: {
            cout << 'n' << endl;
            break;
        }
        case 1:{
            cout << result[0] << endl;
            break;
        }
        case 2:{
            cout << result[0] << " " << result[1] << endl;
            break;
        }
        case 3:{
            cout << result[0] << " " << result[1] << " " << result[2] << endl;
            break;
        }
        }
        count = 0;
    }
}