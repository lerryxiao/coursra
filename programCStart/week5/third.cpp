#include <iostream>
using namespace std;

int main(){
    int k;
    cin >> k;
    int count1 = 0, count5 = 0, count10 =0 ;
    int n;
    // 读取输入的 k 个整数
    for (int i = 0; i < k; i++)
    {
        cin >> n;
        if(n == 1)
        {
            count1++;
        } else if (n == 5)
        {
            count5++;
        } else if (n ==10)
        {
            count10++;
        }
    }

    cout << count1 << endl;
    cout << count5 << endl;
    cout << count10 << endl;
}