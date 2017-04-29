/*
#include <iostream>
#include <cstring>
using namespace std;
*/
// 在此处补充你的代码
class CArray {
    int size; //length
    int *ptr; //
public:
    CArray(int s = 0);// 参数为数组元素的个数
    CArray(const CArray &a);

    ~CArray();

    int length();// 用于数组对象间的赋值

    CArray &operator=(const CArray &a);

    int & operator [] (int i); //用于支持根据下标访问数组元素
};

CArray::CArray(int s) : size(s) {
    if (s == 0) {
        ptr = NULL;
    } else {
        ptr = new int[s];
    }
}

CArray::CArray(const CArray &a) {
    if (!a.ptr) {
        ptr = NULL;
        size = 0;
        return;
    }
    size = a.size;
    ptr = new int[size];
    memcpy(ptr, a.ptr, sizeof(int) * size);
}

CArray::~CArray() {
    if (ptr) {
        delete[]ptr;
    }
}


int CArray::length() {
    return size;
}

CArray & CArray::operator=( const CArray & a)
{ //赋值号的作用是使“=”左边对象里存放的数组，大小和内容都和右边的对象一样
    if( ptr == a.ptr) //防止a=a这样的赋值导致出错
    {
        return * this;
    }
    if( a.ptr == NULL) { //如果a里面的数组是空的
        if( ptr )
        {
            delete [] ptr;
        }
        ptr = NULL;
        size = 0;
        return * this;
    }
    if( size < a.size)
    { //如果原有空间够大，就不用分配新的空间 if(ptr)
        delete [] ptr;
        ptr = new int[a.size];
    }
    memcpy( ptr,a.ptr,sizeof(int)*a.size);
    size = a.size;
    return * this;
}

int & CArray::operator [] (int i) {
    return ptr[i];
}

class Array2
{
    int row, column;
    CArray *ptr;
public:
    Array2(int r =0, int s = 0);
    Array2(const Array2 & a);

    CArray & operator [] (int i);
    int operator ()(int r, int j);



};

Array2::Array2(int r, int s):row(r),column(s)
{
    if(row == 0 && column == 0)
    {
        ptr = NULL;
    }
    else
    {
        ptr = new CArray[s];
        for(int i = 0; i < row; ++i)
        {
            ptr[i] = CArray(column);
        }
    }
}

Array2::Array2(const Array2& a)
{
    if(!a.ptr)
    {
        ptr = NULL;
        row = 0;
        column = 0;
        return ;
    }
    row = a.row;
    column = a.column;
    for(int i = 0; i < row; ++i)
    {
        ptr[i] = a.ptr[i];
    }
}

CArray & Array2::operator [] (int i)
{
    return ptr[i];
}

int Array2::operator () (int i, int j)
{
    return ptr[i][j];
}



// end
/*
int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
*/