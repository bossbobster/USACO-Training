#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <stack>
using namespace std;
typedef pair<int, int> pii;
#define max(n, m) ((n>m)?n:m)
#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

int nums[110];
int dp[110][110];
int pre[110];
int sum(int a, int b)
{
    return pre[b + 1] - pre[a];
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> nums[i];
        pre[i + 1] = pre[i] + nums[i];
    }
    for(int i = 0; i < n; i ++)
        dp[i][1] = nums[i];
    for(int i = 2; i <= n; i ++)
        for(int j = 0; j < n - i + 1; j ++)
            dp[j][i] = sum(j, j + i - 1) - min(dp[j][i - 1], dp[j + 1][i - 1]);
    cout << dp[0][n] << " " << pre[n] - dp[0][n] << "\n";
}
