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
typedef pair<int, ll> pil;
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

ifstream fin("sprinklers.in");
ofstream fout("sprinklers.out");

const ll mod = 1000000007;
int seg[300010];
int lazy[300010];
void msum(int& a, ll b)
{
    if(b >= mod) b %= mod;
    a += b;
    if(a >= mod) a -= mod;
}
void msub(int& a, ll b)
{
    if(b >= mod) b %= mod;
    a -= b;
    a += mod;
    if(a >= mod) a -= mod;
}
void updateRec(int node, int l, int r, int lq, int rq, int val)
{
    if(lazy[node])
    {
        msum(seg[node], (ll)lazy[node] * (r-l+1));
        if(l != r)
        {
            msum(lazy[node*2+1], lazy[node]);
            msum(lazy[node*2+2], lazy[node]);
        }
        lazy[node] = 0;
    }
    if(l > rq || r < lq || l > r) return;
    if(l >= lq && r <= rq)
    {
        msum(seg[node], (ll)val * (r-l+1));
        if(l != r)
        {
            msum(lazy[node*2+1], val);
            msum(lazy[node*2+2], val);
        }
        return;
    }
    int mid = (l+r)/2;
    updateRec(node*2+1, l, mid, lq, rq, val); updateRec(node*2+2, mid+1, r, lq, rq, val);
    seg[node] = (seg[node*2+1]+seg[node*2+2])%mod;
}
void update(int lq, int rq, int val, int n) { updateRec(0, 0, n-1, lq, rq, val); }
int sumRec(int node, int l, int r, int lq, int rq)
{
    if(lazy[node])
    {
        msum(seg[node], (ll)lazy[node] * (r-l+1));
        if(l != r)
        {
            msum(lazy[node*2+1], lazy[node]);
            msum(lazy[node*2+2], lazy[node]);
        }
        lazy[node] = 0;
    }
    if(l > rq || r < lq || l > r) return 0;
    if(l >= lq && r <= rq)
        return seg[node];
    int mid = (l+r)/2;
    return (sumRec(node*2+1, l, mid, lq, rq)+sumRec(node*2+2, mid+1, r, lq, rq))%mod;
}
int sum(int lq, int rq, int n) { return sumRec(0, 0, n-1, lq, rq); }
struct pt
{
    int x, y;
    const bool operator<(const pt& other) const
    {
        return y < other.y;
    }
};
pt nums[100010];
set<int, greater<int>> all;
int len[100010], l[100010], r[100010];
int ch2(ll x)
{
    return ((x*(x+1))/2)%mod;
}
int main()
{
    input();
    int n, mn = 2000000000;
    fin >> n;
    for(int i = 0; i < n; i ++)
        fin >> nums[i].x >> nums[i].y;
    sort(nums, nums+n);
    for(int i = 0; i < n; i ++)
        all.insert(nums[i].x);
    memset(l, -1, sizeof(l)); memset(r, -1, sizeof(r));
    for(int i = 0; i < n; i ++)
    {
        all.erase(nums[i].x);
        mn = min(mn, nums[i].x);
        len[i] = max(0, *all.begin()-mn);
        if(len[i] != 0)
            l[i] = mn, r[i] = *all.begin();
    }
    int cur = ch2(len[0]), ans = cur;
    update(l[0], r[0]-1, 1, n);
    for(int i = 1; i < n; i ++)
    {
        if(l[i] == -1) { cur = 0; continue; }
        msum(cur, ch2(len[i]));
        if(r[i] < r[i-1])
            for(int j = r[i]; j <= r[i-1]-1; j ++)
                msub(cur, sum(l[i-1], j, n));
        update(l[i], r[i]-1, 1, n);
        msum(ans, cur);
    }
    fout << ans << '\n';
    return 0;
}
