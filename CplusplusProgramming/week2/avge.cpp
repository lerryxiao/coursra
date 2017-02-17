/**
   描述

在一个学生信息处理程序中，要求实现一个代表学生的类，并且所有成员变量都应该是私有的。

（注：评测系统无法自动判断变量是否私有。我们会在结束之后统一对作业进行检查，请同学们严格按照题目要求完成，否则可能会影响作业成绩。）

输入

姓名，年龄，学号，第一学年平均成绩，第二学年平均成绩，第三学年平均成绩，第四学年平均成绩。

其中姓名、学号为字符串，不含空格和逗号；年龄为正整数；成绩为非负整数。

各部分内容之间均用单个英文逗号","隔开，无多余空格。

输出

一行，按顺序输出：姓名，年龄，学号，四年平均成绩（向下取整）。

各部分内容之间均用单个英文逗号","隔开，无多余空格。

样例输入

Tom,18,7817,80,80,90,70
样例输出

Tom,18,7817,80
 */

#include <iostream>
#include <string>
#include <stdlib.h> // for atoi function

using namespace std;


class Student {

public:

    std::string name;
    std::string number;

    int score[4];
    int averageScroe;
    int age;

    void average();
    void printResult();

};

void Student::average()
{

    averageScroe = (score[0] + score[1] + score[2] + score[3]) / 4 ;

}

void Student::printResult()
{

    std::cout << name << "," << age << "," << number << "," <<  averageScroe << std::endl;

}

int main()
{
    Student stdu;
    std::string tmp;

    std::getline(std::cin, stdu.name, ',');

    std::getline(std::cin, tmp, ',');
    stdu.age = atoi(tmp.c_str());
    //stdu.age = std::stoi(tmp);

    std::getline(std::cin, stdu.number, ',');

    for( int i = 0; i < 4; i++){

        if ( i == 3)
        {
            std::getline(std::cin, tmp, '\n');
        }
        else
        {
            std::getline(std::cin, tmp, ',');
        }
        //stdu.score[i] = std::stoi(tmp);
        stdu.score[i] = atoi(tmp.c_str());

    }


    stdu.average();
    stdu.printResult();

    return 0;
}