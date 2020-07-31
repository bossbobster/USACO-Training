#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

pii h[1010];
pii g[1010];
int dp[1010][1010][2];
int dist(int x1, int y1, int x2, int y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        cin >> h[i].first >> h[i].second;
    for(int i = 0; i < m; i ++)
        cin >> g[i].first >> g[i].second;
    for(int i = 0; i <= n; i ++)
        for(int j = 0; j <= m; j ++)
            dp[i][j][0] = dp[i][j][1] = 2000000000;
    dp[0][0][0] = 0;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j <= m; j ++)
        {
            dp[i + 1][j][0] = min(dp[i + 1][j][0], min(dp[i][j][0] + dist(h[i].first, h[i].second, h[i + 1].first, h[i + 1].second), dp[i][j][1] + dist(g[j - 1].first, g[j - 1].second, h[i + 1].first, h[i + 1].second)));
            dp[i][j + 1][1] = min(dp[i][j + 1][1], min(dp[i][j][0] + dist(h[i].first, h[i].second, g[j].first, g[j].second), dp[i][j][1] + dist(g[j - 1].first, g[j - 1].second, g[j].first, g[j].second)));
        }
    cout << dp[n - 1][m][0] << "\n";
}
