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

struct dsu
{
    int par[200010];
    int sz[200010];
    dsu(int szz)
    {
        for(int i = 0; i <= szz; i ++)
            par[i] = i, sz[i] = 1;
    }
    int root(int n)
    {
        if(par[n] == n || par[n] == -1)
            return n;
        return par[n] = root(par[n]);
    }
    void un(int n, int m)
    {
        n = root(n); m = root(m);
        if(n == m) return;
        if(sz[n] < sz[m])
            swap(n, m);
        par[m] = n;
        sz[n] += sz[m];
    }
};

vector<int> adj[200010];
unordered_set<int>* all[200010];
int main()
{
    input();
    int n, m, a, b;
    cin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        cin >> a >> b; a--; b--;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    ll ans = 0;
    dsu d = dsu(n);
    for(int i = 0; i < n; i ++)
    {
        int mx = -1;
        for(auto it : adj[i])
            if(it < i)
                if(mx == -1 || all[d.root(it)]->size() > all[mx]->size())
                    mx = d.root(it);
        int ii = d.root(i);
        if(mx == -1)
            all[ii] = new unordered_set<int>;
        else
            all[ii] = all[mx];
        for(auto it : adj[i])
        {
            if(it < i)
            {
                if(d.root(it) != mx)
                    for(auto it2 : *all[d.root(it)])
                        all[ii]->insert(it2);
            }
            else
                all[ii]->insert(it);
        }
        for(auto it : adj[i])
            if(it < i)
                d.un(i, it);
        all[ii]->erase(i);
        ans += all[ii]->size();
        all[d.root(i)] = all[ii];
    }
    cout << ans-m << '\n';
}
