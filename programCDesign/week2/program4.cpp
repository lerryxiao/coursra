/**
 * author: lerry xiao
 * datetime: 2016-11-27
 *
 * 编程题＃4：Tomorrow never knows？
 *
 * 来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)
 *
 * 注意： 总时间限制: 1000ms 内存限制: 65536kB
 *
 * 描述
 *
 * 甲壳虫的《A day in the life》和《Tomorrow never knows》脍炙人口，如果告诉你a day in the life,真的会是tomorrow never knows?相信学了计概之后这个不会是难题，现在就来实现吧。
 *
 * 读入一个格式为yyyy-mm-dd的日期（即年－月－日），输出这个日期下一天的日期。可以假定输入的日期不早于1600-01-01，也不晚于2999-12-30。
 *
 * 输入
 *
 * 输入仅一行，格式为yyyy-mm-dd的日期。
 *
 * 输出
 *
 * 输出也仅一行，格式为yyyy-mm-dd的日期
 *
 * 样例输入
 *
 * 1 2010-07-05
 *
 * 样例输出
 *
 * 1 2010-07-06
 *
 * 提示
 *
 * 闰年的标准：
 *
 * (1)普通年能被4整除且不能被100整除的为闰年。（如2004年就是闰年,1901年不是闰年）
 *
 * (2)世纪年能被400整除的是闰年。(如2000年是闰年，1100年不是闰年)
 *
 * 可以利用一个字符变量吃掉输入的短横线（减号），输出时请活用setfill和setw 控制符。
 */

#include <iostream>
#include <iomanip>
using namespace std;

void parseDate(int year, int month,int day, int maxDay);
int checkYear(int year);
int getMaxDayInMonth(int month, bool isY);

int main()
{
    int year, month, day;
    char s;
    int maxMonthDay = 30;
    bool isY = false;
    cin >> year >> s >> month >> s >> day;
    day = day + 1;
    isY = checkYear(year);
    maxMonthDay = getMaxDayInMonth(month, isY);

    parseDate(year, month, day, maxMonthDay);
    return 0;
}


int checkYear(int year)
{
    if((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 ==0))
    {
       return true;
    }
    return false;
}

int getMaxDayInMonth(int month,bool isY)
{
    switch(month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 2:
        if (isY)
        {
            return 29;
        }
        else
        {
            return 28;
        }
    case 4:
    case 6:
    case 9:
    case 11:
       return 30;
    default:
        return 30;
    }
}

void parseDate(int year, int month, int day, int maxday)
{
    if (day > maxday)
    {
        month = month + 1;
        day = day - maxday;
    }
    if(month > 12)
    {
        month = month - 12;
        year++;
    }
    cout << year;
    if(month > 9)
    {
        cout << '-' << month;
    }
    else
    {
        cout << '-' << '0'  << month;
    }
    if(day > 9)
    {
        cout << '-' << day;
    }
    else
    {
        cout << "-" << '0' << day;
    }
    cout << endl;
}