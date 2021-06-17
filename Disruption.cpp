#include <iostream>
#include <string.h>
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
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);

ifstream fin("disrupt.in");
ofstream fout("disrupt.out");

struct chash
{
    const uint64_t C = ll(2e18*(3.14))+71;
    const int RANDOM = rand();
    ll operator()(ll x) const
    {
        return __builtin_bswap64((x^RANDOM)*C);
    }
};
struct st
{
    int a, b, c;
    const bool operator<(const st& other) const
    {
        return c < other.c;
    }
};

int n, m, a, b, mx;
vector<pii> adj[50010];
vector<st> path[50010];
gp_hash_table<int, null_type, chash>* l[50010];
set<st>* c[50010];
multimap<int, st>* q[50010];
int ans[50010];
st paths[50010];
vector<multimap<int, st>::iterator> v;
void dfs(int cur, int par, int idx)
{
    for(auto it : adj[cur])
    {
        if(it.f == par) continue;
        dfs(it.f, cur, it.s);
    }
    if(cur == 0) return;
    if(cur == 42 || cur == 221)
        cout << "hi";
    if(adj[cur].size() == 1 && cur != 0) { c[cur] = new set<st>; l[cur] = new gp_hash_table<int, null_type, chash>; q[cur] = new multimap<int, st>; }
    else
    {
        mx = -1;
        for(auto it : adj[cur])
        {
            if(it.f == par) continue;
            if(mx == -1) mx = it.f;
            if(l[it.f]->size() > l[mx]->size())
                mx = it.f;
        }
        l[cur] = l[mx]; c[cur] = c[mx]; q[cur] = q[mx];
        for(auto it : adj[cur])
            if(it.f != par && it.f != mx)
            {
                for(auto a : *c[it.f])
                    c[cur]->insert(a);
                for(auto a : *q[it.f])
                    q[cur]->insert(a);
                for(auto a : *l[it.f])
                {
                    if(q[cur]->find(a) != q[cur]->end())
                        for(auto it = q[cur]->equal_range(a).f; it != q[cur]->equal_range(a).s; ++it)
                            if(c[cur]->find(it->s) != c[cur]->end())
                            {
                                c[cur]->erase(it->s);
                                v.push_back(it);
                            }
                    l[cur]->insert(a);
                }
            }
    }
    l[cur]->insert(cur); v.clear();
    if(q[cur]->find(cur) != q[cur]->end())
        for(auto it = q[cur]->equal_range(cur).f; it != q[cur]->equal_range(cur).s; ++it)
            if(c[cur]->find(it->s) != c[cur]->end())
            {
                c[cur]->erase(it->s);
                v.push_back(it);
            }
    for(int i = 0; i < v.size(); i ++)
        q[cur]->erase(v[i]);
    for(auto it : path[cur])
    {
        if(it.b == cur) { if(l[cur]->find(it.a) == l[cur]->end()) {c[cur]->insert(it);q[cur]->insert({it.a, it});} }
        else { if(l[cur]->find(it.b) == l[cur]->end()) {c[cur]->insert(it);q[cur]->insert({it.b,it});} }
    }
    if(c[cur]->empty()) ans[idx] = -1;
    else ans[idx] = (*c[cur]->begin()).c;
}
int main()
{
    fin >> n >> m;
    for(int i = 0; i < n-1; i ++)
    {
        fin >> a >> b; a--; b--;
        adj[a].push_back({b, i}); adj[b].push_back({a, i});
    }
    for(int i = 0; i < m; i ++)
    {
        fin >> paths[i].a >> paths[i].b >> paths[i].c;
        paths[i].a--; paths[i].b--;
        path[paths[i].a].push_back(paths[i]); path[paths[i].b].push_back(paths[i]);
    }
    dfs(0, -1, -1);
    for(int i = 0; i < n-1; i ++)
        fout << ans[i] << "\n";
}
