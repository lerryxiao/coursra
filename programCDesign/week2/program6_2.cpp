#include <iostream>
#include <stdio.h>
using namespace std;

int n;
char d[101][101] = {1};
// 设置第 day+1 天的病人，并返回当天被传染的病人数量
void setPatient(int day);

int main()
{
    int count = 0;
    int m = 0;
    char c;
    int maxCount = 0; // 最多可以有多少病人

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> d[i][j];
        }
    }
    cin >> m;

    // 计算病人
    for(int i = 1; i < m; i++)
    {
        setPatient(i);
        for(int r = 0; r < n; r++)
        {
            for(int cl = 0; cl < n; cl++)
            {
                if(d[r][cl] == '!')
                {
                    d[r][cl] = '@';
                }
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if( d[i][j] == '@'){
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}


void setPatient( int day )
{
    int count = 0;//第 day+1 天被传染的病人的数量

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if( d[i][j] == '@')
            {

                if( j-1 >= 0 && d[i][j-1] == '.' ) // left
                {
                    d[i][j-1] = '!';
                }

                if( i - 1 >= 0 && d[i-1][j] == '.' ) // above
                {
                    d[i-1][j] = '!';
                }

                if( j+1 < n && d[i][j+1] == '.' ) // right
                {
                    d[i][j+1] = '!';
                }

                if( i+1 < n && d[i+1][j] == '.' ) // below
                {
                    d[i+1][j] = '!';
                }
            }
        }
    }
}