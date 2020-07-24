#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>
using namespace std;

ifstream fin("feast.in");
ofstream fout("feast.out");

bool dp[5000010][2];
bool f[5000010];
int main()
{
    int n, a, b;
    fin >> n >> a >> b;
    dp[0][0] = dp[0][1] = true;
    for(int i = 1; i <= n; i ++)
    {
        if(i - a >= 0)
            if(dp[i - a][0])
                dp[i][0] = dp[i / 2][1] = true;
        if(i - b >= 0)
            if(dp[i - b][0])
                dp[i][0] = dp[i / 2][1] = true;
    }
    for(int i = 0; i <= n; i ++)
    {
        if(i - a >= 0)
            if(dp[i - a][1] || f[i - a] || dp[i - a][0])
                f[i] = true;
        if(i - b >= 0)
            if(dp[i - b][1] || f[i - b] || dp[i - b][0])
                f[i] = true;
    }
    for(int i = n; i >= 0; i --)
        if(f[i] || dp[i][0] || dp[i][1])
        {
            fout << i << "\n";
            break;
        }
}
