#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a = 0, k=0;
    for( int i = 0; i < n; i++) {
        cin >> k;

        while(k > 0) {
            if(k % 2 == 1) {
                a++;
            }
            k = k / 2;
        }
        cout << a << endl;
        a = 0;
    }

    return 0;
}