#include <iostream>
using namespace std;

int n, b, cur = 0, ans = 10000000, cnt = 1;
int heights[20];
void printAll(int n1, int idx, int m)
{
    if(n1 == 0)
    {
        if(cur >= b) ans = min(ans, cur - b);
        return;
    }
    for(int i = m - n1 + idx; i < m - n1 + n - m + 1; i ++)
    {
        cur += heights[i];
        printAll(n1 - 1, idx, m);
        idx ++;
        cur -= heights[i];
    }
}
int main()
{
    cin >> n >> b;
    for(int i = 0; i < n; i ++)
        cin >> heights[i];
    for(int i = 0; i < n; i ++)
        printAll(i + 1, 0, i + 1);
    cout << ans;
}
