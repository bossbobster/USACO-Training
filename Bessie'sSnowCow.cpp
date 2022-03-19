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

ifstream fin("snowcow.in");
ofstream fout("snowcow.out");

vector<int> adj[100010];
int n, q, i, j;
ll ans = 0;
int seg[1000010];
int lazy[1000010];
int arr[1000010];
void updateRec(int node, int l, int r, int lq, int rq, int val)
{
    if(lazy[node])
    {
        seg[node] += lazy[node] * (r-l+1);
        if(l != r)
        {
            lazy[node*2+1] += lazy[node];
            lazy[node*2+2] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(l > rq || r < lq || l > r) return;
    if(l >= lq && r <= rq)
    {
        seg[node] += val * (r-l+1);
        if(l != r)
        {
            lazy[node*2+1] += val;
            lazy[node*2+2] += val;
        }
        return;
    }
    int mid = (l+r)/2;
    updateRec(node*2+1, l, mid, lq, rq, val); updateRec(node*2+2, mid+1, r, lq, rq, val);
    seg[node] = seg[node*2+1] + seg[node*2+2];
}
void update(int lq, int rq, int val, int n) { updateRec(0, 0, n-1, lq, rq, val); }
int sumRec(int node, int l, int r, int lq, int rq)
{
    if(lazy[node])
    {
        seg[node] += lazy[node] * (r-l+1);
        if(l != r)
        {
            lazy[node*2+1] += lazy[node];
            lazy[node*2+2] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(l > rq || r < lq || l > r) return 0;
    if(l >= lq && r <= rq)
        return seg[node];
    int mid = (l+r)/2;
    return sumRec(node*2+1, l, mid, lq, rq) + sumRec(node*2+2, mid+1, r, lq, rq);
}
int sum(int lq, int rq, int n) { return sumRec(0, 0, n-1, lq, rq); }
int cnt = 0;
pii endpts[100010];
int sz[100010];
void euler(int cur, int par)
{
    endpts[cur].first = cnt ++;
    for(int i = 0; i < adj[cur].size(); i ++)
        if(adj[cur][i] != par)
            euler(adj[cur][i], cur), sz[cur] += sz[adj[cur][i]];
    endpts[cur].second = cnt - 1;
    sz[cur] ++;
}
struct query
{
    int type, a, b;
};
query qs[100010];
set<pii> upd[100010];
bitset<100010> bad;
int main()
{
    input();
    fin >> n >> q;
    int a, b;
    for(int i = 0; i < n-1; i ++)
        fin >> a >> b, a--, b--, adj[a].push_back(b), adj[b].push_back(a);
    for(int i = 0; i < q; i ++)
    {
        fin >> qs[i].type >> qs[i].a; qs[i].a --;
        if(qs[i].type == 1) fin >> qs[i].b;
    }
    euler(0, -1);
    for(int i = q-1; i >= 0; i --)
        if(qs[i].type == 1)
        {
            set<pii>::iterator it1 = upd[qs[i].b].lower_bound({endpts[qs[i].a].f, 0}), it2 = upd[qs[i].b].upper_bound({endpts[qs[i].a].s, 1000000000});
            for(set<pii>::iterator it = it1; it != it2 && !upd[qs[i].b].empty();)
            {
                set<pii>::iterator nx = next(it);
                bad[it->s] = 1;
                upd[qs[i].b].erase(it);
                it = nx;
            }
            upd[qs[i].b].insert({endpts[qs[i].a].f, i});
        }
    for(int i = 0; i <= 100000; i ++)
        upd[i].clear();
    for(int i = 0; i < q; i ++)
    {
        if(qs[i].type == 1)
        {
            if(bad[i]) continue;
            set<pii>::iterator it1 = upd[qs[i].b].lower_bound({endpts[qs[i].a].f, 0}), it2 = upd[qs[i].b].upper_bound({endpts[qs[i].a].s, 1000000000});
            for(set<pii>::iterator it = it1; it != it2 && !upd[qs[i].b].empty();)
            {
                set<pii>::iterator nx = next(it);
                update(endpts[qs[it->s].a].f, endpts[qs[it->s].a].s, -1, n), upd[qs[i].b].erase(it);
                it = nx;
            }
            update(endpts[qs[i].a].f, endpts[qs[i].a].s, 1, n);
            upd[qs[i].b].insert({endpts[qs[i].a].f, i});
        }
        else
            fout << sum(endpts[qs[i].a].f, endpts[qs[i].a].s, n) << '\n';
    }
}
