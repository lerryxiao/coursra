#include <iostream>
using namespace std;

int main()
{
    int l, m;

    int start[100], end[100];
    int count = 0;
    cin >> l >> m;
    for ( int i = 0; i < m; i++)
    {
        cin >> start[i] >> end[i];
    }

    for ( int i = 0; i < m; i++){
        for (int j = 1; j < m; j++)
        {
            if(start[j] < start[j-1])
            {
                int temp = start[j];
                start[j] = start[j-1];
                start[j-1]= temp;
            }
            if(end[j] < end[j-1]){
                int temp = end[j];
                end[j] = end[j-1];
                end[j-1] = temp;
            }
        }
    }

    for(int i = 0; i < m; i++)
    {
        if(i == 0){
            count = end[i] - start[i] + 1;
        }else{

            count += end[i] - start[i] + 1;
            if(start[i] < end[i-1]){
                count = count - (end[i-1]-start[i] + 1);
            }
        }
    }
    cout << l+1 - count << endl;
    return 0;
}