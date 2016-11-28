#include <iostream>
using namespace std;

int main()
{
    int n;
    int data[15000];
    while(cin >> n){
        for(int i = 0; i < n; i++)
        {
            cin >> data[i];
        }
        if(n == 1)
        {
            cout << data[0] << endl;
        }
        else if(n == 2)
        {
            cout << (data[0] + data[1]) / 2 << endl;
        }
        else
        {
            for (int i = 0; i <= n /2; i++)
            {
                for (int j = 0;  j < n - i -1; j++)
                {
                    if(data[j+1] < data[j])
                    {
                        int temp = data[j + 1];
                        data[j+1] = data[j];
                        data[j] = temp;
                    }
                }
            }
            if (n % 2 == 0){
                cout << (data[n/2 - 1] + data[n/2])/2 << endl;
            }else{
                cout << data[n/2] << endl;
            }
        }
    }

    return 0;
}