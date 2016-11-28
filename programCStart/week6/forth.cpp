#include <iostream>
using namespace std;

int main()
{
    int minEven = 0;//偶数
    int maxOdd = 0;//奇数
    int input = 0;
    int cha = 0;
    for ( int i = 0; i < 6; i++)
    {
        cin >> input;
        if (input % 2 == 0) // 偶数
        {
            if (minEven == 0)
            {
                minEven = input;
            }
            else
            {
                if(minEven > input)
                {
                    minEven = input;
                }
            }
        }
        else
        {
            if (maxOdd < input)
            {
                maxOdd = input;
            }
        }
    }
    if (minEven > maxOdd){
        cha = minEven - maxOdd;
    }else{
        cha = maxOdd - minEven;
    }
    cout << cha << endl;
    return 1;
}