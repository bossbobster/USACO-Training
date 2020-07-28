#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int n, ans = 0;
pii targets[1010];
int dp[1010][1010];
void solve()
{
    sort(targets, targets + n);
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            dp[i][j] = 0;
    dp[0][0] = 0;
    for(int i = 1; i < n; i ++)
    {
        dp[i][0] = targets[0].second + targets[i].second;
        dp[i][i] = targets[i].second;
    }
    for(int i = 1; i < n - 1; i ++)
        for(int j = 0; j <= i; j ++)
            for(int k = i + 1; k < n; k ++)
                if(targets[k].first - targets[i].first >= targets[i].first - targets[j].first)
                {
                    dp[k][i] = max(dp[k][i], dp[i][j] + targets[k].second);
                    ans = max(ans, dp[k][i]);
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
