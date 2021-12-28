#include <iostream>
#include <string.h>
#include <random>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <complex>
#include <valarray>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
//template <class T> using Tree = tree<T, null_type, less<T>,
//rb_tree_tag, tree_order_statistics_node_update>;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, string> pss;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef pair<float, float> pff;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<pll, ld> plld;
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
typedef pair<ld, ld> pld;
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ifstream fin("yinyang.in");
ofstream fout("yinyang.out");

int n, a, b, c, root;
int sz[100010];
vector<pii> adj[100010];
int p[100010];
bitset<100010> vis;
int dfs1(int cur, int par)
{
    sz[cur] = 1;
    for(auto nx : adj[cur])
        if(nx.f != par && !vis[nx.f])
            sz[cur] += dfs1(nx.f, cur);
    return sz[cur];
}
int dfs2(int cur, int par, int n)
{
    for(auto nx : adj[cur])
        if(nx.f != par && sz[nx.f] > n/2 && !vis[nx.f])
            return dfs2(nx.f, cur, n);
    return cur;
}
int mx;
ll ans = 0, sub;
gp_hash_table<int, ll> cnt, cnt2, allcnt, bef;
void dfs25(int cur, int par, int num)
{
    allcnt[num] ++;
    for(auto nx : adj[cur])
        if(nx.f != par && !vis[nx.f])
            dfs25(nx.f, cur, num+nx.s);
}
void dfsB(int cur, int par, int num)
{
    bef[num] ++;
    for(auto nx : adj[cur])
        if(nx.f != par && !vis[nx.f])
            dfsB(nx.f, cur, num+nx.s);
}
void dfs3(int cur, int par, int num)
{
    if(!num)
        ans += cnt[0]+min(1LL, cnt2[0]);
    else
        if(cnt2[num])
        {
            ans += allcnt[-num]-bef[-num], allcnt[num]--, bef[num]--;
        }
    cnt2[num] ++;
    for(auto nx : adj[cur])
        if(nx.f != par && !vis[nx.f])
            dfs3(nx.f, cur, num+nx.s);
    cnt2[num] --;
}
void dfs4(int cur, int par, int num)
{
    cnt[num] ++;
    for(auto nx : adj[cur])
        if(nx.f != par && !vis[nx.f])
            dfs4(nx.f, cur, num+nx.s);
}
void make(int cur, int par)
{
    int cent = dfs2(cur, par, dfs1(cur, par));
    vis[cent] = 1;
    mx = 0;
    for(auto it : adj[cent])
        if(!vis[it.f])
            dfs25(it.f, cent, it.s);
    for(auto it : adj[cent])
        if(!vis[it.f])
            dfsB(it.f, cent, it.s), dfs3(it.f, cent, it.s), dfs4(it.f, cent, it.s), bef.clear(), cnt2.clear();
    allcnt.clear(); cnt.clear(); cnt2.clear();
    for(auto it : adj[cent])
        if(!vis[it.f])
            make(it.f, cent);
}
int main()
{
    input();
    fin >> n;
    for(int i = 0; i < n-1; i ++)
    {
        fin >> a >> b >> c; a--; b--;
        if(c == 0) c = -1;
        adj[a].push_back({b, c}); adj[b].push_back({a, c});
    }
    make(0, -1);
    fout << ans << '\n';
    return 0;
}
