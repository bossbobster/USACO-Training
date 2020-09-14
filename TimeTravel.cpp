#include <iostream>
#include <algorithm>
using namespace std;

int val[100000];
int pre[100000];
int main()
{
    int n, k;
    char c;
    cin >> n;
    val[0] = -1;
    pre[0] = -100000;
    for(int i = 1; i <= n; i ++)
    {
        cin >> c;
        if(c != 's') cin >> k;
        if(c == 'a')
        {
            val[i] = k;
            pre[i] = i - 1;
        }
        else if(c == 's')
        {
            val[i] = val[pre[i - 1]];
            pre[i] = pre[pre[i - 1]];
        }
        else
        {
            val[i] = val[k - 1];
            pre[i] = pre[k - 1];
        }
        cout << val[i] << "\n";
    }
}
