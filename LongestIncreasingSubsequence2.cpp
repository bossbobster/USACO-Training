//THIS VERSION WORKS IN N LOG N INSTEAD OF N^2
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

int nums[100010];
vector<int> dp;
int main()
{
    int n, ans = 0, change;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    dp.push_back(nums[0]);
    for(int i = 0; i < n; i ++)
        dp.push_back(INT_MAX);
    for(int i = 1; i < n; i ++)
    {
        change = (int)(lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin());
        dp[change] = nums[i];
        ans = max(ans, change + 1);
    }
    cout << ans << "\n";
}
