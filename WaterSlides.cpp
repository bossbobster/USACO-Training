#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int n, m, k, one, two, three;
vector<pii> adj[50010];
long long dp[50010][20];
long long minL(long long f, long long s)
{
    if(f <= s) return f;
    return s;
}
long long maxL(long long f, long long s)
{
    if(f >= s) return f;
    return s;
}
long long rec(int cur, int remK)
{
    if(cur == n) return 0;
    if(dp[cur][remK] != -1) return dp[cur][remK];
    long long minS = 200000000000, maxW = -200000000000;
    for(int i = 0; i < adj[cur].size(); i ++)
    {
        if(remK > 0)
            minS = minL(minS, adj[cur][i].second + rec(adj[cur][i].first, remK - 1));
        maxW = maxL(maxW, adj[cur][i].second + rec(adj[cur][i].first, remK));
    }
    dp[cur][remK] = minL(minS, maxW);
    //if(dp[cur][remK] < 0) dp[cur][remK] = -1;
    return dp[cur][remK];
}
int main()
{
    cin >> n >> m >> k;
    for(int i = 0; i < m; i ++)
    {
        cin >> one >> two >> three;
        adj[one].push_back(pii(two, three));
    }
    for(int i = 0; i < n; i ++)
        for(int j = 0; j <= k; j ++)
            dp[i][j] = -1;
    cout << rec(1, k) << "\n";
}
