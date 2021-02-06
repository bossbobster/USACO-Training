#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;

double nums[2010];
double dp[2010];
int main()
{
    int n;
    double a, b;
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i ++)
        cin >> nums[i];
    sort(nums, nums + n + 1);
    for(int i = 0; i <= n; i ++)
        dp[i] = 2000000000;
    dp[0] = 0;
    for(int i = 1; i <= n; i ++)
        for(int j = i; j <= n; j ++)
            dp[j] = min(dp[j], dp[i - 1] + a + (b * (nums[j] - nums[i]) / 2));
    if(dp[n] - (int)dp[n] >= 0.1) cout << fixed << setprecision(1) << dp[n] << "\n";
    else cout << fixed << (int)round(dp[n]) << "\n";
}
