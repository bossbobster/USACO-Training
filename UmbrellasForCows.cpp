#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;

int dp[5010];
int nums[5010];
int cost[100010];
int pref[100010];
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    sort(nums, nums + n);
    for(int i = 0; i < m; i ++)
        cin >> cost[i];
    pref[m - 1] = cost[m - 1];
    for(int i = m - 2; i >= 0; i --)
        pref[i] = min(pref[i + 1], cost[i]);
    for(int i = 0; i <= n; i ++)
        dp[i] = 2000000000;
    dp[0] = 0;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 0; j < i; j ++)
            dp[i] = min(dp[i], dp[j] + pref[nums[i - 1] - nums[j]]);
        dp[i] = min(dp[i], dp[i - 1] + pref[0]);
    }
    cout << dp[n] << "\n";
}
