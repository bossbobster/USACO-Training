#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, pii> piiii;

piiii parts[10010];
int preC[1010];
int dp[1010][1010];
int main()
{
    int l, n, b, ans = 0;
    cin >> l >> n >> b;
    for(int i = 0; i < n; i ++)
    {
        cin >> parts[i].first.first >> parts[i].first.second >> parts[i].second.first >> parts[i].second.second;
        parts[i].first.second += parts[i].first.first;
    }
    sort(parts, parts + n);
    for(int i = 0; i < n; i ++)
        if(preC[parts[i].first.first] == 0)
            preC[parts[i].first.first] = i + 1;
    for(int i = 0; parts[i].first.first == 0; i ++)
        dp[parts[i].first.second][parts[i].second.second] = parts[i].second.first;
    for(int i = 0; i < l; i ++)
        for(int j = 0; j < b; j ++)
        {
            if(dp[i][j] == 0 || preC[i] == 0) continue;
            for(int k = preC[i] - 1; k < n && parts[k].first.first == i; k ++)
                if(j + parts[k].second.second <= b)
                    dp[parts[k].first.second][j + parts[k].second.second] = max(dp[parts[k].first.second][j + parts[k].second.second], dp[i][j] + parts[k].second.first);
        }
    for(int i = 0; i <= b; i ++)
        ans = max(ans, dp[l][i]);
    if(ans == 0) { cout << -1 << "\n"; return 0; }
    cout << ans << "\n";
}
