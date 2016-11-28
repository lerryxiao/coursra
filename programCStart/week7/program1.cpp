#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n, age;
    cin >> n;
    double count1 = 0.0, count2 = 0.0, count3= 0.0, count4=0.0;
    double pre1 = 0.0, pre2 = 0.0, pre3 = 0.0, pre4 = 0.0;

    for(int i = 0; i < n; i++)
    {
        cin >> age;
        if (age <= 18)
        {
            count1++;
        }
        else if (age <= 35)
        {
            count2++;
        }
        else if (age < 60)
        {
            count3++;
        }
        else
        {
            count4++;
        }
    }
    pre1 = 100 * count1 / (double)n;
    pre2 = 100 * count2 / (double)n;
    pre3 = 100 * count3 / (double)n;
    pre4 = 100 * count4 / (double)n;
    cout << fixed << setprecision(2);
    cout << "1-18: "  << pre1 << "%" << endl;
    cout << "19-35: " << pre2 << "%" << endl;
    cout << "36-60: " << pre3 << "%" << endl;
    cout << "60-: " << pre4 << "%" << endl;
    return 0;
}