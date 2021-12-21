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
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
typedef pair<ld, ld> pld;
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int sz[100010];
set<int> adj[100010];
vector<int> tree[100010];
int p[100010];
int dfs1(int cur, int par)
{
    sz[cur] = 1;
    for(auto nx : adj[cur])
        if(nx != par)
            sz[cur] += dfs1(nx, cur);
    return sz[cur];
}
int dfs2(int cur, int par, int n)
{
    for(auto nx : adj[cur])
        if(nx != par && sz[nx] > n/2)
            return dfs2(nx, cur, n);
    return cur;
}
void make(int cur, int par)
{
    int cent = dfs2(cur, par, dfs1(cur, par));
    if(par == -1) par = cent;
    p[cent] = par;
    if(par != cent) tree[par].push_back(cent);
    while(!adj[cent].empty())
    {
        int nx = *adj[cent].begin();
        adj[cent].erase(nx), adj[nx].erase(cent), make(nx, cent);
    }
}

int main()
{
    input();
    int n, a, b;
    cin >> n;
    for(int i = 0; i < n-1; i ++)
    {
        cin >> a >> b;
        adj[a].insert(b); adj[b].insert(a);
    }
    make(0, -1);
    return 0;
}
