#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define max(n, m) ((n>m)?n:m)
#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

ifstream fin("dirtraverse.in");
ofstream fout("dirtraverse.out");

int n, m, tmp; long long total = 0;
long long ans = 2000000000000000000;
int len[100010];
vector<int> adj[100010];
long long cnt[100010];
long long dp[100010];
long long dp2[100010];
void dfs1(int cur, int par)
{
    for(int other : adj[cur])
    {
        if(other == par) continue;
        dfs1(other, cur);
        dp[cur] += dp[other] + (len[other] + ((adj[other].size()==0)?0:1)) * cnt[other];
        cnt[cur] += cnt[other];
    }
}
void dfs2(int cur, int par)
{
    for(int other : adj[cur])
    {
        if(other == par) continue;
        dp2[other] += dp2[cur] + (total - cnt[other]) * 3 - (len[other] + 1) * cnt[other];
        dfs2(other, cur);
    }
}
int main()
{
    fin >> n;
    string st;
    for(int i = 0; i < n; i ++)
    {
        fin >> st;
        len[i] = (int)st.length();
        fin >> m;
        for(int j = 0; j < m; j ++)
        {
            fin >> tmp;
            adj[i].push_back(tmp - 1);
        }
        if(m == 0) { cnt[i] = 1; total ++; }
    }
    dfs1(0, -1);
    dp2[0] = dp[0];
    dfs2(0, -1);
    for(int i = 0; i < n; i ++)
        if(adj[i].size())
            ans = min(ans, dp2[i]);
    fout << ans << "\n";
}
