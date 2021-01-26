#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
using namespace std;
typedef pair<int, int> pii;
#define max(n, m) ((n>m)?n:m)

ifstream fin("snakes.in");
ofstream fout("snakes.out");

long long pre[410][410];
long long nums[410];
void sparse(int n)
{
    for(int i = 0; i < n; i ++)
        pre[i][0] = nums[i];
    for(int i = 1; i <= floor(log2(n)); i ++)
        for(int j = 0; j <= n - (1 << i); j ++)
            pre[j][i] = max(pre[j][i - 1], pre[j + (1 << (i - 1))][i - 1]);
}

long long maxQ(int l, int r)
{
    int log = floor(log2(r - l + 1));
    return max(pre[l][log], pre[r - (1 << log) + 1][log]);
}
long long sum[410];
long long dp[410][410];
int main()
{
    long long n, m, tmp, maxN = 0;
    fin >> n >> m;
    for(int i = 0; i < n; i ++)
        fin >> nums[i];
    sparse((int)n);
    sum[0] = 0;
    for(int i = 1; i <= n; i ++)
        sum[i] = sum[i - 1] + nums[i - 1];
    for(int i = 0; i <= n; i ++)
        for(int j = 0; j <= n; j ++)
            dp[i][j] = 2000000000;
    for(int i = 1; i <= n; i ++)
    {
        maxN = max(maxN, nums[i - 1]);
        dp[i][0] = maxN * i;
        for(int k = 1; k <= m; k ++)
            for(int j = i - 1; j >= 0; j --)
            {
                tmp = maxQ(j, i - 1) * (i - j);
                dp[i][k] = min(dp[i][k], dp[j][k - 1] + tmp);
            }
    }
    fout << dp[n][m] - sum[n] << "\n";
}
