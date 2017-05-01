/**
编程题＃4：大整数的加减乘除

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述

给出两个正整数以及四则运算操作符（+ - * /），求运算结果。

输入

第一行：正整数a，长度不超过100

第二行：四则运算符o，o是“+”，“-”，“*”，“/”中的某一个

第三行：正整数b，长度不超过100

保证输入不含多余的空格或其它字符

输出

一行：表达式“a o b”的值。

补充说明：

1. 减法结果有可能为负数

2. 除法结果向下取整

3. 输出符合日常书写习惯，不能有多余的0、空格或其它字符

样例输入
9876543210
+
9876543210

样例输出
19753086420

 */

#include <string>
#include <iostream>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;

class CBigInt
{

public:

    CBigInt();

    CBigInt(const int i);

    CBigInt(const std::string &strValues);

    CBigInt(const CBigInt &bigInt); //复制构造函数

    //析构函数
    ~CBigInt();

public:
    int compareBigInt(const CBigInt &rhs) const; //比较两个数的大小

    CBigInt &operator=(const CBigInt &rhs); //赋值操作符重载

    friend std::ostream &operator<<(std::ostream &ou, const CBigInt &bigInt); //重载输出操作符

    friend std::istream &operator>>(std::istream &in, CBigInt &bigInt); //输入操作符的重载

    friend const CBigInt operator+(const CBigInt &lhs, const CBigInt &rhs); //加法操作重载

    friend const CBigInt operator-(const CBigInt &lhs, const CBigInt &rhs); //减法操作符重载

    friend const CBigInt operator*(const CBigInt &lhs, const CBigInt &rhs); //乘法操作符重载

    friend const CBigInt operator/(const CBigInt &lhs, const CBigInt &rhs); //除法操作重载

    void setValue(const std::string &strValues); //根据字符串设置数值

private:

    std::string values; //保存所有位上的数字

};

//重载标准输入符
std::ostream &operator<<(std::ostream &ou, const CBigInt &bigInt);

//重载输出符
std::istream &operator>>(std::istream &in, CBigInt &bigInt);

const CBigInt operator+(const CBigInt &lhs, const CBigInt &rhs); //加法操作符重载
const CBigInt operator-(const CBigInt &lhs, const CBigInt &rhs); //剑法操作符重载
const CBigInt operator*(const CBigInt &lhs, const CBigInt &rhs); //乘法操作符重载
const CBigInt operator/(const CBigInt &lhs, const CBigInt &rhs); //除法操作重载


CBigInt::CBigInt() : values("")
{
}

CBigInt::CBigInt(const int i)
{
    values.clear();
    int v = abs(i);

    while (v)
    {
        values.push_back(char('0' + (v % 10)));
        v /= 10;
    }

    reverse(values.begin(), values.end());
    if (values.empty())
    {
        values.push_back('0');
    }
}

CBigInt::CBigInt(const string &strValues)
{
    setValue(strValues); //调用成员函数完成
}

CBigInt::CBigInt(const CBigInt &bigInt) : values(bigInt.values)
{
}

CBigInt::~CBigInt() {}


int CBigInt::compareBigInt(const CBigInt &rhs) const
{
    //同号情况，先比较绝对值，然后根据符号判断大小
    int ret = 0;
    if (values.length() > rhs.values.length())
    {
        ret = 1;
    }
    else if (values.length() < rhs.values.length())
    {
        ret = -1;
    }
    else
    {
        ret = values.compare(rhs.values);
    }
    return ret;
}


void CBigInt::setValue(const string &strValues)
{
    values.clear();
    string tmpStr(strValues.begin() + strValues.find_first_not_of(' '), strValues.end()); //去掉前面的空格
    if (tmpStr.empty())
    {
        values.push_back('0');
        return;
    }

    int i = (int) tmpStr.find_first_of("0123456789");
    int j = (int) tmpStr.find_last_of("0123456789");

    values = tmpStr.substr((unsigned long) i, (unsigned long) (j - i + 1));//从符号位之后开始的所有数字，直到遇到第一个非数字位
}

CBigInt &CBigInt::operator=(const CBigInt &rhs)
{
    this->values = rhs.values;
    return *this;
}

ostream &operator<<(ostream &ou, const CBigInt &bigInt)
{
    ou << bigInt.values;
    return ou;
}

istream &operator>>(istream &in, CBigInt &bigInt)
{
    string str;
    in >> str;
    bigInt.setValue(str); //设置读入的新的数值
    return in;
}

const CBigInt operator+(const CBigInt &lhs, const CBigInt &rhs)
{
    CBigInt ret;
    string lvalues(lhs.values), rvalues(rhs.values);
    reverse(lvalues.begin(), lvalues.end());
    reverse(rvalues.begin(), rvalues.end());

    //逐位相加
    int i = 0;
    for (; i < lvalues.length() && i < rvalues.length(); ++i)
    {
        ret.values.push_back(lvalues.at(i) + rvalues.at(i) - '0');
    }

    if (i < lvalues.length())
    {
        for (; i < lvalues.length(); ++i)
        {
            ret.values.push_back(lvalues.at(i));
        }
    }
    else
    {
        for (; i < rvalues.length(); ++i)
        {
            ret.values.push_back(rvalues.at(i));
        }
    }
    //处理进位
    int carry = 0;
    for (int i = 0; i < ret.values.length(); ++i)
    {
        int newValue = ret.values.at(i) - '0' + carry;
        carry = newValue / 10;
        ret.values.at(i) = (char) (newValue - carry * 10 + '0');
    }
    if (carry)
    {
        ret.values.push_back((char) (carry + '0'));
    }


    reverse(ret.values.begin(), ret.values.end());
    i = (int) ret.values.find_first_not_of(" 0");
    if (i == string::npos)//空的，说明结果是0
    {
        ret.setValue("0");
        return ret;
    }
    ret.values = string(ret.values.begin() + ret.values.find_first_not_of(" 0"), ret.values.end()); //去掉前面的空白和0
    return ret;
}

