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
#include <array>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <complex>
#include <valarray>
#include <memory>
#include <cassert>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<pis, string> piss;
typedef pair<int, short> pish;
typedef pair<string, string> pss;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef pair<double, int> pdi;
typedef pair<float, float> pff;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef pair<uint, uint> puint;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> plll;
typedef pair<pll, ld> plld;
typedef pair<ld, int> pldi;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ull, ull> pull;
typedef pair<ld, ld> pld;
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//#define eps 1e-8
//#define eps2 1e-15
#define leni(x) sizeof(x)/sizeof(int)
#define v(i,j,k) for(i=j;i<k;i++)
//#define cin fin
//#define cout fout
#pragma GCC optimize("O1,O2,O3,Ofast,unroll-loops")

vector<int> adj[200010];
int p[200010];
ll dp[200010][2], sz[200010];
void dfs1(int cur)
{
    for(auto it : adj[cur])
    {
        dfs1(it);
        sz[cur] += sz[it];
    }
    sz[cur] ++;
}
void dfs2(int cur)
{
    if(adj[cur].empty())
        return;
    int mx = 0, mx2 = 0, mx3 = 0;
    ll tot = 0;
    for(auto it : adj[cur])
    {
        dfs2(it);
        if(sz[it] > mx) mx = sz[it];
        if(dp[it][1]-dp[it][0]+sz[it] >= mx2) mx3 = mx2, mx2 = dp[it][1]-dp[it][0]+sz[it];
        else if(dp[it][1]-dp[it][0]+sz[it] >= mx3) mx3 = dp[it][1]-dp[it][0]+sz[it];
        tot += sz[it]+dp[it][1];
    }
    dp[cur][1] = min(tot-mx2-mx3, tot-mx);
    dp[cur][0] = tot-mx2;
}
int main()
{
    input();
    int n, pp;
    cin >> n;
    for(int i = 1; i < n; i ++)
    {
        cin >> pp; pp--;
        p[i] = pp;
        adj[pp].push_back(i);
    }
    p[0] = -1;
    dfs1(0);
    dfs2(0);
    cout << (dp[0][1]+sz[0])*2 << '\n';
}
