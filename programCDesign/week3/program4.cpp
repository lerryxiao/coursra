/**
 * 编程题＃4：扩号匹配问题
 * 来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)
 * 注意： 总时间限制: 1000ms 内存限制: 65536kB
 * 描述
 * 在某个字符串（长度不超过100）中有左括号、右括号和大小写字母；规定（与常见的算数式子一样）任何一个左括号都从内到外与在它右边且距离最近的右括号匹配。
 * 写一个程序，找到无法匹配的左括号和右括号，输出原来字符串，并在下一行标出不能匹配的括号。不能匹配的左括号用"$"标注,不能匹配的右括号用"?"标注.
 *
 *输入
 *
 * 输入包括多组数据，每组数据一行，包含一个字符串，只包含左右括号和大小写字母，字符串长度不超过100
 *
 * 注意：cin.getline(str,100)最多只能输入99个字符！
 *
 * 输出
 *
 * 对每组输出数据，!!!输出两行，第一行包含原始输入字符!!!，第二行由"$","?"和空格组成，"$"和"?"表示与之对应的左括号和右括号不能匹配。
 *
 * 样例输入
((ABCD(x)
)(rttyy())sss)(

* 样例输出

((ABCD(x)
$$
)(rttyy())sss)(
?            ?$
 *
 */

#include <iostream>
#include <string>
using namespace std;


int match(char s[], int start);

int main()
{
    char s[101];
    int m= 0;

    while( true )
    {
        cin.getline(s, 101);
        cout << s << endl;


        if(strlen(s) > 0)
        {
            while(s[m] != '(')
            {
                if (s[m] != ')'){
                    s[m] = ' ';
                }
                m++;
            }

            while(m != -1)
            {
                m = match(s,m);
                if(s[m] == ')')
                {
                    m++;
                }
            }
        }

        // parse
        for(int i = 0; i < strlen(s); i++)
        {
            switch (s[i]) {
            case '(': {
                s[i] = '$';
                break;
            }
            case ')':
                s[i] = '?';
                break;
            default:
                break;
            }
        }
        cout << s << endl;
        m = 0;
    }
    return 0;
}


int match(char s[], int start){
    if(s[start] == '\0' || strlen(s) == start){
        return -1;
    }

    if(s[start] == '(')
    {
        int n;
        n = match(s, start+1);
        if(s[n] != '\0' && s[n] == ')')
        {
            s[start] = ' ';
            s[n] = ' ';
            return match(s, n + 1);
        }
        else
        {
            return match(s, n);
        }
    }
    else
    {
        while(s[start] != '\0' && s[start] != '(' && s[start] != ')')
        {
            s[start] = ' ';
            start++;
        }
        if (s[start] == ')')
        {
            return start;
        }else{
            return match(s, start);
        }
    }
}