#include <iostream>
using namespace std;

int main()
{
    int n, m;
    int data[100] = {0};
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
    }

    for (int i = n-1; i >= n-m ; i--)
    {
        for(int j = n-1; j > 0; j--){
            int temp = data[j];
            data[j]=data[j-1];
            data[j-1]= temp;
        }
    }

    for (int i=0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    return 0;
}
