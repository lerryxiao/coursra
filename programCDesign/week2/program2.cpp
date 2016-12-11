/**
 * author: lerry xiao
 * datetime: 2016-11-27
 *
 * 编程题＃2：四大湖
 *
 * 注意： 总时间限制: 1000ms 内存限制: 65536kB
 *
 * 描述
 *
 * 我国有4大淡水湖。
 *
 * A说：洞庭湖最大，洪泽湖最小，鄱阳湖第三。
 *
 * B说：洪泽湖最大，洞庭湖最小，鄱阳湖第二，太湖第三。
 *
 * C说：洪泽湖最小，洞庭湖第三。
 *
 * D说：鄱阳湖最大，太湖最小，洪泽湖第二，洞庭湖第三。
 *
 * 已知这4个湖的大小均不相等，4个人每人仅答对一个，
 *
 * 请编程按照鄱阳湖、洞庭湖、太湖、洪泽湖的顺序给出他们的大小排名。
 *
 * 输入
 *
 * 无。
 *
 * 输出
 *
 * 输出为4行，第1行为鄱阳湖的大小名次，从大到小名次分别表示为1、2、3、4；第2、3、4行分别为洞庭湖、太湖、洪泽湖的大小名次。
*/

#include <iostream>
using namespace std;

int main()
{
    int Dt,Hz,Py,Th,sum[4]={0};     //定义变量
    //Dt表示洞庭湖，Hz表示洪泽湖，Py表示鄱阳湖，Th表示太湖
    //穷举四大湖排名的所有可能，用1、2、3、4分别来表示它们的大小关系
    //1最大，4最小
    for(Dt=1; Dt<=4; Dt++)
    {
        for(Hz=1; Hz<=4; Hz++)
        {
            if(Dt==Hz) continue;//湖的面积各不相同
            for(Py=1; Py<=4; Py++)
            {
                if(Py==Hz || Py==Dt) continue;//湖的面积各不相同
                Th=10-Dt-Hz-Py;//计算太湖的排名

                // 判断4个人说的话，有一个对，
                sum[0]= (1==Dt) + (4==Hz) + (3==Py);//A说的话
                sum[1]= (1==Hz) + (4==Dt) + (2==Py) + (3==Th);//B说的话
                sum[2]= (4==Hz) + (3==Dt);//C说的话
                sum[3]= (1==Py) + (4==Th) + (2==Hz) + (3==Dt);//D说的话

                if(sum[0]==1 && sum[1]==1 && sum[2]==1 && sum[3]==1)
                {
                    //按题目要求的鄱阳湖、洞庭湖、太湖、洪泽湖的顺序输出
                    cout << Py << endl << Dt << endl << Th << endl << Hz << endl;
                }

            }
        }
    }
}