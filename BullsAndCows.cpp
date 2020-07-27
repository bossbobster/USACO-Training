#include <iostream>
#include <algorithm>
using namespace std;

int dp[100010];
int main()
{
    int n, k;
    cin >> n >> k;
    dp[0] = 1;
    dp[1] = 2;
    for(int i = 2; i <= n; i ++)
    {
        dp[i] += dp[i - 1];
        if(i - k - 1 > 0) dp[i] += dp[i - k - 1];
        else dp[i] ++;
        dp[i] %= 5000011;
    }
    cout << dp[n] << "\n";
}
