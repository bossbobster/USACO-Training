//count number of components which are strongly connected.
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
//ifstream fin("/Users/bobby/prob1_platinum_feb21/20.in");

vector<int> adj[10010];
vector<int> rev[10010];
vector<int> bi[10010];
int scc[10010], cc[10010];
set<int> sccs[10010], ccs[10010];
stack<int> ord;
int curCC = 1, curCC2 = 0;
bitset<10010> visited;
queue<int> q;
void dfs1(int cur)
{
    visited[cur] = true;
    for(auto it : adj[cur])
    {
        if(visited[it]) continue;
        dfs1(it);
    }
    ord.push(cur);
}
void dfs2(int cur)
{
    scc[cur] = curCC;
    for(auto it : rev[cur])
    {
        if(scc[it]) continue;
        dfs2(it);
    }
}
int main()
{
    int n, m, a, b;
    int ans = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        cin >> a >> b; a--; b--;
        adj[a].push_back(b); rev[b].push_back(a);
        bi[a].push_back(b); bi[b].push_back(a);
    }
    for(int i = 0; i < n; i ++)
        if(!visited[i])
            dfs1(i);
    while(!ord.empty())
    {
        if(!scc[ord.top()])
        {
            dfs2(ord.top());
            curCC ++;
        }
        ord.pop();
    }
    for(int i = 0; i < n; i ++)
        sccs[scc[i]].insert(i);
    visited.reset();
    for(int i = 0; i < n; i ++)
    {
        if(visited[i]) continue;
        curCC2 ++;
        q.push(i);
        while(!q.empty())
        {
            a = q.front();
            q.pop();
            if(visited[a]) continue;
            cc[a] = curCC2;
            visited[a] = 1;
            ccs[curCC2].insert(a);
            for(auto it : bi[a])
                q.push(it);
        }
    }
    visited.reset();
    for(int i = 0; i < n; i ++)
    {
        if(visited[i]) continue;
        if(sccs[scc[i]] == ccs[cc[i]] && sccs[scc[i]].size() != 1)
            ans ++;
        visited[i] = 1;
        for(auto it : sccs[scc[i]])
            visited[it] = 1;
        for(auto it : ccs[cc[i]])
            visited[it] = 1;
    }
    cout << ans << '\n';
}
