/**
   编程题＃2：字符串中次数第2多的字母

    来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

    注意： 总时间限制: 1000ms 内存限制: 65536kB

    描述

    输入一串长度不超过500个符号的字符串，输出在串中出现第2多的英语字母(大小写字母认为相同)和次数（如果串中有其它符号，则忽略不考虑）。如果有多个字母的次数都是第2多，则按串中字母出现的顺序输出第1个。

    例 ab&dcAab&c9defgb

    这里，a 和 b都出现3次，c和d都出现2次，e、f 和 g 各出现1次，其中的符号&和9均忽略不考虑。因此，出现第2多的应该是 c 和 d，但是 d 开始出现的位置在 c 的前面，因此，输出为

    D+d:2

    (假定在字符串中，次数第2多的字母总存在)

    输入

    一个字符串

    输出

    大写字母+小写字母:个数

    样例输入

    ab&dcAab&c9defgb


    样例输出

    1 D+d:2

 */

#include <iostream>
#include <ctype.h>
#include <stdio.h>
using namespace std;

struct CharCount {
    char c;
    int count;// 出现此次
    int index;// 最早出现的下标
};

int main()
{
    char str[500];
    CharCount res[500];
    CharCount tmp;
    bool hasSet = false;
    int index = 0;

    cin >> str;

    for ( int i = 0; str[i] != '\0'; i++)
    {
        hasSet = false;
        // 只记录字母
        if((str[i] >=65 && str[i] <= 90) ||( str[i] >= 97 && str[i] <= 122))
        {
            for(int j = 0; j < index; j++ )
            {
                if(toupper(str[i]) == res[j].c)
                {
                    hasSet = true;
                    res[j].count = res[j].count +1;
                    break;
                }
            }

            if( !hasSet ){
                CharCount r = {toupper(str[i]), 1, i};
                res[index++] = r;
            }
        }
    }

    //sort by count and index
    for(int i = 0; i < index; i++ )
    {
        for( int j = i+1; j < index; j++)
        {

            if(res[i].count < res[j].count || (res[i].count == res[j].count && res[i].index > res[j].index )){
                tmp = res[i];
                res[i] = res[j];
                res[j] = tmp;
            }
        }
    }

    for( int i = 1; i < index; i++)
    {
        //找到第二多的字符集退出
        if( res[i].count < res[i-1].count)
        {
            printf("%c+%c:%d\n", res[i].c, tolower(res[i].c), res[i].count);
            break;
        }
    }
    return 0;
}