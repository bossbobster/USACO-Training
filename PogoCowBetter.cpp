#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int n, ans = 0, mx, idx;
pii targets[1010];
int dp[1010][1010];
void solve()
{
    sort(targets, targets + n);
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            dp[i][j] = 0;
    for(int i = 1; i < n; i ++)
    {
        dp[i][0] = targets[0].second + targets[i].second;
        dp[i][i] = targets[i].second;
    }
    for(int i = 1; i < n - 1; i ++)
    {
        idx = i - 1;
        mx = dp[i][i];
        for(int k = i + 1; k < n; k ++)
        {
            while(idx != -1 && targets[k].first - targets[i].first >= targets[i].first - targets[idx].first)
            {
                mx = max(mx, dp[i][idx]);
                idx --;
            }
            dp[k][i] = max(dp[k][i], mx + targets[k].second);
            ans = max(ans, dp[k][i]);
        }
    }
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> targets[i].first >> targets[i].second;
    solve();
    for(int i = 0; i < n; i ++)
        targets[i].first *= -1;
    solve();
    cout << ans << "\n";
}
