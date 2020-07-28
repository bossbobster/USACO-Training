// NOT A USACO PROBLEM
#include <iostream>
#include <algorithm>
using namespace std;

int dp[50][2500];
int nums[50];
int main()
{
    int n, sum;
    cin >> n;
    sum = (n * (n + 1)) / 2;
    if(sum % 2 == 1) { cout << 0 << "\n"; return 0; }
    for(int i = 1; i <= n; i ++)
        nums[i - 1] = i;
    dp[0][0] = 1;
    for(int i = 0; i <= n; i ++)
        for(int j = 0; j <= sum; j ++)
        {
            dp[i + 1][j + nums[i]] += dp[i][j];
            dp[i + 1][j] += dp[i][j];
        }
    cout << dp[n - 1][sum / 2] << "\n";
}
