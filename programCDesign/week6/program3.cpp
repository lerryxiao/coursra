/**
   编程题＃3：寻找山顶

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述

在一个m×n的山地上，已知每个地块的平均高程，请求出所有山顶所在的地块（所谓山顶，就是其地块平均高程不比其上下左右相邻的四个地块每个地块的平均高程小的地方)。

输入

第一行是两个整数，表示山地的长m（5≤m≤20）和宽n（5≤n≤20）。

其后m行为一个m×n的整数矩阵，表示每个地块的平均高程。每行的整数间用一个空格分隔。

输出

输出所有上顶所在地块的位置。每行一个。按先m值从小到大，再n值从小到大的顺序输出。


样例输入

10 5
0 76 81 34 66
1 13 58 4 40
5 24 17 6 65
13 13 76 3 20
8 36 12 60 37
42 53 87 10 65
42 25 47 41 33
71 69 94 24 12
92 11 71 3 82
91 90 20 95 44

样例输出

0 2
0 4
2 1
2 4
3 0
3 2
4 3
5 2
5 4
7 2
8 0
8 4
9 3

 */

#include<stdio.h>
using namespace std;

int main() {
    int m, n, i, j;
    scanf("%d %d", &m, &n);

    int a[m][n];
    for (i=0;i<m;i++) {
        for (j=0;j<n;j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            bool shan = true;

            if (shan && i-1 >= 0)
            {
                if (a[i][j] < a[i-1][j])
                {
                    shan = false;
                }
            }

            if (shan && i+1 < m)
            {
                if (a[i][j] < a[i+1][j])
                {
                    shan = false;
                }
            }

            if (shan && j-1 >= 0)
            {
                if (a[i][j] < a[i][j-1])
                {
                    shan = false;
                }
            }

            if (shan && j+1 < n)
            {
                if (a[i][j] < a[i][j+1])
                {
                    shan = false;
                }
            }

            if (shan)
            {
                printf("%d %d\n", i, j);
            }
        }
    }
    return 0;
}