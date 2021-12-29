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

int n, k, a, b, root, ans = 0, curK;
vector<int> adj[100010];
int sz[100010], leaf[100010];
bool done = false, alr = false;
void dfsCent(int cur, int par)
{
    if(done) return;
    bool good = true;
    for(auto it : adj[cur])
    {
        if(done) return;
        if(it == par) continue;
        dfsCent(it, cur);
        sz[cur] += sz[it];
        if(sz[it] > n/2) good = false;
    }
    sz[cur] ++;
    if(n - sz[cur] > n/2) good = false;
    if(good)
        root = cur, done = true;
}
void dfs(int cur, int par)
{
    if(adj[cur].size() == 1) { leaf[cur] ++; return; }
    for(auto it : adj[cur])
    {
        if(it == par) continue;
        dfs(it, cur);
    }
    alr = false; curK = k;
    for(auto it : adj[cur])
    {
        if(it == par) continue;
        if(leaf[it] && curK)
        {
            if(alr) ans ++, curK --;
            alr = !alr;
        }
    }
    if(curK && alr)
        leaf[cur] ++;
}
int main()
{
    cin >> n >> k;
    for(int i = 0; i < n-1; i ++)
    {
        cin >> a >> b; a--; b--;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    if(n == 1) { cout << "0\n"; return 0; }
    if(n == 2) { cout << "1\n"; return 0; }
    dfsCent(0, -1);
    dfs(root, -1);
    cout << ans << '\n';
}
