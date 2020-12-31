#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int t[2510];
int dp[2510];
int main()
{
    int n, m, w;
    cin >> n >> m;
    t[0] = m * 2;
    for(int i = 1; i <= n; i ++)
    {
        cin >> w;
        t[i] = t[i - 1] + w;
    }
    for(int i = 0; i <= n; i ++)
        dp[i] = 2000000000;
    dp[0] = 0;
    for(int i = 0; i < n; i ++)
        for(int j = 1; j <= n; j ++)
            dp[j] = min(dp[j], dp[i] + t[j - i]);
    cout << dp[n] - m << "\n";
}
