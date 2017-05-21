//
// Created by 肖乐源 on 07/05/2017.
//

#include "parta.h"

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;
// 在此处补充你的代码
class MyString
        : public std::string
{
public:
    MyString();

    MyString(const MyString &str);

    MyString(const char *str);

    MyString operator()(int start, int end);

    bool operator<(MyString &s);

    bool operator>(MyString &s);

    bool operator==(MyString &s);

    MyString operator+(MyString& s);
    MyString& operator+(const char * cs2);

};

MyString::MyString()
{
}

MyString::MyString(const MyString &str) : string(str)
{
}

MyString::MyString(const char *str) : string(str)
{}

MyString MyString::operator()(int start, int end)
{
    return *new MyString(substr(start, end).c_str());
}

bool MyString::operator<(MyString &s)
{
    return (this->compare(s) < 0 );
}

bool MyString::operator==(MyString &s)
{
    return (this->compare(s) == 0);
}

bool MyString::operator>(MyString &s)
{
    return (this->compare(s) > 0 );
}

MyString MyString::operator+(MyString& s)
{
    string s1 = *this;
    string s2 = s;
    string r = s1 + s2;
    return *new MyString(r.c_str());
}

MyString & MyString::operator +(const char * cs2)
{
    string str1 = *this;
    string s = str1 + cs2;
    return *new MyString(s.c_str());
}

MyString operator+(const char * op1, MyString & op2)
{
    string st2 = op2;
    string s = op1 + st2;
    return *new MyString(s.c_str());
}

std::ostream &operator<<(std::ostream &ou, const MyString &s)
{
    ou << (string &) s;
    return ou;
}



// ***  完成补充代码 ****
int CompareString(const void *e1, const void *e2)
{
    MyString *s1 = (MyString *) e1;
    MyString *s2 = (MyString *) e2;
    if (*s1 < *s2) return -1;
    else if (*s1 == *s2) return 0;
    else if (*s1 > *s2) return 1;
}

void parta()
{
    MyString s1("abcd-"), s2, s3("efgh-"), s4(s1);
    MyString SArray[4] = {"big", "me", "about", "take"};
    cout << "1. " << s1 << s2 << s3 << s4 << endl;
    s4 = s3;
    s3 = s1 + s3;
    cout << "2. " << s1 << endl;
    cout << "3. " << s2 << endl;
    cout << "4. " << s3 << endl;
    cout << "5. " << s4 << endl;
    cout << "6. " << s1[2] << endl;
    s2 = s1;
    s1 = "ijkl-";
    s1[2] = 'A';
    std::cout << s1[2] << std::endl;
    cout << "7. " << s2 << endl;
    cout << "8. " << s1 << endl;
    s1 += "mnop";
    cout << "9. " << s1 << endl;
    s4 = "qrst-" + s2;
    cout << "10. " << s4 << endl;
    s1 = s2 + s4 + " uvw " + "xyz";
    cout << "11. " << s1 << endl;
    qsort(SArray, 4, sizeof(MyString), CompareString);
    for (int i = 0; i < 4; ++i)
        cout << SArray[i] << endl;
    //输出s1从下标0开始长度为4的子串
    cout << s1(0, 4) << endl;
    //输出s1从下标为5开始长度为10的子串
    cout << s1(5, 10) << endl;
}
