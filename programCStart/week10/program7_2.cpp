#include <iostream>
using namespace std;

int main()
{
    int result = 0, max = 0;
    int n;
    int data[15000];
    int count = 0;
    while(cin >> n){
        ;
        for(int i = 0; i < n; i++)
        {
            cin >> data[i];
        }
        if (n == 1)
        {
            cout << result << endl;
        }
        else if (n == 2)
        {
            cout << (data[0] + data[1])/2 << endl;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                max = data[i];
                count = 0;
                for(int j =0; j < n; j++)
                {
                    if(j != i && data[j] >= max )
                    {
                        count++;
                    }
                }

                if(n%2 != 0 && count >= n/2)
                {
                    result = max;
                    break;
                }
                else if(n%2 == 0 )
                {
                    if (count == n/2 || count == n/2 -1)
                    {
                        result += max;
                    }
                }
            }
            if (n%2 == 0){
                result /= 2;
            }
            cout << result << endl;
        }
        result = 0;
    };

    return 0;
}