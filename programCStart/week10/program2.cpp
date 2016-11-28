#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    char s1[100], s2[100];
    cin.getline(s1, 80);
    cin.getline(s2, 80);
    int i = 0;
    char result;
    while (s1[i] != '\0' && (toupper(s1[i]) == toupper(s2[i]))){
        i++;
    }
    if (toupper(s1[i]) > toupper(s2[i])) {
        result = '>';
    } else if (toupper(s1[i]) < toupper(s2[i])) {
        result = '<';
    } else{
        result = '=';
    }
    cout << result << endl;
}