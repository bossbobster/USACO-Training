//do a Kruskal's, and every time you connect two components,
//check to see if the new size is >= T. If it is, then the answer
//for all of the starting points in that component is at most
//the current edge weight.
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

struct edge
{
    ll d; int r1, c1, r2, c2;
    const bool operator<(const edge& other) const
    {
        return d < other.d;
    }
};
int n, m, t;
int board[510][510];
bitset<510> star[510];
bitset<510> vis[510];
vector<edge> all;
ll ans = 0, dd = 0;
struct dsu
{
    int par[250010];
    int size[250010];
    vector<pii> stars[250010];
    // constructor
    dsu(int s)
    {
        for(int i = 0; i <= s; i ++)
        {
            par[i] = i; size[i] = 1;
            if(star[i/m][i%m])
                stars[i].push_back({i/m, i%m});
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
        if(stars[n].size() < stars[m].size())
            swap(n, m);
        par[m] = n;
        size[n] += size[m];
        for(auto it : stars[m])
            stars[n].push_back(it);
        if(size[n] >= t)
            ans += dd * stars[n].size(), stars[n].clear();
    }
};
int main()
{
    input();
    int num;
    cin >> n >> m >> t;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            cin >> board[i][j];
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            cin >> num, star[i][j] = num;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
        {
            if(i+1 < n) all.push_back({abs(board[i][j]-board[i+1][j]), i, j, i+1, j});
            if(j+1 < m) all.push_back({abs(board[i][j]-board[i][j+1]), i, j, i, j+1});
        }
    sort(all.begin(), all.end());
    dsu d = dsu(n*m+5);
    for(auto cur : all)
    {
        int co1 = cur.r1*m+cur.c1, co2 = cur.r2*m+cur.c2;
        dd = cur.d;
        d.un(co1, co2);
    }
    cout << ans << '\n';
}
