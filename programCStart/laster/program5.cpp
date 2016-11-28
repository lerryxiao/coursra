#include <iostream>
using namespace std;

int main()
{
    char s1[14], s2[4];
    int maxIndex = 0;
    int lens1 = 0;
    int LENS2 = 3;

    while( cin >> s1 >> s2)
    {
        maxIndex = 0;
        lens1 = 0;
        while(s1[lens1] != '\0')
        {
            if(s1[lens1] > s1[maxIndex])
            {
                maxIndex = lens1;
            }
            lens1++;
        }

        for(int i = lens1 -1; i >  maxIndex; i--)
        {
            s1[i + LENS2 ] = s1[i];
        }

        s1[lens1 + LENS2] = '\0';

        for(int i = 0; i < LENS2; i++){
            s1[maxIndex + i + 1] = s2[i];
        }
        cout << s1 << endl;
    }
    return 0;
}
