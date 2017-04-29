class CArray
{
    int size; //length
    int *ptr; //
public:
    CArray(int s = 0);// 参数为数组元素的个数
    CArray(CArray &a);
    ~CArray();
    void push_back(int v); // 用于向数组的尾部添加一个元素 V
    CArray & operator = (const CArray &a);
    // 用于数组对象间的赋值
    int length();
    int & CArray::operator[](int i); //用于支持根据下标访问数组元素
};

CArray::CArray(int s):size(s)
{
    if( s == 0)
    {
        ptr = NULL;
    }
    else
    {
        ptr = new int[2];
    }
}

CArray::CArray(CArray &a)
{
    if( !a.ptr) {
        ptr = NULL;
        size = 0;
        return;
    }
    ptr = new int[a.size];
    memcpy( ptr, a.ptr, sizeof(int ) * a.size);
    size = a.size;
}

void CArray::push_back(int v)
{
    if( ptr) {
        int * tmpPtr = new int[size+1]; //重新分配空间
        memcpy(tmpPtr,ptr,sizeof(int)*size); //拷贝原数组内容
        delete [] ptr;
        ptr = tmpPtr;
    }
    else //数组本来是空的
    {
        ptr = new int[1];
    }
    ptr[size++] = v; //加入新的数组元素
}

CArray::length()
{
    return size;
}

int & CArray::operator [] (int i)
{
    return ptr[i];
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