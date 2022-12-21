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

//suffix array on concatenation, then do string hashing and binary walk to find LCP

ifstream fin("standingout.in");
ofstream fout("standingout.out");

string st[100010];
int which[200010], len[200010];
int n, idxAll, num, pp;
int cnt[27], idx[28];
piii all[200010];
string big;
int pre[200010][20];
const ll mod = 1000000007, p = 31;
ll pw[200010], hsh[200010];
void hshs()
{
    hsh[0] = 1;
    for(int i = 0; i < (int)big.length(); i ++)
        hsh[i+1] = ((hsh[i]*p) % mod + (ll)big[i]) % mod;
}
ll get(int a, int b)
{
    return (hsh[b+1] - (hsh[a]*pw[b-a+1])%mod+mod) % mod;
}
void suf()
{
    int whichA = 0;
    memset(len, -1, sizeof(len));
    for(int i = 0; i < n; i ++)
    {
        cnt[big[i]-'a'] ++;
        if(big[i] == '{')
        {
            whichA ++;
            which[i] = -1;
            for(int j = i-(int)st[which[i-1]].length(); j < i; j ++)
                len[j] = i-j;
        }
        else which[i] = whichA;
    }
    idx[0] = -1;
    for(int i = 1; i < 28; i ++)
        idx[i] = idx[i-1] + min(1, cnt[i-1]);
    for(int i = 0; i < n; i ++)
        pre[i][0] = idx[big[i]-'a'+1];
    pp = log2(n);
    for(int i = 1; i <= pp; i ++)
    {
        idxAll = 0;
        for(int j = 0; j < n; j ++)
            all[idxAll++] = {{pre[j][i-1], pre[j+(1<<(i-1))][i-1]}, j};
        sort(all, all+n);
        num = 0;
        for(int j = 0; j < n; j ++)
            pre[all[j].s][i] = (j != 0 && all[j].f.f == all[j-1].f.f && all[j].f.s == all[j-1].f.s)?pre[all[j-1].s][i]:num++;
    }
}
set<pii> srt1;
vector<int> sorted;
int l[200010], r[200010], same[200010];
ll lcp(int i1, int i2)
{
    if(i1 == -1 || i2 == -1) return 0;
    int mx = min(len[i1], len[i2]);
    int ppp = log2(mx), eq1 = i1, eq2 = i2;
    while(ppp > -1)
    {
        if(get(eq1, eq1+(1<<ppp)-1) == get(eq2, eq2+(1<<ppp)-1)) eq1 = eq1+(1<<ppp), eq2 = eq2+(1<<ppp);
        ppp--;
    }
    return min((ll)mx, (ll)(eq1-i1));
}
ll ans[100010];
int main()
{
    input();
    int m;
    fin >> m;
    big.reserve(m+100010);
    for(int i = 0; i < m; i ++)
        fin >> st[i], big += st[i], big += "{";
    n = (int)big.length();
    suf();
    for(int i = 0; i < n; i ++)
        srt1.insert({pre[i][pp], i});
    for(auto it : srt1)
        if(which[it.s] != -1)
            sorted.push_back(it.s);
    pw[0] = 1;
    for(int i = 1; i <= big.length(); i ++)
        pw[i] = (pw[i-1]*p)%mod;
    hshs();
    int prr = -1;
    memset(same, -1, sizeof(same));
    for(auto it : sorted)
    {
        if(prr != -1 && which[prr] == which[it]) same[it] = prr;
        if(prr == -1) l[it] = -1;
        else
        {
            if(which[prr] == which[it]) l[it] = l[prr];
            else l[it] = prr;
        }
        prr = it;
    }
    prr = -1;
    for(int i = (int)sorted.size()-1; i >= 0; i --)
    {
        if(prr == -1) r[sorted[i]] = -1;
        else
        {
            if(which[prr] == which[sorted[i]]) r[sorted[i]] = r[prr];
            else r[sorted[i]] = prr;
        }
        prr = sorted[i];
    }
    for(auto it : sorted)
        ans[which[it]] += len[it]-max({lcp(it, l[it]), lcp(it, r[it]), lcp(it, same[it])});
    for(int i = 0; i < m; i ++)
        fout << ans[i] << '\n';
}
