#include <iostream>
#include <algorithm>
using namespace std;

int dp[30010][3];
int nums[30010];
int main()
{
    int n, cur, ans;
    cin >> n;
    cin >> nums[0];
    nums[0] --;
    if(nums[0] != 0) dp[0][0] = 1;
    if(nums[0] != 1) dp[0][1] = 1;
    if(nums[0] != 2) dp[0][2] = 1;
    for(int i = 1; i < n; i ++) dp[i][0] = dp[i][1] = dp[i][2] = 2000000000; 
    for(int i = 1; i < n; i ++)
    {
        cin >> nums[i];
        nums[i] --;
        for(int j = 0; j < 3; j ++)
            for(int k = 0; k <= j; k ++)
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + ((nums[i]==j)?0:1));
    }
    ans = min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
    for(int i = 1; i < n; i ++) dp[i][0] = dp[i][1] = dp[i][2] = 2000000000; 
    for(int i = 1; i < n; i ++)
        for(int j = 0; j < 3; j ++)
            for(int k = 2; k >= j; k --)
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + ((nums[i]==j)?0:1));
    ans = min(min(ans, dp[n - 1][0]), min(dp[n - 1][1], dp[n - 1][2]));
    cout << ans << "\n";
}
