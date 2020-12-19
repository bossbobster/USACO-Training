#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
using namespace std;

ifstream fin("teamwork.in");
ofstream fout("teamwork.out");

int pre[10010][35];
int nums[10010];
void sparse(int n)
{
    for(int i = 0; i < n; i ++)
        pre[i][0] = nums[i];
    for(int i = 1; i <= floor(log2(n)); i ++)
        for(int j = 0; j <= n - (1 << i); j ++)
            pre[j][i] = max(pre[j][i - 1], pre[j + (1 << (i - 1))][i - 1]);
}
int maxQ(int l, int r)
{
    int log = floor(log2(r - l + 1));
    return max(pre[l][log], pre[r - (1 << log) + 1][log]);
}

int dp[10010][1010];
int maxs[10010];
int main()
{
    int n, k;
    fin >> n >> k;
    for(int i = 0; i < n; i ++)
        fin >> nums[i];
    sparse(n);
    dp[0][0] = nums[0];
    maxs[0] = nums[0];
    for(int i = 1; i < n; i ++)
        for(int j = 0; j < min(i + 1, k); j ++)
        {
            dp[i][j] = maxs[i - j - 1] + (maxQ(i - j, i) * (j + 1));
            maxs[i] = max(maxs[i], dp[i][j]);
        }
    fout << maxs[n - 1] << "\n";
}
