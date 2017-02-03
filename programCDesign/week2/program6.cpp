/**
 * author: lerry xiao
 * datetime: 2016-11-27
 *
 * C语言进阶
 * 编程作业: 综合编程练习（1）
 * 编程题＃6：流感传染
 * 注意： 总时间限制: 1000ms 内存限制: 65536kB
 * 描述
 *
 * 有一批易感人群住在网格状的宿舍区内，宿舍区为n*n的矩阵，每个格点为一个房间，房间里可能住人，也可能空着。在第一天，有些房间里的人得了流感，以后每天，得流感的人会使其邻居传染上流感，（已经得病的不变），空房间不会传染。请输出第m天得流感的人数。
 *
 * 输入
 *
 * 第一行一个数字n，n不超过100，表示有n*n的宿舍房间。
 *
 * 接下来的n行，每行n个字符，’.’表示第一天该房间住着健康的人，’#’表示该房间空着，’@’表示第一天该房间住着得流感的人。
 *
 * 接下来的一行是一个整数m，m不超过100.
 *
 * 输出
 *
 * 输出第m天，得流感的人数
 * 样例输入
 *   5
...#.
.#.@.
.#@..
#....
.....
 *   4
 *
 * 样例输出
 * 1 16
 *
 * test case 1
 * first day
 7
.......
.#@..@#
...@...
#......
.......
.@.#.#.
.....@.
2
| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
| 1 | . | . | @ | . | . | @ | . |
| 2 | . | # | @ | @ | @ | @ | # |
| 3 | . | . | @ | @ | @ | @ | . |
| 4 | # | . | . | @ | . | . | . |
| 5 | . | @ | . | . | . | . | . |
| 6 | @ | @ | @ | # | . | # | . |
| 7 | . | @ | . | . | @ | @ | @ |
 */

#include <iostream>
#include <stdio.h>
using namespace std;

int n;
int d[100][100] = {0};
// 设置第 day+1 天的病人，并返回当天被传染的病人数量
int setPatient(int day);

int main()
{
    int total = 0;
    int m = 0;
    char c;
    int maxCount = 0; // 最多可以有多少病人

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> c;
            switch (c) {
            case '.': {
                d[i][j] = 0; // 可以被传染
                maxCount++;
                break;
            }
            case '#':
                d[i][j] = -1;
                break;
            case '@': // 第一天感冒的人
                d[i][j] = 1;
                total++;
                maxCount++;
                break;
            }
        }
    }
    cin >> m;

    // 计算病人
    for(int i = 1; i < m; i++)
    {
        total = total + setPatient(i);
        //total 与最大可患病的人数相同了就不再循环了
        if (total == maxCount)
        {
            break;
        }
    }

    cout << total << endl;
    return 0;
}


int setPatient( int day )
{
    int count = 0;//第 day+1 天被传染的病人的数量

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(d[i][j] == day)
            {

                if( j-1 >= 0 && d[i][j-1] == 0 ) // left
                {
                    d[i][j-1] = day+1;
                    count++;
                }

                if( i - 1 >= 0 && d[i-1][j] == 0 ) // above
                {
                    d[i-1][j] = day +1;
                    count++;
                }

                if( j+1 < n && d[i][j+1] == 0 ) // right
                {
                    d[i][j+1] = day + 1;
                    count++;
                }

                if( i+1 < n && d[i+1][j] == 0 ) // below
                {
                    d[i+1][j] = day + 1;
                    count++;
                }
            }
        }
    }
    return count;
}