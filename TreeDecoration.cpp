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

ll n, a, ans = 0;
ll cnt[100010], mn[100010], cost[100010], req[100010];
vector<int> adj[100010];
void dfs(int cur, int par)
{
    for(auto it : adj[cur])
        if(it != par)
        {
            dfs(it, cur);
            mn[cur] = min(mn[cur], mn[it]);
            cnt[cur] += cnt[it];
        }
    mn[cur] = min(mn[cur], cost[cur]);
    if(req[cur] > cnt[cur])
    {
        ans += mn[cur]*(req[cur]-cnt[cur]);
        cnt[cur] = req[cur];
    }
}
int main()
{
    input();
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> a >> req[i] >> cost[i];
        if(a != -1) adj[a-1].push_back(i);
        mn[i] = 2000000000;
    }
    dfs(0, -1);
    cout << ans << '\n';
}
