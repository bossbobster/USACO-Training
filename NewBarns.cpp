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

ifstream fin("newbarn.in");
ofstream fout("newbarn.out");

int q, cur = 0;
int par[100010];
vector<int> adj[100010];
int cc[100010], dep[100010];
int lca[100010][20];
pii dim[100010];
int LCA(int a, int b)
{
    if(dep[b] > dep[a]) swap(a, b);
    for(int i = 19; i >= 0; i --)
        if(dep[a] - (1<<i) >= dep[b])
            a = lca[a][i];
    for(int i = 19; i >= 0; i --)
        if(lca[a][i] != lca[b][i])
            a = lca[a][i], b = lca[b][i];
    if(a != b)
        a = lca[a][0];
    return a;
}
int dist(int a, int b)
{
    if(a == -1 || b == -1) return 0;
    return dep[a] + dep[b] - 2*dep[LCA(a, b)];
}
int main()
{
    input();
    fin >> q;
    char c;
    int a, curCC = 1;
    memset(par, -1, sizeof(par)); memset(lca, -1, sizeof(lca));
    for(int i = 0; i < q; i ++)
        dim[i] = {-1,-1};
    while(q--)
    {
        fin >> c >> a;
        if(a > 0) a--;
        if(c == 'B')
        {
            if(a != -1)
            {
                adj[a].push_back(cur);
                cc[cur] = cc[a];
                dep[cur] = dep[a]+1;
                lca[cur][0] = a;
                for(int i = 1; i < 20; i ++)
                    lca[cur][i] = lca[lca[cur][i-1]][i-1];
                if(dist(cur, dim[cc[cur]].f) > dist(dim[cc[cur]].f, dim[cc[cur]].s))
                    dim[cc[cur]].s = cur;
                if(dist(cur, dim[cc[cur]].s) > dist(dim[cc[cur]].f, dim[cc[cur]].s))
                    dim[cc[cur]].f = cur;
            }
            else
            {
                cc[cur] = curCC++;
                dim[cc[cur]].f = cur;
            }
            cur ++;
        }
        else
            fout << max(dist(a, dim[cc[a]].f), dist(a, dim[cc[a]].s)) << '\n';
    }
}
