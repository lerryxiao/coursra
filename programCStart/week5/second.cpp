#include <iostream>
using namespace std;

int main(){
    int m, n, sum = 0;
    cin >> m >> n;
    if (m < 0 || n > 300 || m > n ){
        cout << "0 <= m <= n <= 300" << endl;
        return 0;
    }

    for (int i = m; i< n +1 ; i++) {
        if(i % 2 == 1) {
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}