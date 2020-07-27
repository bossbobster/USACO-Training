// NOT A USACO PROBLEM
#include <iostream>
#include <algorithm>
using namespace std;

int nums[20010];
int dp[20010];
int main()
{
    int n, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    dp[0] = 1;
    for(int i = 1; i < n; i ++)
    {
        dp[i] = 1;
        for(int j = 0; j < i; j ++)
            if(nums[j] < nums[i])
                dp[i] = max(dp[i], dp[j] + 1);
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
}
