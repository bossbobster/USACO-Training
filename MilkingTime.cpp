#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

piii cows[1010];
int nextC[1010];
int dp[1010];
int main()
{
    int n, m, r, ans = 0;
    cin >> n >> m >> r;
    for(int i = 0; i < m; i ++)
    {
        cin >> cows[i].first >> cows[i].second.first >> cows[i].second.second;
        cows[i].second.first += r;
    }
    sort(cows, cows + m);
    for(int i = 0; i < m; i ++) 
        nextC[i] = m;
    for(int i = 0; i < m; i ++)
        for(int j = i + 1; j < m; j ++)
            if(cows[i].second.first <= cows[j].first)
            {
                nextC[i] = j;
                break;
            }
    for(int i = 0; i < m; i ++)
        dp[i] = cows[i].second.second;
    for(int i = 0; i < m; i ++)
        for(int j = nextC[i]; j < m; j ++)
            dp[j] = max(dp[j], dp[i] + cows[j].second.second);
    for(int i = 0; i < m; i ++)
        ans = max(ans, dp[i]);
    cout << ans << "\n";
}
