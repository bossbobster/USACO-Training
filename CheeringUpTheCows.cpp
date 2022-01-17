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

struct dsu
{
    // parent array
    int par[100010];
    // size array
    int size[100010];
    // constructor
    dsu(int s)
    {
        for(int i = 0; i <= s; i ++)
        {
            par[i] = i; size[i] = 1;
        }
    }
    // find root of n
    int root(int n)
    {
        if(par[n] == n || par[n] == -1)
            return n;
        return par[n] = root(par[n]);
    }
    // return true if n and m are in the same CC
    bool con(int n, int m)
    {
        return (root(n) == root(m));
    }
    // connect n and m
    void un(int n, int m)
    {
        n = root(n); m = root(m);
        if(n == m) return;
        if(size[n] < size[m])
            swap(n, m);
        par[m] = n;
        size[n] += size[m];
    }
};

int cost[100010];
struct edge
{
    int a, b, c;
    const bool operator<(const edge& other) const
    {
        return (cost[a]+cost[b]+2*c) < (cost[other.a]+cost[other.b]+2*other.c);
    }
};
vector<edge> edges;
int main()
{
    input();
    int n, m, a, b, c, ans = 2000000000;
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        cin >> cost[i], ans = min(ans, cost[i]);
    for(int i = 0; i < m; i ++)
    {
        cin >> a >> b >> c; a--; b--;
        edges.push_back({a, b, c});
    }
    sort(edges.begin(), edges.end());
    dsu d = dsu(n+5);
    for(auto cur : edges)
        if(!d.con(cur.a, cur.b))
        {
            d.un(cur.a, cur.b);
            ans += cost[cur.a]+cost[cur.b]+2*cur.c;
        }
    cout << ans << '\n';
}
