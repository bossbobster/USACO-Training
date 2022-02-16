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
//template <class T> using Tree = tree<T, null_type, less<T>,
//rb_tree_tag, tree_order_statistics_node_update>;
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
#include "grader.h"

vector<int> adj[100010], dep[100010];
int depth[100010], lca[100010][20], sz[100010], x[100010], y[100010];
int n, q, curX, curY;
bool swapped;
pii LCA(int a, int b)
{
    swapped = false;
    if(depth[b] > depth[a]) swap(a, b), swapped = true;
    for(int i = 19; i >= 0; i --)
        if(depth[a] - (1 << i) >= depth[b])
            a = lca[a][i];
    for(int i = 19; i >= 0; i --)
        if(lca[a][i] != lca[b][i])
            a = lca[a][i], b = lca[b][i];
    if(a != b)
        a = lca[a][0];
    return {a, b};
}
void dfs(int cur, int par)
{
    y[cur] = curY--;
    for(int it : adj[cur])
    {
        if(it == par) continue;
        depth[it] = depth[cur] + 1;
        lca[it][0] = cur;
        dfs(it, cur);
        sz[cur] += sz[it];
    }
    x[cur] = curX++;
    sz[cur]++;
}
void addRoad(int a, int b)
{
    cout << a << ' ' << b << "  ";
    adj[a].push_back(b); adj[b].push_back(a);
}

void buildFarms()
{
    n = getN(); q = getQ();
    cout << n << '\n';
    curX = 1; curY = n;
    dfs(0, -1);
    for(int i = 1; i < 20; i ++)
        for(int j = 0; j < n; j ++)
            lca[j][i] = lca[lca[j][i - 1]][i - 1];
    for(int i = 0; i < n; i ++)
        setFarmLocation(i, x[i], y[i]);
}

void notifyFJ(int a, int b)
{
    pii lc = LCA(a, b);
    if(lc.f == a)
        addBox(x[b], y[b], x[a], y[a]);
    else if(lc.f == b)
        addBox(x[a], y[a], x[b], y[b]);
    else
    {
        if(swapped) swap(a, b);
        addBox(x[a], y[a], x[lc.f], y[lc.f]);
        addBox(x[b], y[b], x[lc.s], y[lc.s]);
    }
}
