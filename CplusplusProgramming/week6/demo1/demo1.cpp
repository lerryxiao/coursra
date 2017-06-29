//
// Created by 肖乐源 on 20/06/2017.
//

#include <iostream>

using namespace std;

class CBase
{
public:
    virtual void someVirtualFunc()
    {
        std::cout << " Parend func" << std::endl;
    };
};

class CDerived
        : public CBase
{
public:
    virtual void someVirtualFunc()
    {
        std::cout << " Child func" << std::endl;
    }
};

int main()
{
    CDerived cDerived;
    CBase * b = & cDerived;
    b -> someVirtualFunc();
    return 0;
}