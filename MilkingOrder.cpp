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
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
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
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int n, k, r, a, b, idx = 0, cur;
bool good;
vector<int> adj[110], adj2[30];
int in[110], og[110], og2[110];
set<int> top;
unordered_map<int, int> m;
queue<int> nextInLine;
ll dp[(1<<20)+10], ans;
bitset<30> vis;
ll fac[110];
bool g(int num)
{
    for(int i = 0; i < top.size(); i ++) in[i] = og[i];
    for(int i = 0; i < top.size(); i ++)
        if(!in[i])
            nextInLine.push(i);
    vis.reset();
    while(!nextInLine.empty())
    {
        cur = nextInLine.front();
        nextInLine.pop();
        if(!((1<<cur) & num)) continue;
        vis[cur] = 1;
        for(auto it : adj2[cur])
        {
            in[it] --;
            if(in[it] == 0)
                nextInLine.push(it);
        }
    }
    for(int i = 0; i < top.size(); i ++)
        if((num & (1<<i)) != (vis[i]<<i))
            return false;
    return true;
}
ll exp(ll base, ll power)
{
    ll ans = 1;
    while(power)
    {
        if(power&1) ans = (ans * base) % r;
        base = (base * base) % r;
        power /= 2;
    }
    return ans;
}
int main()
{
    input();
    cin >> n >> k >> r;
    for(int i = 0; i < k; i ++)
    {
        cin >> a >> b; a--; b--;
        top.insert(a); top.insert(b);
        adj[a].push_back(b); in[b] ++; og2[b] ++;
    }
    for(auto it : top)
        if(!in[it])
            nextInLine.push(it);
    while(!nextInLine.empty())
    {
        cur = nextInLine.front();
        nextInLine.pop();
        m[cur] = idx++;
        for(auto it : adj[cur])
        {
            in[it] --;
            if(in[it] == 0)
                nextInLine.push(it);
        }
    }
    for(auto it : top)
        og[m[it]] = og2[it];
    for(int i = 0; i < n; i ++)
        for(auto it : adj[i])
            adj2[m[i]].push_back(m[it]);
    dp[0] = 1;
    for(int i = 1; i < 1<<top.size(); i ++)
    {
        if(!g(i)) continue;
        for(int j = 0; j < top.size(); j ++)
            if(i & (1<<j))
                dp[i] = (dp[i] + dp[i^(1<<j)]) % r;
    }
    fac[0] = 1;
    for(ll i = 1; i <= n; i ++)
        fac[i] = (fac[i-1] * i) % r;
    ans = exp(fac[top.size()], r-2);
    ans = (ans * fac[n]) % r;
    ans = (ans * exp(fac[n-top.size()], r-2)) % r;
    ans = (((ans * dp[(1<<top.size())-1]) % r) * fac[n-top.size()]) % r;
    cout << ans << '\n';
}