const CBigInt operator-(const CBigInt &lhs, const CBigInt &rhs)
{
    CBigInt absL = lhs;
    CBigInt absR = rhs;
    CBigInt ret;
    int compFlag = absL.compareBigInt(absR);
    if (compFlag == 0)
    {
        ret.setValue("0");
        return ret;
    }
    else
    {
        if (compFlag == -1) //交换位置，使得absL > absR
        {
            CBigInt tmp(absL);
            absL = absR;
            absR = tmp;
        }

        reverse(absL.values.begin(), absL.values.end());
        reverse(absR.values.begin(), absR.values.end());

        //处理差值
        int i = 0;
        for (; i < absL.values.length() && i < absR.values.length(); ++i)
        {
            ret.values.push_back(absL.values.at(i) - absR.values.at(i) + '0');
        }

        if (i < absL.values.length()) //不可能出现i < absR.values.length()的情况
        {
            for (; i < absL.values.length(); ++i) {
                ret.values.push_back(absL.values.at(i));
            }
        }

        //处理借位
        int carry = 0;
        for (i = 0; i < ret.values.length(); ++i)
        {
            int newValue = ret.values.at(i) - carry - '0';
            if (newValue < 0)
            {
                carry = 1;
            } //向前借位
            else
            {
                carry = 0;
            }
            ret.values.at(i) = (char) (newValue + carry * 10 + '0');
        }
    }
    reverse(ret.values.begin(), ret.values.end());
    int i = (int) ret.values.find_first_not_of(" 0");
    if (i == string::npos)//空的，说明结果是0
    {
        ret.setValue("0");
        return ret;
    }
    ret.values = string(ret.values.begin() + ret.values.find_first_not_of(" 0"), ret.values.end()); //去掉前面的空白和0
    if (compFlag == -1){
        ret.values = "-" + ret.values;
    }
    return ret;
}

//乘法操作符重载
const CBigInt operator*(const CBigInt &lhs, const CBigInt &rhs)
{
    CBigInt ret;
    int flag1 = lhs.compareBigInt(CBigInt(0));
    int flag2 = rhs.compareBigInt(CBigInt(0));
    if (flag1 == 0 || flag2 == 0)
    {
        ret.setValue("0");
        return ret;
    }

    string lvalues(lhs.values), rvalues(rhs.values);
    reverse(lvalues.begin(), lvalues.end());
    reverse(rvalues.begin(), rvalues.end());
    ret.values.resize(lvalues.size() + rvalues.size(), '0');

    //相乘
    for (int i = 0; i < lvalues.size(); ++i)
        for (int j = 0; j < rvalues.size(); ++j)
        {
            int newValue = ret.values[i + j] + (lvalues[i] - '0') * (rvalues[j] - '0') - '0';
            int carry = newValue / 10;
            ret.values[i + j] = (char) (newValue % 10 + '0');

            //这里之所以对每一位进行进位处理，是为了防止出现溢出情况的出现，如'0' + 9 * 9 = 48 + 81 > 127已经溢出
            for (int k = i + j + 1; carry != 0 && k < ret.values.size(); ++k) //处理进位
            {
                ret.values[k - 1] = (char) (newValue % 10 + '0');
                newValue = ret.values[k] + carry - '0';
                ret.values[k] = (char) (newValue % 10 + '0');
                carry = newValue / 10;
            }
        }

    reverse(ret.values.begin(), ret.values.end()); //翻转
    ret.values = string(ret.values.begin() + ret.values.find_first_not_of(" 0"), ret.values.end()); //去掉前面的空白和0

    return ret;
}

const CBigInt operator/(const CBigInt &lhs, const CBigInt &rhs)  //除法操作重载
{
    CBigInt ret;
    assert(rhs.compareBigInt(CBigInt(0)) != 0);
    ret.setValue("0"); //初始化为0

    CBigInt absL(lhs);
    CBigInt absR(rhs);

    int comFlag = absL.compareBigInt(absR);
    if (comFlag < 0)
    {
        return ret;
    }

    if (comFlag == 0)
    {
        ret.setValue("1");
        return ret;
    }
    int movCount = (int) (absL.values.size() - absR.values.size());

    const CBigInt tenBigInt(10);
    //使用减法实现除法的操作
    do {
        CBigInt tmp(absR);
        for (int i = 0; i < movCount; ++i) //tmp是10的movCount次方
            tmp = tmp * tenBigInt;
        int addNum = 0;
        while (absL.compareBigInt(tmp) >= 0) {
            absL = absL - tmp;
            addNum++;
        }

        ret = ret * tenBigInt + CBigInt(addNum);

        movCount--;

    } while (movCount >= 0);

    return ret;
}

int main(int argc, char **argv)
{
    string num1, num2;
    char op;
    cin >> num1 >> op >> num2;
    CBigInt bi1(num1);
    CBigInt bi2(num2);
    switch (op) {
        case '+':
            cout << bi1 + bi2 << std::endl;
            break;
        case '-':
            cout << bi1 - bi2 << std::endl;
            break;
        case '*':
            cout << bi1 * bi2 << std::endl;
            break;
        case '/':
            cout << bi1 / bi2 << std::endl;
            break;
        default:
            cout << "not support" << std::endl;
    }
    return 0;
}
