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