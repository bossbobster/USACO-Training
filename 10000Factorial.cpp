#include <iostream>
using namespace std;

int num[500000];
int len = 1, ogLen, previous, tmp, start;
void factorial(int n)
{
    num[499999] *= n;
    tmp = num[499999];
    num[499999] %= 10;
    previous = tmp / 10;
    ogLen = len;
    for(int i = 499998; i > 499998 - ogLen - 5; i --)
    {
        num[i] = num[i] * n + previous;
        tmp = num[i];
        num[i] %= 10;
        previous = tmp / 10;
    }
    len += 4;
    cout << "\n";
    if(n < 10000)
        factorial(n + 1);
}
int main()
{
    num[499999] = 1;
    factorial(2);
    for(start = 499999 - len; start <= 499999; start ++)
        if(num[start] != 0)
            break;
    for(int i = start; i <= 499999; i ++)
        cout << num[i];
}
