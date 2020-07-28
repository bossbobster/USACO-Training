#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int dp[510][510];
pii coo[510];
int main()
{
    int n, k, ans = 2000000000;
    cin >> n >> k;
    for(int i = 0; i < n; i ++)
        cin >> coo[i].first >> coo[i].second;
    for(int i = 0; i < 510; i ++)
        for(int j = 0; j < 510; j ++)
            dp[i][j] = 2000000000;
    dp[0][0] = 0;
    for(int i = 0; i < n - 1; i ++)
        for(int j = 0; j <= i; j ++)
            for(int k = i + 1; k < n; k ++)
            {
                dp[k][j + k - i - 1] = min(dp[k][j + k - i - 1], dp[i][j] + abs(coo[i].first - coo[k].first) + abs(coo[i].second - coo[k].second));
            }
    for(int i = 0; i <= k; i ++)
        ans = min(ans, dp[n - 1][i]);
    cout << ans << "\n";
}
