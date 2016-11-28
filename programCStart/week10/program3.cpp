#include <iostream>
using namespace std;

int main()
{
    char s[501];
    cin.getline(s, 500);
    int maxLen = 0, tempLen = 0;
    int end = 0;
    int i = 0;
    while( s[i] != '\0' )
    {
        if (s[i] == ' ' || s[i] == '.')
        {
            if(maxLen < tempLen)
            {
                maxLen = tempLen;
                end = i;
            }
            tempLen = 0;
        }
        else
        {
            tempLen++;
        }
        i++;
    }
    for(i = end - maxLen; i < end; i++)
    {
        cout << s[i];
    }
    cout << endl;
}