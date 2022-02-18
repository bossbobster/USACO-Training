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

ifstream fin("roboherd.in");
ofstream fout("roboherd.out");

struct st
{
    ll cost;
    ll hsh;
    set<pii> idx;
    const bool operator>(const st& other) const
    {
        if(cost == other.cost)
            return hsh > other.hsh;
        return cost > other.cost;
    }
    const bool operator<(const st& other) const
    {
        if(cost == other.cost)
            return hsh < other.hsh;
        return cost < other.cost;
    }
    const bool operator==(const st& other) const
    {
        return hsh == other.hsh;
    }
};

st cur;
const ll base = 100003, mod = 20000000000001;
const ll inf = 2000000000000000000;
unordered_set<ll> vis;
//set<set<pii>> vis;
set<pii> empt;
int n, k, num;
int sz[100010];
vector<ll> nums[100010];
ll pw[100010];
set<st> pq;
queue<st> q;
priority_queue<st, vector<st>, greater<st>> pq2;
ll ogS = 0, mx = 0;
unordered_map<ll, ll> add;
set<pii> ord, ogOrd;
set<ll> all;
int idx, i;
plll bs(ll l, ll r)
{
    ll mid = (l+r+1)/2, sum = ogS;
    int cnt = 1;
    pq.clear();
    pq.insert({ogS, 0, empt}); vis.clear(); ord = ogOrd;
    vis.insert(0);
    while(!pq.empty())
    {
        cur = *pq.begin();
        pq.erase(pq.begin());
        for(auto it : cur.idx)
            ord.erase({nums[it.f][1]-nums[it.f][0], it.f}), ord.insert({nums[it.f][it.s+1]-nums[it.f][it.s], it.f});
        for(auto it : ord)
        {
            i = it.s;
            if(vis.find((cur.hsh+pw[i]) % mod) != vis.end()) continue;
            idx = 0;
            for(auto it2 : cur.idx)
                if(it2.f == i)
                {
                    idx = it2.s;
                    break;
                }
            if(idx == sz[i]-1) continue;
            if(cur.cost + (ll)it.f <= mid)
            {
                cnt ++;
                sum += cur.cost + (ll)it.f;
                add[cur.cost + (ll)it.f] ++;
                all.insert(cur.cost + (ll)it.f);
                if(cnt > k)
                {
                    ll mx = *all.rbegin();
                    all.erase(mx);
                    while(pq.size() && pq.rbegin()->cost == mx) pq.erase(prev(pq.end()));
                    sum -= add[mx]*mx;
                    cnt -= add[mx];
                    mid = mx-1;
                }
                if(cur.cost+(ll)it.f > mid) break;
                vis.insert((cur.hsh+pw[i]) % mod);
                if(idx == 0)
                    cur.idx.insert({i, 1});
                else
                    for(set<pii>::iterator j = cur.idx.begin(); j != cur.idx.end(); j ++)
                        if(j->f == i)
                        {
                            cur.idx.erase(j);
                            cur.idx.insert({i, idx+1});
                            break;
                        }
                pq.insert({cur.cost + (ll)it.f, (ll)((cur.hsh+pw[i]) % mod), cur.idx});
                if(idx == 0)
                    cur.idx.erase({i, 1});
                else
                    for(set<pii>::iterator j = cur.idx.begin(); j != cur.idx.end(); j ++)
                        if(j->f == i)
                        {
                            cur.idx.erase(j);
                            cur.idx.insert({i, idx});
                            break;
                        }
            }
            else
                break;
        }
        for(auto it : cur.idx)
            ord.insert({nums[it.f][1]-nums[it.f][0], it.f}), ord.erase({nums[it.f][it.s+1]-nums[it.f][it.s], it.f});
    }
    if(l >= r) return {{cnt, mid}, sum};
    return bs(mid, r);
}
int main()
{
    input();
    fin >> n >> k;
    for(int i = 0; i < n; i ++)
    {
        fin >> sz[i];
        for(int j = 0; j < sz[i]; j ++)
            fin >> num, nums[i].push_back(num);
        sort(nums[i].begin(), nums[i].end());
        mx += nums[i][0];
        nums[i].push_back(2000000000000000000);
        ord.insert({nums[i][1]-nums[i][0], i});
    }
    ogOrd = ord;
    pw[0] = 1;
    for(int i = 1; i <= n; i ++)
        pw[i] = (pw[i-1] * base) % mod;
    for(int i = 0; i < n; i ++)
        ogS += nums[i][0];
    set<pii>::iterator it = ord.begin();
    ll num = 0;
    for(int i = 0; i < min(19, n); i++, it++)
        num += it->f;
    plll ans = bs(mx+num, mx+num);
    fout << ans.s + (ll)(k-ans.f.f)*(ans.f.s+1LL) << '\n';
}
