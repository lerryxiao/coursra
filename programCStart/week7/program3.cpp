#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int input = 0;
    int data[n];

    for(int i =0; i < n ;i ++)
    {
        cin >> data[i];
    }
    int c =0;
    for(int i=0; i < n; i++)
    {
        c = 0;
        for(int j=0; j < n; j++)
        {
            if (data[j] > data[i] ){
                c++;
            }
        }
        if ((c+1) == k){
            cout << data[i] << endl;
            break;
        }
    }

}
