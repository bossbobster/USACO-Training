#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int dp[50010];
int pos[60];
int visited[50010];
bool isfav[50010];
int main()
{
    int n, nopt, f, m, idx, ans = 0;
    cin >> n >> nopt >> f >> m;
    for(int i = 0; i < nopt; i ++)
        cin >> pos[i];
    for(int i = 0; i < f; i ++)
    {
        cin >> idx;
        isfav[idx] = true;
    }
    for(int i = 0; i < n + m + 5; i ++)
        dp[i] = -1;
    idx = n;
    dp[n] = 0;
    while(idx >= 0)
    {
        for(int i = 0; i < nopt; i ++)
            if(dp[idx] != -1 && idx - pos[i] >= 0)
                dp[idx - pos[i]] = max(dp[idx - pos[i]], dp[idx] + pos[i]);
        if(isfav[idx] && dp[idx] > 0)
        {
            if(dp[idx] > dp[idx + m])
            {
                if(visited[idx] > f + 1) { cout << -1 << endl; return 0; }
                visited[idx] ++;
                dp[idx + m] = dp[idx];
                idx += m;
            }
            else
            {
                idx --;
            }
        }
        else
            idx --;
    }
    for(int i = 0; i <= n + m; i ++)
        ans = max(ans, dp[i]);
    cout << ans << "\n";
}
