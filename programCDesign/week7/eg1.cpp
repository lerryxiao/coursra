/**
    指定总结：
    1. 定义： struct name
      name 为类型名称，类似于 int float 等.
   2. 结构体之间的相互赋值是 copy
*/

#include <iostream>
using namespace std;

struct student
{
    int id_num;
    char name[10];
};

int main()
{
    student mike1 = {123, {'m', 'i', 'k', 'e'} };
    student mike2;
    mike2 = mike1;
    mike2.id_num = 20130000 + mike2.id_num;

    for (int i = 0; mike2.name[i] != '\0'; i++)
    {
        mike2.name[i] = toupper(mike2.name[i]);
    }

    cout << mike1.id_num << " " << mike1.name << endl;
    cout << mike2.id_num << " " << mike2.name << endl;

    return 0;
}