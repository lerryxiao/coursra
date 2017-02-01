/**
    编程题＃5：走出迷宫

    来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

    注意： 总时间限制: 1000ms 内存限制: 65536kB

    描述

    当你站在一个迷宫里的时候，往往会被错综复杂的道路弄得失去方向感，如果你能得到迷宫地图，事情就会变得非常简单。

    假设你已经得到了一个n*m的迷宫的图纸，请你找出从起点到出口的最短路。

    输入

    第一行是两个整数n和m(1 <= n,m <= 100)，表示迷宫的行数和列数。

    接下来n行，每行一个长为m的字符串，表示整个迷宫的布局。字符'.'表示空地，'#'表示墙，'S'表示起点,'T'表示出口。

    输出

    输出从起点到出口最少需要走的步数。(你不能起出迷宫外)

    样例输入

    3 3
    S#T
    .#.
    ...

    样例输出

    1 6

 */

#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int N=105,tx[4]={0,1,0,-1},ty[4]={1,0,-1,0};
bool a[100][100] = {false};

struct node
{
    int x,y,s;
}k;
queue<node>q;
int main()
{
    int n,m,sta_x,sta_y,end_x,end_y,qx,qy,qs,i,j,l;
    char c;
    bool flag;

    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>c;
            switch (c) {
                case '#': {
                    a[i][j]=true;
                    break;
                }
                case 'S':
                {
                    sta_x=i;
                    sta_y=j;
                    break;
                }
                case 'T':
                {
                    end_x=i;
                    end_y=j;
                    break;
                }
            }
        }
    }

    k.x=sta_x;
    k.y=sta_y;
    k.s=0;
    q.push(k);
    a[sta_x][sta_y]=true;
    flag=false;
    while(!q.empty())
    {
        for(l=0;l<4;l++)
        {
            k=q.front();
            qx=k.x+tx[l];
            qy=k.y+ty[l];
            qs=k.s;
            if( qx < 1|| qx > n || qy < 1 || qy > m ){
                continue;
            }

            if( !(a[qx][qy]))
            {
                a[qx][qy] = true;
                k.x=qx;
                k.y=qy;
                k.s=qs+1;
                q.push(k);
            }

            if( qx == end_x && qy == end_y)
            {
                flag=true;
                break;
            }
        }
        if(flag==true){
            break;
        }

        q.pop();
    }

    k=q.back();

    cout<<k.s;

    return 0;
}