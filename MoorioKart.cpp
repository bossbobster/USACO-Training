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
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<int, short> pish;
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
typedef pair<pll, ll> plll;
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
#define eps 1e-9
//#define cin fin

ifstream fin("mooriokart.in");
ofstream fout("mooriokart.out");

vector<pll> adj[2510];
const ll mod = 1000000007;
pll dp[2][2510];
unordered_map<ll, pll> sums[1260];
ll cc[2510];
ll curCC = 0;
queue<pll> q;
ll exp(ll base, ll power)
{
    ll ans = 1;
    while(power)
    {
        if(power&1) ans = (ans * base) % mod;
        base = (base * base) % mod;
        power /= 2;
    }
    return ans;
}
bitset<2510> vis;
int main()
{
    input();
    ll n, m, a, b, c, cur;
    ll x, y, curD;
    fin >> n >> m >> x >> y;
    for(ll i = 0; i < m; i ++)
    {
        fin >> a >> b >> c; a--; b--;
        adj[a].push_back({b, c}); adj[b].push_back({a, c});
    }
    for(ll i = 0; i < n; i ++)
    {
        if(cc[i]) continue;
        curCC ++;
        q.push({i, 0});
        while(!q.empty())
        {
            cur = q.front().f;
            q.pop();
            if(cc[cur]) continue;
            cc[cur] = curCC;
            for(auto it : adj[cur])
                q.push({it.f, 0});
        }
    }
    ll k = (ll)(n-1-m+1);
    for(ll i = 0; i < n; i ++)
    {
        q.push({i, 0});
        vis.reset();
        while(!q.empty())
        {
            cur = q.front().f; curD = q.front().s;
            q.pop();
            if(vis[cur]) continue;
            vis[cur] = 1;
            if(cur != i)
            {
                sums[cc[cur]][min(y, curD)].f = (sums[cc[cur]][min(y, curD)].f + curD) % mod;
                sums[cc[cur]][min(y, curD)].s = (sums[cc[cur]][min(y, curD)].s + 1) % mod;
            }
            for(auto it : adj[cur])
                q.push({it.f, (curD+it.s)%mod});
        }
    }
    ll div2 = exp(2, mod-2);
    for(ll i = 1; i <= curCC; i ++)
        for(auto it : sums[i])
            sums[i][it.f].f = (sums[i][it.f].f * div2) % mod, sums[i][it.f].s = (sums[i][it.f].s * div2) % mod;
    for(int j = 0; j <= y; j ++)
        dp[0][j] = {-1, -1};
    dp[0][min(y, x*k)] = {x*k, 1};
    for(ll i = 1; i <= curCC; i ++)
    {
        for(int j = 0; j <= y; j ++)
            dp[i%2][j] = {-1, -1};
        ll mn = 2000000000000;
        for(ll j = y; j >= 0; j --)
            if(dp[(i+1)%2][j].f != -1)
                for(auto it : sums[i])
                {
                    ll idx = min(y, j+it.f);
                    if(dp[i%2][idx].f == -1 || dp[i%2][idx].s == -1)
                        dp[i%2][idx] = {0, 0};
                    dp[i%2][idx].f = (dp[i%2][idx].f + (dp[(i+1)%2][j].f*it.s.s)%mod + (it.s.f*dp[(i+1)%2][j].s)%mod) % mod;
                    dp[i%2][idx].s = (dp[i%2][idx].s + dp[(i+1)%2][j].s*it.s.s) % mod;
                    mn = min(mn, it.f);
                }
    }
    ll fac = 1;
    for(ll i = 2; i <= 2*k-2; i += 2)
        fac = (fac * i) % mod;
    if(dp[curCC%2][y].f < 0) fout << "0\n";
    else fout << (dp[curCC%2][y].f*fac)%mod << '\n';
}
