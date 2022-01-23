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

int n, q;
int lca[100010][19];
int dep[100010];
vector<int> adj[100010];
int LCA(int a, int b)
{
    if(dep[b] > dep[a]) swap(a, b);
    for(int i = 18; i >= 0; i --)
        if(dep[a] - (1 << i) >= dep[b])
            a = lca[a][i];
    for(int i = 18; i >= 0; i --)
        if(lca[a][i] != lca[b][i])
        {
            a = lca[a][i]; b = lca[b][i];
        }
    if(a != b)
        a = lca[a][0];
    return a;
}
void dfs(int cur, int par, int d)
{
    dep[cur] = d;
    for(int other : adj[cur])
    {
        if(other == par) continue;
        lca[other][0] = cur;
        dfs(other, cur, d+1);
    }
}
int main()
{
    input();
    int a, b;
    cin >> n >> q;
    for(int i = 0; i < n-1; i ++)
    {
        cin >> a >> b; a--; b--;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    dfs(0, -1, 0);
    for(int i = 1; i < 19; i ++)
        for(int j = 0; j < n; j ++)
            lca[j][i] = lca[lca[j][i - 1]][i - 1];
    while(q--)
    {
        cin >> a >> b; a--; b--;
        cout << dep[a] + dep[b] - dep[LCA(a, b)]*2 << "\n";
    }
}
