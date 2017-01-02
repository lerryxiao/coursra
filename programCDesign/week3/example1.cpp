/**
 * 题目：放苹果
 * 把 M 个同样的苹果放在 N 个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？
 *
 * 注意：5, 1 ，1  和 1，5，1  是同一种分法
 *
 * 输入: 7 3
 *
 * 输出： 8
 */

#include <iostream>
using namespace std;

int count(int m, int n)
{
    if (m <= 1 || n <=0)
    {
        return 1;
    }

    if ( m < n)
    {
        return count(m, n);
    }
    else
    {
        return count(m, n -1 ) + count( m - n, n);
    }
}

int main()
{
    int apples, plates;
    cin >> apples >> plates;

    cout << count(apples, plates);

    return 0;
}