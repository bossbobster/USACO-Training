#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
using namespace std;
typedef pair<int, int> pii;

ifstream fin("time.in");
ofstream fout("time.out");

int nums[1010];
int dp[1010][1010];
pii e[2010];
int main()
{
    int n, m, c, ans = 0;
    fin >> n >> m >> c;
    for(int i = 0; i < n; i ++)
        fin >> nums[i];
    for(int i = 0; i < m; i ++)
        fin >> e[i].first >> e[i].second;
    for(int i = 0; i < 1005; i ++)
        for(int j = 1; j <= n; j ++)
            dp[i][j] = -2000000000;
    dp[0][1] = 0;
    for(int i = 1; i < 1005; i ++)
        for(int j = 0; j < m; j ++)
        {
            if(dp[i - 1][e[j].first] >= 0)
                dp[i][e[j].second] = max(dp[i][e[j].second], dp[i - 1][e[j].first] + nums[e[j].second - 1]);
        }
    for(int i = 0; i < 1005; i ++)
        if(dp[i][1] != -2000000000)
            ans = max(ans, dp[i][1] - i * i * c);
    fout << ans << "\n";
}
