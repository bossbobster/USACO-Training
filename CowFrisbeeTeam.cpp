#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

int dp[2010][1010];
int nums[2010];
int main()
{
    int n, f;
    cin >> n >> f;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    dp[0][0] = 1;
    for(int i = 1; i <= n; i ++)
        for(int j = 0; j < f; j ++)
            dp[i][j] = (dp[i][j] + dp[i - 1][j] + dp[i - 1][((j - (nums[i - 1] % f) + 3 * f) % f)]) % 100000000;
    cout << dp[n][0] - 1 << "\n";
}
