#include <iostream>
using namespace std;

int main()
{
    char s[100];
    cin.getline(s, 80);
    int count[5] = {0};
    int i = 0;
    while (s[i] != '\0')
    {
        switch (s[i])
        {
                case 'a':
                    count[0]++;
                    break;
                case 'e':
                    count[1]++;
                    break;
                case 'i':
                    count[2]++;
                    break;
                case 'o':
                    count[3]++;
                    break;
                case 'u':
                    count[4]++;
                    break;
        }
        i++;
    }
    for(i = 0; i < 5; i++){
       cout << count[i] << " ";
    }
    cout << "" << endl;
    return 0;
}
