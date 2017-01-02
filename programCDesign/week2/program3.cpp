/**
 * author: lerry xiao
 * datetime: 2016-11-27
 *
 * 编程题＃3：发票统计
 *
 * 注意： 总时间限制: 1000ms 内存限制: 65536kB
 *
 * 描述
 *
 * 有一个小型的报账系统，它有如下功能：
 *
 *（1）统计每个人所报发票的总钱数
 *
 *（2）统计每类发票的总钱数
 *
 * 将此系统简化为如下：假设发票类别共有A、B、C三种;一共有三个人，ID分别为1、2、3。
 *
 * 输入
 *
 * 系统输入包含三行，每行第一个数为人员ID（整型，1或2或3），第二个数为发票总张数(张数不超过100)，之后是多个发票类别（字符型，A或B或C）和相应发票金额（单进度浮点型,不超过1000.0）。
 *
 * 输出
 *
 * 输出包含六行，前三行为每人（按ID由小到大输出）所报发票总钱数（保留两位小数），后三行为每类发票的总钱数（保留两位小数）。
 *
 * 样例输入
 *
 * 1 1 5 A 1.0 A 2.0 C 1.0 B 1.0 C 1
 * 2 3 3 B 1 C 2 C 1
 * 3 2 4 B 1 A 1 C 1 A 1
 *
 * 样例输出
 *
 * 1 1 6.00
 * 2 2 4.00
 * 3 3 4.00
 * 4 A 5.00
 * 5 B 3.00
 * 6 C 6.00
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float count[4][4] = {0.0,0.0};
    int user,c;
    char t;
    float m;

    for(int i = 0; i < 3; i++)
    {
        cin >> user >> c;// input user and count
        for(int j = 0; j < c; j++)
        {
            cin >> t;
            cin >> m;
            switch (t)
            {
            case 'A':
                count[user-1][0] = m + count[user-1][0];
                break;
            case 'B':
                count[user-1][1] = m + count[user-1][1];
                break;
            case 'C':
                count[user-1][2] = m + count[user-1][2];
                break;
            default:
                break;
            }
        }
    }

    // count user
    for(int i =0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            count[i][3] = count[i][3] + count[i][j];
        }
    }

    //count type
    for(int i =0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            count[3][i] = count[3][i] + count[j][i];
        }
    }

    cout << fixed << setprecision(2);
    //output user
    for(int i =0 ; i < 3; i++)
    {
        cout << ( i + 1 ) << " " << count[i][3] << endl;
    }

    //output type
    for(int i =0 ; i < 3; i++)
    {
        cout << char(('A' + i)) << " " <<  count[3][i] << endl;
    }

    return 0;
}