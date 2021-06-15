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
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
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
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);

ifstream fin("maxflow.in");
ofstream fout("maxflow.out");

int n, k;
int arr[100010], dep[100010], idx[100010];
int dif[100010], ans[100010];
vector<int> adj[100010];
int pars[100010];
int cnt = 0;
void euler(int cur, int par, int d)
{
    pars[cur] = par;
    dep[cnt] = d;
    arr[cnt] = cur;
    idx[cur] = cnt++;
    for(auto it : adj[cur])
        if(it != par)
        {
            euler(it, cur, d+1);
            dep[cnt] = d;
            arr[cnt++] = cur;
        }
}
pii pre[100010][25];
void sparse(int n)
{
    for(int i = 0; i < n; i ++)
        pre[i][0] = {dep[i], i};
    for(int i = 1; i <= floor(log2(n)); i ++)
        for(int j = 0; j <= n - (1 << i); j ++)
            pre[j][i] = min(pre[j][i - 1], pre[j + (1 << (i - 1))][i - 1]);
    
}
int minQ(int l, int r)
{
    int log = floor(log2(r - l + 1));
    if(pre[l][log].f < pre[r-(1<<log)+1][log].f) return arr[pre[l][log].s];
    return arr[pre[r-(1<<log)+1][log].s];
}
void dfs(int cur, int par)
{
    ans[cur] = dif[cur];
    for(auto it : adj[cur])
    {
        if(it == par) continue;
        dfs(it, cur);
        ans[cur] += ans[it];
    }
}
int main()
{
    input();
    int a, b, lca, ansans = 0;
    fin >> n >> k;
    for(int i = 0; i < n-1; i ++)
    {
        fin >> a >> b; a--; b--;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    euler(0, -1, 0);
    sparse(2*n);
    while(k--)
    {
        fin >> a >> b; a--; b--;
        if(idx[a] > idx[b]) swap(a, b);
        lca = minQ(idx[a], idx[b]);
        dif[a] ++; dif[b] ++; dif[lca] --;
        if(pars[lca] != -1) dif[pars[lca]] --;
    }
    dfs(0, -1);
    for(int i = 0; i < n; i ++)
        ansans = max(ansans, ans[i]);
    fout << ansans << "\n";
}
