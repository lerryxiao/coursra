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
...#
.#.@.
.#@..
#....
.....
 *   4
 * 样例输出
 * 1 16
 */
#include <iostream>
using namespace std;


bool checkThisDay(int newD[100][2], int i, int j, int n);
int setPatient(char d[100][100],int n);

int main()
{
    int n = 0;
    char d[100][100] = {'.'};
    int m = 0;
    int count = 0;
    int maxCount = 0;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> d[i][j];
            if(d[i][j] != '#')
            {
                maxCount++;
            }
            if (d[i][j] == '@')
            {
                count++;
            }
        }
    }
    cin >> m;
    // 计算病人
    for(int i = 1; i < m; i++)
    {
        count = setPatient(d, n);
        if (count == maxCount)
        {
            break;
        }
    }

    cout << count << endl;
    return 0;
}

bool checkThisDay(int newD[100][2], int i, int j, int n)
{
    for(int k=0; k < n; k++)
    {
        if (newD[k][0] == i && newD[k][1] == j)
        {
            return true;
        }
    }
    return false;
}

int setPatient(char d[100][100], int n)
{
    int newD[100][2] = {0};
    int count = 0;//病人的数量
    int newCount = 0;// 当前病人后面传染的病人的数量
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(d[i][j] == '@' && !checkThisDay(newD, i, j, newCount))// 房间住着病人，且不是今天新增的
            {
                count++;

                if(i > 0)
                {
                    if(d[i-1][j] == '.')//传染上方的人
                    {
                        d[i-1][j] = '@';
                        count++;
                    }
                }

                if(j > 0)
                {
                    if(d[i][j-1] == '.')// 传染左测的人
                    {
                        d[i][j-1] = '@';
                        count++;
                    }
                }

                if((i+1) < n)
                {
                    if(d[(i+1)][j] == '.') // 传染下方的人
                    {
                        d[(i+1)][j] = '@';
                        newD[newCount][0] = i + 1;
                        newD[newCount][1] = j;
                        newCount++;
                        count++;
                    }
                }

                if((j+1) < n)
                {
                    if(d[i][(j+1)] == '.') // 传染右测的人
                    {
                        d[i][(j+1)] = '@';
                        newD[newCount][0] = i;
                        newD[newCount][1] = j + 1;
                        newCount++;
                        count++;
                    }
                }
            }
        }
    }
    return count;
}