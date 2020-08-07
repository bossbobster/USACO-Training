#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("taming.in");
ofstream fout("taming.out");

int cows[110];
int dp[110][110][110];
int main()
{
    int n, ans;
    fin >> n;
    for(int i = 0; i < n; i ++)
        fin >> cows[i];
    for(int i = 0; i <= n; i ++)
        for(int j = 0; j <= n; j ++)
            for(int k = 0; k <= n; k ++)
                dp[i][j][k] = 2000000000;
    dp[1][0][0] = (cows[0]==0?0:1);
    for(int i = 1; i < n; i ++)
        for(int j = 0; j < n; j ++)
            for(int k = 0; k < n; k ++)
            {
                dp[i + 1][0][k + 1] = min(dp[i + 1][0][k + 1], dp[i][j][k] + (cows[i]==0?0:1));
                dp[i + 1][j + 1][k] = min(dp[i + 1][j + 1][k], dp[i][j][k] + (cows[i]==(j + 1)?0:1));
            }
    for(int i = 0; i < n; i ++)
    {
        ans = 2000000000;
        for(int j = 0; j < n; j ++)
            ans = min(ans, dp[n][j][i]);
        fout << ans << "\n";
    }
}
